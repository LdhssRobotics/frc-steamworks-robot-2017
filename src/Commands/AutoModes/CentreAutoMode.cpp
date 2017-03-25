#include <Commands/AutoModes/CentreAutoMode.h>
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"

CentreAutoMode::CentreAutoMode() {
	AddSequential(new DriveDistance(-93.307));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(20));
}
