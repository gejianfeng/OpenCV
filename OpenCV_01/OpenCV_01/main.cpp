#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[])
{
	Mat _Image = imread("F:\\git_root\\OpenCV\\OpenCV_01\\Res\\pic.jpg");
	namedWindow("Game Image");
	imshow("Game Image", _Image);
	waitKey(6000);
}