#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Open the default camera
    VideoCapture cap(0);
    
    // Check if camera opened successfully
    if(!cap.isOpened()){
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    // Create a window to display the camera feed
    namedWindow("Camera Feed", WINDOW_NORMAL);
    
    while(1){
        Mat img;
        // Capture img-by-img
        cap >> img;
        
        // If the img is empty, break the loop
        if (img.empty())
            break;
        
        // Display the resulting img
        imshow( "Camera Feed", img );
        
        // Press ESC on keyboard to exit
        char c=(char)waitKey(25);
        if(c==27)
            break;
    }
    
    // When everything done, release the video capture object
    cap.release();
    
    // Closes all the imgs
    destroyAllWindows();
    
    return 0;
}
