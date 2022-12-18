/*resize ����

#include<opencv2/imgproc.hpp>

void cv::resize (
	InputArray      src,    ����ͼ��
	OutputArray     dst,    ���ͼ������������Ӧ��src��ͬ
	Size            dsize,    ���ͼ��ĳߴ硣��Ϊ0������fx��fy��������ĳ����Ϊ׼��
	double          fx = 0,    ���ű������ӡ���������dsize��һ�£���dsizeΪ׼
	double          fy = 0,    
	int             interpolation = INTER_LINEAR(�Ŵ�) INTER_AREA(��С) ��ֵ�㷨

	*/

#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;
int main4(void) {

	Mat normalImage = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png", 0);
	if (normalImage.empty()) {
		std::cerr << "no image" << std::endl;
		return 0;
	}

	Mat smallImage, bigImage;

	resize(normalImage, smallImage, Size(), 0.5, 0.5);
	resize(normalImage, bigImage, Size(), 2, 2);
	
	imshow("Normal Image", normalImage);
	imshow("Small Image", smallImage);    
	imshow("Big Image", bigImage); 

	waitKey(0);    
	
	return 0;


}