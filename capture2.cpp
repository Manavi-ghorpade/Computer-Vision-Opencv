#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("/home/manavi/Documents/ass6/que5_video_output.mp4");
	if (!cap.isOpened())
        {
            cout<<"No camera or video input!\n"<<endl;
            return -1;
        }
 
    string window_name = "My Camera Feed";
    namedWindow(window_name,WINDOW_NORMAL); //create a window called "My Camera Feed"
    resizeWindow("My Camera Feed",640,480);
    int n = 1;
    while (true)
    {
	Mat frame;
	Mat thr;
        cap>>frame; // read a new frame from the video camera	
	threshold(frame, thr, 127, 255, THRESH_BINARY );
	vector<vector<int>> vec;
	Scalar intensity ;
	for(int i=0; i<=frame.rows; i++) //for loops to get every pixel of frame
	{
  		for(int j=0; j<=frame.cols; j++) 
		{	
			int val = frame.at<Vec3b>(i,j)[0];
			if(val==255) //if the pixel intesity is equal to 255, then store the co=ordinates of pixel in the vector of vector.
			{
				vector<int> v1;
				v1.push_back(i);
				v1.push_back(j);
				vec.push_back(v1);
			}
		}
	}
	int xleft=1920;
	for(int i = 0; i<vec.size(); ++i)//for loop to get the xleft value(minimum value of x)
	{
			if(vec[i][0]<xleft)
			{
				xleft = vec[i][0];
			}		
	}	
	int ytop=1920;
	for(int i = 0; i<vec.size(); ++i)//for loop to get the ytop value(minimum value of y)
	{
			if(vec[i][1]<ytop)
			{
				ytop = vec[i][1];
			}		
	}	
	int xright=0;
	for(int i = 0; i<vec.size(); ++i)//for loop to get the xright value(maximum value of x)
	{
			if(vec[i][0]>xright)
			{
				xright = vec[i][0];
			}		
	}	
	int ybottom=0;
	for(int i = 0; i<vec.size(); ++i)//for loop to get the ybottom value(maximum value of y)
	{
			if(vec[i][1]>ybottom)
			{
				ybottom = vec[i][1];
			}		
	}	
	vector<Mat> rgb;//vector to spit the frame in rbg
	split(thr,rgb);
	double Ybar = (ybottom-ytop)/2 + ytop;//calculation of Ybar
	double Xbar = (xright-xleft)/2 + xleft;//calculation of Xbar
	Point p(Ybar, Xbar);//creating a point on Ybar and Xbar
	drawMarker(rgb[1],p, Scalar(255,255,255),MARKER_CROSS,50,5);//drawing a crosshair marker on the centroid of the laser spot
	string name = "/home/manavi/Documents/ass6/frames/" + std::to_string(n) + ".pgm";
	imwrite(name,rgb[1]);// wrote the images in a folder to covert it into video frame
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
	n+=1;//counter to store the each frame in sequence
    }   
    return 0;
}
