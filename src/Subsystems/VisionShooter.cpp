/*
 * VisionShooter.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: programmer
 */

double VisionShooter:: distanceToTargetL(double l){
	return ((1.62log(l-52))/0.305)-11;
}

double VisionShooter:: distanceToTargetW(double w){
	return ((1.7log(w-44.786))/0.25)-86;
}

double VisionShooter:: avgDistance(double dL, double dW){
	return (dL+dW)/2;
}

double VisionShooter:: centering(double x1, double x2, double xc){
	return xc-((x1-x2)/2)-x1;
}

/* double distanceToTargetL(double l){
	return ((1.62log(l-52))/0.305)-11;
}

double distanceToTargetW(double w){
	return ((1.7log(w-44.786))/0.25)-86;
}

double avgDistance(double dL, double dW){
	return (dL+dW)/2;
}

double centering(double x1, double x2, double xc){
	return xc-((x1-x2)/2)-x1;
}*/

double length = 56;
double width = 0;
double distanceL;
double distanceW;

