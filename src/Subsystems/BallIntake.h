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

class BallIntake: public Subsystem {
private:
	std::shared_ptr<SpeedController> ballIntakeMotor;

public:
	BallIntake();
	void Reset();
	void SetIntakeSpeed(float speed);
	void ReverseIntakeSpeed(float speed);
	void Stop();
	void Log(float intakeSpeed);
};

#endif /* SRC_SUBSYSTEMS_BALLINTAKE_H_ */
