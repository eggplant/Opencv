/*resize 函数

#include<opencv2/imgproc.hpp>

void cv::resize (
	InputArray      src,    输入图像
	OutputArray     dst,    输出图像，其数据类型应与src相同
	Size            dsize,    输出图像的尺寸。若为0，则以fx和fy计算出来的长宽比为准。
	double          fx = 0,    缩放比例因子。若比例与dsize不一致，以dsize为准
	double          fy = 0,    
	int             interpolation = INTER_LINEAR(放大) INTER_AREA(缩小) 插值算法

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