#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace cv;

int main () {

    // read the image.
    Mat img = imread("/home/kpit/opencv-4.x/samples/data/butterfly.jpg", IMREAD_COLOR);

    //convert to grayscale image.
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    //Initialize the SURF detector.
    Ptr<xfeatures2d::SURF> surf= xfeatures2d::SURF::create(50000);

    std::vector<KeyPoint> keypoints;
    Mat descriptors;

    //Detect keypoints and compute descriptors.
    surf->detectAndCompute(img, noArray(),keypoints, descriptors);

    //Draw the detected keypoints on the image.
    Mat img_keypts;
    drawKeypoints(img, keypoints, img_keypts, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    
    //Display the image with keypoints.

    imshow("surf", img_keypts);
    imwrite("surf.jpg", img_keypts);
    waitKey(0);
    return 0;


}
