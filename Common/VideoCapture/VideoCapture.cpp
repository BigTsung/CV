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
    cv::Mat frame;
    cv::VideoCapture cap(0); // open the default camera
    
    if(!cap.isOpened())  // check if we succeeded
        return -1;
   
   for(;;)
    {
        cap >> frame; // get a new frame from camera
        cv::imshow("Display Window", frame);
        if(cv::waitKey(30) >= 0) break;
	}

    return 0;
}

// Reference 
// 1. https://docs.opencv.org/3.1.0/d8/dfe/classcv_1_1VideoCapture.html