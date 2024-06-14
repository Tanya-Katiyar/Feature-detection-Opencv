#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int, char**){

    //read the image
    Mat img = imread("/home/kpit/opencv-4.x/samples/data/building.jpg", IMREAD_COLOR);

    //convert to grayscale image
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    Mat dst = Mat::zeros(img.size(), CV_32FC1);

    //applying corner harris function
    cornerHarris(gray, dst, 2, 3, 0.04);

    Mat norm;

    //normalizing the image
    normalize(dst, norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    Mat scaled;

    //converting to unsigned 8-bit image.
    convertScaleAbs(norm, scaled );

    for(int i=0; i<scaled.rows; i++) {
        for(int j=0; j<scaled.cols; j++) {

            //if the value is greater than threshold, then it will be a corner.
            if((int)norm.at<float>(i,j) > 156) {

                //drawing circles on the detected points in scaled as well as original image.
                circle(img, Point(j,i), 2, Scalar(0,0,255), 2, LINE_AA, 0);
                circle(scaled, Point(j,i), 2, Scalar(0,0,255), 2, LINE_AA, 0);
            }
        }
    }

    //output display
    imshow("corners on scaled image", scaled);
    imwrite("scaled.jpg", scaled);
    imshow("corners", img);
    imwrite("corners.jpg", img);
    waitKey(0);
}
