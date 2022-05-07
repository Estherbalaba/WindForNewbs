#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

void MyLines();
int ISPING = 100;

int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;

Mat src,gray_src, dst,gblur,edge_output, g_edge_output,ROI,gray_src_2;

int main() {
	
	int t1_value = 50;
	int max_value = 255;
	int h = src.rows;
	int w = src.cols;
	src = imread("D:/opencv/作业2/Mission 2/nova/data/nova_0.bmp");//D:/opencv/作业2/Mission 2/nova/data/nova_0.bmp
	if (!src.data) {
		printf("could not load image...");
		return -1;
	}
	//namedWindow("input image", WINDOW_AUTOSIZE);
	//imshow("input image",src);

	//转为灰度图像
	cvtColor(src,gray_src,COLOR_BGR2GRAY);
	//二值化
	threshold(gray_src, gray_src_2, threshold_value, threshold_max, type_value);
	imshow("2gray_image",gray_src_2);
	
	//高斯模糊	
	GaussianBlur(gray_src, gblur, Size(9, 9), 11, 11);
	//imshow("guassian blur", gblur);

	//边缘检测
	Canny(gblur, edge_output, t1_value, t1_value * 2, 3, false);
	imshow("output image", edge_output);

	Rect rect(252,32, 916,252);
	ROI = src(rect);

    int length, i, j;
	const uchar* ptr = gray_src_2.ptr<uchar>(gray_src_2.rows/2);//固定列的数组
	for (i = 0; i < gray_src_2.cols; i++) {
		if (ptr[i]<100)break;
	}
	for (j = gray_src_2.cols; j > i; j--) {
		if (ptr[j] < 100)break;
	}
	length = j - i;
	printf("%d\n",length);//检测出瓶子的长度
	
	int width,a, b;
	for (a = 0; a< gray_src_2.rows; a++) {
		if (gray_src_2.at<uchar>(a,gray_src_2.cols/3) < 100)//固定行的数组
			break;
	}
	for (b = gray_src_2.rows-1; b > a; b--) {
		if (gray_src_2.at<uchar>( b,gray_src_2.cols/3) < 100)break;
	}
	width = b-a;
	printf("%d\n", width);//检测出瓶子的宽度

	//putText(ROI,length, Point(1046, 130), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.5, Scalar(12, 25, 200), 1, 8);
	imshow("ROI", ROI);

	//画直线
	//MyLines();
	Point p1 = Point(252, 156);
	Point p2;
	p2.x = 1167;
	p2.y = 156;
	Scalar color = Scalar(0, 0, 255);
	line(src, p1, p2, color, 1, LINE_AA);

	Point p3 = Point(1146, 68);
	Point p4;
	p4.x = 1146;
	p4.y =251;
	Scalar color_0 = Scalar(0, 0, 255);
	line(src, p3, p4, color, 1, LINE_AA);

	Point p5 = Point(1124, 256);
	Point p6;
	p6.x = 1159;
	p6.y = 256;
	Scalar color_1 = Scalar(0, 0, 255);
	line(src, p5, p6, color, 1, LINE_AA);

	Point p7 = Point(1124, 250);
	Point p8;
	p8.x = 1124;
	p8.y = 262;
	Scalar color_2 = Scalar(0, 0, 255);
	line(src, p7, p8, color, 1, LINE_AA);

	Point p9 = Point(1159, 250);
	Point p10;
	p10.x = 1159;
	p10.y = 262;
	Scalar color_3 = Scalar(0, 0, 255);
	line(src, p9, p10, color, 1, LINE_AA);
	//标长度FONT_HERSHEY_SCRIPT_SIMPLEX/FONT_HERSHEY_COMPLEX
	putText(src, "915", Point(650, 148), FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, Scalar(12, 25, 200),2, 8);
	putText(src, "35", Point(1132, 270), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.5, Scalar(12, 25, 200), 1, 8);
	putText(src, "183", Point(1146, 130), FONT_HERSHEY_SCRIPT_SIMPLEX, 0.5, Scalar(12, 25, 200), 1, 8);
	imshow("output image", src);
	imwrite("homework2.jpg",src);
	int LENGTHLOG = src.rows / 2;
	waitKey(0);
	return 0;
}

ohheiheihei
