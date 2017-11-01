#include <iostream>
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void CreateAlphaMat(Mat& InMat)
{
	for (int i = 0; i < InMat.rows; ++i)
	{
		for (int j = 0; j < InMat.cols; ++j)
		{
			Vec4b& _Rgba = InMat.at<Vec4b>(i, j);
			_Rgba[0] = UCHAR_MAX;
			_Rgba[1] = saturate_cast<uchar>((float(InMat.cols - j)) / ((float)InMat.cols) * UCHAR_MAX);
			_Rgba[2] = saturate_cast<uchar>((float(InMat.rows - i)) / ((float)InMat.rows) * UCHAR_MAX);
			_Rgba[3] = saturate_cast<uchar>(0.5 * (_Rgba[1] + _Rgba[2]));
		}
	}
}

int main(int argc, char* argv[])
{
	Mat _Mat(480, 640, CV_8UC4);
	CreateAlphaMat(_Mat);

	vector<int> _CompressionParams;
	_CompressionParams.push_back(CV_IMWRITE_PNG_COMPRESSION);
	_CompressionParams.push_back(9);

	try
	{
		imwrite("Alpha.png", _Mat, _CompressionParams);
	}
	catch (runtime_error& ex)
	{
		fprintf(stderr, "Error during convert to png format: ", ex.what());
		return 1;
	}

	fprintf(stdout, "Alpha data for .png file is saved.");

	return 0;
}