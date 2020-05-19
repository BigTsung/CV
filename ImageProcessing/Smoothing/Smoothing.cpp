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
// #include <opencv2/tracking.hpp>

using namespace std;

int main()
{
    int imgW, imgH, offsetX = 50, offsetY = 20, windowSpacing = 20;
    int MAX_KERNEL_LENGTH = 31;
    int DELAY_BLUR = 100;
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/Lena_512.jpg");
    cv::Mat rgb = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::Mat gray, blur, gaussianBlur, medianBlur, bilateralFilter;
    
    imgW = rgb.cols;
    imgH = rgb.rows;
    
    cvtColor(rgb, gray, cv::COLOR_RGB2GRAY); 

    // Blur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        cv::blur(gray, blur, cv::Size( i, i), cv::Point(-1,-1));
    }

    // GaussianBlur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur( gray, gaussianBlur, cv::Size( i, i ), 0, 0 );
    }

    // MedianBlur
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        cv::medianBlur ( gray, medianBlur, i );
    }

    // BilateralFilter
    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        cv::bilateralFilter ( gray, bilateralFilter, i, i*2, i/2 );
    }

    cv::imshow("Original_RGB", rgb);
    cv::imshow("Original_Gray", gray);
    cv::imshow("Blur", blur);
    cv::imshow("GaussianBlur", gaussianBlur);
    cv::imshow("MedianBlur", medianBlur);
    cv::imshow("BilateralFilter", bilateralFilter);
  
    cv::moveWindow("Original_RGB", offsetX + imgW * 0, offsetY + imgH * 0);
    cv::moveWindow("Blur", offsetX + imgW * 1, offsetY + imgH * 0);
    cv::moveWindow("GaussianBlur", offsetX + imgW * 2, offsetY + imgH * 0);

    cv::moveWindow("Original_Gray", offsetX + imgW * 0, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("MedianBlur", offsetX + imgW * 1, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("BilateralFilter", offsetX + imgW * 2, offsetY + imgH * 1 + windowSpacing);

    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. https://docs.opencv.org/3.4/dc/dd3/tutorial_gausian_median_blur_bilateral_filter.html
