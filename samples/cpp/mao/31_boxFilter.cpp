#include <stdio.h>
//:read /home/peter/mao/31_boxFilter.cpp

//--------------------------------------【程序說明】-------------------------------------------
//		程序說明：《OpenCV3程式設計入門》OpenCV2版書本配套範例程序31
//		程序描述：方框濾波boxFilter函數的使用範例程序
//		開發測試所用操作系統： Windows 7 64bit
//		開發測試所用IDE版本：Visual Studio 2010
//		開發測試所用OpenCV版本：	2.4.9
//		2014年06月 Created by @淺墨_毛星云
//		2014年11月 Revised by @淺墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【頭文件、命名空間包含部分】-------------------------------
//		描述：包含程序所使用的頭文件和命名空間
//------------------------------------------------------------------------------------------------
#include "opencv2/core/core.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
using namespace cv; 

//-----------------------------------【main( )函數】--------------------------------------------
//	描述：控制臺應用程序的入口函數，我們的程序從這里開始
//-----------------------------------------------------------------------------------------------
int main( )
{ 
	// 載入原圖
	Mat image=imread("/home/peter/1.jpg"); 

	//建立視窗
	namedWindow( "方框濾波【原圖】" ); 
	namedWindow( "方框濾波【效果圖】"); 

	//顯示原圖
	imshow( "方框濾波【原圖】", image ); 

	//進行方框濾波操作
	Mat out; 
	boxFilter( image, out, -1,Size(5, 5)); 

	//顯示效果圖
	imshow( "方框濾波【效果圖】" ,out ); 

	waitKey( 0 );     
} 
