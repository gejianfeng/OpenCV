#include <iostream>
#include <opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void CreateAlphaMat(Mat& InMat)
{
	for (int i = 0; i < InMat.rows; ++i)
	{
		for (int j = 0; j < InMat.cols; ++j)
		{
			Vec4b& _Pixel = InMat.at<Vec4b>(i, j);
			_Pixel[0] = UCHAR_MAX; //saturate_cast<uchar>((float(InMat.rows - i)) / ((float)InMat.rows) * UCHAR_MAX);
			_Pixel[1] = saturate_cast<uchar>((float(InMat.cols - j)) / ((float)InMat.cols) * UCHAR_MAX);
			_Pixel[2] = saturate_cast<uchar>((float(InMat.rows - i)) / ((float)InMat.rows) * UCHAR_MAX);
			_Pixel[3] = saturate_cast<uchar>(0.5 * (_Pixel[1] + _Pixel[2]));
		}
	}
}

int main(int argc, char* argv[])
{
	Mat _Mat(480, 640, CV_8UC4);
	
	CreateAlphaMat(_Mat);

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