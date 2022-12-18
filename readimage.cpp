/*imread函数

1. 读取路径方式：
	//-- 1 --双右斜线法
	//string imgpath = "C:\\Users\\bingbuyu\\Pictures\\photo\\miao1.jpg";
	//-- 2 --双左斜线法
	//string imgpath = "C://Users//bingbuyu//Pictures//photo//miao1.jpg";
	//-- 3 --单左斜线法
	//string imgpath = "C:/Users/bingbuyu/Pictures/photo/miao1.jpg";
	//-- 4 --以上三种混合法
	//string imgpath = "C:/Users//bingbuyu\\Pictures//photo//miao1.jpg";
	//-- 5 --相对路径法
	//string imgpath = "miao.jpg";
	//-- 6 --命令行参数法
	string imgpath = argv[1];
2. 第二个参数 flag：
	- 1：按照解码方式读取
	0：按照单通道读取，也就是灰白图像
	1：三通道读取，彩色图像

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
