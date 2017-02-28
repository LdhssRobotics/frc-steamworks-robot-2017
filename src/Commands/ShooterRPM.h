#ifndef ShooterRPM_H
#define ShooterRPM_H

#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"
#include "Commands/Subsystem.h"

class ShooterRPM : public Command {
public:
	ShooterRPM();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShooterRPM_H
