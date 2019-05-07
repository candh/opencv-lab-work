#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat makeRed(Mat image) {
  int i, j;
  for(i = image.rows / 2; i < image.rows; i++) {
    for(j = 0; j < image.cols; j++) {
      image.at<Vec3b>(i, j)[0] = 0; // blue
      image.at<Vec3b>(i, j)[1] = 0; // green
      image.at<Vec3b>(i, j)[2] = 255; // red
    }
  }
  return image;
}

int main(int argc, char * argv[]) {
  if (argc != 2) {
    puts("DisplayImage: PLease provide an image file");
    return 1;
  }

  Mat image;
  image = imread(argv[1], -1);

  if (!image.data) {
    puts("No image data");
    return 1;
  }

	namedWindow("Display Image", WINDOW_AUTOSIZE );

  imshow("Cat", image);

  Mat red = makeRed(image);
  imshow("Cat Red", red);

  // making the image red
  // wait
  waitKey(0);
  return 0;
}
