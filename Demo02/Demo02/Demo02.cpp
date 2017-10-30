#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[])
{
	Mat _Image = imread("D:\\Project\\OpenCV\\Resource\\pic.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	Mat _Icon = imread("D:\\Project\\OpenCV\\Resource\\icon.png");

	namedWindow("Image");
	imshow("Image", _Image);

	namedWindow("Icon");
	imshow("Icon", _Icon);

	Mat _MixedImage = _Image(Rect(0, 0, _Icon.cols, _Icon.rows));
	addWeighted(_MixedImage, 0.5, _Icon, 0.3, 0, _MixedImage);

	namedWindow("Mixed Image");
	imshow("Mixed Image", _Image);

	imwrite("Demo02.jpg", _Image);

	waitKey();

	return 0;
}