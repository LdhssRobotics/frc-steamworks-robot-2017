/*
 * BallIntake.h
 *
 *  Created on: Feb 8, 2017
 *      Author: programmer
 */

#ifndef SRC_SUBSYSTEMS_BALLINTAKE_H_
#define SRC_SUBSYSTEMS_BALLINTAKE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
// Testing
class BallIntake: public Subsystem {
private:
	std::shared_ptr<SpeedController> ballIntakeMotor;
	std::shared_ptr<Servo> ballIntakeServo;

public:
	BallIntake();
	void InitDefaultCommand();
};

#endif /* SRC_SUBSYSTEMS_BALLINTAKE_H_ */
