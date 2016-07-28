#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat img1, img2, g1, g2;
	Mat disp, disp8;
	
	 VideoCapture cap1(0);
	 VideoCapture cap2(1);
	 namedWindow("right", CV_WINDOW_AUTOSIZE);
	 namedWindow("left", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		cap1.read(img1);
		cap2.read(img2);

		cvtColor(img1, g1, CV_BGR2GRAY);
		cvtColor(img2, g2, CV_BGR2GRAY);*/

		StereoSGBM sbm;
		sbm.SADWindowSize = 3;
		sbm.numberOfDisparities = 16*3;
		sbm.preFilterCap = 100;
		sbm.minDisparity = 5;
		sbm.uniquenessRatio = 0;
		sbm.speckleWindowSize = 10;
		sbm.speckleRange = 2;
		sbm.disp12MaxDiff = 5;
		sbm.fullDP = true;
		sbm.P1 = 600;
		sbm.P2 = 2400;
		sbm(img1, img2, disp);



		normalize(disp, disp8, 0, 255, CV_MINMAX, CV_8U);
		imshow("left", img1);
		imshow("right", img2);
		imshow("disp", disp8);

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
		waitKey(0);
	}
return(0);
}