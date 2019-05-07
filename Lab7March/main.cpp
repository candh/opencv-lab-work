#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
  if (argc != 2) {
    puts("DisplayImage: PLease provide an image file");
    return 1;
  }

  Mat image;
  image = imread(argv[1], 1);
  if (!image.data) {
    puts("No image data");
    return 1;
  }

  imshow("Cat", image);
  // wait
  waitKey(0);
  return 0;
}