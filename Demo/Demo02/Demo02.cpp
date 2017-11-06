#include <iostream>
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void CreateAlphaMat(Mat& MatBuffer)
{
	for (int i = 0; i < MatBuffer.rows; ++i)
	{
		for (int j = 0; j < MatBuffer.cols; ++j)
		{
			Vec4b& _RGBA = MatBuffer.at<Vec4b>(i, j);
			_RGBA[0] = UCHAR_MAX;
			_RGBA[1] = saturate_cast<uchar>((float(MatBuffer.cols - j)) / ((float)MatBuffer.cols) * UCHAR_MAX);
			_RGBA[2] = saturate_cast<uchar>((float(MatBuffer.rows - i)) / ((float)MatBuffer.rows) * UCHAR_MAX);
			_RGBA[3] = saturate_cast<uchar>(0.5 * (_RGBA[1] + _RGBA[2]));
		}
	}
}

int main(int argc, char* argv[])
{
	Mat _MatBuffer(480, 640, CV_8UC4);

	CreateAlphaMat(_MatBuffer);

	vector<int> _CompressionParams;
	_CompressionParams.push_back(CV_IMWRITE_PNG_COMPRESSION);
	_CompressionParams.push_back(9);

	try
	{
		imwrite("AlphaImage.png", _MatBuffer, _CompressionParams);
	}
	catch (runtime_error& ex)
	{
		fprintf(stderr, "Error: %s\n", ex.what());
		return 1;
	}

	waitKey(0);

	return 0;
}