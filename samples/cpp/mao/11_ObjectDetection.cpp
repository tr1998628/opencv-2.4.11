
#include <stdio.h>

/**
 * @file ObjectDetection.cpp
 * @author A. Huaman ( based in the classic facedetect.cpp in samples/c )
 * @brief A simplified version of facedetect.cpp, show how to load a cascade classifier and how to find objects (Face + eyes) in a video stream
 */

//---------------------------------【頭文件、命名空間包含部分】----------------------------
//		描述：包含程序所使用的頭文件和命名空間
//-------------------------------------------------------------------------------------------------
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

//--------------------------------【全局變數宣告】----------------------------------------------
//		描述：宣告全局變數
//-------------------------------------------------------------------------------------------------
//注意，需要把"haarcascade_frontalface_alt.xml"和"haarcascade_eye_tree_eyeglasses.xml"這兩個文件復制到專案路徑下

String face_cascade_name = "/home/peter/opencv-2.4.11/samples/cpp/mao/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "/home/peter/opencv-2.4.11/samples/cpp/mao/haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "Capture - Face detection";
RNG rng(12345);


//--------------------------------【help( )函數】----------------------------------------------
//		描述：輸出說明訊息
//-------------------------------------------------------------------------------------------------
static void ShowHelpText()
{
	//輸出歡迎訊息和OpenCV版本
	cout <<"\n\n\t\t\t非常感謝購買《OpenCV3程式設計入門》一書！\n"
		<<"\n\n\t\t\t此為本書OpenCV2版的第11個配套範例程序\n"
		<<	"\n\n\t\t\t   現在使用的OpenCV版本為：" << CV_VERSION 
		<<"\n\n  ----------------------------------------------------------------------------" ;
}


//-----------------------------------【main( )函數】--------------------------------------------
//		描述：控制臺應用程序的入口函數，我們的程序從這里開始
//-------------------------------------------------------------------------------------------------
int main( void )
{
  VideoCapture capture;
  Mat frame;


  //-- 1. 加載級聯（cascades）
  if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
  if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

  //-- 2. 讀取視訊
  capture.open(0);
  ShowHelpText();
  if( capture.isOpened() )
  {
    for(;;)
    {
      capture >> frame;

      //-- 3. 對現在幅使用分類別器（Apply the classifier to the frame）
      if( !frame.empty() )
       { detectAndDisplay( frame ); }
      else
       { printf(" --(!) No captured frame -- Break!"); break; }

      int c = waitKey(10);
      if( (char)c == 'q' ) { break; }

    }
  }
  return 0;
}


void detectAndDisplay( Mat frame )
{
   std::vector<Rect> faces;
   Mat frame_gray;

   cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
   equalizeHist( frame_gray, frame_gray );
   //-- 人臉檢測
   face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

   for( size_t i = 0; i < faces.size(); i++ )
    {
      Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
      ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 2, 8, 0 );

      Mat faceROI = frame_gray( faces[i] );
      std::vector<Rect> eyes;

      //-- 在臉中檢測眼睛
      eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

      for( size_t j = 0; j < eyes.size(); j++ )
       {
         Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
         int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
         circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 3, 8, 0 );
       }
    }
   //-- 顯示最終效果圖
   imshow( window_name, frame );
   moveWindow( window_name, 100,100  );
}
