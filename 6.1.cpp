﻿// Part6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    // упражнение 6.1

    IplImage* src = cvLoadImage("../Part3/picture/88.png");
    IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

    float kernel[9] = { 0, 0, 1, 0, 1, 0, 1, 0, 0 };
    CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");


} 