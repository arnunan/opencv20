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
    // упражнение 6.1

    /*IplImage* src = cvLoadImage("../Part3/picture/88.png");
    IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

    float kernel[9] = { 0, 0, 1, 0, 1, 0, 1, 0, 0 };
    CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");*/

    //##################################################################################
    // упражнение 6.2

    // упражнение 6.2.a

    /*IplImage* src = cvLoadImage("../Part3/picture/88.png");
    IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

    float kernel[9] = { 1 / 16,  2 / 16,  1 / 16, 2 / 16,  4 / 16, 2 / 16, 1 / 16, 2 / 16, 1 / 16 };
    CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    cvFilter2D(src, dst, &kernel_matrix);

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");*/

    // упражнение 6.2.б

    /*IplImage* src = cvLoadImage("../Part3/picture/88.png");
    IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

    float kernel1[9] = { 1 / 4, 2 / 4, 1 / 4, 1 / 4, 2 / 4, 1 / 4 , 1 / 4, 2 / 4, 1 / 4 };
    float kernel2[9] = { 1 / 4, 1 / 4, 1 / 4, 2 / 4, 2 / 4, 2 / 4 , 1 / 4, 1 / 4, 1 / 4 };
    CvMat kernel_matrix1 = cvMat(3, 3, CV_32FC1, kernel1);
    CvMat kernel_matrix2 = cvMat(3, 3, CV_32FC1, kernel2);
    cvFilter2D(src, dst, &kernel_matrix1);
    cvFilter2D(dst, dst, &kernel_matrix2);

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");*/

    // упражнение 6.2.с

    //##################################################################################
    // упражнение 6.3



    //##################################################################################
    // упражнение 6.4

    //IplImage* src = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    //cvZero(src);

    //for (int i = 20; i < 200; i=i+20)
    //{
    //    cvCircle(src, cvPoint(100, 100), i, cvScalarAll(255), 1);
    //}

    //// упражнение 6.4.a

    //for (int i = 0; i <= 200; i = i + 20)
    //{
    //    cvLine(src, cvPoint(100, 100), cvPoint(i, 0), cvScalarAll(128), 1);
    //}

    //// упражнение 6.4.б

    //IplImage* dst = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    //float kernel[9] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };

    ///*CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
    //cvFilter2D(src, dst, &kernel_matrix);*/

    ///*CvMat kernel_matrix = cvMat(5, 5, CV_32FC1, kernel);
    //cvFilter2D(src, dst, &kernel_matrix);*/

    ///*CvMat kernel_matrix = cvMat(9, 9, CV_32FC1, kernel);
    //cvFilter2D(src, dst, &kernel_matrix);*/

    //CvMat kernel_matrix = cvMat(13, 13, CV_32FC1, kernel);
    //cvFilter2D(src, dst, &kernel_matrix);

    //cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    //cvShowImage("Square", dst);
    //cvWaitKey(0);
    //cvDestroyWindow("Square");

    //##################################################################################
    // упражнение 6.5

    /*IplImage* src = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    cvZero(src);

    for (int i = 0; i <= src->height; i += 2)
    {
         cvLine(src, cvPoint(0, i), cvPoint(src->height-i, src->height), cvScalarAll(255), 1);
         cvLine(src, cvPoint(i, 0), cvPoint(src->height, src->height - i), cvScalarAll(255), 1);
    }

    IplImage* dst = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
    float kernel_x[9] = { -3, 0, 3, - 10, 0, 10, - 3, 0, 3 };
    float kernel_y[9] = { -3, - 10, - 3, 0, 0, 0, 3, 10, 3 };

    CvMat kernel_matrix = cvMat(13, 13, CV_32FC1, kernel_y);
    cvFilter2D(src, dst, &kernel_matrix);



    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", dst);
    cvWaitKey(0);
    cvDestroyWindow("Square");*/

    //##################################################################################
    // упражнение 6.6
    
    static CvScalar colors[] =
    {
        {{0,0,255}},
        {{0,128,255}},
        {{0,255,255}},
        {{0,255,0}},
        {{255,128,0}},
        {{255,255,0}},
        {{255,0,0}},
        {{255,0,255}}
    };


    IplImage* src = cvLoadImage("../Part6/picture/Face.jpg");
    IplImage* gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    cvCvtColor(src, gray, CV_BGR2GRAY);

    // определение кругов
    CvMemStorage* storage = cvCreateMemStorage(0);
    cvSmooth(gray, gray, CV_GAUSSIAN, 9, 9);
    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 1, 20, 50, 30, 1, 30);
    for (int j = 0; j < circles->total; j++)
    {
        float* p = (float*)cvGetSeqElem(circles, j);
        cvCircle(src, cvPoint(p[0], p[1]), p[2], colors[3], 2);
    }

    cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
    cvShowImage("Square", src);
    cvWaitKey(0);
    cvDestroyWindow("Square");

} 