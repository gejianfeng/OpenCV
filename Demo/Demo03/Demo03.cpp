#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

const int MaxPath = 250;

int main(int argc, char* argv[])
{
	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\pic.jpg");

	Mat _Image = imread(_Path);
	namedWindow("Image");
	imshow("Image", _Image);

	memset(_Path, 0, sizeof(_Path));

	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon3.jpg");

	Mat _Icon = imread(_Path);
	namedWindow("Icon");
	imshow("Icon", _Icon);

	Mat _ROI = _Image(Rect(0, 0, _Icon.cols, _Icon.rows));
	addWeighted(_ROI, 0.5, _Icon, 0.3, 0, _ROI);

	namedWindow("Mixed Image");
	imshow("Mixed Image", _Image);

	imwrite("mixed.jpg", _Image);

	waitKey();

	return 0;
}