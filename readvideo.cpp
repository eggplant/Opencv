/*
VideoCapture

	cv::VideoCapture capture(
	const string& filename, // �����ļ��� .MPG��.AVI��ʽ
	);

	cv::VideoCapture capture(
	int device // ��Ƶ��׽�豸 id ���ֻ��1�����������ô����0�����ϵͳ���ж�����������ôֻҪ�����������Ӽ���
	);

	cv::VideoCapture capture(cv::CAP_IEEE1394 + 1); cv::VideoCapture�����Դ򿪵�2������Ŵ�0��ʼ��1394�������

	cv::VideoCapture capture();

Video write

	cv::VideoWriter::write(
		const Mat& image // д��ͼ����Ϊ��һ֡
	);

	my_video_writer << my_frame;

	���ڶ�ȡ��д���ϸ�µĺ�������
		https://blog.csdn.net/guduruyu/article/details/68486063
*/


#include<opencv2/videoio.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void playVideo(VideoCapture& video) {
	if (!video.isOpened()) {//��Ч��ȡ
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

