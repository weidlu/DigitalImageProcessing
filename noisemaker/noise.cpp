#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

#define TWO_PI 6.2831853071795864769252866

//盐噪声 n为噪声数
void salt(Mat src, int n); 
//椒盐噪声
void peppersalt(Mat src, int n);
//胡椒噪声
void pepper(Mat src, int n);
//高斯噪声
void AddGaussianNoise(Mat I, double ratio); 

static void help()
{
	cout
	    <<"\n------------------------------------------------------------"<<endl
	    <<"                     DigitalImageProcessing                   "<<endl
	    <<" Usage:                                                       "<<endl
	    <<"./Noise G/C PicturetNametoUse salt/pepper/peppersalt/gussianNoise"<<endl
	    <<" G for grey picture.C for colorful picture                    "<<endl
	    <<"                                                              "<<endl
	    <<endl;
}




int main(int argc, char** argv)
{
	help();
	Mat src_g = imread(argv[2],0);//灰度图像
	Mat src_color = imread(argv[2],1);
	//可以重写判断条件的逻辑，但是不想写了 就这么用吧
		if(!strcmp(argv[1],"G")){//处理灰度图像
			namedWindow("src_grey",1);
			imshow("src_grey",src_g);
			//salt
			if(!strcmp(argv[3],"salt")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			salt(src_g,num);
			namedWindow("src_g",1);
			imshow("src_g",src_g);
			imwrite("saltnoise.jpg",src_g);
			}
			//pepper
			if(!strcmp(argv[3],"pepper")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			pepper(src_g,num);
			namedWindow("pepper",1);
			imshow("pepper",src_g);
			imwrite("peppernois.jpg",src_g);
			}
			//pepper-salt
			if(!strcmp(argv[3],"peppersalt")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			peppersalt(src_g,num);
			namedWindow("peppersalt",1);
			imshow("peppersalt",src_g);
			imwrite("peppersalt.jpg",src_g);
			}
			
			//gaussian noise
			if(!strcmp(argv[3],"gaussianNoise")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			AddGaussianNoise(src_g,num);
			namedWindow("gussian-noise",1);
			imshow("gussian-noise",src_g);
			imwrite("gussianNoise.jpg",src_g);
			}
		}


		if(!strcmp(argv[1],"C")){
			namedWindow("src_color",1);
			imshow("src_color",src_color);
			//salt
			if(!strcmp(argv[3],"salt")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			salt(src_color,num);
			namedWindow("salt",1);
			imshow("salt",src_color);
			imwrite("saltnoisecolor.jpg",src_color);
			}
			//pepper
			if(!strcmp(argv[3],"pepper")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			pepper(src_color,num);
			namedWindow("pepper",1);
			imshow("pepper",src_color);
			imwrite("peppernoiscolor.jpg",src_color);
			}
			//pepper-salt
			if(!strcmp(argv[3],"peppersalt")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			peppersalt(src_color,num);
			namedWindow("peppersalt",1);
			imshow("peppersalt",src_color);
			imwrite("peppersaltcolor.jpg",src_color);
			}
			//gaussian noise
			if(!strcmp(argv[3],"gaussianNoise")){
			int num = 0;
			stringstream s;
			s << argv[4];
			s >> num;
			AddGaussianNoise(src_color,num);
			namedWindow("gussian-noise",1);
			imshow("gussian-noise",src_color);
			imwrite("gussianNoiseC.jpg",src_color);
			}
		}
	
	

	waitKey(0);
	return 0;			
}
/***************************************************A*P*I*********************************************************/
//saltnoise
//n 为噪声数
void salt(Mat src, int n)
{
	if(!src.data){cout<<"读图失败！"<<endl;}
	int i = 0;
	int ncols = src.cols;
	int nrows = src.rows;
	for(i=0;i<n;++i)
	{
		int x = rand()%ncols;
		int y = rand()%nrows;
		if(src.channels()==1)
		{
			src.at<uchar>(y,x) = 255;
		}
		if(src.channels()==3)
		{
			src.at<Vec3d>(y,x)[0] = 255;
			src.at<Vec3d>(y,x)[1] = 255;
			src.at<Vec3d>(y,x)[2] = 255;
		}
	}
}
//椒盐噪声
void peppersalt(Mat src, int n)
{
	int i = 0;
	for(i=0;i<n/2;++i)
	{
		int x = rand()%src.cols;
		int y = rand()%src.rows;
		if(src.channels()==1)
		{
			src.at<uchar>(y,x) = 0;
		}
		if(src.channels()==3)
		{
			src.at<Vec3d>(y,x)[0] = 0;
			src.at<Vec3d>(y,x)[1] = 0;
			src.at<Vec3d>(y,x)[2] = 0;
		}
	}
	
	int j = 0;
	for(j=0;j<n/2;++j)
	{
		int x = rand()%src.cols;
		int y = rand()%src.rows;
		if(src.channels()==1)
		{
			src.at<uchar>(y,x) = 255;
		}
		if(src.channels()==3)
		{
			src.at<Vec3d>(y,x)[0] = 255;
			src.at<Vec3d>(y,x)[1] = 255;
			src.at<Vec3d>(y,x)[2] = 255;
		}
	}
}

//胡椒噪声
void pepper(Mat src, int n)
{
	int i = 0;
	for(i=0;i<n;++i)
	{
		int x = rand()%src.cols;
		int y = rand()%src.rows;
		if(src.channels()==1)
		{
			src.at<uchar>(y,x) = 0;
		}
		if(src.channels()==3)
		{
			src.at<Vec3d>(y,x)[0] = 0;
			src.at<Vec3d>(y,x)[1] = 0;
			src.at<Vec3d>(y,x)[2] = 0;
		}
	}
}
//根据Box-Muller变换 高斯分布
double generateGaussian()
{
	static bool hasSpare = false;  
    	static double rand1, rand2;  
   	//交替产生
    	if(hasSpare)  
    	{  
     	   hasSpare = false;  
      	  return sqrt(rand1) * sin(rand2);  
   	}  
   
    	hasSpare = true;  
   
   	rand1 = rand() / ((double) RAND_MAX);  
   	if(rand1 < 1e-100) rand1 = 1e-100;  
        rand1 = -2 * log(rand1);  
   	rand2 = (rand() / ((double) RAND_MAX)) * TWO_PI;  
   	return sqrt(rand1) * cos(rand2);  
}
//ratio 系数控制噪声污染程度
void AddGaussianNoise(Mat src,double ratio)  
{  
	  
	CV_Assert(src.depth() != sizeof(uchar));
	int channels = src.channels();  
        int nRows = src.rows;  
        int nCols = src.cols * channels;
	int i = 0;
	int j = 0;
	for(i=0;i<nRows;++i)
	{
	//cout<<"i"<<i<<endl;
		for(j=0;j<nCols;++j)
		{
		if(channels==1){
		//cout<<"j"<<j<<endl;
			double val = src.at<uchar>(i,j) + generateGaussian() * ratio;
			if(val < 0)  
                	val = 0;  
            		if(val > 255)  
               		val = 255;  
               		//cout<<"val"<<val<<endl;
            		src.at<uchar>(i,j) = (uchar)val; 
            		//int temp = src.at<uchar>(i,j);
			//cout<<"val"<<temp<<endl;
		}
		if(channels==3)
		{
			double change = generateGaussian() * ratio;
			//B
			double val1 = src.at<Vec3b>(i,j)[0] + change;
			if(val1 < 0)  
                	val1 = 0;  
            		if(val1 > 255)  
               		val1 = 255;  
            		src.at<Vec3b>(i,j)[0] = (uchar)val1; 
            	
            		//G
            		double val2 = src.at<Vec3b>(i,j)[1] + change;
			if(val2 < 0)  
                	val2 = 0;  
            		if(val2 > 255)  
               		val2 = 255;  
            		src.at<Vec3b>(i,j)[1] = (uchar)val2; 
            		//R
            		double val3 = src.at<Vec3b>(i,j)[2] + change;
			if(val3 < 0)  
                	val3 = 0;  
            		if(val3 > 255)  
               		val3 = 255;  
            		src.at<Vec3b>(i,j)[2] = (uchar)val3; 
            		
		}
	        }
        }
		
}


