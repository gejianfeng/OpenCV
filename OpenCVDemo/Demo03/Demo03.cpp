#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma warning (disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

int main(int argc, char* argv[])
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _OrignalMat = imread(_Path);

	namedWindow("Demo03 - Orignal Image");
	imshow("Demo03 - Orignal Image", _OrignalMat);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon3.jpg");

	Mat _MarkerMat = imread(_Path);

	namedWindow("Demo03 - Marker Image");
	imshow("Demo03 - Marker Image", _MarkerMat);

	Mat _ImageROI = _OrignalMat(Rect(50, 50, _MarkerMat.cols, _MarkerMat.rows));
	addWeighted(_ImageROI, 0.5, _MarkerMat, 0.3, 0.0, _ImageROI);

	namedWindow("Demo03 - Mixed Image");
	imshow("Demo03 - Mixed Image", _OrignalMat);

	imwrite("MixedImage.jpg", _OrignalMat);

	waitKey(0);
	return 0;
}