#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[])
{
	Mat _Image = imread("F:\\git_root\\OpenCV\\Resource\\pic.jpg");
	namedWindow("Image");
	imshow("Image", _Image);
	waitKey(6000);
}