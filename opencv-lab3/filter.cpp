#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;


static void help()
{
	cout
	    <<"\n------------------------------------------------------------"<<endl
	    <<"                     DigitalImageProcessing                   "<<endl
	    <<" Usage:                                                       "<<endl
	    <<"./Filter G/C PicturetNametoUse M/G/L/R/S  ratio               "<<endl
	    <<" G for grey picture.C for colorful picture                    "<<endl
	    <<" M-meanFilter G-gussianFilter L-laplasianFilter R-robert S-sobel"<<endl
	    <<" for L/R/S ratio is not nesseary                              "<<endl
	    <<" ./Filter G pictureNametoUse H moudelInt ratio                "<<endl
	    <<" H for highFilter(grey picture only)                          "<<endl
	    <<endl;
}


Mat meanFilter(Mat src,int moudelInt);
Mat gussianFilter(Mat src, int moudelInt);
Mat laplasianFilter(Mat src,int moudelInt,int laplasian[][3]);
Mat changeableFilter(Mat src,int moudelInt,int changeable_x[][3],int changeable_y[][3]);
Mat highFilter(Mat src,int moudelInt,double k);//moudelInt 均值模板的大小 k 系数




int main(int argc, char** argv)
{
	help();
	Mat src_g = imread(argv[2],0);//灰度图像
	Mat src_color = imread(argv[2],1);
	
	//灰度图像
	
		if(!strcmp(argv[1],"G")){//处理灰度图像
			namedWindow("src_grey",1);
			imshow("src_grey",src_g);
			//均值
			if(!strcmp(argv[3],"M")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			Mat src_mean = meanFilter(src_g,num);
			namedWindow("mean",1);
			imshow("mean",src_mean);
			}
			//高斯
			if(!strcmp(argv[3],"G")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			Mat src_gussian = gussianFilter(src_g,num);
			namedWindow("gussian",1);
			imshow("gussian",src_gussian);
			}
			//laplasian
			if(!strcmp(argv[3],"L")){
			int laplasian[3][3] = {0,-1,0,-1,4,-1,0,-1,0};
			Mat src_laplasian = laplasianFilter(src_g,3,laplasian);
			namedWindow("laplasian",1);
			imshow("laplasian",src_laplasian);
			}
			
			//高频增强/Filter G pictureNametoUse H moudelInt ratio  
			if(!strcmp(argv[3],"H")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			
			int moudel = 0;
			stringstream str;
			str << argv[4];
			str >> moudel;
			
			Mat src_high = highFilter(src_g,moudel,num);
			namedWindow("high",1);
			imshow("high",src_high);
			}
			//Robert
			if(!strcmp(argv[3],"R")){
			int robert_y[3][3] = {-1,0,0,1};
			int robert_x[3][3] = {0,-1,1,0};
			Mat src_robert = changeableFilter(src_g,3,robert_x,robert_y);
			namedWindow("robert",1);
			imshow("robert",src_robert);
			}
			//sobel
			if(!strcmp(argv[3],"S")){
			int sobel_x[3][3] = {1,2,1,0,0,0,-1,-2,-1};
			int sobel_y[3][3] = {1,0,-1,2,0,-2,1,0,1};
			Mat src_sobel = changeableFilter(src_g,3,sobel_x,sobel_y);
			namedWindow("sobel",1);
			imshow("sobel",src_sobel);
			}
			
			}
			
		if(!strcmp(argv[1],"C")){//处理彩色图像
			namedWindow("src_color",1);
			imshow("src_color",src_color);
			Mat imageBlue,imageGreen, imageRed;
			Mat mergeImage;
			vector<Mat> split_mat;
			split(src_color,split_mat);
			imageBlue = split_mat.at(0);
			imageGreen = split_mat.at(1);
			imageRed = split_mat.at(2);
				
			//均值
			if(!strcmp(argv[3],"M")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			split_mat.at(0) = meanFilter(imageBlue,num);
			split_mat.at(1) = meanFilter(imageGreen,num);
			split_mat.at(2) = meanFilter(imageRed,num);	
			merge(split_mat,mergeImage);
			namedWindow("mean",1);
			imshow("mean",mergeImage);
			}
				
			//高斯
			if(!strcmp(argv[3],"G")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			split_mat.at(0) = gussianFilter(imageBlue,num);
			split_mat.at(1) = gussianFilter(imageGreen,num);
			split_mat.at(2) = gussianFilter(imageRed,num);	
			merge(split_mat,mergeImage);
			namedWindow("gussian",1);
			imshow("gussian",mergeImage);
			}
				
			//laplasian
			if(!strcmp(argv[3],"L")){
			int laplasian[3][3] = {0,-1,0,-1,4,-1,0,-1,0};		
			split_mat.at(0) = laplasianFilter(imageBlue,3,laplasian);
			split_mat.at(1) = laplasianFilter(imageGreen,3,laplasian);	
			split_mat.at(2) = laplasianFilter(imageRed,3,laplasian);
			merge(split_mat,mergeImage);
			namedWindow("laplasian",1);
			imshow("laplasian",mergeImage);
			}
			//Robert
			if(!strcmp(argv[3],"R")){
			int robert_y[3][3] = {0,0,0,0,-1,0,0,0,1};
			int robert_x[3][3] = {0,0,0,0,0,-1,0,1,0};
			split_mat.at(0) = changeableFilter(imageBlue,3,robert_x,robert_y);
			split_mat.at(1) = changeableFilter(imageGreen,3,robert_x,robert_y);
			split_mat.at(2) = changeableFilter(imageRed,3,robert_x,robert_y);
			merge(split_mat,mergeImage);
			namedWindow("robert",1);
			imshow("robert",mergeImage);
			}
			//sobel
			if(!strcmp(argv[3],"S")){
			int sobel_x[3][3] = {1,2,1,0,0,0,-1,-2,-1};
			int sobel_y[3][3] = {1,0,-1,2,0,-2,1,0,1};
			split_mat.at(0) = changeableFilter(imageBlue,3,sobel_x,sobel_y);
			split_mat.at(1) = changeableFilter(imageGreen,3,sobel_x,sobel_y);
			split_mat.at(2) = changeableFilter(imageRed,3,sobel_x,sobel_y);
			merge(split_mat,mergeImage);
			namedWindow("sobel",1);
			imshow("sobel",mergeImage);
			}
			
		}		
	
	waitKey(0);
	return 0;			
}


/************************************************A P I***********************************************************/
//Mat扩张，避免模板在矩阵[0,0]以及类似边缘位置时无法操作
Mat expandsrc(Mat src,int moudelInt)
{
	Mat src_clone = src.clone();
	int controller = moudelInt/2;
	if(!src_clone.data)
	{
	cout<<"读取图像失败！"<<endl;
	//return 失败信息并阻止继续执行
	}
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	int expand = 2 * controller;
	//扩张这个Mat 避免对边缘进行操作
	//在src_clone外部套上几行几列
	int r = nRows+expand;
	int c = nCols+expand;
	Mat src_expand = Mat::zeros(r,c,CV_8UC1);//初始化扩张Mat初始值0
	int x,y=0;
	for(x=0;x<nRows;++x)	
	{
		for(y=0;y<nCols;++y)
		{
			src_expand.at<uchar>(x+controller,y+controller) = src_clone.at<uchar>(x,y);
		}
	}
	//把外层嵌套的0全部改为和边框相同的值
	//todo......
	
	return src_expand;
	
}


//处理单通道图像的均值平滑滤波
//src 源图像 moudelInt模板大小 为奇数
Mat meanFilter(Mat src,int moudelInt)
{
	Mat src_clone = src.clone();
	int controller = moudelInt/2;
	if(!src_clone.data)
	{
	cout<<"读取图像失败！"<<endl;
	//return 失败信息并阻止继续执行
	}
	
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	//int expand = 2 * controller;
	
	Mat src_expand = expandsrc(src_clone,moudelInt);
	
	//对src_expand进行计算，把计算结果写入src_clone
	int i,j=0;
	int inneri,innerj=0;
	for(i=controller;i<nRows+controller;++i)	
	{
		for(j=controller;j<nCols+controller;++j)
		{
			//计算内部小矩阵
			int sum = 0;
			for(inneri = i-controller;inneri<=i+controller;++inneri)
			{
				for(innerj = j-controller;innerj<=j+controller;++innerj)
				{
					sum += src_expand.at<uchar>(inneri,innerj);
				}
			}
			src_clone.at<uchar>(i-controller,j-controller) = sum/(moudelInt*moudelInt);
			sum = 0;
		}
	}
	return src_clone;
	
}

//单通道高斯滤波模板
Mat gussianFilter(Mat src, int moudelInt)
{	
	//model存储高斯模板的权值
	double model[moudelInt][moudelInt] = {0};
	int controller = moudelInt/2;
	int i,j=0;
	for(i=0;i<moudelInt;++i)
	{
		for(j=0;j<moudelInt;++j)
		{	
			int squra_sum = (i-controller)*(i-controller)+(j-controller)*(j-controller);//x^2+y^2
			double ratio = double(squra_sum)/1.5;
			model[i][j] = exp(-ratio);
		}
	}
	//归一化处理
	int x,y=0;
	double model_sum = 0;
	for(x=0;x<moudelInt;++x)
	{
		for(y=0;y<moudelInt;++y)
		{	
			model_sum += model[x][y];
			
		}
	}
	
	int p,q=0;

	for(p=0;p<moudelInt;++p)
	{
		for(q=0;q<moudelInt;++q)
		{	
			model[p][q] = model[p][q]/model_sum;
			
		}
	}
	
	
	//处理Mat
	
	Mat src_clone = src.clone();
	
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	//int expand = 2 * controller;
	//扩张这个Mat 避免对边缘进行操作
	//在src_clone外部套上几行几列
	Mat src_expand = expandsrc(src_clone,moudelInt);
	
	//对src_expand进行计算，把计算结果写入src_clone
	int i1,j1=0;
	int inneri1,innerj1=0;
	for(i1=controller;i1<nRows+controller;++i1)	
	{
		for(j1=controller;j1<nCols+controller;++j1)
		{
			//计算内部小矩阵
			double average = 0;
			for(inneri1 = i1-controller;inneri1<=i1+controller;++inneri1)
			{
				for(innerj1 = j1-controller;innerj1<=j1+controller;++innerj1)
				{
					average += (double)src_expand.at<uchar>(inneri1,innerj1)*model[inneri1%moudelInt][innerj1%moudelInt];
				}
			}
			src_clone.at<uchar>(i1-controller,j1-controller) = (int)average;
			average = 0;
		}
	}
	return src_clone;
	
}

//单通道的Laplacian锐化 
Mat laplasianFilter(Mat src,int moudelInt,int laplasian[][3])
{
	//定义一个laplacian模板
	//int laplacian[3][3] = {0,-1,0,-1,4,-1,0,-1,0};
	Mat src_clone = src.clone();
	int controller = moudelInt/2;
	
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	//int expand = 2 * controller;
	
	Mat src_expand = expandsrc(src_clone,moudelInt);
	
	//对src_expand进行计算，把计算结果写入src_clone
	int i,j=0;
	int inneri,innerj=0;
	for(i=controller;i<nRows+controller;++i)	
	{
		for(j=controller;j<nCols+controller;++j)
		{
			//计算内部小矩阵
			int sum = 0;
			for(inneri = i-controller;inneri<=i+controller;++inneri)
			{
				for(innerj = j-controller;innerj<=j+controller;++innerj)
				{
					sum += src_expand.at<uchar>(inneri,innerj)*laplasian[inneri%3][innerj%3];
				}
			}
			src_clone.at<uchar>(i-controller,j-controller) += sum;
			sum = 0;
		}
	}
	return src_clone;
	
}


//单通道的Sobel锐化 
Mat changeableFilter(Mat src,int moudelInt,int changeable_x[][3],int changeable_y[][3])
{
	
	//int laplacian[3][3] = {0,-1,0,-1,4,-1,0,-1,0};
	Mat src_clone = src.clone();
	int controller = moudelInt/2;
	
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	//int expand = 2 * controller;
	
	Mat src_expand = expandsrc(src_clone,moudelInt);
	
	//对src_expand进行计算，把计算结果写入src_clone
	int i,j=0;
	int inneri,innerj=0;
	for(i=controller;i<nRows+controller;++i)	
	{
		for(j=controller;j<nCols+controller;++j)
		{
			//计算内部小矩阵
			int sum1 = 0;
			int sum2 = 0;
			for(inneri = i-controller;inneri<=i+controller;++inneri)
			{
				for(innerj = j-controller;innerj<=j+controller;++innerj)
				{
					sum1 += src_expand.at<uchar>(inneri,innerj)*changeable_x[inneri%moudelInt][innerj%moudelInt];
					sum2 += src_expand.at<uchar>(inneri,innerj)*changeable_y[inneri%moudelInt][innerj%moudelInt];
				}
			}
			src_clone.at<uchar>(i-controller,j-controller) = abs(sum1)+abs(sum2);
			sum1 = 0;
			sum2 = 0;
		}
	}
	return src_clone;
	
}


//高频提升滤波
//平滑图像使用均值平滑 
//k是权重系数 =1 非锐化掩蔽 >1 高提升 <1不强调非锐化模板的贡献
Mat highFilter(Mat src,int moudelInt,double k)
{
	Mat src_clone = src.clone();
	int controller = moudelInt/2;
	if(!src_clone.data)
	{
	cout<<"读取图像失败！"<<endl;
	//return 失败信息并阻止继续执行
	}
	
	int nRows = src_clone.rows;
	int nCols = src_clone.cols;
	//int expand = 2 * controller;
	
	Mat src_expand = expandsrc(src_clone,moudelInt);
	Mat src_mean = meanFilter(src_clone,moudelInt);
	
	
	//对src_expand进行计算，把计算结果写入src_clone
	int i,j=0;
	int inneri,innerj=0;
	int mask = 0;
	for(i=controller;i<nRows+controller;++i)	
	{
		for(j=controller;j<nCols+controller;++j)
		{
			
			mask = src.at<uchar>(i,j) - src_mean.at<uchar>(i,j); 
			src_clone.at<uchar>(i-controller,j-controller) = src.at<uchar>(i,j) + k*mask;
			
		}
	}
	return src_clone;
	
}


