#include <Commands/AutoModes/CentreAutoMode.h>
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"
#include "../ToggleFrontEnd.h"

CentreAutoMode::CentreAutoMode() {
	AddParallel(new ToggleFrontEnd());
	AddSequential(new DriveDistance(40.307));
	//AddSequential(new GearMechanism());
	//AddSequential(new DriveDistance(-20));
}
