#include <stdio.h>
//:read /home/peter/mao/54_PyrAndResize.cpp




#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;


#define WINDOW_NAME "真真真"		//真真真真真


Mat g_srcImage, g_dstImage, g_tmpImage;


//-----------------------------------真真真真真--------------------------------------
//		真真真真�
//-----------------------------------------------------------------------------------------------
static void ShowHelpText();

//-----------------------------------�main( )真�--------------------------------------------
//		真真真真真真真真真真真真真
//-----------------------------------------------------------------------------------------------
int main( )
{
	//真console真真
	system("color 2F");  

	//真真真
	ShowHelpText();

	//真真
	g_srcImage = imread("/home/peter/opencv-2.4.11/samples/cpp/mao/1.jpg");//真真真真真真1.jpg真真真真真真2�N真真�N真真真真
	if( !g_srcImage.data ) { printf("Oh�no真�srcImage真~� \n"); return false; }

	// 真真真
	namedWindow( WINDOW_NAME, CV_WINDOW_AUTOSIZE );
	imshow(WINDOW_NAME, g_srcImage);

	//真真
	g_tmpImage = g_srcImage;
	g_dstImage = g_tmpImage;

	int key =0;

	//真真真真
	while(1)
	{
		key=waitKey(9) ;//真真�key真�

		//真key真真真真真真
		switch(key)
		{
			//======================真真真真真真=======================  
		case 27://真ESC
			return 0;
			break; 

		case 'q'://真Q
			return 0;
			break; 

			//======================真真真真真真=======================  
		case 'a'://真A真真�pyrUp真
			pyrUp( g_tmpImage, g_dstImage, Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ) );
			printf( ">真真真A真真真真真真pyrUp真真真真真真迅2 \n" );		
			break; 

		case 'w'://真W真真�resize真
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( ">真真真W真真真真真真resize真真真真真真迅2 \n" );		
			break; 

		case '1'://真1真真�resize真
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( ">真真真1真真真真真真resize真真真真真真迅2 \n" );
			break; 

		case '3': //真3真真�pyrUp真
			pyrUp( g_tmpImage, g_dstImage, Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( ">真真真3真真真真真真pyrUp真真真真真真迅2 \n" );
			break; 
			//======================真真真真真真=======================  
		case 'd': //真D真真�pyrDown真
			pyrDown( g_tmpImage, g_dstImage, Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( ">真真真D真真真真真真pyrDown真真真真真真�/2\n" );
			break; 

		case  's' : //真S真真�resize真
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( ">真真真S真真真真真真resize真真真真真真�/2\n" );
			break; 

		case '2'://真2真真�resize真
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( ">真真真2真真真真真真resize真真真真真真�/2\n" );
			break; 

		case '4': //真4真真�pyrDown真
			pyrDown( g_tmpImage, g_dstImage, Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ) );
			printf( ">真真真4真真真真真真pyrDown真真真真真真�/2\n" );
			break; 
		}

		//真真真真真真�
		imshow( WINDOW_NAME, g_dstImage );

		//�g_dstImage真g_tmpImage真真真真
		g_tmpImage = g_dstImage;
	}

	return 0;
}

//-----------------------------------�ShowHelpText( )真�----------------------------------
//		真真真真真�
//----------------------------------------------------------------------------------------------
static void ShowHelpText()
{

	//真真真�OpenCV真
	printf("\n\n\t\t\t真真真�OpenCV3真真真真真\n");
	printf("\n\n\t\t\t真真OpenCV2真�54真真真�\n");
	printf("\n\n\t\t\t   真真�OpenCV真真" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");

	//真真真真
	printf("\n\t真真OpenCV真真真resize真真~\n\n");
	printf( "\n\n\t真真真: \n\n"
		"\t\t真真�ESC真真Q�- 真真\n"
		"\t\t真真�1真真W�- 真真�resize真真真真\n"
		"\t\t真真�2真真S�- 真真�resize真真真真\n"
		"\t\t真真�3真真A�- 真真�pyrUp真真真真\n"
		"\t\t真真�4真真D�- 真真�pyrDown真真真真\n"
		);
}
