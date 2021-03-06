
#include <stdio.h>


//---------------------------------【頭文件、命名空間包含部分】----------------------------
//		描述：包含程序所使用的頭文件和命名空間
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


//-----------------------------------【main( )函數】------------------------------------------
//		描述：控制臺應用程序的入口函數，我們的程序從這里開始
//-----------------------------------------------------------------------------------------------
int main( )
{
	//【1】載入原始圖、Mat變數定義   
	Mat srcImage = imread("/home/peter/opencv-2.4.11/samples/cpp/mao/1.jpg");  //專案目錄下應該有一張名為1.jpg的素材圖
	Mat midImage,dstImage;//臨時變數和目標圖的定義

	//【2】顯示原始圖
	imshow("【原始圖】", srcImage);  
	moveWindow("【原始圖】", 100,100);  

	//【3】轉為灰度圖並進行圖像平滑
	cvtColor(srcImage,midImage, CV_BGR2GRAY);//轉化邊緣檢測後的圖為灰度圖
	GaussianBlur( midImage, midImage, Size(9, 9), 2, 2 );

	//【4】進行霍夫圓變換
	vector<Vec3f> circles;
	HoughCircles( midImage, circles, CV_HOUGH_GRADIENT,1.5, 10, 200, 100, 0, 0 );

	//【5】依次在圖中繪製出圓
	for( size_t i = 0; i < circles.size(); i++ )
	{
		//參數定義
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//繪製圓心
		circle( srcImage, center, 3, Scalar(0,255,0), -1, 8, 0 );
		//繪製圓輪廓
		circle( srcImage, center, radius, Scalar(155,50,255), 3, 8, 0 );
	}

	//【6】顯示效果圖  
	imshow("【效果圖】", srcImage);  
	moveWindow("【效果圖】", 1000, 1000);  

	waitKey(0);  

	return 0;  
}


