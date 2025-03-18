#include <iostream>
#include<opencv2/opencv.hpp>
int main() {
    cv::Mat img = cv::imread("/home/stud-05/Downloads/images.jpeg",cv::IMREAD_COLOR);
    if(img.empty()) {
        std::cerr<<"Can not load image"<<std::endl;
        return -1;
    }
    cv:: Mat resized;
    /*int new_width = 300;
    int new_height = 200;
    cv::resize(img, resized, cv::Size(new_width, new_height));*/
    /*int x=10,y=4,width=50,height=50;
    cv::Mat cropped = img(cv::Rect(x,y,width,height));
    cv::imshow("images",cropped);
    cv::waitKey(0);
    cv::destroyAllWindows();*/

    double angle = 45.0;
    cv::Point2f center(cv::Point(img.cols/2,img.rows/2));
    cv::Mat rotation_mat = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::Mat rotated;
    cv::warpAffine(img, rotated, rotation_mat,img.size());
    cv::imshow("images",rotated);
    cv::waitKey(0);
    cv::destroyAllWindows();


    return 0;
}
