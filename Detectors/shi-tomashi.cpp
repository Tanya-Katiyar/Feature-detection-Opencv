#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int, char**){

    //read the image

    Mat img = imread("/home/kpit/opencv-4.x/samples/data/left09.jpg", IMREAD_COLOR);

    //convert to grayscale image

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    std::vector<Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;

    //detects the corners in the grayscale image, where number of corners to be detected is 200.

    goodFeaturesToTrack(gray, corners, 200, qualityLevel, minDistance);

    int radius = 4;
    for( size_t i = 0; i < corners.size(); i++ )
    {
    circle( img, corners[i], radius, Scalar(0,255,255),2 );  //drawing the circle on the corners.
    }

    imshow("image", img);
    imwrite("shitomashi.jpg", img);
    waitKey(0);

}
