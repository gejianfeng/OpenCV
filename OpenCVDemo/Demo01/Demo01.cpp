#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

#pragma warning (disable: 4996 4068)

const int PATH_SIZE = 256;

int main(int argc, char* argv[])
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _Mat = imread(_Path);
	namedWindow("Demo01");
	imshow("Demo01", _Mat);

	waitKey(0);

	return 0;
}