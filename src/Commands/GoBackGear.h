/*
 * GoBackGear.h

 *
 *  Created on: Feb 16, 2017
 *      Author: Mariam
 */

#ifndef SRC_COMMANDS_GOBACKGEAR_H_
#define SRC_COMMANDS_GOBACKGEAR_H_

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"
#include "Commands/Subsystem.h"

class GoBackGear : public Command {

public:
	GoBackGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_GOBACKGEAR_H_ */
