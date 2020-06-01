// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <_highgui.h>

int main()
{
    

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

}
