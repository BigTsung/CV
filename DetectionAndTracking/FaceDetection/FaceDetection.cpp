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

int main()
{
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/1.prepodavateli_1_may_19511may1951-prepodavateli-stefan_kutsarov,prof.dudulov,ivan_petrov,prof._boris_mitov,_prof._marko_markov,_panayot_panayotov,_nenko_balkanski,_krum_kiuliavkov,kadrovichka_velcheva.jpg");
    cv::Mat img = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::Mat gray;
    string face_cascade_name = string(getenv("CV_SOURCE_PATH")) + "/etc/haarcascades/haarcascade_frontalface_alt.xml";
    cv::CascadeClassifier face_cascade;
    if( !face_cascade.load( face_cascade_name ) )
    {
    	 cout << ("--(!)Error loading") << endl; 
    	 return -1; 
    };
   

    cvtColor( img, gray, CV_RGB2GRAY );
  	equalizeHist( gray, gray );

  	std::vector<cv::Rect> faces;
  	face_cascade.detectMultiScale( gray, faces);

  	for( size_t i = 0; i < faces.size(); i++ )
  	{
	    cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	    ellipse( img, center, cvSize( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cvScalar( 0, 230, 230 ), 4, 8, 0 );
  	}

    cv::imshow("Face Detection Result", img);  
    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. https://docs.opencv.org/2.4/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html