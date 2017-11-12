#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma warning (disable: 4996)

using namespace cv;

const int MAX_PATH_SIZE = 255;

int main(int argc, char* argv[])
{
	char _Path[MAX_PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _Image = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon2.jpg");

	Mat _Icon = imread(_Path);

	Mat _ImageROI = _Image(Rect(50, 100, _Icon.cols, _Icon.rows));
	addWeighted(_ImageROI, 0.5, _Icon, 0.3, 0, _ImageROI);

	namedWindow("Demo03");
	imshow("Demo03", _Image);

	waitKey(0);

	return 0;
}