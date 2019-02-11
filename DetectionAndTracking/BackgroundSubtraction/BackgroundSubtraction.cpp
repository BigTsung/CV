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
    cv::Mat frame, foreground;
    string videoName = string(getenv("CV_SOURCE_PATH")) + string("/video/vtest.avi");
    cv::VideoCapture cap(videoName); // open the default camera
    
    // cv::Ptr<cv::BackgroundSubtractorMOG2> pBackSub = cv::createBackgroundSubtractorMOG2();
    cv::Ptr<cv::BackgroundSubtractorKNN> pBackSub = cv::createBackgroundSubtractorKNN();

    if(!cap.isOpened())  // check if we succeeded
        return -1;
   
   for(;;)
    {
        cap >> frame; // get a new frame from camera
        pBackSub->apply(frame, foreground);
        cv::imshow("source video",  frame);
        cv::imshow("foreground",    foreground);
        if(cv::waitKey(30) >= 0) break;
	}

    return 0;
}

// Reference 
// 1. https://docs.opencv.org/3.3.1/de/de1/group__video__motion.html