// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{

    //##################################################################################
	// упражнение 5.5

	// упражнение 5.5.a

    IplImage* src1 = cvLoadImage("../Part3/picture/88.png");
    IplImage* src2 = cvLoadImage("../Part3/picture/88.png");

	IplImage* src1_gray = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	IplImage* src2_gray = cvCreateImage(cvGetSize(src2), IPL_DEPTH_8U, 1);

    cvCvtColor(src1, src1_gray, CV_BGR2GRAY);
	cvCvtColor(src2, src2_gray, CV_BGR2GRAY);

	IplImage* diff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 1);
	cvAbsDiff(src1_gray, src2_gray, diff);


	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", diff);
	cvWaitKey(0);
	cvDestroyWindow("Square");


	getchar();

}
