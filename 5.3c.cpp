// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{
	//##################################################################################
	// упражнение 5.3

	IplImage* Picture = cvLoadImage("../Part3/picture/88.png");

	// упражнение 5.3.a

	IplImage* Picture1 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
	IplImage* Picture4 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
	IplImage* Picture6 = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);

	// упражнение 5.3.с

	cvSmooth(Picture, Picture1, CV_GAUSSIAN, 0, 0, 9, 1);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	getchar();

}
