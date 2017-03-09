#include "Vision.h"
#include "../RobotMap.h"

using namespace cv;
using namespace std;

Vision::Vision() : Subsystem("Vision") {
}

void Vision::process(cv::Mat source) {
	// Resize image
	cv::Mat resizeImageInput = source;
	double resizeImageWidth = 160.0;  // default Double
	double resizeImageHeight = 120.0;  // default Double
	int resizeImageInterpolation = cv::INTER_CUBIC;
	resizeImage(resizeImageInput, resizeImageWidth, resizeImageHeight, resizeImageInterpolation, this->resizeImageOutput);

	// CV dilate
	cv::Mat cvDilateSrc = resizeImageOutput;
	cv::Mat cvDilateKernel;
	cv::Point cvDilateAnchor(-1, -1);
	double cvDilateIterations = 1.0;  // default Double
	int cvDilateBordertype = cv::BORDER_CONSTANT;
	cv::Scalar cvDilateBordervalue(-1);
	cvDilate(cvDilateSrc, cvDilateKernel, cvDilateAnchor, cvDilateIterations, cvDilateBordertype, cvDilateBordervalue, this->cvDilateOutput);

	// HSL threshold
	cv::Mat hslThresholdInput = cvDilateOutput;
	double hslThresholdHue[] = {73.27635073338668, 102.39986158206233};
	double hslThresholdSaturation[] = {38.05970262680481, 255.0};
	double hslThresholdLuminance[] = {32.44927561423205, 240.49488607933904};
	hslThreshold(hslThresholdInput, hslThresholdHue, hslThresholdSaturation, hslThresholdLuminance, this->hslThresholdOutput);

	// Find contours
	cv::Mat findContoursInput = hslThresholdOutput;
	bool findContoursExternalOnly = false;  // default Boolean
	findContours(findContoursInput, findContoursExternalOnly, this->findContoursOutput);

	// Filter contours
	std::vector<std::vector<cv::Point> > filterContoursContours = findContoursOutput;
	double filterContoursMinArea = 25.0;  // default Double
	double filterContoursMinPerimeter = 0.0;  // default Double
	double filterContoursMinWidth = 1.0;  // default Double
	double filterContoursMaxWidth = 1000.0;  // default Double
	double filterContoursMinHeight = 9.0;  // default Double
	double filterContoursMaxHeight = 1000.0;  // default Double
	double filterContoursSolidity[] = {0.0, 100.0};
	double filterContoursMaxVertices = 1.0E7;  // default Double
	double filterContoursMinVertices = 0.0;  // default Double
	double filterContoursMinRatio = 0.0;  // default Double
	double filterContoursMaxRatio = 1000.0;  // default Double
	filterContours(filterContoursContours, filterContoursMinArea, filterContoursMinPerimeter, filterContoursMinWidth, filterContoursMaxWidth, filterContoursMinHeight, filterContoursMaxHeight, filterContoursSolidity, filterContoursMaxVertices, filterContoursMinVertices, filterContoursMinRatio, filterContoursMaxRatio, this->filterContoursOutput);

	// Get the edges using canny
	Canny(hslThresholdOutput, cannyOutput, thresh, thresh*2, 3);

	// Get the moments
	vector<Moments> mu(filterContoursOutput.size());
	for (int i = 0; i < filterContoursOutput.size(); i++) {
		mu[i] = moments(filterContoursOutput[i], false);
	}

	// Get the mass centres
	std::vector<cv::Point2f> mc(filterContoursOutput.size());
	for (int i = 0; i < filterContoursOutput.size(); i++) {
		mc[i] = Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
	}

	// Get the x-coordinates
	x1 = mc[1].x;
	x2 = mc[2].x;

	// Draw the contours
	Mat drawing = Mat::zeros(cannyOutput.size(), CV_8UC3);
	for (int i = 0; i < filterContoursOutput.size(); i++) {
		Scalar colour = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, filterContoursOutput, i, colour, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, colour, -1, 8, 0);
	}
}

short Vision::findTarget() {
	// Make sure the x-coordinates are correct
	frc::SmartDashboard::PutNumber("x1", x1);
	frc::SmartDashboard::PutNumber("x2", x2);

	int xAvg = (x1 + x2) / 2;
	if ((xAvg + 10) > xCentre || (xAvg - 10) < xCentre) {
		// On target
		return 0;
	} else if (xAvg < xCentre) {
		// Need to turn left
		return -1;
	}
	// Need to turn right
	return 1;
}

cv::Mat Vision::returnOutput() {
	return drawing;
}

cv::Mat Vision::getresizeImageOutput() {
	return resizeImageOutput;
}

cv::Mat Vision::getcvDilateOutput() {
	return cvDilateOutput;
}

cv::Mat Vision::gethslThresholdOutput() {
	return hslThresholdOutput;
}

std::vector<std::vector<cv::Point> > Vision::getfindContoursOutput() {
	return findContoursOutput;
}

std::vector<std::vector<cv::Point> > Vision::getfilterContoursOutput() {
	return filterContoursOutput;
}

/**
 * Scales and image to an exact size.
 *
 * @param input The image on which to perform the Resize.
 * @param width The width of the output in pixels.
 * @param height The height of the output in pixels.
 * @param interpolation The type of interpolation.
 * @param output The image in which to store the output.
 */
void Vision::resizeImage(cv::Mat &input, double width, double height, int interpolation, cv::Mat &output) {
	cv::resize(input, output, cv::Size(width, height), 0.0, 0.0, interpolation);
}

/**
 * Expands area of higher value in an image.
 * @param src the Image to dilate.
 * @param kernel the kernel for dilation.
 * @param anchor the center of the kernel.
 * @param iterations the number of times to perform the dilation.
 * @param borderType pixel extrapolation method.
 * @param borderValue value to be used for a constant border.
 * @param dst Output Image.
 */
void Vision::cvDilate(cv::Mat &src, cv::Mat &kernel, cv::Point &anchor, double iterations, int borderType, cv::Scalar &borderValue, cv::Mat &dst) {
	cv::dilate(src, dst, kernel, anchor, (int)iterations, borderType, borderValue);
}

/**
 * Segment an image based on hue, saturation, and luminance ranges.
 *
 * @param input The image on which to perform the HSL threshold.
 * @param hue The min and max hue.
 * @param sat The min and max saturation.
 * @param lum The min and max luminance.
 * @param output The image in which to store the output.
 */
//void hslThreshold(Mat *input, double hue[], double sat[], double lum[], Mat *out) {
void Vision::hslThreshold(cv::Mat &input, double hue[], double sat[], double lum[], cv::Mat &out) {
	cv::cvtColor(input, out, cv::COLOR_BGR2HLS);
	cv::inRange(out, cv::Scalar(hue[0], lum[0], sat[0]), cv::Scalar(hue[1], lum[1], sat[1]), out);
}

/**
 * Finds contours in an image.
 *
 * @param input The image to find contours in.
 * @param externalOnly if only external contours are to be found.
 * @param contours vector of contours to put contours in.
 */
void Vision::findContours(cv::Mat &input, bool externalOnly, std::vector<std::vector<cv::Point> > &contours) {
	contours.clear();
	int mode = externalOnly ? cv::RETR_EXTERNAL : cv::RETR_LIST;
	int method = cv::CHAIN_APPROX_SIMPLE;
	cv::findContours(input, contours, hierarchy, mode, method);
}


/**
 * Filters through contours.
 * @param inputContours is the input vector of contours.
 * @param minArea is the minimum area of a contour that will be kept.
 * @param minPerimeter is the minimum perimeter of a contour that will be kept.
 * @param minWidth minimum width of a contour.
 * @param maxWidth maximum width.
 * @param minHeight minimum height.
 * @param maxHeight  maximimum height.
 * @param solidity the minimum and maximum solidity of a contour.
 * @param minVertexCount minimum vertex Count of the contours.
 * @param maxVertexCount maximum vertex Count.
 * @param minRatio minimum ratio of width to height.
 * @param maxRatio maximum ratio of width to height.
 * @param output vector of filtered contours.
 */
void Vision::filterContours(std::vector<std::vector<cv::Point> > &inputContours, double minArea, double minPerimeter, double minWidth, double maxWidth, double minHeight, double maxHeight, double solidity[], double maxVertexCount, double minVertexCount, double minRatio, double maxRatio, std::vector<std::vector<cv::Point> > &output) {
	std::vector<cv::Point> hull;
	output.clear();
	for (std::vector<cv::Point> contour: inputContours) {
		cv::Rect bb = boundingRect(contour);
		if (bb.width < minWidth || bb.width > maxWidth) continue;
		if (bb.height < minHeight || bb.height > maxHeight) continue;
		double area = cv::contourArea(contour);
		if (area < minArea) continue;
		if (arcLength(contour, true) < minPerimeter) continue;
		cv::convexHull(cv::Mat(contour, true), hull);
		double solid = 100 * area / cv::contourArea(hull);
		if (solid < solidity[0] || solid > solidity[1]) continue;
		if (contour.size() < minVertexCount || contour.size() > maxVertexCount)	continue;
		double ratio = bb.width / bb.height;
		if (ratio < minRatio || ratio > maxRatio) continue;
		output.push_back(contour);
	}
}
