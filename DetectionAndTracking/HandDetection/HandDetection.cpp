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
#include <opencv2/dnn.hpp>
// Opencv - Contrib
#include <opencv2/tracking.hpp>

using namespace std;

const int POSE_PAIRS[20][2] =
{
    {0,1}, {1,2}, {2,3}, {3,4},         // thumb
    {0,5}, {5,6}, {6,7}, {7,8},         // index
    {0,9}, {9,10}, {10,11}, {11,12},    // middle
    {0,13}, {13,14}, {14,15}, {15,16},  // ring
    {0,17}, {17,18}, {18,19}, {19,20}   // small
};

string protoFile = "/etc/hand/pose_deploy.prototxt";
string weightsFile = "/etc/hand/pose_iter_102000.caffemodel";

int nPoints = 22;

int main()
{
    cv::Mat frame;
    cv::VideoCapture cap(0);

    int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    float aspect_ratio = frameWidth/(float)frameHeight;
    int inHeight = 368;
    int inWidth = (int(aspect_ratio*inHeight) * 8) / 8;
    float thresh = 0.01;
    
    if(!cap.isOpened())
        return -1;
   
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(string(getenv("CV_SOURCE_PATH")) + protoFile, string(getenv("CV_SOURCE_PATH")) + weightsFile);
    cv::Mat output;
   for(;;)
    {
        cap >> frame; 
        
        cv::Mat inpBlob = cv::dnn::blobFromImage(frame, 1.0 / 255, cvSize(inWidth, inHeight), cvScalar(0, 0, 0), false, false);
        
        net.setInput(inpBlob);

        output = net.forward();

        int H = output.size[2];
        int W = output.size[3];

        vector<cv::Point> points(nPoints);
        for (int n=0; n < nPoints; n++)
        {
            cv::Mat probMap(H, W, CV_32F, output.ptr(0,n));
            resize(probMap, probMap, cvSize(frameWidth, frameHeight));

            cv::Point maxLoc;
            double prob;
            minMaxLoc(probMap, 0, &prob, 0, &maxLoc);
            if (prob > thresh)
            {
                circle(frame, cv::Point((int)maxLoc.x, (int)maxLoc.y), 8, cvScalar(0,255,255), -1);
                cv::putText(frame, cv::format("%d", n), cv::Point((int)maxLoc.x, (int)maxLoc.y), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2);

            }
            points[n] = maxLoc;
        }

        int nPairs = sizeof(POSE_PAIRS)/sizeof(POSE_PAIRS[0]);

        for (int n = 0; n < nPairs; n++)
        {
            cv::Point2f partA = points[POSE_PAIRS[n][0]];
            cv::Point2f partB = points[POSE_PAIRS[n][1]];

            if (partA.x<=0 || partA.y<=0 || partB.x<=0 || partB.y<=0)
                continue;

            line(frame, partA, partB, cvScalar(0,255,255), 8);
            circle(frame, partA, 8, cvScalar(0,0,255), -1);
            circle(frame, partB, 8, cvScalar(0,0,255), -1);
        }

        cv::imshow("hand detection resuly",  frame);
        if(cv::waitKey(30) >= 0) break;
	}

    return 0;
}

// Reference 
// 1. https://github.com/spmallick/learnopencv/tree/master/HandPose
// 2. https://www.learnopencv.com/hand-keypoint-detection-using-deep-learning-and-opencv/