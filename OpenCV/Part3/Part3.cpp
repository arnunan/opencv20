// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    
    //##################################################################################
    // упражнение 3.1

    // упражнение 3.1.a

    double example = -1.125;
    int ExampleFromRound = cvRound(example);
    int ExampleFromCeiling = cvCeil(example);
    int ExampleFromFloor = cvFloor(example);

    // упражнение 3.1.б

    float value0 = rand();
    float value1 = rand();

    // упражнение 3.1.c

    CvPoint2D32f* CvPointFloat = new CvPoint2D32f();
    CvPointFloat->x = value0;
    CvPointFloat->y = value1;
    CvPoint CvPointInt = cvPointFrom32f(CvPointFloat[0]);
    CvPoint2D32f CvPointFloatBack = cvPointTo32f(CvPointInt);

    // удаление переменных
    delete CvPointFloat;

    //##################################################################################
    // упражнение 3.2
    
    // упражнение 3.2.a

    /*int rows = 100;
    int cols = 100;
    int size = rows * cols;
    float* data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0.0;

    CvMat* Picture = new CvMat();
    Picture[0] = cvMat(rows, cols, CV_8UC1, data);*/

    // упражнение 3.2.б

    /*cvCircle(Picture, cvPoint(50,50), 10, cvScalar(255, 255, 255), 1);
    cvNamedWindow("Circle", CV_WINDOW_AUTOSIZE);
    cvShowImage("Circle", Picture);
    cvWaitKey(0);
    cvDestroyWindow("Circle");*/

    //##################################################################################
    // упражнение 3.3

    /*int rows = 100;
    int cols = 100;
    int size = rows * cols;
    float* data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0.0;

    CvMat* Picture1 = new CvMat();
    Picture1[0] = cvMat(rows, cols, CV_8UC1, data);
    for (int row = 20; row < 40; row++)
    {
        for (int col = 5; col < 20; col++)
        {
            *cvPtr2D(Picture1, row, col) = 255;
        }
    }

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", Picture1);
    cvWaitKey(0);
    cvDestroyWindow("Square");*/

    //##################################################################################
    // упражнение 3.4

    /*int rows = 100;
    int cols = 100;
    int size = rows * cols;
    float* data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0.0;

    CvMat* Picture2 = new CvMat();
    Picture2[0] = cvMat(rows, cols, CV_8UC3, data);
    cvSet(Picture2, cvScalar(255, 255, 255));
    cvRectangle(Picture2, cvPoint(20, 40), cvPoint(5, 20), cvScalar(0, 128, 0), 1);

    cvNamedWindow("Square1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square1", Picture2);
    cvWaitKey(0);
    cvDestroyWindow("Square1");*/

    //##################################################################################
    // упражнение 3.5 -- переделать через RoI

    /*int rows = 210;
    int cols = 210;
    int size = rows * cols;
    float* data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0.0;   
    
    CvMat* Picture3 = new CvMat();
    Picture3[0] = cvMat(rows, cols, CV_8UC1, data);
    cvZero(Picture3);

    for (int i = 0; i < 210; i = i + 10)
    {
        cvRectangle(Picture3, cvPoint(i, i), cvPoint(rows-i, cols-i), cvScalar(255, 255, 255), 1);
    }

    cvNamedWindow("Picture", 1);
    cvShowImage("Picture", Picture3);
    cvWaitKey(0);
    cvDestroyWindow("Picture");*/

    //##################################################################################
    // упражнение 3.6

    /*IplImage* Picture4 = cvLoadImage("../Part3/picture/88.png");
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
    cvDestroyWindow("Picture");*/

    //##################################################################################
    // упражнение 3.7

    IplImage* Picture = cvLoadImage("../Part3/picture/88.png");

    IplImage* PictureR = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    IplImage* PictureG = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    IplImage* PictureB = cvCreateImage(cvGetSize(Picture), IPL_DEPTH_8U, 1);
    cvSplit(Picture, PictureR, PictureG, PictureB, 0);

    // упражнение 3.7.a

    /*cvNamedWindow("Picture", 1);
    cvShowImage("Picture", PictureG);
    cvWaitKey(0);
    cvDestroyWindow("Picture");*/

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
