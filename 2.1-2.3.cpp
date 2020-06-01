// Part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cv.h> 
#include <highgui.h> 

int g_slider_position = 0;
CvCapture*  g_capture = NULL;

void onTrackbarSlide(int pos) {     
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos); 
} 

int main(int argc, char* argv[])
{

	//##################################################################################
	// упражнение 2.1

	// проект компилируется, библиотеки и dll собираются

	//##################################################################################
	// упражнение 2.2

	// программа собирается

	//##################################################################################
	// упражнение 2.3

	CvCapture* capture = 0;

	cvNamedWindow("TrackBar", CV_WINDOW_AUTOSIZE);
	capture = cvCreateFileCapture(argv[1]);

	if (!capture) { 
		return -1; 
	}

	IplImage* bgr_frame = cvQueryFrame(capture);
	double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);


	CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH), (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
	CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

	while ((bgr_frame = cvQueryFrame(capture)) != NULL) {		
		
		// упраженение 2.3 - добавление сжатия данных

		cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width/2, bgr_frame->height/2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		IplImage* logpolar_frame_wr = cvCreateImage(cvSize(logpolar_frame->width / 2, logpolar_frame->height / 2), logpolar_frame->depth, logpolar_frame->nChannels);
		cvPyrDown(logpolar_frame, logpolar_frame_wr); // сжатие изображения в 2 раза
		cvWriteFrame(writer, logpolar_frame_wr);

	}

	cvReleaseImage(&logpolar_frame);
	cvReleaseVideoWriter(&writer);         
	cvReleaseCapture(&capture);

	getchar();

	return(0);
}

