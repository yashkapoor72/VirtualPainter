#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img(512,512,CV_8UC3,Scalar(255,121,200));
    circle(img,Point(256,256),155, Scalar(0,0,0),FILLED);
    rectangle(img,Point(130,100),Point(382,286),Scalar(255,255,255),3);
    imshow("image",img);
    waitKey(0);
}