#include <iostream>
#include <direct.h>
#include <opencv2/opencv.hpp>

#pragma warning(disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

int main(int argc, char* argv[])
{
	Mat _Mat(480, 960, CV_8UC4);

	for (int i = 0; i < _Mat.rows; ++i)
	{
		for (int j = 0; j < _Mat.cols; ++j)
		{
			Vec4b &_RGBA = _Mat.at<Vec4b>(i, j);
			_RGBA[0] = UCHAR_MAX;
			_RGBA[1] = saturate_cast<uchar>((float(_Mat.cols - j)) / ((float)_Mat.cols) * UCHAR_MAX);
			_RGBA[2] = saturate_cast<uchar>((float(_Mat.rows - i)) / ((float)_Mat.rows) * UCHAR_MAX);
			_RGBA[3] = saturate_cast<uchar>(0.5f * (_RGBA[1] + _RGBA[2]));
		}
	}

	std::vector<int> _CompressParams;
	_CompressParams.push_back(CV_IMWRITE_PNG_COMPRESSION);
	_CompressParams.push_back(9);

	try {
		imwrite("AlphaImage.png", _Mat, _CompressParams);
	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}

	namedWindow("Demo02");
	imshow("Demo02", _Mat);

	waitKey(0);

	return 0;
}