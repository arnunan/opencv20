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

    //// упражнение 6.4.a

    for (int i = 0; i <= 200; i = i + 20)
    {
        cvLine(src, cvPoint(100, 100), cvPoint(i, 0), cvScalarAll(128), 1);
    }

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");


} 