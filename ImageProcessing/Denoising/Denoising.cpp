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
    int imgW, imgH, offsetX = 100, offsetY = 10, windowSpacing = 0;
    int MAX_KERNEL_LENGTH = 31;
    int DELAY_BLUR = 100;
    string imgName = string(getenv("CV_SOURCE_PATH")) + string("/img/Lena_salt_noise.jpg");
    cv::Mat rgb = cv::imread(imgName, cv::IMREAD_UNCHANGED);
    cv::Mat denoise_h_3;
    cv::Mat denoise_h_9;
    cv::Mat denoise_h_15;
    cv::Mat denoise_h_30;
    cv::Mat denoise_h_60;

    imgW = rgb.cols;
    imgH = rgb.rows;

    // h: Parameter regulating filter strength for luminance component. 
    //    Bigger h value perfectly removes noise but also removes image details, 
    //    smaller h value preserves details but also preserves some noise

    // hColor: The same as h but for color components. 
    //         For most images value equals 10 will be enough to remove colored noise and do not distort colors

    // templateWindowSize: Size in pixels of the template patch that is used to compute weights. 
    //                     Should be odd. Recommended value 7 pixels

    // searchWindowSize: Size in pixels of the window that is used to compute weighted average for given pixel.
    //                   Should be odd. Affect performance linearly: greater searchWindowsSize - greater denoising time. 
    //                   Recommended value 21 pixels

    cv::fastNlMeansDenoisingColored(rgb, denoise_h_3, 3, 0, 7, 21);
    cv::fastNlMeansDenoisingColored(rgb, denoise_h_9, 9, 0, 7, 21);   
    cv::fastNlMeansDenoisingColored(rgb, denoise_h_15, 15, 0, 7, 21);   
    cv::fastNlMeansDenoisingColored(rgb, denoise_h_30, 30, 0, 7, 21);       
    cv::fastNlMeansDenoisingColored(rgb, denoise_h_60, 60, 0, 7, 21);  

    cv::imshow("Original_RGB", rgb);
    cv::imshow("Original_Denoise_h_3", denoise_h_3);
    cv::imshow("Original_Denoise_h_9", denoise_h_9);
    cv::imshow("Original_Denoise_h_15", denoise_h_15);
    cv::imshow("Original_Denoise_h_30", denoise_h_30);
    cv::imshow("Original_Denoise_h_60", denoise_h_60);

    cv::moveWindow("Original_RGB", offsetX + imgW * 0, offsetY + imgH * 0);
    cv::moveWindow("Original_Denoise_h_3", offsetX + imgW * 1, offsetY + imgH * 0);
    cv::moveWindow("Original_Denoise_h_9", offsetX + imgW * 2, offsetY + imgH * 0);

    cv::moveWindow("Original_Denoise_h_15", offsetX + imgW * 0, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("Original_Denoise_h_30", offsetX + imgW * 1, offsetY + imgH * 1 + windowSpacing);
    cv::moveWindow("Original_Denoise_h_60", offsetX + imgW * 2, offsetY + imgH * 1 + windowSpacing);

    cv::waitKey(0);
    return 0;
}

// Reference 
// 1. 
