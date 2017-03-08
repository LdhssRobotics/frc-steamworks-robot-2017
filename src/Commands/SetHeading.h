#ifndef SetHeading_H
#define SetHeading_H

#include "../Robot.h"
#include "WPILib.h"

class SetHeading: public Command
{
private:
	double desHeading;

public:

	SetHeading(float heading);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};


#endif

