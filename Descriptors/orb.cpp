#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
 
Mat visualizeORB(Mat image, vector<KeyPoint> keypoints) {

    // Draw keypoints on the original image
    Mat visualizedImage;

    drawKeypoints(image, keypoints, visualizedImage, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
 
    return visualizedImage;
}
 
int main() {

    // Read the image
    Mat image = imread("/home/kpit/opencv-4.x/samples/data/leuvenB.jpg", IMREAD_COLOR);
 
    // Initialize ORB detector
    Ptr<ORB> orb = ORB::create();
 
    // Detect ORB keypoints and compute descriptors
    vector<KeyPoint> keypoints;
    Mat descriptors;
    
    orb->detectAndCompute(image, Mat(), keypoints, descriptors);
 
    // Visualize keypoints on the original image
    Mat visualizedImage = visualizeORB(image, keypoints);
 
    // Display the visualized image
    imshow("ORB", visualizedImage);
    waitKey(0);
 
    // Save the visualized image
    imwrite("orb.jpg", visualizedImage);
 
    return 0;
}
 

