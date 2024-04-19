///Users/yashkapoor/Desktop/SampleWobot/SampleVideo2.mp4
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    string path = "/Users/yashkapoor/Desktop/SampleWobot/SampleVideo2.mp4";
    VideoCapture captcha(path);
    Mat img;
    while (true){
        captcha.read(img);
        imshow("Imaage",img);
        waitKey(10);
    }

    return 0;
}