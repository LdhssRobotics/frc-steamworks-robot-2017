/*
 * testingReset.h
 *
 *  Created on: Feb 14, 2017
 *      Author: programmer
 */

#ifndef SRC_COMMANDS_TESTINGRESET_H_
#define SRC_COMMANDS_TESTINGRESET_H_

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"


class testingReset: public Command {
public:
	testingReset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TESTINGRESET_H_ */
