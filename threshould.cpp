/*��ֵ��
* cv::threshold()
* opencv2/imgproc.hpp
* 
 ����ֵ�����������ص㣬���������ֵ�����ھ���Сֵ��

double cv::threshold (    
	InputArray      src,    
	OutputArray     dst,    
	double          thresh,    ��ֵ
	double          maxval,    ���ֵ��ֻ��cv::THRESH_BINARY��cv::threSH_BINARY_INV���ֶ�ֵ��������ʹ��
	int             type  ��ֵ��������־����cv::THRESH_BINARY��cv::THRESH_BINARY_INV
);

cv::THRESH_BINARY ����ֵ�����������ص㣬���������ֵ�����ھ���Сֵ��
cv::THRESH_BINARY_INV �෴

����ֵ�Ƚ� https://security.feishu.cn/link/safety?target=https%3A%2F%2Fdocs.opencv.org%2F4.5.4%2Fd2%2Fde8%2Fgroup__core__array.html%23gab55b8d062b7f5587720ede032d34156f&scene=ccm&logParams=%7B%22location%22%3A%22ccm_drive%22%7D&lang=zh-CN
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
