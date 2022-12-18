/*
void cv::GaussianBlur (    
	InputArray  src,    
	OutputArray dst,   
	Size        ksize,    高斯滤波器的尺寸，可以不为正方形，但边长必须为正奇数。若尺寸位0，则由标准偏差计算尺寸
	double      sigmaX,    x、y轴方向的标准差，若后者位0，则置为与前者相同；若均为0，则由滤波器尺寸计算
	double      sigmaY = 0,    
	int         borderType = BORDER_DEFAULT  像素外推法选择标志，默认的cv::BORDER_DEFAULT表示不含边界值倒序填充，其余标志参见 cv::BorderTypes
);

高斯滤波对高斯噪声去除效果较高，但会造成图像模糊，且滤波器尺寸越大，滤波后图像变得越模糊。

轮廓检测 cv::findContours

void cv::findContours (    
	InputArray          image,    
	OutputArrayOfArrays contours,  输出的轮廓，每个轮廓存放着像素的坐标  
	int                 mode,   检测轮廓的模式，可以为cv::RETR_EXTERNAL, cv::RETR_LIST, cv::RETR_CCOMP, cv::RETR_TREE，具体含义参见cv::RetrievalModes 
	int                 method,  轮廓逼近方法标志，可以为cv::CHAIN_APPROX_NONE,cv::CHAIN_APPROX_SIMPLE,cv::CHAIN_APPROX_TC89_L1,cv::CHAIN_APPROX_TC89_KOS，具体含义参见cv::ContourApproximationModes  
	Point               offset = Point()每个轮廓点移动的可选偏移量。这个参数主要用在从ROI图像中找出轮廓并基于整个图像分析轮廓的场景中
);

cv::drawContours

void cv::drawContours (    
	InputOutputArray    image,    待绘制轮廓的目标图像
	InputArrayOfArrays  contours,    将要绘制的所有轮廓
	int                 contourIdx,    绘制轮廓的输入，若为负数，则绘制所有的轮廓
	const Scalar &      color,    绘制轮廓的颜色
	int                 thickness = 1,    绘制轮廓线条的粗细，若为负数，则绘制轮廓的内部
	int                 lineType = LINE_8,   边界线的连接类型，可以为四连通线型cv::LINE_4，8联通线型cv::LINE_8，抗锯齿线型cv::LINE_AA
	InputArray          hierarchy = noArray(),    可选的轮廓结构关系信息
	int                 maxLevel = INT_MAX,    绘制轮廓的最大等级
	Point               offset = Point() 可选的轮廓偏移参数，按指定的移动距离绘制所有的轮廓
)；

如果您需要获取轮廓之间的层级关系，cv::drawContours函数还有一个重载，能够帮助我们获取轮廓间的层级关系，有兴趣的朋友可以参见cv::drawContours。
*/

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>#include <vector>
using namespace cv;using namespace std;
int main(void){    
	Mat image = imread("C:\\Users\\Lenovo\\Desktop\\C0636E072DED5DA64B7C395292AA567F.png");    
	if (image.empty())    {        
		std::cerr << "Check if the image exists!" << std::endl;       
		return 0;    
	}    
	Mat grayImage, binaryImage;    
	cvtColor(image, grayImage, COLOR_BGR2GRAY);    
	GaussianBlur(grayImage, grayImage, Size(5, 5), 2, 2);    
	threshold(grayImage, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);   
	vector< vector<Point> > contours;    
	vector<Vec4i> hierarchy;    
	findContours(binaryImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());    
	
	for (int i = 0; i < contours.size(); ++i)        
		drawContours(image, contours, i, Scalar(0, 0, 255), 2, LINE_AA);    
	
	imshow("Result", image);   
	waitKey(0);    
	return 0;
}