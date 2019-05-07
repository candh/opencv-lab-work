#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// #include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv ) {
	if ( argc != 2 ) {
		printf("usage: DisplayImage.out <Image_Path>\n");
		return -1;
	}
	Mat image;
	// Mat result;
	image = imread( argv[1], 1 );
	if ( !image.data ) {
		printf("No image data \n");
		return -1;
	}

  // in this program we basically flip an image
  Mat flipped;
  flip(image, flipped, -1);
  Mat flipped2;
  flip(image, flipped2, 0);
  Mat flipped3;
  flip(image, flipped3, 1);


  // for these values, see your register notes
  Mat output1;
  // count the number of red pixels detected
  inRange(image, Scalar(0, 0, 100), Scalar(100, 100, 255), output1);
  
  Mat output2;
  inRange(image, Scalar(100, 0, 0), Scalar(255, 100, 100), output2);

  Mat output3;
  inRange(image, Scalar(0, 100, 0), Scalar(100, 255, 100), output3);

  Mat combine = output1|output2|output3; 

  int redPixels = countNonZero(output1);
  cout << "Total Number of red extracted pixels: "  << redPixels << endl;

	namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);
  imshow("Flipped image 1 -1", flipped);
  imshow("Flipped image 2 - 0", flipped2);
  imshow("Flipped image 2 - 1", flipped3);
  imshow("Red extracted?", output1);
  imshow("Blue extracted?", output2);
  imshow("Combined output", combine);

	waitKey(0);
	return 0;
}
