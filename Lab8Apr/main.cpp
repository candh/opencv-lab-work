#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {

  VideoCapture cap(0);

  while (69) {
    Mat frame;
    Mat output;

    bool flg = cap.read(frame);
    // inRange(frame, Scalar(100, 0, 0), Scalar(255, 100, 100), output);

    Mat output1;

    inRange(frame, Scalar(0, 0, 100), Scalar(100, 100, 255), output1);
  
    Mat output2;
    inRange(frame, Scalar(100, 0, 0), Scalar(255, 100, 100), output2);

    Mat output3;
    inRange(frame, Scalar(0, 100, 0), Scalar(100, 255, 100), output3);

    Mat combine = output1|output2|output3; 

    namedWindow("Display Image From Webcam. ", WINDOW_AUTOSIZE );
    imshow("Frame", combine);

    if (waitKey(27) == 27) {
      cout << "quiting" << endl;
      break;
    }
  } 

  return 0;
}
