#ifndef ToggleBallIntake_H
#define ToggleBallIntake_H

#include "Commands/Command.h"
#include "WPILib.h"

class ToggleBallIntake : public Command {
private:
	float intakeSpeed;

public:
	static const float INTAKE_SPEED;
	static const float REVERSEINTAKE_SPEED;

	ToggleBallIntake(float speed);
	void Initialize();
//	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleBallIntake_H
