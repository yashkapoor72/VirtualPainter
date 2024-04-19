#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
//my pen color 0,0,151,114,255,255,,
using namespace cv;
using namespace std;

Mat imgHsv,mask;
int hmin =0, smin = 0, vmin =0;
int hmax =179, smax = 255, vmax =255;
VideoCapture cap(0);
Mat img;

int main() {
    namedWindow("TrackBars", (640,200));
    createTrackbar("Hue MiN", "TrackBars",&hmin,255);
    createTrackbar("Hue Max", "TrackBars",&hmax,255);
    createTrackbar("Sat Min", "TrackBars",&smin,255);
    createTrackbar("Sat Max", "TrackBars",&smax,255);
    createTrackbar("Val MiN", "TrackBars",&vmin,255);
    createTrackbar("Val Max", "TrackBars",&vmax,255);
    namedWindow("Camera Feed", WINDOW_NORMAL);
    
    while(1){
        cap >> img;
        cvtColor(img,imgHsv,COLOR_BGR2HSV);
        Scalar lower(hmin,smin,vmin);
        Scalar upper(hmax,smax,vmax);
        inRange(imgHsv,lower,upper,mask);
        cout<<hmin<<","<<smin<<","<<vmin<<","<<hmax<<","<<smax<<","<<vmax<<","<<endl;
        imshow( "Camera Feed", img );
        imshow("Mask",mask);
        
        waitKey(1);
    }
    
    return 0;
}
