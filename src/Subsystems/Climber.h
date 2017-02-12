/*
 * Climber.h
 *
 *  Created on: Feb 8, 2017
 *      Author: programmer
 */

#ifndef SRC_SUBSYSTEMS_CLIMBER_H_
#define SRC_SUBSYSTEMS_CLIMBER_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber: public Subsystem {
private:
	std::shared_ptr<SpeedController> winchMotor;
	std::shared_ptr<Servo> rachetServo;

public:
	Climber();
	void SetWinchSpeed(float speed);
	void SetRachet(float position);
	void StartClimb();
	void StopClimb();
	void Reset();
};

#endif /* SRC_SUBSYSTEMS_CLIMBER_H_ */
