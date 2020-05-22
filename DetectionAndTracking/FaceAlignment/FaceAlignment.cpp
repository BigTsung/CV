// System
#include <iostream>
#include <sstream>

// Opencv - Basic
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/opencv.hpp>
// Opencv - Contrib
#include <opencv2/tracking.hpp>

using namespace std;
using namespace cv;

int spacing = 40;

int main()
{
    // ===============================
    // Init
    // ===============================
    int frameIndex = 0;
    cv::Mat frame, gray, faceROIRGB, faceROIGray;
    cv::Mat canvas = cv::Mat(cv::Size(1024, 1024), CV_8UC3);

    std::vector<cv::Rect> faces;
    std::vector<cv::Rect> noses;
     
    string videoName = string(getenv("CV_SOURCE_PATH")) + string("/video/dick_schulman_content_IMG_1307.mp4");
    VideoCapture cam(videoName);
    
    // ===============================
    // Init for Face
    // ===============================
    string face_cascade_name = string(getenv("CV_SOURCE_PATH")) + "/etc/haarcascades/haarcascade_frontalface_alt.xml";
    cv::CascadeClassifier face_cascade;

    if( !face_cascade.load( face_cascade_name ) )
    {
       cout << ("--(!)Error loading") << endl; 
       return -1; 
    };

    // ===============================
    // Init for Nose
    // ===============================
    std::vector<cv::Point> nosePoints;
    string nose_cascade_name = string(getenv("CV_SOURCE_PATH")) + "/etc/cascades/haarcascade_mcs_nose.xml";
    cv::CascadeClassifier nose_cascade;

    if( !nose_cascade.load( nose_cascade_name ) )
    {
       cout << ("--(!)Error loading") << endl; 
       return -1; 
    };

    // ===============================
    // Processing
    // ===============================

    while(cam.read(frame))
    {
      // ===============================
      // Pre Processing
      // ===============================
      // cout << "Pre Processing" << endl;
      cvtColor(frame, gray, CV_RGB2GRAY);
    
      equalizeHist(gray, gray);
      // ===============================
      // Face Detection
      // ===============================
      // cout << "Face Detection" << endl;
      face_cascade.detectMultiScale(gray, faces);

      // cv::Mat faceROI;
      float faceAreaValue = std::numeric_limits<float>::min();
      cv::Rect targetFace;
      float tempForFaceArea = 0;
      cv::Point center;
      for( size_t i = 0; i < faces.size(); i++)
      {
        tempForFaceArea = faces[i].width * faces[i].height;

        if(tempForFaceArea > faceAreaValue)
        {
          targetFace = faces[i];
          center.x = faces[i].x + faces[i].width * 0.5;
          center.y = faces[i].y + faces[i].height * 0.5;

          faceAreaValue = tempForFaceArea;
        }
      }

      // ellipse(frame, center, cvSize(targetFace.width * 0.5, targetFace.height * 0.5), 0, 0, 360, cvScalar(0, 230, 230), 4, 8, 0 );
      
      // ===============================
      // Nose Detection
      // ===============================
      // cout << "FNose Detection" << endl;
      // faceROIRGB = frame(cv::Rect(targetFace.x, targetFace.y, targetFace.width, targetFace.height));

      faceROIRGB = frame;

      cvtColor(faceROIRGB, faceROIGray, CV_RGB2GRAY);

      nose_cascade.detectMultiScale(faceROIGray, noses, 1.1, 50);

      // cout << "Nose number: " << noses.size() << endl;

      if(noses.size() <= 0)
        continue;
      
      cv::Point noseCenter;
      cv::Rect targetNose;

      float noseAreaValue = std::numeric_limits<float>::min();
      float tempForNoseArea = 0;
      int radius;
      
      for( size_t j = 0; j < noses.size(); j++)
      {
        tempForNoseArea = noses[j].width * noses[j].height;

        if(tempForNoseArea > noseAreaValue)
        {
          targetNose = noses[j];
          noseCenter.x = noses[j].x + noses[j].width * 0.5;
          noseCenter.y = noses[j].y + noses[j].height * 0.5;

          radius = noses[j].width;

          noseAreaValue = tempForNoseArea;
          nosePoints.push_back(noseCenter);
        }
      }
      // rectangle(faceROIRGB,
      //           cv::Point(targetNose.x - spacing * 0.5, + targetNose.y),
      //           cv::Point(targetNose.x + targetNose.width + spacing * 0.5, targetNose.y + targetNose.height),
      //           cvScalar(20, 150, 240), 4, 8, 0
      // );
      
      // cv::imshow("faceROIRGB", faceROIRGB);

      // for(int i = 0; i < nosePoints.size(); i++)
      // {
      //   ellipse(faceROIRGB, nosePoints[i], cvSize(2, 2), 0, 0, 360, cvScalar(0, 230, 230), 4, 8, 0 );
      // }

      // ===============================
      // Face Alignment (Simple)
      // ===============================
      // cout << "Face Alignment (Simple)" << endl;
      cv::Mat image(frame); 

      cv::Rect faceROI(targetNose.x + targetNose.width * 0.5 - targetFace.width * 0.5,
                       targetNose.y + targetNose.height * 0.5 - targetFace.height * 0.5,
                       targetFace.width,
                       targetFace.height);

      cv::Mat croppedImage = image(faceROI);

      canvas.setTo(cv::Scalar::all(0));

      // imshow("croppedImage", croppedImage);

      cv::Mat insetImage(canvas, 
                         Rect(canvas.rows * 0.5 - targetFace.width * 0.5,
                              canvas.cols * 0.5 - targetFace.height * 0.5,
                              targetFace.width,
                              targetFace.height));

      croppedImage.copyTo(insetImage);

      cv::imshow("insetImage", canvas);
      // cv::imwrite("dick_aligned_result/" + to_string(frameIndex) + ".jpg", canvas);

      // ===============================
      // Display
      // ===============================
      // Frame Index
      // cv::putText(faceROIRGB, "Frame Index: " + std::to_string(frameIndex), cv::Point(20, 50), cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(20, 20, 20), 2);
      
      // Target Nose Center
      // cv::putText(faceROIRGB, "Nose Center: " + std::to_string(targetNose.x) + " " + std::to_string(targetNose.y), cv::Point(20, 100), cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(50, 50, 50), 2);
      
      
      // Show Image Result      
      // cv::imshow("ROI", imgRoi);
      // cv::imshow("Result", faceROIRGB);
      // cv::imshow("Face Detection Result", frame);  

      frameIndex++;
      if (cv::waitKey(1) == 27) break;
    }

    return 0;
}

// Reference 
// 1. https://docs.opencv.org/2.4/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html