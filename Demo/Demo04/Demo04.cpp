#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma warning(disable: 4996)

using namespace cv;

const int MAX_PATH_SIZE = 255;

int main(int argc, char* argv[])
{
	char _Path[MAX_PATH_SIZE];
	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _MaskSrc = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon7.jpg");

	Mat _MaskTarget = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon6.jpg");

	Mat _MaskMat = imread(_Path, CV_LOAD_IMAGE_GRAYSCALE);

	Mat _MaskROI = _MaskSrc(Rect(50, 50, _MaskMat.cols, _MaskMat.rows));
	_MaskTarget.copyTo(_MaskROI, _MaskMat);

	namedWindow("Demo04 - Mask");
	imshow("Demo04 - Mask", _MaskSrc);

	double _AlphaValue = 0.5;
	double _BetaValue = 1 - _AlphaValue;

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _MixSrc = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon.png");

	Mat _MixTarget = imread(_Path);

	Mat _MixROI = _MixSrc(Rect(50, 50, _MixTarget.cols, _MixTarget.rows));
	addWeighted(_MixROI, _AlphaValue, _MixTarget, _BetaValue, 0.0, _MixROI);

	namedWindow("Demo04 - Line Blending");
	imshow("Demo04 - Line Blending", _MixSrc);

	waitKey(0);

	return 0;
}