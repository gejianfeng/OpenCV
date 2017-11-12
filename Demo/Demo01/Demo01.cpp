#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

#pragma warning(disable:4996) 

using namespace cv;

const int MAX_PATH_SIZE = 256;

int main(int argc, char* argv[])
{
	char _Path[MAX_PATH_SIZE];
	
	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _Image = imread(_Path);
	namedWindow("Demo01");
	imshow("Demo01", _Image);

	waitKey(0);

	return 0;
}