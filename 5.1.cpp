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

	IplImage* Picture = cvLoadImage("../Part3/picture/88.png");
	
	
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 3, 3);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 5, 5);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 9, 9);
	cvSmooth(Picture, Picture, CV_GAUSSIAN, 11, 11);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture);
	cvWaitKey(0);
	cvDestroyWindow("Square");

	getchar();

}
