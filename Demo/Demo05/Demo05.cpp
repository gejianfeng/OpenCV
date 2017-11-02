#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

const int MaxPath = 250;

void ShowSingleChannelImage();
void MultiChannelBlending(int Index, const std::string& ChannelName);

int main(int argc, char* argv[])
{
	//ShowSingleChannelImage();
	MultiChannelBlending(0, "Blue Channel");
	MultiChannelBlending(1, "Green Channel");
	MultiChannelBlending(2, "Red Channel");

	waitKey(0);

	return 0;
}

void ShowSingleChannelImage()
{
	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\pic2.jpg");

	Mat _Image = imread(_Path);

	std::vector<Mat> _Channels;

	split(_Image, _Channels);

	for (int i = 0; i < _Channels.size(); ++i)
	{
		auto _Element = _Channels[i];

		std::string _Name;

		switch (i)
		{
		case 0:
			_Name = "Blue";
			break;
		case 1:
			_Name = "Green";
			break;
		case 2:
			_Name = "Red";
			break;
		default:
			_Name = "Undefined";
			break;
		}

		namedWindow(_Name);
		imshow(_Name, _Element);
	}
}

void MultiChannelBlending(int Index, const std::string& ChannelName)
{
	if (Index < 0 || Index > 2)
	{
		return;
	}

	std::vector<Mat> _Channels;

	char _Path[MaxPath];
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\pic.jpg");

	Mat _Image = imread(_Path);

	memset(_Path, 0, sizeof(_Path));
	getcwd(_Path, MaxPath);
	strcat(_Path, "\\..\\..\\Resource\\icon1.jpg");

	Mat _Icon = imread(_Path, CV_LOAD_IMAGE_GRAYSCALE);

	split(_Image, _Channels);

	Mat _BlueChannelMat = _Channels.at(Index);
	Mat _ROIBlue = _BlueChannelMat(Rect(0, 0, _Icon.cols, _Icon.rows));
	addWeighted(_ROIBlue, 1.0, _Icon, 0.5, 0, _ROIBlue);

	merge(_Channels, _Image);

	namedWindow(ChannelName);
	imshow(ChannelName, _Image);
}