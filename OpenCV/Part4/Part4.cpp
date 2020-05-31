// Part4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>

#include <cv.h> 
#include <highgui.h> 


IplImage* temp = new IplImage();

void my_mouse_callback1(int event, int x, int y, int flags, void* param) 
{
	IplImage* image = (IplImage*)param;     
	switch (event)
	{
	    case CV_EVENT_LBUTTONDOWN:
	    {
			
			CvScalar Pixel = cvGet2D(image, x, y);
			
			std::ostringstream strs;
			strs << Pixel.val[0] << " " << Pixel.val[1] << " " << Pixel.val[2] << " ";
			CvFont font;
			cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.3, 0.3);

			temp = cvCloneImage(image);
			cvPutText(temp, strs.str().c_str(), cvPoint(x, y), &font, cvScalarAll(0));

			break;
	    }
		default:
		{
			break;
		}
	}
}

CvRect  box;
bool drawing_box = false;

void draw_box(IplImage* img, CvRect rect) { 
	 cvRectangle(img, cvPoint(box.x, box.y), cvPoint(box.x + box.width, box.y + box.height), cvScalar(0x00, 0x00, 0x00)); 
}

void my_mouse_callback2(int event, int x, int y, int flags, void* param)
{
	IplImage* image = (IplImage*)param;     
	switch (event) 
	{
	    case CV_EVENT_MOUSEMOVE: {            
		     if (drawing_box) { 
		         box.width = x - box.x;
		         box.height = y - box.y; 
			 }      
			 break;
		}         
		case CV_EVENT_LBUTTONDOWN: {             
		     drawing_box = true;             
		     box = cvRect(x, y, 0, 0); 
			 break;
		}                  
		case CV_EVENT_LBUTTONUP: {             
			 drawing_box = false;
		     if (box.width < 0) {
			     box.x += box.width;                 
				 box.width *= -1;
		     }
		     if (box.height < 0) { 
				 box.y += box.height;                 
				 box.height *= -1; 
			 }
			 temp = cvCloneImage(image);
			 draw_box(temp, box);
			 break;
		}
		default: {
			 break;
		}
	}
}

bool status_drawing = false;
CvPoint PointA, PointB;
void my_mouse_callback3(int event, int x, int y, int flags, void* param)
{
	IplImage* image = (IplImage*)param;
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN: {
		status_drawing = true;
		PointA.x = x;
		PointA.y = y;
	}
	case CV_EVENT_LBUTTONUP: {
		status_drawing = false;
		PointB.x = x;
		PointB.y = y;
		temp = cvCloneImage(image);
		cvLine(temp, PointA, PointB, cvScalarAll(0), 1);
		break;
	}
	case CV_EVENT_RBUTTONDOWN: {
		cvCircle(temp, cvPoint(x, y), 5, cvScalarAll(255), 20);

		break;
	}
	default: {
		break;
	}
	}
}


int pos_value = 0;
void position_callback(int position) 
{ 
	pos_value = position * 10; 
}

int turn = 0;
void turn_callback(int position)
{
	turn = position;
}


int main(int argc, char* argv[])
{
    
	//##################################################################################
	// упражнение 4.1 - чтение кадров из видеофайла
	
	//CvCapture* capture = 0;
	//capture = cvCreateFileCapture(argv[1]);

	//if (!capture) {
	//	return -1;
	//}

	//IplImage* bgr_frame = cvQueryFrame(capture);
	//double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

	//CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH), (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
	//IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

	//while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
	//	
	//	cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);

	//	// конвертация в черно-белый цвет

	//	IplImage* PictureBW = cvCreateImage(cvGetSize(logpolar_frame), IPL_DEPTH_8U, 1);
	//	cvThreshold(logpolar_frame, PictureBW, 128, 255, CV_THRESH_BINARY);
	//	
	//	IplImage* PictureCanny = cvCreateImage(cvGetSize(PictureBW), IPL_DEPTH_8U, 1);
	//	
	//	cvCanny(PictureBW, PictureCanny, 10, 10, 3);

	//	// отображение на разных изображениях

	//	cvNamedWindow("Picture", 1);
	//	cvShowImage("Picture", logpolar_frame);
	//	cvWaitKey(0);
	//	cvDestroyWindow("Picture");

	//	cvNamedWindow("Picture", 1);
	//	cvShowImage("Picture", PictureBW);
	//	cvWaitKey(0);
	//	cvDestroyWindow("Picture");

	//	cvNamedWindow("Picture", 1);
	//	cvShowImage("Picture", PictureCanny);
	//	cvWaitKey(0);
	//	cvDestroyWindow("Picture");

	//	// отображение на 1 изображении

	//	IplImage* PictureAll = cvCreateImage(cvSize(logpolar_frame->width*3, logpolar_frame->height), IPL_DEPTH_8U, 1);
	//	IplImage* A = cvCreateImage(cvGetSize(logpolar_frame), IPL_DEPTH_8U, 1);
	//	IplImage* B = cvCreateImage(cvGetSize(logpolar_frame), IPL_DEPTH_8U, 1);
	//	IplImage* C = cvCreateImage(cvGetSize(logpolar_frame), IPL_DEPTH_8U, 1);
	//	cvCopyImage(A, PictureAll, 0);
	//	cvCopyImage(B, PictureAll, cvGetSize(logpolar_frame));
	//	cvCopyImage(C, PictureAll, cvGetSize(logpolar_frame)*2);
	//}

	//cvReleaseImage(&logpolar_frame);
	//cvReleaseCapture(&capture);

	//##################################################################################
	// упражнение 4.2 - текст на изображении

	//IplImage* Picture = cvLoadImage("../Part3/picture/88.png");
	//temp = cvCloneImage(Picture);

	//cvNamedWindow("Pixels");
	//cvSetMouseCallback("Pixels", my_mouse_callback1, (void*)Picture);
	//
	//bool work = true;
	//while (work) 
	//{
	//	cvShowImage("Pixels", temp);

	//	if (27 == cvWaitKey(15)) // нажатие кнопки ecs
	//		work = false;
	//}
	//
	//cvDestroyWindow("Pixels");

	//##################################################################################
	// упражнение 4.3 - прямоугольник на изображении

	// упражнение 4.3.a

	//IplImage* Picture = cvLoadImage("../Part3/picture/88.png");
	//temp = cvCloneImage(Picture);

	//cvNamedWindow("Pixels");
	//cvSetMouseCallback("Pixels", my_mouse_callback2, (void*)Picture);
	//
	//bool work = true;
	//while (work) 
	//{
	//	cvShowImage("Pixels", temp);

	//	if (27 == cvWaitKey(15)) // нажатие кнопки ecs
	//		work = false;
	//}
	
	//cvDestroyWindow("Pixels");

	// упражнение 4.3.б

	//##################################################################################
	// упражнение 4.4 - слайдер

	cvNamedWindow("Video", 1);
	cvCreateTrackbar("Position", "Video", &pos_value, 1, position_callback);
	cvCreateTrackbar("Turn OFFON", "Video", &turn, 1, turn_callback);

	CvCapture* capture = cvCreateCameraCapture(0);

	int count_kadr = 0;

	while (1) 
	{
			
		if (turn)
		{
			if (pos_value)
			{
				count_kadr = count_kadr + 1;
				if ((count_kadr % 10) == 0)
				{
					cvGrabFrame(capture);
					IplImage* kadr = cvRetrieveFrame(capture);
					cvShowImage("Video", kadr);
				}
			}
			else
			{
				cvGrabFrame(capture);
				IplImage* kadr = cvRetrieveFrame(capture);
				cvShowImage("Video", kadr);
			}
		}
		
		if (27 == cvWaitKey(15)) // ecs
		{
			break;
		}
	}

	cvReleaseCapture(&capture);

	//##################################################################################
	// упражнение 4.5 - paint
    // рисует и стирает линию, остальное однотипно


	//IplImage* Picture = cvCreateImage(cvSize(400, 400), IPL_DEPTH_8U, 1);
	//cvSet(Picture, cvScalarAll(255));
	//temp = cvCloneImage(Picture);

	//cvNamedWindow("Pixels");
	//cvSetMouseCallback("Pixels", my_mouse_callback3, (void*)Picture);
	//
	//bool work = true;
	//while (work) 
	//{
	//	cvShowImage("Pixels", temp);

	//	if (27 == cvWaitKey(15)) // нажатие кнопки ecs
	//		work = false;
	//}

	//cvDestroyWindow("Pixels");

    getchar();
}

