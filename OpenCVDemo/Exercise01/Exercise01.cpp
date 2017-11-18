#include <iostream>
#include <direct.h>
#include <opencv2/opencv.hpp>

#pragma warning (disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

int main(int argc, char* argv[])
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _SrcMat = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon1.jpg");

	Mat _MaskMat = imread(_Path, CV_LOAD_IMAGE_GRAYSCALE);
	bitwise_not(_MaskMat, _MaskMat);
	threshold(_MaskMat, _MaskMat, 30, 255,  THRESH_BINARY);

	Mat _ImageROI = _SrcMat(Rect((_SrcMat.cols - _MaskMat.cols) / 2, (_SrcMat.rows - _MaskMat.rows) / 2, _MaskMat.cols, _MaskMat.rows));
	
	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic4.jpg");

	Mat _LogoMat = imread(_Path);

	Mat _LogoROI = _LogoMat(Rect((_LogoMat.cols - _MaskMat.cols) / 2, (_LogoMat.rows - _MaskMat.rows) / 2, _MaskMat.cols, _MaskMat.rows));
	
	_LogoROI.copyTo(_ImageROI, _MaskMat);

	namedWindow("Exercise01");
	imshow("Exercise01", _SrcMat);

	waitKey(0);

	return 0;
}