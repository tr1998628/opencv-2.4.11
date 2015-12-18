
#include <opencv2/opencv.hpp>  // full path ~/opencv-2.4.11/include/opencv2/opencv.hpp
#include <iostream>
#include <fstream> 

#define aaa cout << "MO: [aaaaaaaaa] FILE=%s " <<  __FILE__  <<  " FUNCTION=%s " <<  __FUNCTION__ <<  " LINE=%d" <<  __LINE__ << endl ;

using namespace cv; 
using namespace std;


int g_slider_position = 0; 
int g_run = 1, g_dontset = 0; //start out in single step mode 
cv::VideoCapture g_cap; 

#if 0
void onTrackbarSlide( int pos, void *) { 
 g_cap.set( CV_CAP_PROP_POS_FRAMES, pos ); 
 if( !g_dontset ) 
 g_run = 1; 
 g_dontset = 0; 
} 
#endif 


int main( int argc, char** argv )
{

#if 0
 cv::namedWindow( "Example2_4", cv::WINDOW_AUTOSIZE ); 
 g_cap.open( "cube4.avi"  ); 

 int frames = (int) g_cap.get(CV_CAP_PROP_FRAME_COUNT); 
 int tmpw   = (int) g_cap.get(CV_CAP_PROP_FRAME_WIDTH); 
 int tmph   = (int) g_cap.get(CV_CAP_PROP_FRAME_HEIGHT); 
 cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl; 

 cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide); 

 cv::Mat frame; 

 while(1) { 
     if( g_run != 0 ) { 
	 g_cap >> frame; if(!frame.data) break; 
	 int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES); 
	 g_dontset = 1; 
	 cv::setTrackbarPos("Position", "Example2_4", current_pos); 
	 cv::imshow( "Example2_4", frame ); 
	 g_run-=1; 
     } 

     char c = (char) cv::waitKey(10); 
     if(c == 's') // single step 
     {g_run = 1; cout << "Single step, run = " << g_run << endl;} 
     if(c == 'r') // run mode 
     {g_run = -1; cout << "Run mode, run = " << g_run <<endl;} 
     if( c == 27 ) // ESC key
	 break; 
 }
#endif 

#if 0
    cv::namedWindow( "Example3", cv::WINDOW_AUTOSIZE ); 
    cv::VideoCapture cap; 
    // cap.open( string(argv[1]) ); 
    cap.open( "cube4.avi"  ); 
    cv::Mat frame; 
    while( 1 ) { 

	cap >> frame; 

	if( !frame.data ) break; // Ran out of film 

	cv::imshow( "Example3", frame ); 

	if( cv::waitKey(33) >= 0 ) break; 
    }

#endif 

#if 0
    cout <<" hello 3 1 1" << endl;

    Mat img = imread( "lena.jpg", -1 ); 

    if( img.empty() ) {

	cout << " missing parameter. " << endl;
	return -1; 
    }

    namedWindow( "Example2", WINDOW_AUTOSIZE ); 
    imshow( "Example2", img ); 

    waitKey( 0 ); 
    destroyWindow( "Example2" ); 
#endif 

#if 0
    cout <<" Example2_5 and 2_6" << endl;
    namedWindow( "Example2_5-in", cv::WINDOW_AUTOSIZE ); 
    namedWindow( "Example2_5-out", cv::WINDOW_AUTOSIZE ); 

    Mat img = imread( "lena.jpg", -1 ); 

    if( img.empty() ) {
	cout << " missing parameter. " << endl;
	return -1; 
    }

    imshow( "Example2_5-in", img ); 

    Mat out; 

    out = img ; 

    // comment out to try "A Not-So-Simple Transformation"
    pyrDown( img, out ); 

    // comment out to try "A Simple Transformation" 
//    GaussianBlur( img, out, cv::Size(5,5), 3, 3); 
//    GaussianBlur( out, out, cv::Size(5,5), 3, 3); 

    imshow( "Example2_5-out", out ); 

    waitKey( 0 ); 
    destroyWindow( "Example2_5-in" ); 
    destroyWindow( "Example2_5-out" ); 
#endif 

#if 1
    // comment out to try "Example 2-7"
    cout <<" Example2 7 " << endl;

    Mat img_rgb = cv::imread("lena.jpg"); 

    if( img_rgb.empty() ) {
	cout << " missing parameter. " << endl;
	return -1; 
    }

    Mat img_gry, img_cny; 
    cvtColor( img_rgb, img_gry, CV_BGR2GRAY); 

    Mat img_pyr; 
    pyrDown( img_gry, img_pyr ); 

    Mat img_pyr2; 
    pyrDown( img_pyr, img_pyr2 ); 

    namedWindow( "Example Gray", cv::WINDOW_AUTOSIZE ); 
    namedWindow( "Example Canny", cv::WINDOW_AUTOSIZE ); 
    imshow( "Example Gray", img_gry ); 

//    Canny( img_gry, img_cny, 10, 100, 3, true ); 
    Canny( img_pyr2, img_cny, 10, 100, 3, true ); 

    imshow( "Example Canny", img_cny ); 
    waitKey(0); 
    destroyWindow( "Example Gray" ); 
    destroyWindow( "Example Canny" ); 

#endif 



    return 0;
}