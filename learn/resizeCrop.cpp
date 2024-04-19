#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    string path = "/Users/yashkapoor/Desktop/yashcop.png";
    Mat img = imread(path);
    Mat imgResize, imgCrop;
    //cout<<img.size()<<endl;
    resize(img,imgResize,Size(640,480));
    Rect roi(200,100,250,350);
    imgCrop = img(roi);


    imshow("Image",img);
    imshow("Resized Image",imgResize);
    imshow("Cropped Image",imgCrop);

    waitKey(0);

    return 0;
}