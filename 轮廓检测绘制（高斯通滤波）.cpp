/*
void cv::GaussianBlur (    
	InputArray  src,    
	OutputArray dst,   
	Size        ksize,    ��˹�˲����ĳߴ磬���Բ�Ϊ�����Σ����߳�����Ϊ�����������ߴ�λ0�����ɱ�׼ƫ�����ߴ�
	double      sigmaX,    x��y�᷽��ı�׼�������λ0������Ϊ��ǰ����ͬ������Ϊ0�������˲����ߴ����
	double      sigmaY = 0,    
	int         borderType = BORDER_DEFAULT  �������Ʒ�ѡ���־��Ĭ�ϵ�cv::BORDER_DEFAULT��ʾ�����߽�ֵ������䣬�����־�μ� cv::BorderTypes
);

��˹�˲��Ը�˹����ȥ��Ч���ϸߣ��������ͼ��ģ�������˲����ߴ�Խ���˲���ͼ����Խģ����

������� cv::findContours

void cv::findContours (    
	InputArray          image,    
	OutputArrayOfArrays contours,  �����������ÿ��������������ص�����  
	int                 mode,   ���������ģʽ������Ϊcv::RETR_EXTERNAL, cv::RETR_LIST, cv::RETR_CCOMP, cv::RETR_TREE�����庬��μ�cv::RetrievalModes 
	int                 method,  �����ƽ�������־������Ϊcv::CHAIN_APPROX_NONE,cv::CHAIN_APPROX_SIMPLE,cv::CHAIN_APPROX_TC89_L1,cv::CHAIN_APPROX_TC89_KOS�����庬��μ�cv::ContourApproximationModes  
	Point               offset = Point()ÿ���������ƶ��Ŀ�ѡƫ���������������Ҫ���ڴ�ROIͼ�����ҳ���������������ͼ����������ĳ�����
);

cv::drawContours

void cv::drawContours (    
	InputOutputArray    image,    ������������Ŀ��ͼ��
	InputArrayOfArrays  contours,    ��Ҫ���Ƶ���������
	int                 contourIdx,    �������������룬��Ϊ��������������е�����
	const Scalar &      color,    ������������ɫ
	int                 thickness = 1,    �������������Ĵ�ϸ����Ϊ������������������ڲ�
	int                 lineType = LINE_8,   �߽��ߵ��������ͣ�����Ϊ����ͨ����cv::LINE_4��8��ͨ����cv::LINE_8�����������cv::LINE_AA
	InputArray          hierarchy = noArray(),    ��ѡ�������ṹ��ϵ��Ϣ
	int                 maxLevel = INT_MAX,    �������������ȼ�
	Point               offset = Point() ��ѡ������ƫ�Ʋ�������ָ�����ƶ�����������е�����
)��

�������Ҫ��ȡ����֮��Ĳ㼶��ϵ��cv::drawContours��������һ�����أ��ܹ��������ǻ�ȡ������Ĳ㼶��ϵ������Ȥ�����ѿ��Բμ�cv::drawContours��
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