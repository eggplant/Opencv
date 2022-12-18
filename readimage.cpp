/*imread����

1. ��ȡ·����ʽ��
	//-- 1 --˫��б�߷�
	//string imgpath = "C:\\Users\\bingbuyu\\Pictures\\photo\\miao1.jpg";
	//-- 2 --˫��б�߷�
	//string imgpath = "C://Users//bingbuyu//Pictures//photo//miao1.jpg";
	//-- 3 --����б�߷�
	//string imgpath = "C:/Users/bingbuyu/Pictures/photo/miao1.jpg";
	//-- 4 --�������ֻ�Ϸ�
	//string imgpath = "C:/Users//bingbuyu\\Pictures//photo//miao1.jpg";
	//-- 5 --���·����
	//string imgpath = "miao.jpg";
	//-- 6 --�����в�����
	string imgpath = argv[1];
2. �ڶ������� flag��
	- 1�����ս��뷽ʽ��ȡ
	0�����յ�ͨ����ȡ��Ҳ���ǻҰ�ͼ��
	1����ͨ����ȡ����ɫͼ��

*/
#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;
int main2(void) {

	Mat imad = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png",0);
	if (imad.empty()) {
		std::cerr << "no image" << std::endl;
		return 0;
	}

	const char* const WN = "imad";
	namedWindow(WN, WINDOW_FREERATIO);
	imshow(WN, imad);
	waitKey(0);

	imwrite("schedule", imad);
	return 0;

}
