// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    
    // упражнение 3.7

    IplImage* Picture = cvLoadImage("../Part3/picture/88.png");

    IplImage* PictureR = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    IplImage* PictureG = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    IplImage* PictureB = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    cvSplit(Picture, PictureR, PictureG, PictureB, 0);

    // упражнение 3.7.a

    cvNamedWindow("Picture", 1);
    cvShowImage("Picture", PictureG);
    cvWaitKey(0);
    cvDestroyWindow("Picture");

    // упражнение 3.7.б

    IplImage* clone1 = cvCloneImage(PictureG);
    IplImage* clone2 = cvCloneImage(PictureG);

    // упражнение 3.7.c

    double* maximum = new double();
    double* minimum = new double();
    cvMinMaxLoc(PictureG, minimum, maximum);
    
    // упражнение 3.7.d

    int thresh = (int)((maximum - minimum) / 2.0);
    cvSet(clone1, cvScalarAll(thresh));

    // упражнение 3.7.e

    cvSet(clone2, cvScalarAll(0));
    cvCmp(PictureG, clone1, clone2, CV_CMP_GE);

    // упражнение 3.7.f

    cvSubS(PictureG, cvScalarAll(thresh / 2), PictureG, clone2);

    cvNamedWindow("Picture", 1);
    cvShowImage("Picture", PictureG);
    cvWaitKey(0);
    cvDestroyWindow("Picture");

    getchar();
}
