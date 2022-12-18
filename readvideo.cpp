/*
VideoCapture

	cv::VideoCapture capture(
	const string& filename, // 输入文件名 .MPG或.AVI格式
	);

	cv::VideoCapture capture(
	int device // 视频捕捉设备 id 如果只有1个摄像机，那么就是0，如果系统中有多个摄像机，那么只要将其向上增加即可
	);

	cv::VideoCapture capture(cv::CAP_IEEE1394 + 1); cv::VideoCapture将尝试打开第2个（编号从0开始）1394摄像机。

	cv::VideoCapture capture();

Video write

	cv::VideoWriter::write(
		const Mat& image // 写入图像作为下一帧
	);

	my_video_writer << my_frame;

	关于读取和写入更细致的函数介绍
		https://blog.csdn.net/guduruyu/article/details/68486063
*/


#include<opencv2/videoio.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void playVideo(VideoCapture& video) {
	if (!video.isOpened()) {//有效读取
		cerr << "Check if the video exists!" << endl;
		return;
	}
	while (true) {
		Mat frame;
		video >> frame;

		if (frame.empty())
			break;

		imshow("Video", frame);

		if (waitKey(1000 / video.get(CAP_PROP_FPS)) != -1)
			break;

	}
}

int main3(void) {

	VideoCapture camera(0);
	playVideo(camera);

//	VideoCapture video("");
//	playVideo(video);

	return 0;

}

