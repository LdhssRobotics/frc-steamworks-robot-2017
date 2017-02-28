/*
 * Ultrasonic.h
 *
 *  Created on: Feb 27, 2017
 *      Author: programmer
 */

#include "Commands/Subsystem.h"
#include "WPILib.h"

#ifndef SRC_SUBSYSTEMS_ULTRASONIC_H_
#define SRC_SUBSYSTEMS_ULTRASONIC_H_

class Ultrasonic {
public:
	Ultrasonic();
	//virtual ~Ultrasonic();
	void GetRange();
	void Reset();
};

#endif /* SRC_SUBSYSTEMS_ULTRASONIC_H_ */
