// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
 
    // упражнение 3.3

    int rows = 100;
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
    cvDestroyWindow("Square");

}
