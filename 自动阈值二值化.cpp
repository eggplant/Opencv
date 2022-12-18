/*自动阈值化
cv::THRESH_OTSC和cv::THRESH_TRIANGLE 使用大津法和三角形法结合图像灰度值的分布特性获取二值化的阈值

与原二值化标志进行或运算

*/


#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main8() {

	Mat imad = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png", 0);
	if (imad.empty()) {
		cerr << "no image" << std::endl;
		return 0;
	}

	Mat binaryImgsu, binaryInvImgsu, binaryImgtri, binaryInvImgtri;
	threshold(imad, binaryImgsu, 0, 255, THRESH_BINARY | THRESH_OTSU);
	threshold(imad, binaryInvImgsu, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
	threshold(imad, binaryImgtri, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);
	threshold(imad, binaryInvImgtri, 0, 255, THRESH_BINARY_INV | THRESH_TRIANGLE);

	imshow("ORIGINAL", imad);
	imshow("THRESH_BINARYSU", binaryImgsu);
	imshow("THRESH_BINARY_INVSU", binaryInvImgsu);
	imshow("THRESH_BINARYTRI", binaryImgtri);
	imshow("THRESH_BINARY_INVTRI", binaryInvImgtri);

	waitKey(0);
	return 0;

}