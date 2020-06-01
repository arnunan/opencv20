﻿// Part5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

int main()
{
    //##################################################################################
	// упражнение 5.6

	CvConnectedComp mask;
	for (int i = 0; i < mop->width; i++)
	{
		for (int j = 0; j < mop->height; j++)
		{
			CvScalar Pixel = cvGet2D(mop, j, i);

			if (Pixel.val[0] == 255)
			{
				cvFloodFill(mop, cvPoint(j, i), cvScalarAll(100), cvScalarAll(10), cvScalarAll(10), &mask, CV_FLOODFILL_FIXED_RANGE + 8, 0);
			}
		}
	}

	getchar();

}
