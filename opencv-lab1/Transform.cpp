#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

static void help()
{
    cout
        << "\n--------------------------------------------------------------------------" << endl
        << "高级图像处理实验一                                                          " << endl
        << "Usage:"                                                                       << endl
        << "./TransForm ImageNameToUse ratio []            "                              << endl
        << "[B]二值化   [L]对数变换ratio*log(1+src)   [G]伽马变换 src^ratio    "            << endl
        << "./TransForm ImageNameToUse C             "                                   << endl
        << "彩色图像的补值变换                         "                                   << endl
        << "--------------------------------------------------------------------------"   << endl
        << endl;
}

Mat& BinaryImage(Mat& I,int dividNum);
Mat& LogImage(Mat& I,int c);
Mat& GammaImage(Mat& I,int gamma);
Mat& ComplementaryImage(Mat& I);


int main( int argc, char* argv[])
{
    help();

    Mat I, J, C;
    namedWindow("original",1);
    namedWindow("changed",1);
    C = imread(argv[1],CV_LOAD_IMAGE_COLOR);
    I = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    
    if (!I.data)
    {
        cout << "The image" << argv[1] << " could not be loaded." << endl;
        return -1;
    }

    

     cv::Mat clone_i = I.clone();
     cv::Mat clone_c = C.clone();
     
     if(argc == 4&&!strcmp(argv[3],"B")){
     	int num = 0;
     	stringstream s;
    	s << argv[2];
     	s >> num;
     	J = BinaryImage(clone_i,num);
     }
     
     if(argc == 4&&!strcmp(argv[3],"L")){
     	int ratio = 0; 	
     	stringstream c;
     	c << argv[2];
     	c >> ratio;
     	J = LogImage(clone_i,ratio);
     }

    if(argc == 4&&!strcmp(argv[3],"G")){
     	int gamma = 0; 	
     	stringstream c;
     	c << argv[2];
     	c >> gamma;
     	J = GammaImage(clone_i,gamma);
     }
     
    if(argc == 3&&!strcmp(argv[2],"C")){
    	J = ComplementaryImage(clone_c);
    }
//显示原图和变换后的图片
    imshow("original",C);
    imshow("changed",J);
    waitKey(0);
    return 0;
}
//灰度图像的二值化
Mat& BinaryImage(Mat& I,int divideNum)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);//CV_Assert表示一个比较 flase返回出错信息。depth每一个像素的位数(bits) 0(CV_8U),1(CV_8S)表示8位;2(CV_16U),3(CV_16S)表示16位;以此类推。

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;//列数*通道数
    //可以看作是在一维化处理，但是物理上的存储其实没有改变
    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int j;
    uchar* p;
    p = I.ptr<uchar>(0);//得到头指针
    for ( j = 0; j < nCols; ++j)
        {
        	if(p[j]>divideNum){
            p[j] = 255;
            }else{
            p[j] = 0;
            }
        }
    
    return I;
}
//灰度图像对数变换
Mat& LogImage(Mat& I,int ratio)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;//列数*通道数

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int j;
    uchar* p;
    p = I.ptr<uchar>(0);//得到头指针
    for ( j = 0; j < nCols; ++j)
        {
            p[j] = ratio * log((double)(p[j]+1));
            
        }
 normalize(I, I, 0, 255, NORM_MINMAX, -1);
    
    return I;
}
//gamma变换
Mat& GammaImage(Mat& I,int gamma)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;//列数*通道数

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int j;
    uchar* p;
    p = I.ptr<uchar>(0);//得到头指针
    for ( j = 0; j < nCols; ++j)
        {
            p[j] = (double)pow((double)p[j],(double)gamma);  
        }
    normalize(I, I, 0, 255, NORM_MINMAX, -1);
    return I;
}
//彩色图像的补色变换
Mat& ComplementaryImage(Mat& C)
{
    // accept only char type matrices
    CV_Assert(C.depth() == CV_8U);

    int channels = C.channels();

    int nRows = C.rows;
    int nCols = C.cols * channels;//列数*通道数

    if (C.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }
    int j;
    uchar* p;
    p = C.ptr<uchar>(0);//得到头指针
    for ( j = 0; j < nCols; ++j)
        {
            p[j] = 255 - p[j];
            
        }
    
    return 	C;
}




