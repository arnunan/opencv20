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
    IplImage* diff12 = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	//// упражнение 5.4.б

	IplImage* cleandiff = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	cvErode(diff12, cleandiff);
	cvDilate(diff12, diff12);

	
	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", diff12);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	getchar();

}
