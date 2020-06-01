// Part6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

static CvMemStorage* storage = 0;

int main()
{
    
    //##################################################################################
    // упражнение 6.4

    IplImage* src = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    cvZero(src);

    for (int i = 20; i < 200; i=i+20)
    {
        cvCircle(src, cvPoint(100, 100), i, cvScalarAll(255), 1);
    }


    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");


} 