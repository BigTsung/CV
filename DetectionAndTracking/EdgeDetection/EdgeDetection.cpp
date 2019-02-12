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
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    int lowThreshold = 70;
    int ratio = 3;
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/Lena.jpg");
    cv::Mat rgb = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::Mat gray;
    cv::Mat soble_x, soble_y, abs_soble_x, abs_soble_y, sobel_result;
    cv::Mat abs_laplacian, laplacian_result;
    cv::Mat canny_result;
    
    imgW = rgb.cols;
    imgH = rgb.rows;
    
    GaussianBlur(rgb, rgb, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );
    cvtColor(rgb, gray, cv::COLOR_RGB2GRAY);

    // Sobel /////////////////////////
    Sobel( gray, soble_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
    convertScaleAbs( soble_x, abs_soble_x );
    
    Sobel( gray, soble_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
    convertScaleAbs( soble_x, abs_soble_y );

    addWeighted( abs_soble_x, 0.5, abs_soble_y, 0.5, 0, sobel_result );
   
    // Laplacian /////////////////////////
    Laplacian( gray, abs_laplacian, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT );
    convertScaleAbs( abs_laplacian, laplacian_result );
    
    // Canny /////////////////////////
    Canny( gray, canny_result, lowThreshold, lowThreshold * ratio, kernel_size );

    cv::imshow("rgb", rgb);
    cv::imshow("gray", gray);
    cv::imshow("soble", sobel_result);
    cv::imshow("laplacian", laplacian_result);
    cv::imshow("canny", canny_result);

    cv::moveWindow("rgb", 	offsetX + imgW * 0, offsetY + imgH * 0);
    cv::moveWindow("gray", 	offsetX + imgW * 1, offsetY + imgH * 0);
    cv::moveWindow("soble",  offsetX + imgW * 0, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("laplacian",  offsetX + imgW * 1, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("canny",  offsetX + imgW * 2, offsetY + imgH * 1 + windowSpacing);

    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html#sobel-derivatives
// 2. https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/laplace_operator/laplace_operator.html#laplace-operator
// 3. https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html#canny-detector



