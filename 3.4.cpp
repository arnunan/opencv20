// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    //##################################################################################
    // упражнение 3.4

    int rows = 100;
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
    cvDestroyWindow("Square1");

}
