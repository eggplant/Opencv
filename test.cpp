
//打开摄像头测试
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
using namespace cv;

int main1()
{
	VideoCapture cap(0);
	Mat frame;
	while (1)
	{
		cap >> frame;
		imshow("调用摄像头", frame);
		waitKey(30);
	}
	return 0;
}
