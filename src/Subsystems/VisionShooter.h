/*
 * VisionShooter.h
 *
 *  Created on: Feb 13, 2017
 *      Author: programmer
 */

#ifndef SRC_SUBSYSTEMS_VISIONSHOOTER_H_
#define SRC_SUBSYSTEMS_VISIONSHOOTER_H_

#include <math.h>
#include <stdio.h>
#include <sstream>
#include <iostream>


class VisionShooter: public Subsystem {

public:
	VisionShooter();
	double distanceToTargetL( double l);
	double distanceToTargetW( double w);
	double avgDistance( double dL, double dW);
	double centering(double x1, double x2, double xc);
	void Reset();
};

#endif /* SRC_SUBSYSTEMS_VISIONSHOOTER_H_ */
