#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    string path = "/Users/yashkapoor/Desktop/WobotImages/Jpeg2/img_449.jpg";
    Mat img = imread(path);
    imshow("Imaage",img);
    waitKey(0);

    return 0;
}