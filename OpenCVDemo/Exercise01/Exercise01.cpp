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
	strcat(_Path, "/../../Resource/icon1.jpg");

	Mat _SrcMat = imread(_Path);
	namedWindow("Exercise01 - Src", WINDOW_FREERATIO);
	imshow("Exercise01 - Src", _SrcMat);

	Mat _GrayMat = imread(_Path, CV_LOAD_IMAGE_GRAYSCALE);
	namedWindow("Exercise01 - Gray", WINDOW_FREERATIO);
	imshow("Exercise01 - Gray", _GrayMat);

	Mat _MaskMat;
	bitwise_not(_GrayMat, _MaskMat);
	threshold(_MaskMat, _MaskMat, 30, 255, THRESH_BINARY);
	namedWindow("Exercise01 - Mask", WINDOW_FREERATIO);
	imshow("Exercise01 - Mask", _MaskMat);

	std::vector<Mat> _Channels;
	split(_SrcMat, _Channels);

	Mat _RedChannel = _Channels.at(2);
	namedWindow("Exercise01 - Red Channel", WINDOW_FREERATIO);
	imshow("Exercise01 - Red Channel", _RedChannel);

	Mat _BlueChannel = _Channels.at(0);
	namedWindow("Exercise01 - Blue Channel", WINDOW_FREERATIO);
	imshow("Exercise01 - Red Channel", _BlueChannel);

	Mat _GreenChannel = _Channels.at(1);
	namedWindow("Exercise01 - Green Channel", WINDOW_FREERATIO);
	imshow("Exercise01 - Green Channel", _GreenChannel);
	
	Mat _MixMat;
	Mat _TmpBlue, _TmpRed, _TmpGreen;

	std::vector<Mat> _BlueColor;

	_TmpBlue = Mat::zeros(_MaskMat.size(), CV_8UC1);
	bitwise_not(_TmpBlue, _TmpBlue);
	bitwise_not(_MaskMat, _TmpGreen);
	bitwise_not(_MaskMat, _TmpRed);

	_BlueColor.push_back(_TmpBlue);
	_BlueColor.push_back(_TmpGreen);
	_BlueColor.push_back(_TmpRed);

	merge(_BlueColor, _MixMat);
	namedWindow("Exercise01 - Blue Merge", WINDOW_FREERATIO);
	imshow("Exercise01 - Blue Merge", _MixMat);

	std::vector<Mat> _RedColor;

	_TmpRed = Mat::zeros(_MaskMat.size(), CV_8UC1);
	bitwise_not(_TmpRed, _TmpRed);
	bitwise_not(_MaskMat, _TmpGreen);
	bitwise_not(_MaskMat, _TmpBlue);

	_RedColor.push_back(_TmpBlue);
	_RedColor.push_back(_TmpGreen);
	_RedColor.push_back(_TmpRed);

	merge(_RedColor, _MixMat);
	namedWindow("Exercise01 - Red Merge", WINDOW_FREERATIO);
	imshow("Exercise01 - Red Merge", _MixMat);

	std::vector<Mat> _GreenColor;

	_TmpGreen = Mat::zeros(_MaskMat.size(), CV_8UC1);
	bitwise_not(_TmpGreen, _TmpGreen);
	bitwise_not(_MaskMat, _TmpRed);
	bitwise_not(_MaskMat, _TmpBlue);

	_GreenColor.push_back(_TmpBlue);
	_GreenColor.push_back(_TmpGreen);
	_GreenColor.push_back(_TmpRed);

	merge(_GreenColor, _MixMat);
	namedWindow("Exercise01 - Green Merge", WINDOW_FREERATIO);
	imshow("Exercise01 - Green Merge", _MixMat);

	waitKey(0);

	return 0;
}