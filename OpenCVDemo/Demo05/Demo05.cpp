#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma warning (disable: 4996 4068)

using namespace cv;

const int PATH_SIZE = 256;

void MultiChannelBlending(int Index, Mat& SrcMat, const Mat& MarkerMat, const std::string& WindowTitle)
{
	if (Index < 0 || Index >= 3)
	{
		return;
	}

	std::vector<Mat> _Channels;
	split(SrcMat, _Channels);

	Mat _TargetChannel = _Channels.at(Index);

	Mat _ImageROI = _TargetChannel(Rect(0, 0, MarkerMat.cols, MarkerMat.rows));
	addWeighted(_ImageROI, 1.0f, MarkerMat, 0.5f, 0.0f, _ImageROI);

	Mat _DstMat;
	merge(_Channels, _DstMat);

	namedWindow(WindowTitle.c_str());
	imshow(WindowTitle.c_str(), _DstMat);
}

int main(int argc, char* argv[])
{
	char _Path[PATH_SIZE];

	std::vector<std::string> _WindowTitle;
	_WindowTitle.push_back("Demo05 - Blue Channel");
	_WindowTitle.push_back("Demo05 - Green Channel");
	_WindowTitle.push_back("Demo05 - Red Channel");

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, sizeof(_Path));
	strcat(_Path, "/../../Resource/icon3.jpg");

	Mat _MarkerMat = imread(_Path, 0);

	for (int i = 0; i < _WindowTitle.size(); ++i)
	{
		memset(_Path, 0, sizeof(_Path));
		getcwd(_Path, sizeof(_Path));
		strcat(_Path, "/../../Resource/pic.jpg");

		Mat _SrcMat = imread(_Path);

		MultiChannelBlending(i, _SrcMat, _MarkerMat, _WindowTitle.at(i));
	}

	waitKey(0);

	return 0;
}