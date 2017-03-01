#ifndef GetUltrasonic_H
#define GetUltrasonic_H

#include "../RobotMap.h"
#include "WPILib.h"
#include "../Robot.h"

class GetUltrasonic : public Command {
public:
	GetUltrasonic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetUltrasonic_H
