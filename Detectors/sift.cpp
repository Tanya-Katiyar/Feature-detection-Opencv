#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main () {

    // read the image.

    Mat img = imread("/home/kpit/opencv-4.x/samples/data/home.jpg", IMREAD_COLOR);

    //convert to grayscale image.
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    //Initialize the SIFT detector.
    Ptr<SIFT> sift = SIFT::create();

    std::vector<KeyPoint> keypoints;
    Mat descriptors;

    //Detect keypoints and compute descriptors.
    sift->detectAndCompute(img, noArray(),keypoints, descriptors);

    //Draw the detected keypoints on the image.
    Mat img_keypts;
    drawKeypoints(img, keypoints, img_keypts, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
    
    //Display the image with keypoints.

    imshow("sift", img_keypts);
    imwrite("sift.jpg", img_keypts);
    waitKey(0);
    return 0;

}
