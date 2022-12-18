/*RGB GRAY ת��
* 
* RGB ��ͨ�� ����ͨ�� alpha��ʾ͸����
	��8λ���޷���ͼ������ȡֵ��ΧΪ0-255��������ͼ��ȡֵ��ΧΪ0-1
* 
* GRAY ��ͨ�� Y = 0.299R + 0.587G + 0.114B

*/

#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main5(void) {
	Mat Rgb = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png",1);
	if (Rgb.empty()) {
		cout << "no image" << endl;
		return 0;
	}

	Mat Gray;
	cvtColor(Rgb, Gray, COLOR_BGR2GRAY);

	imshow("RGB", Rgb);
	imshow("Gray", Gray);
	
	waitKey(0);

	return 0;
}

// ��ɫת����� https://security.feishu.cn/link/safety?target=https%3A%2F%2Fdocs.opencv.org%2F4.5.4%2Fd8%2Fd01%2Fgroup__imgproc__color__conversions.html%23ga4e0972be5de079fed4e3a10e24ef5ef0&scene=ccm&logParams=%7B%22location%22%3A%22ccm_drive%22%7D&lang=zh-CN