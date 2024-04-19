#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
//81,49,99,105,255,247
//0,138,120,255,210,255
using namespace cv;
using namespace std;

Mat img;
VideoCapture cap(0);

vector<vector<int>> myColors {
    {81,49,99,105,255,247}, //blue
    {0,138,120,255,210,255} //yellow
};

vector<Scalar> myColorValues{{255,0,0},//blue
                            {0,100,100}//yellow
                           };

vector<vector<int>> newPoints;

int hmin =0, smin = 0, vmin =0;
int hmax =179, smax = 255, vmax =255;

Point getContours(Mat mask){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(mask,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    Point myPoint(0,0);
    for (int i=0;i<contours.size();i++){
        int area = contourArea(contours[i]);
        //cout<<area<<endl;
        string objectType ;
        if (area > 1000){
            float peri = arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02 * peri, true);
            //cout<<conPoly[i].size()<<endl;
            boundRect[i] = boundingRect(conPoly[i]);
            myPoint.x = boundRect[i].x + boundRect[i].width /2 ;
            myPoint.y = boundRect[i].y ;
            drawContours(img, conPoly,i, Scalar(255,0,255),2);
            rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),5);
        }
    }
    return myPoint;
}

void findColor(Mat img){ 
    Mat imgHsv;
    for (int i=0; i<myColors.size();i++){
        cvtColor(img,imgHsv,COLOR_BGR2HSV);
        Scalar lower(myColors[i][0],myColors[i][1],myColors[i][2]);
        Scalar upper(myColors[i][3],myColors[i][4],myColors[i][5]);
        Mat mask;
        inRange(imgHsv,lower,upper,mask);
        //imshow(to_string(i),mask);
        Point myPoint = getContours(mask);
        if (myPoint.x !=0 && myPoint.y !=0){
            newPoints.push_back({myPoint.x,myPoint.y,i});
        }
        waitKey(1);
    }
}

void drawOnCanvas(vector<vector<int>> newPoints,vector<Scalar> myColorValues){
    for (int i =0 ; i<newPoints.size();i++){
        circle(img,Point(newPoints[i][0],newPoints[i][1]),10,myColorValues[newPoints[i][2]],FILLED);
    }
}

int main() {

    while(1){
        cap >> img;
        findColor(img);
        drawOnCanvas(newPoints,myColorValues);
        imshow("Image",img);
        waitKey(1);
    }
    
    return 0;
}
