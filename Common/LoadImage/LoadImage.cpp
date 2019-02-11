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
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/Lena.jpg");
    cv::Mat img = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::imshow("Display Window", img);  
    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. https://docs.opencv.org/3.1.0/d4/da8/group__imgcodecs.html
// 2. http://monkeycoding.com/?p=540