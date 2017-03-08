/*
 * Ultrasonic.h
 *
 *  Created on: Feb 22, 2017
 *      Author: programmer
 */

#ifndef SRC_SUBSYSTEMS_ULTRASONIC_H_
#define SRC_SUBSYSTEMS_ULTRASONIC_H_

#include "Commands/Subsystem.h"
#include"WPILib.h"

class Ultrasonic : public Subsystem {

private:
	std:: shared_ptr<DigitalInput> echo;
	std:: shared_ptr<DigitalOutput> trigger;

public:
	 Ultrasonic(std::shared_ptr<DigitalOutput> pingChannel,
	             std::shared_ptr<DigitalInput> echoChannel);

	int GetDistance();

};



#endif /* SRC_SUBSYSTEMS_ULTRASONIC_H_ */
