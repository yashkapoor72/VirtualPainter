#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    string path = "/Users/yashkapoor/Desktop/WobotImages/Jpeg2/img_449.jpg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgErode, imgDia;

    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(img,imgBlur,Size(3,3),3,0);
    Canny(imgBlur,imgCanny,25,75);

    Mat kernel = getStructuringElement( MORPH_RECT, Size(3,3) );
    dilate(imgCanny,imgDia,kernel);
    erode(imgDia,imgErode,kernel);

    imshow("Image",img);
    imshow("Gray Image",imgGray);
    imshow("Blur Image",imgBlur);
    imshow("Canny Image",imgCanny);
    imshow("Dilated Image",imgDia);
    imshow("Eroded Image",imgErode);

    waitKey(0);

    return 0;
}