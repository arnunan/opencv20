// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{


    // упражнение 3.2.a

    int rows = 100;
    int cols = 100;
    int size = rows * cols;
    float* data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0.0;

    CvMat* Picture = new CvMat();
    Picture[0] = cvMat(rows, cols, CV_8UC1, data);

    // упражнение 3.2.б

    cvCircle(Picture, cvPoint(50,50), 10, cvScalar(255, 255, 255), 1);
    cvNamedWindow("Circle", CV_WINDOW_AUTOSIZE);
    cvShowImage("Circle", Picture);
    cvWaitKey(0);
    cvDestroyWindow("Circle");

}
