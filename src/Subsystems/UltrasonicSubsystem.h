/*
 * Ultrasonic.h
 *
 *  Created on: Feb 27, 2017
 *      Author: programmer
 */

#include "Commands/Subsystem.h"
#include "WPILib.h"

#ifndef SRC_SUBSYSTEMS_ULTRASONICSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_ULTRASONICSUBSYSTEM_H_

class UltrasonicSubsystem: public Subsystem {
public:
	std::shared_ptr<Ultrasonic> ultrasonic;

	UltrasonicSubsystem();
	void InitDefaultCommand();
	void GetRange();
	void Reset();
};

#endif /* SRC_SUBSYSTEMS_ULTRASONIC_H_ */
