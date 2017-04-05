#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;
using namespace std;

static void help()
{
    printf("\nThis program demonstrated the use of the discrete Fourier transform (dft)\n"
           "The dft of an image is taken and it's power spectrum is displayed.\n"
           "Usage:\n"
            "./dft [image_name -- default lena.jpg]\n");
}

const char* keys =
{
    "{1| |lena.jpg|input image file}"
};

int main(int argc, const char ** argv)
{
    help();
    CommandLineParser parser(argc, argv, keys);
    string filename = parser.get<string>("1");

    Mat img = imread(filename.c_str(), CV_LOAD_IMAGE_GRAYSCALE);
    if( img.empty() )
    {
        help();
        printf("Cannot read image file: %s\n", filename.c_str());
        return -1;
    }
//这里获取符合快速傅里叶变换（FFT）的大小，m和n都可以分解为2、3、5相乘的组合，参见 注1
    int M = getOptimalDFTSize( img.rows );// 获得最佳DFT尺寸，为2的次方  // 获得最佳DFT尺寸，为2的次方  
    int N = getOptimalDFTSize( img.cols );
    Mat padded;
//将原图像的大小变为m*n的大小，补充的位置填0 Scalar::all(0) 按照已有的通道形式填充0比如(0,0,0)
    copyMakeBorder(img, padded, 0, M - img.rows, 0, N - img.cols, BORDER_CONSTANT, Scalar::all(0));
//这里是获取了两个mat，一个用于存放dft变换的实部，一个用于存放虚部，初始的时候，实部就是图像本身，虚部全为0
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexImg;
//将几个单通道的mat融合成一个多通道的mat，这里融合的complexImg即有实部，又有虚部
    merge(planes, 2, complexImg);
//dft变换，因为complexImg本身就是两个通道的mat，所以dft变换的结果也可以保存在其中 dft的结果(对于实函数来说)就是一个复函数 所以需要一个2通道的Mat存储结果
    dft(complexImg, complexImg);
    //将complexImg重新拆分成两个mat，一个是实部，一个是虚部
    split(complexImg, planes); //其实就是分割([0][1])

    // compute log(1 + sqrt(Re(DFT(img))^2 + Im(DFT(img))^2))
    //这一部分是为了计算dft变换后的幅值，以便于显示幅值的 计算公式如上
    //傅立叶变换的幅度值范围大到不适合在屏幕上显示。高值在屏幕上显示为白点，  
    //而低值为黑点，高低值的变化无法有效分辨。为了在屏幕上凸显出高低变化的连续性，我们可以用对数尺度来替换线性尺度:  
    magnitude(planes[0], planes[1], planes[0]);//求sqrt(x^2+y^2) 求傅里叶变换各频率的幅值，幅值放在第一页中。
    mag += Scalar::all(1);
    log(mag, mag);

    // crop the spectrum, if it has an odd number of rows or columns
    //修剪频谱，如果图像的行或者列是奇数的话，那其频谱是不对称的，因此要修剪
    //这里为什么要用  &-2这个操作，我会在代码后面的 注2 说明
    mag = mag(Rect(0, 0, mag.cols & -2, mag.rows & -2));
    Mat _magI = magI.clone();
    normalize(_magI, _magI, 0, 1, CV_MINMAX);
    imshow("before rearrange ", _magI)

    int cx = mag.cols/2;
    int cy = mag.rows/2;
    // rearrange the quadrants of Fourier image
    // so that the origin is at the image center
    Mat tmp;
    Mat q0(mag, Rect(0, 0, cx, cy));    // Top-Left
    Mat q1(mag, Rect(cx, 0, cx, cy));   // Top-Right
    Mat q2(mag, Rect(0, cy, cx, cy));   // Bottom-Left
    Mat q3(mag, Rect(cx, cy, cx, cy));  // Bottom-Right

    //左上角的频域和右下角的互换，右上角和左下角互换。
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(mag, mag, 0, 1, CV_MINMAX);

    imshow("spectrum magnitude", mag);
    waitKey();
    return 0;
}