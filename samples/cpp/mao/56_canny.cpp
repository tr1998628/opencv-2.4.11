#include <stdio.h>

//--------------------------------------\u3010\u7a0b\u5e8f\u8aaa\u660e\u3011-------------------------------------------
//		\u7a0b\u5e8f\u8aaa\u660e\uff1a\u300aOpenCV3\u7a0b\u5f0f\u8a2d\u8a08\u5165\u9580\u300bOpenCV2\u7248\u66f8\u672c\u914d\u5957\u7bc4\u4f8b\u7a0b\u5e8f56
//		\u7a0b\u5e8f\u63cf\u8ff0\uff1acanny\u51fd\u6578\u7528\u6cd5\u7bc4\u4f8b
//		\u958b\u767c\u6e2c\u8a66\u6240\u7528\u64cd\u4f5c\u7cfb\u7d71\uff1a Windows 7 64bit
//		\u958b\u767c\u6e2c\u8a66\u6240\u7528IDE\u7248\u672c\uff1aVisual Studio 2010
//		\u958b\u767c\u6e2c\u8a66\u6240\u7528OpenCV\u7248\u672c\uff1a	2.4.9
//		2014\u5e7406\u6708 Created by @\u6dfa\u58a8_\u6bdb\u661f\u4e91
//		2014\u5e7411\u6708 Revised by @\u6dfa\u58a8_\u6bdb\u661f\u4e91
//------------------------------------------------------------------------------------------------



//---------------------------------\u3010\u982d\u6587\u4ef6\u3001\u547d\u540d\u7a7a\u9593\u5305\u542b\u90e8\u5206\u3011----------------------------
//		\u63cf\u8ff0\uff1a\u5305\u542b\u7a0b\u5e8f\u6240\u4f7f\u7528\u7684\u982d\u6587\u4ef6\u548c\u547d\u540d\u7a7a\u9593
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;


//-----------------------------------\u3010main( )\u51fd\u6578\u3011-------------------------------------------
//            \u63cf\u8ff0\uff1a\u63a7\u5236\u81fa\u61c9\u7528\u7a0b\u5e8f\u7684\u5165\u53e3\u51fd\u6578\uff0c\u6211\u5011\u7684\u7a0b\u5e8f\u5f9e\u9019\u91cc\u958b\u59cb
//-----------------------------------------------------------------------------------------------
int main( )
{
	//\u8f09\u5165\u539f\u59cb\u5716  
	Mat srcImage = imread("1.jpg");  //\u5c08\u6848\u76ee\u9304\u4e0b\u61c9\u8a72\u6709\u4e00\u5f35\u540d\u70ba1.jpg\u7684\u7d20\u6750\u5716
	Mat srcImage1=srcImage.clone();

	//\u986f\u793a\u539f\u59cb\u5716 
	imshow("\u3010\u539f\u59cb\u5716\u3011Canny\u908a\u7de3\u6aa2\u6e2c", srcImage); 

	//----------------------------------------------------------------------------------
	//	\u4e00\u3001\u6700\u7c21\u55ae\u7684canny\u7528\u6cd5\uff0c\u62ff\u5230\u539f\u5716\u5f8c\u76f4\u63a5\u7528\u3002
	//----------------------------------------------------------------------------------
	Canny( srcImage, srcImage, 150, 100,3 );
	imshow("\u3010\u6548\u679c\u5716\u3011Canny\u908a\u7de3\u6aa2\u6e2c", srcImage); 


	//----------------------------------------------------------------------------------
	//	\u4e8c\u3001\u9ad8\u968e\u7684canny\u7528\u6cd5\uff0c\u8f49\u6210\u7070\u5ea6\u5716\uff0c\u964d\u566a\uff0c\u7528canny\uff0c\u6700\u5f8c\u5c07\u5f97\u5230\u7684\u908a\u7de3\u4f5c\u70ba\u63a9\u78bc\uff0c\u62f7\u8c9d\u539f\u5716\u5230\u6548\u679c\u5716\u4e0a\uff0c\u5f97\u5230\u5f69\u8272\u7684\u908a\u7de3\u5716
	//----------------------------------------------------------------------------------
	Mat dstImage,edge,grayImage;

	// \u30101\u3011\u5efa\u7acb\u8207src\u540c\u985e\u5225\u578b\u548c\u5927\u5c0f\u7684\u77e9\u9663(dst)
	dstImage.create( srcImage1.size(), srcImage1.type() );

	// \u30102\u3011\u5c07\u539f\u5716\u50cf\u8f49\u63db\u70ba\u7070\u5ea6\u5716\u50cf
	cvtColor( srcImage1, grayImage, CV_BGR2GRAY );

	// \u30103\u3011\u5148\u7528\u4f7f\u7528 3x3\u6838\u5fc3\u4f86\u964d\u566a
	blur( grayImage, edge, Size(3,3) );

	// \u30104\u3011\u57f7\u884cCanny\u7b97\u5b50
	Canny( edge, edge, 3, 9,3 );

	//\u30105\u3011\u5c07g_dstImage\u5167\u7684\u6240\u6709\u5143\u7d20\u8a2d\u5b9a\u70ba0 
	dstImage = Scalar::all(0);

	//\u30106\u3011\u4f7f\u7528Canny\u7b97\u5b50\u8f38\u51fa\u7684\u908a\u7de3\u5716g_cannyDetectedEdges\u4f5c\u70ba\u63a9\u78bc\uff0c\u4f86\u5c07\u539f\u5716g_srcImage\u62f7\u5230\u76ee\u6a19\u5716g_dstImage\u4e2d
	srcImage1.copyTo( dstImage, edge);

	//\u30107\u3011\u986f\u793a\u6548\u679c\u5716 
	imshow("\u3010\u6548\u679c\u5716\u3011Canny\u908a\u7de3\u6aa2\u6e2c2", dstImage); 


	waitKey(0); 

	return 0; 
}
