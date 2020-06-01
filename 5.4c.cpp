// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{
	//##################################################################################
	// упражнение 5.4

    IplImage* src1 = cvLoadImage("../Part3/picture/88.png"); 
	IplImage* src2 = cvLoadImage("../Part3/picture/88.png");

	//// упражнение 5.4.c
    IplImage* diff12 = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	IplImage* dirtydiff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	cvDilate(diff12, diff12);
	cvErode(diff12, dirtydiff);

	
	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", diff12);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	getchar();

}
