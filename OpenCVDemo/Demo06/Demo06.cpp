#include <iostream>
#include <direct.h>
#include <opencv2/opencv.hpp>

#pragma warning (disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

static void ContrastAndBright(int, void*);

Mat SrcMat, DstMat;
int ContrastValue, BrightValue;

int main(int argc, char* argv[])
{
	char _Path[PATH_SIZE];

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/pic.jpg");

	SrcMat = imread(_Path);

	namedWindow("Demo06 - Src Image");
	imshow("Demo06 - Src Image", SrcMat);

	DstMat = Mat::zeros(SrcMat.size(), SrcMat.type());

	ContrastValue = 80;
	BrightValue = 80;

	namedWindow("Demo06 - Adjust");

	createTrackbar("Contrast: ", "Demo06 - Adjust", &ContrastValue, 300, ContrastAndBright);
	createTrackbar("Bright: ", "Demo06 - Adjust", &BrightValue, 300, ContrastAndBright);

	ContrastAndBright(ContrastValue, nullptr);
	ContrastAndBright(BrightValue, nullptr);

	while (char(waitKey(1)) != 'q') {}

	return 0;
}

static void ContrastAndBright(int Value, void* Data)
{
	for (int i = 0; i < SrcMat.rows; ++i)
	{
		for (int j = 0; j < SrcMat.cols; ++j)
		{
			for (int c = 0; c < 3; ++c)
			{
				DstMat.at<Vec3b>(i, j)[c] = saturate_cast<uchar>((ContrastValue * 0.01) * (SrcMat.at<Vec3b>(i, j)[c]) + BrightValue);
			}
		}
	}

	imshow("Demo06 - Adjust", DstMat);
}