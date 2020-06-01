// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    
    // упражнение 3.6

    IplImage* Picture4 = cvLoadImage("../Part3/picture/88.png");
    IplImage* Picture5 = cvCreateImage(cvGetSize(Picture4), IPL_DEPTH_8U, 1);
    IplImage* Picture6 = cvCreateImage(cvGetSize(Picture4), IPL_DEPTH_8U, 1);

    Picture5->origin = Picture4->origin;
    Picture6->origin = Picture4->origin;

    Picture5->depth = Picture4->depth;
    Picture6->depth = Picture4->depth;

    Picture5->nChannels = Picture4->nChannels;
    Picture6->nChannels = Picture4->nChannels;

    Picture5->widthStep = Picture4->widthStep;
    Picture6->widthStep = Picture4->widthStep;

    Picture5->width = 20;
    Picture6->width = 20;

    Picture5->height = 30;
    Picture6->height = 30;

    cvNot(Picture5, Picture6);

    cvNamedWindow("Picture", 1);
    cvShowImage("Picture", Picture6);
    cvWaitKey(0);
    cvDestroyWindow("Picture");

}
