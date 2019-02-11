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
    int imgW, imgH, offsetX = 50, offsetY = 50, windowSpacing = 20;
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/Lena.jpg");
    cv::Mat rgb = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::Mat gray, yCbCr, hsv, hls, lab, luv, bgr;
    
    imgW = rgb.cols;
    imgH = rgb.rows;
    
    cvtColor(rgb, gray, cv::COLOR_RGB2GRAY);
    cvtColor(rgb, yCbCr, cv::COLOR_RGB2YCrCb);
    cvtColor(rgb, hsv, cv::COLOR_RGB2HSV);
    cvtColor(rgb, hls, cv::COLOR_RGB2HLS);
    cvtColor(rgb, lab, cv::COLOR_RGB2Lab);
    cvtColor(rgb, luv, cv::COLOR_RGB2Luv);
    cvtColor(rgb, bgr, cv::COLOR_RGB2BGR);
    
    cv::imshow("rgb", rgb);
    cv::imshow("gray", gray);
    cv::imshow("yCbCr", yCbCr);
    cv::imshow("hsv", hsv);
    cv::imshow("hls", hls);
    cv::imshow("lab", lab);
    cv::imshow("luv", luv);
    cv::imshow("bgr", bgr);

    cv::moveWindow("rgb", 	offsetX + imgW * 0, offsetY + imgH * 0);
    cv::moveWindow("gray", 	offsetX + imgW * 1, offsetY + imgH * 0);
    cv::moveWindow("yCbCr", offsetX + imgW * 2, offsetY + imgH * 0);
    cv::moveWindow("hsv", 	offsetX + imgW * 3, offsetY + imgH * 0);
	cv::moveWindow("hls", 	offsetX + imgW * 0, offsetY + imgH * 1 + windowSpacing);
	cv::moveWindow("lab", 	offsetX + imgW * 1, offsetY + imgH * 1 + windowSpacing);
	cv::moveWindow("luv", 	offsetX + imgW * 2, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("bgr", 	offsetX + imgW * 3, offsetY + imgH * 1 + windowSpacing);

    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. https://docs.opencv.org/3.1.0/de/d25/imgproc_color_conversions.html