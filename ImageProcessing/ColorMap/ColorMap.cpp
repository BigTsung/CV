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
    cv::Mat frame, foreground, heatmap, heatmapColor, gray, threshold, result;
    string videoName = string(getenv("CV_SOURCE_PATH")) + string("/video/vtest.avi");
    cv::VideoCapture cap(videoName);

    cv::Ptr<cv::BackgroundSubtractorKNN> pBackSub = cv::createBackgroundSubtractorKNN();

    if(!cap.isOpened())
        return -1;

   for(;;)
    {
        cap >> frame;
        resize(frame, frame, cvSize(frame.cols/2, frame.rows/2));
        cvtColor(frame, gray, cv::COLOR_RGB2GRAY);
        pBackSub->apply(frame, foreground);
        
        cv::imshow("source(RGB)", frame);

        cv::threshold(foreground, threshold, 2, 255, cv::THRESH_BINARY);
        
        cv::imshow("detection result", threshold);

        normalize(threshold, threshold, 0, 1, cv::NORM_MINMAX);
             
        if(heatmap.empty())
        {
            heatmap.create(threshold.rows, threshold.cols, threshold.type());
        }
        else
        {
            if(!threshold.empty())
            {
                add(threshold, heatmap, heatmap);
                applyColorMap(heatmap, heatmapColor, cv::COLORMAP_JET);
                cv::threshold(heatmapColor, heatmapColor, 150, 255, cv::THRESH_TOZERO);
                addWeighted(frame, 1, heatmapColor, 1, 0.0, result);
            }
        }

        if(!result.empty())
            cv::imshow("result", result);
       
     
        if(!heatmapColor.empty())
            cv::imshow("heatmapColor", heatmapColor);
        
        if(cv::waitKey(30) >= 0) 
            break;
	}

    return 0;
}

// Reference 
// 1. https://www.learnopencv.com/applycolormap-for-pseudocoloring-in-opencv-c-python/
// 2. https://www.kurokesu.com/main/2016/10/24/heatmap-motion-analysis-of-autonomous-robot/
// 3. https://docs.opencv.org/2.4/modules/contrib/doc/facerec/colormaps.html