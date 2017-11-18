#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma warning (disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

void ROI_AddImage()
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _OrignalMat = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon7.jpg");

	Mat _LogoMat = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon6.jpg");

	Mat _MaskMat = imread(_Path, 0);

	Mat _ImageROI = _OrignalMat(Rect(50, 50, _MaskMat.cols, _MaskMat.rows));

	_LogoMat.copyTo(_ImageROI, _MaskMat);

	namedWindow("Demo04 - ROI AddImage");
	imshow("Demo04 - ROI AddImage", _OrignalMat);
}

void LinerBlending()
{
	float _AlphaValue = 0.5f;
	float _BetaValue = 1.0f - _AlphaValue;

	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic3.jpg");

	Mat _OrignalMat = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic4.jpg");

	Mat _MarkerMat = imread(_Path);

	Mat _DestMat;
	addWeighted(_OrignalMat, _AlphaValue, _MarkerMat, _BetaValue, 0.0f, _DestMat);

	namedWindow("Demo04 - LinerBlending");
	imshow("Demo04 - LinerBlending", _DestMat);
}

void ROI_LinerBlending()
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	Mat _OrignalMat = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon3.jpg");

	Mat _MarkerMat = imread(_Path);

	Mat _ImageROI = _OrignalMat(Rect(200, 200, _MarkerMat.cols, _MarkerMat.rows));
	addWeighted(_ImageROI, 0.5f, _MarkerMat, 0.3f, 0.0f, _ImageROI);

	namedWindow("Demo04 - ROI LinerBlending");
	imshow("Demo04 - ROI LinerBlending", _OrignalMat);
}

int main(int argc, char* argv[])
{
	ROI_AddImage();
	LinerBlending();
	ROI_LinerBlending();

	waitKey(0);

	return 0;
}