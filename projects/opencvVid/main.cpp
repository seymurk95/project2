/*#include <iostream>
#include <opencv2/opencv.hpp>
int main() {
    cv::VideoCapture video("/home/stud-05/Downloads/FPV Drone Flight through Beautiful Iceland Canyon.mp4");
    if (!video.isOpened()) {
        std::cerr<<"Can not open the video"<<std::endl;
        return -1;
    }
    cv::Mat frame;
    while(video.read(frame)) {
        cv::imshow("My video",frame);
        if(cv::waitKey(25) == 'q') {
            break;
        }
    }
    video.release();
    cv::destroyAllWindows();
    return 0;
}*/
/*#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
int main() {
    cv::Mat image(500,500, CV_8UC3,cv::Scalar(255,255,255));
    if(!image.data) {
        std::cerr<<"Can not create image"<<std::endl;
        return -1;
    }
    cv::Point p1(30,30);
    cv::Point p2(250,250);
    int thickness = 5;
    cv::rectangle(image,p1,p2,cv::Scalar(20,90,20),thickness);
    cv::imshow("Output",image);
    cv::waitKey();
    return 0;
}*/
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
int main() {
    cv::Mat image = imread("/home/stud-05/Downloads/images.jpeg",cv::IMREAD_GRAYSCALE);
    if(!image.data) {
        std::cerr<<"Can not create image"<<std::endl;
        return -1;
    }
    cv::Point p1(30,30);
    cv::Point p2(250,250);
    int thickness = -1;
    cv::rectangle(image,p1,p2,cv::Scalar(20,90,20),thickness);
    cv::imshow("Output",image);
    cv::waitKey();
    return 0;
}