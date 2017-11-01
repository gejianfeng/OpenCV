#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

const int MaxPath = 250;

int main(int argc, char* argv[])
{
	char _Buffer[MaxPath];
	getcwd(_Buffer, MaxPath);
	strcat(_Buffer, "\\..\\..\\Resource\\pic.jpg");

	Mat _Image = imread(_Buffer);

	namedWindow("Image");
	imshow("Image", _Image);
	
	waitKey(6000);
	
	return 0;
}