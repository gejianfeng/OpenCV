#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void ROI_AddImage()
{
	Mat _Src1 = imread("D:\\Project\\OpenCV\\Resource\\pic.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	Mat _Src2 = imread("D:\\Project\\OpenCV\\Resource\\icon.png", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);

	Mat _ROI = _Src1(Rect(50, 50, _Src2.rows, _Src2.cols));
	Mat _Mask = imread("D:\\Project\\OpenCV\\Resource\\icon.png");

	_Src2.copyTo(_ROI, _Mask);

	namedWindow("ROI Demo");
	imshow("ROI Demo", _Src1);
}

void LinearBlending()
{
	double _AlphaValue = 0.5f;
	double _BetaValue = 0.0f;

	Mat _Src1 = imread("D:\\Project\\OpenCV\\Resource\\icon1.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	Mat _Src2 = imread("D:\\Project\\OpenCV\\Resource\\icon2.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);

	_BetaValue = (1.0f - _AlphaValue);

	Mat _Dst;
	addWeighted(_Src1, _AlphaValue, _Src2, _BetaValue, 0.0f, _Dst);

	namedWindow("Src Image");
	imshow("Src Image", _Src1);

	namedWindow("Blend Image");
	imshow("Blend Image", _Dst);
}

int main(int argc, char* argv[])
{
	//ROI_AddImage();
	LinearBlending();

	waitKey();

	return 0;
}