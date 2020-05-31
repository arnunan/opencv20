// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{
	//##################################################################################
	// упражнение 5.1

	//IplImage* Picture = cvLoadImage("../Part3/picture/88.png");
	
	// упражнение 5.1.a
	
	/*cvSmooth(Picture, Picture, CV_GAUSSIAN, 3, 3);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 9, 9);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 11, 11);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	//##################################################################################
	// упражнение 5.2

	/*IplImage* Picture = cvCreateImage(cvSize(100, 100), IPL_DEPTH_8U, 1);
	cvZero(Picture);
	cvSet2D(Picture, 50, 50, cvScalarAll(255));*/

	// упражнение 5.2.a

	//cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);

	// упражнение 5.2.б

	//cvSmooth(Picture, Picture, CV_GAUSSIAN, 9, 9);

	// упражнение 5.2.с

	/*cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	//##################################################################################
	// упражнение 5.3

	//IplImage* Picture = cvLoadImage("../Part3/picture/88.png");

	// упражнение 5.3.a

	/*IplImage* Picture1 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
	IplImage* Picture4 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
	IplImage* Picture6 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);*/

	/*cvSmooth(Picture, Picture1, CV_GAUSSIAN, 9, 9, 1);
	cvSmooth(Picture, Picture4, CV_GAUSSIAN, 9, 9, 4);
	cvSmooth(Picture, Picture6, CV_GAUSSIAN, 9, 9, 6);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture4);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture6);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	// упражнение 5.3.б

	/*cvSmooth(Picture, Picture1, CV_GAUSSIAN, 0, 0, 1);
	cvSmooth(Picture, Picture4, CV_GAUSSIAN, 0, 0, 4);
	cvSmooth(Picture, Picture6, CV_GAUSSIAN, 0, 0, 6);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture4);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture6);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	// упражнение 5.3.с

	/*cvSmooth(Picture, Picture1, CV_GAUSSIAN, 0, 0, 9, 1);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	// упражнение 5.3.d

	/*cvSmooth(Picture, Picture1, CV_GAUSSIAN, 9, 9, 1);
	cvSmooth(Picture1, Picture1, CV_GAUSSIAN, 0, 0, 9, 1);
	cvSmooth(Picture, Picture4, CV_GAUSSIAN, 9, 9, 4);
	cvSmooth(Picture4, Picture4, CV_GAUSSIAN, 0, 0, 9, 1);
	cvSmooth(Picture, Picture6, CV_GAUSSIAN, 9, 9, 6);
	cvSmooth(Picture6, Picture6, CV_GAUSSIAN, 0, 0, 9, 1);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture4);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture6);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

	// упражнение 5.3.f

	//##################################################################################
	// упражнение 5.4

 //   IplImage* src1 = cvLoadImage("../Part3/picture/88.png"); 
	//IplImage* src2 = cvLoadImage("../Part3/picture/88.png");

	//// упражнение 5.4.a

	//IplImage* diff12 = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	//cvSub(src1, src2, diff12);

	//// упражнение 5.4.б

	//IplImage* cleandiff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	//cvErode(diff12, cleandiff);
	//cvDilate(diff12, diff12);

	//// упражнение 5.4.c

	//IplImage* dirtydiff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	//cvDilate(diff12, diff12);
	//cvErode(diff12, dirtydiff);
	//
	//cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	//cvShowImage("Square", diff12);
	//cvWaitKey(0);
	//cvDestroyWindow("Square");

    //##################################################################################
	// упражнение 5.5

	// упражнение 5.4.a

    IplImage* src1 = cvLoadImage("../Part3/picture/88.png");
    IplImage* src2 = cvLoadImage("../Part3/picture/88.png");

	IplImage* src1_gray = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	IplImage* src2_gray = cvCreateImage(cvGetSize(src2), IPL_DEPTH_8U, 1);

    cvCvtColor(src1, src1_gray, CV_BGR2GRAY);
	cvCvtColor(src2, src2_gray, CV_BGR2GRAY);

	IplImage* diff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	cvAbsDiff(src1_gray, src2_gray, diff);

	// упражнение 5.4.б

	IplImage* thresh = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	cvThreshold(diff, thresh, 128, 255, CV_THRESH_BINARY);

	// упражнение 5.4.c

	IplImage* mop = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	cvThreshold(thresh, mop, 128, 255, CV_MOP_OPEN);

	/*cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", diff);
	cvWaitKey(0);
	cvDestroyWindow("Square");*/

    //##################################################################################
	// упражнение 5.6

	CvConnectedComp mask;
	for (int i = 0; i < mop->width; i++)
	{
		for (int j = 0; j < mop->height; j++)
		{
			CvScalar Pixel = cvGet2D(mop, j, i);

			if (Pixel.val[0] == 255)
			{
				cvFloodFill(mop, cvPoint(j, i), cvScalarAll(100), cvScalarAll(10), cvScalarAll(10), &mask, CV_FLOODFILL_FIXED_RANGE + 8, 0);
			}
		}
	}

	//##################################################################################
    // упражнение 5.7

	IplImage* dst = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	cvCopy(src1, dst, mop);

	//##################################################################################
	// упражнение 5.8



	getchar();

}
