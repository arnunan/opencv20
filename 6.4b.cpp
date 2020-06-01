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

    //// упражнение 6.4.б

    IplImage* dst = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    float kernel[9] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };

    CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    CvMat kernel_matrix = cvMat(5, 5, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    CvMat kernel_matrix = cvMat(9, 9, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    CvMat kernel_matrix = cvMat(13, 13, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");


} 