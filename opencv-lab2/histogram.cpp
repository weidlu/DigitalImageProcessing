#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


void MyLiner(Mat img,Point start,Point end, int r ,int g, int b);
int round_double(double num);
//画直方图
void drawHistogram(Mat plane,int height,double* ratio, int r ,int g, int b);
//累积函数+均衡化
void Myaccumulate(Mat src, double* ratio,int nRows,int nCols);
//获得单一通道的table
void Count(Mat src,int* table,int nRows,int nCols);
//input数组256 三通道的table,ratio数组出现概率 nCols数组长度M*N
void Ratio(int* table,double* ratio,int nCols);
//int* Equliza(int table[], double ratio[]);返回本地变量的地址是不安全的，因为如果这个地址被其他程序使用了，内存中的内容就会发生改变




int main(int argc, char** argv)
{
	Mat src, dst;
	Mat planeNor = Mat::zeros(300,400,CV_8UC1);
	Mat planeEqu = Mat::zeros(300,400,CV_8UC1);
	//load the pic
	Mat colorimg = imread(argv[1],1);
	src = imread(argv[1],0);//imread(src,flag)  falg决定了返回图像的通道数
	Mat Gsrc_clone = src.clone();
	if(!Gsrc_clone.data)
	{return -1;}
	
	int channels = Gsrc_clone.channels();
	int nRows = Gsrc_clone.rows * channels;
	int nCols = Gsrc_clone.cols;
	
	if(Gsrc_clone.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}else{
		cout<<"not continous error"<<endl;
	}

	int table[256] = {0};//使用一个数组存储各个灰度值出现的次数
	Count(Gsrc_clone,table,nRows,nCols);
	//直方图归一化
	double ratio[256] = {0.0};//存储各个灰度值出现的概率
	Ratio(table,ratio,nCols);
	drawHistogram(planeNor,300,ratio,255,255,255);
	double mapping[256] = {0};//存储映射函数

	//灰度图像直方图均衡
	Myaccumulate(Gsrc_clone, ratio, nRows, nCols);
	//绘制均衡后的直方图
	int E_table[256] = {0};
	Count(Gsrc_clone,E_table,nRows,nCols);
	double E_ratio[256] = {0.0};
	Ratio(E_table,E_ratio,nCols);
	drawHistogram(planeEqu,300,E_ratio,255,255,255);
	
	/*******************************************/


	Mat colorimg_clone = colorimg.clone();
	Mat imageBlue, imageGreen, imageRed;
	Mat mergeImage;
	vector<Mat> split_mat;
	split(colorimg_clone,split_mat);
	
	imageBlue = split_mat.at(0);
	imageGreen = split_mat.at(1);
	imageRed = split_mat.at(2);

	Mat plane_RGB = Mat::zeros(300,400,CV_8UC3);

	int B_table[256] = {0};
	Count(imageBlue,B_table,nRows,nCols);
	double B_ratio[256] = {0.0};
	Ratio(B_table,B_ratio,nCols);
	drawHistogram(plane_RGB,300,B_ratio,255,0,0);

	int G_table[256] = {0};
	Count(imageGreen,G_table,nRows,nCols);
	double G_ratio[256] = {0.0};
	Ratio(G_table,G_ratio,nCols);
	drawHistogram(plane_RGB,300,G_ratio,0,255,0);

	int R_table[256] = {0};
	Count(imageRed,R_table,nRows,nCols);
	double R_ratio[256] = {0.0};
	Ratio(R_table,R_ratio,nCols);
	drawHistogram(plane_RGB,300,R_ratio,0,0,255);


	int table_0[256] = {0};
	int table_1[256] = {0};
	int table_2[256] = {0};
	int nRows_ = imageRed.rows;
	int nCols_ = imageRed.cols;
	if(colorimg_clone.isContinuous())
	{
		nCols_ *= nRows_;
		nRows_ = 1;
	}else{
	cout<<"not continuous error!"<<endl;
	}
	
	Count(imageBlue,table_0,nRows_,nCols_);
	Count(imageGreen,table_1,nRows_,nCols_);
	Count(imageRed,table_2,nRows_,nCols_);
	double ratio_0[256] = {0.0}; 
	double ratio_1[256] = {0.0}; 
	double ratio_2[256] = {0.0}; 	
	Ratio(table_0,ratio_0,nCols);
	Ratio(table_1,ratio_1,nCols);
	Ratio(table_2,ratio_2,nCols);
	//对各个通道均衡化
	Myaccumulate(imageBlue, ratio_0, nRows_, nCols_);
	Myaccumulate(imageGreen, ratio_1, nRows_, nCols_);
	Myaccumulate(imageRed, ratio_2, nRows_, nCols_);	

	merge(split_mat,mergeImage);

	

/********************************************/

//显示结果
	
	//原图
	namedWindow("src_window",1);
	imshow("src_window",colorimg);
	//均衡化图像
	namedWindow("equliza_window",1);
	imshow("equliza_window",Gsrc_clone);
	//归一化直方图
	namedWindow("norHistogram",1);
	imshow("norHistogram",planeNor);
	//均衡化直方图
	namedWindow("equHistogram",1);
	imshow("equHistogram",planeEqu);
	//均衡化彩色图像
	namedWindow("equliza",1);
	imshow("equliza",mergeImage);

	namedWindow("RGB",1);
	imshow("RGB",plane_RGB);

	waitKey(0);
	
	return 0;
	
}

//plane画板 height 画板高度 ratio累积数组 rgb控制颜色
void drawHistogram(Mat plane,int height,double* ratio,int r,int g,int b)
{
	for(int count=0;count<256;++count)
	{
		Point start = Point (count,height);
		Point end = Point (count, height-(ratio[count] * 6000));//扩大，为了显示效果明显
		
		MyLiner(plane,start,end,r,g,b);
	}
}

//画线
void MyLiner(Mat img,Point start,Point end,int r,int g, int b)
{
	int thickness = 1;
	int lineType = 8;
	line(img, start,end,Scalar(b,g,r),thickness,lineType);
}

int round_double(double number)//四舍五入
{
	return (number > 0.0) ? floor(number + 0.5) : ceil(number - 0.5);
}
//int table_012[256] = {0};
//获得单一通道的table
void Count(Mat src,int* table,int nRows,int nCols)
{
	Mat src_clone = src.clone();
	int i,j;
	uchar* p;
	for(i=0;i<nRows;++i){
		p=src_clone.ptr<uchar>(i);
		for(j=0;j<nCols;++j){
		table[p[j]]++;
		}
	}	
}


//input数组256 三通道的table,ratio数组出现概率 nCols数组长度M*N
void Ratio(int* table,double* ratio,int nCols)
{
		for(int i=0;i<256;++i)
		{
			ratio[i] = double(table[i])/nCols;
		}
}

//src需要均衡化的图像 ratio[]是输入的各个灰度值的概率 nRows nCols
void Myaccumulate(Mat src, double* ratio,int nRows,int nCols)
{

	double mapping[256] = {0};
	for(int i=0;i<256;++i)
	{	
		for(int j=0;j<=i;++j)
		{	
			mapping[i] += ratio[j];
		}
	}
	
	int i,j;
	uchar* q;
	for(i=0;i<nRows;++i){
		q=src.ptr<uchar>(i);
		for(j=0;j<nCols;++j){
		q[j]=mapping[q[j]]*255;
		}
	}
}
