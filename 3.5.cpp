// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    
    // упражнение 3.5 -- переделать через RoI

    int rows = 210;
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
    cvDestroyWindow("Picture");

}
