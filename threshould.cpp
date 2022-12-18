/*二值化
* cv::threshold()
* opencv2/imgproc.hpp
* 
 拿阈值遍历所有像素点，超过就最大值，低于就最小值。

double cv::threshold (    
	InputArray      src,    
	OutputArray     dst,    
	double          thresh,    阈值
	double          maxval,    最大值，只在cv::THRESH_BINARY和cv::threSH_BINARY_INV两种二值化方法中使用
	int             type  二值化方法标志，如cv::THRESH_BINARY和cv::THRESH_BINARY_INV
);

cv::THRESH_BINARY 拿阈值遍历所有像素点，超过就最大值，低于就最小值。
cv::THRESH_BINARY_INV 相反

多阈值比较 https://security.feishu.cn/link/safety?target=https%3A%2F%2Fdocs.opencv.org%2F4.5.4%2Fd2%2Fde8%2Fgroup__core__array.html%23gab55b8d062b7f5587720ede032d34156f&scene=ccm&logParams=%7B%22location%22%3A%22ccm_drive%22%7D&lang=zh-CN
*/


#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main6() {

	Mat imad = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png");
	if (imad.empty()) {
		cerr << "no image" << std::endl;
		return 0;
	}

	Mat binaryImg, binaryInvImg;    
	threshold(imad, binaryImg, 128, 255, THRESH_BINARY);    
	threshold(imad, binaryInvImg, 128, 255, THRESH_BINARY_INV);

	imshow("ORIGINAL", imad);    
	imshow("THRESH_BINARY", binaryImg);    
	imshow("THRESH_BINARY_INV", binaryInvImg);

	waitKey(0);    
	return 0;

}
