// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{
	//##################################################################################
	// упражнение 5.2

	IplImage* Picture = cvCreateImage(cvSize(100, 100), IPL_DEPTH_8U, 1);
	cvZero(Picture);
	cvSet2D(Picture, 50, 50, cvScalarAll(255));*/

	// упражнение 5.2.a

	cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);


	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	getchar();

}
