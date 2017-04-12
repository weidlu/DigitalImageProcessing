### 图像去噪

##### 图像去噪的算法
* 算数均值滤波：计算模板内的和并取均值。
sum += src_expand.at<uchar>(inneri,innerj);
src_clone.at<uchar>(i,j) = sum/(moudelInt*moudelInt);
* 几何均值滤波：计算模板内的和并取几何均值。方法类似，只要修改下计算公式就行了。需要注意的是开方的时候数据精度不要丢失。
* 谐波均值滤波器：对于盐粒噪声效果较好，但不适用于胡椒噪声。善于处理像高斯噪声那样的其他噪声。
* 逆谐波均值滤波器：适合消除椒盐噪声，但是一次只能消除一种噪声。逆谐波均值可以通过修改Q的数值来达到选择消除何种噪声的效果。其实实现了逆谐波均值滤波器就是实现了上述的算数均值和谐波均值滤波器。
sum1 += pow(src_expand.at<uchar>(inneri,innerj),Q);
sum2 += pow(src_expand.at<uchar>(inneri,innerj),Q+1);
src_clone.at<uchar>(i-controller,j-controller) = sum2/sum1; 
* 中值滤波：在模板内找到这组数列的中值，从而达到平滑/去噪效果。
src_clone.at<uchar>(i,j) = getMedian(moudelInt, array);
* 自适应中值滤波：这个是这次实验中相对难一些的一个算法，主要是算法逻辑的设计。

```
            A: A1=med-min
               A2=med-max
               if(A1>0A2<0) 转到B 否则增大窗口尺寸
               if窗口尺寸小于等于最大值 重复A 否则输出med
            B: B1=current-min
               B2=current-max
               if(B1>0B2<0)输出current
               else输出med
            
```

* 自适应均值滤波：是一种针对性较强的滤波器，在滤波时需要知道全局噪声的方差。在知道了全局噪声的方差的情况下，滤波结果要稍好于均值滤波。
* 彩色图像均值滤波将三通道分割为单通道，操做一样。

###### 补充：噪声生成器 (noisemaker)
>void salt(Mat src, int n);  
void peppersalt(Mat src, int n); 
void pepper(Mat src, int n);
void AddGaussianNoise(Mat I, double ratio);
