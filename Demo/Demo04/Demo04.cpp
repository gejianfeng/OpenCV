#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

const int MaxPath = 250;

void ROI_AddImage();
void LinearBlending();
void ROI_LinearBlending();

int main(int argc, char* argv[])
{
	ROI_AddImage();
	LinearBlending();
	ROI_LinearBlending();

	waitKey(0);
	return 0;
}

void ROI_AddImage()
{
	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\pic.jpg");

	Mat _Image = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon7.jpg");

	Mat _Icon = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon6.jpg");

	Mat _Mask = imread(_Path, CV_LOAD_IMAGE_GRAYSCALE);

	namedWindow("Mask");
	imshow("Mask", _Mask);

	Mat _ROI = _Image(Rect(0, 0, _Icon.cols, _Icon.rows));
	_Icon.copyTo(_ROI, _Mask);

	namedWindow("ROI Add Image");
	imshow("ROI Add Image", _Image);
}

void LinearBlending()
{
	double _AlphaValue = 0.5;
	double _BetaValue;

	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon1.jpg");

	Mat _Image = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon2.jpg");

	Mat _Icon = imread(_Path);

	_BetaValue = 1 - _AlphaValue;

	Mat _Output;

	addWeighted(_Image, _AlphaValue, _Icon, _BetaValue, 0, _Output);

	namedWindow("Mixed Image");
	imshow("Mixed Image", _Output);
}

void ROI_LinearBlending()
{
	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\pic.jpg");

	Mat _Image = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon2.jpg");

	Mat _Icon = imread(_Path);

	Mat _ROI = _Image(Rect(50, 50, _Icon.cols, _Icon.rows));

	addWeighted(_ROI, 0.5, _Icon, 0.3, 0, _ROI);

	namedWindow("ROI Mixed Image");
	imshow("ROI Mixed Image", _Image);
}