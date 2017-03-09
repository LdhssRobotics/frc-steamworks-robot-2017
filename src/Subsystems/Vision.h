#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

class Vision : public Subsystem {
private:
	int thresh = 100;
	int max_thresh = 255;
	cv::RNG rng;

	std::vector<cv::Vec4i> hierarchy;
	cv::Mat drawing;
	cv::Mat cannyOutput;
	cv::Mat resizeImageOutput;
	cv::Mat cvDilateOutput;
	cv::Mat hslThresholdOutput;
	std::vector<std::vector<cv::Point> > findContoursOutput;
	std::vector<std::vector<cv::Point> > filterContoursOutput;
	void resizeImage(cv::Mat &, double , double , int , cv::Mat &);
	void cvDilate(cv::Mat &, cv::Mat &, cv::Point &, double , int , cv::Scalar &, cv::Mat &);
	void hslThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
	void findContours(cv::Mat &, bool , std::vector<std::vector<cv::Point> > &);
	void filterContours(std::vector<std::vector<cv::Point> > &, double , double , double , double , double , double , double [], double , double , double , double , std::vector<std::vector<cv::Point> > &);

public:
	cs::UsbCamera gearCamera;

	Vision();
	void process(cv::Mat source);
	cv::Mat getresizeImageOutput();
	cv::Mat getcvDilateOutput();
	cv::Mat gethslThresholdOutput();
	std::vector<std::vector<cv::Point> > getfindContoursOutput();
	std::vector<std::vector<cv::Point> > getfilterContoursOutput();
	cv::Mat returnOutput();
};

#endif  // Vision_H
