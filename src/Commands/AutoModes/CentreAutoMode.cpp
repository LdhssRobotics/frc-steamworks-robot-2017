#include <Commands/AutoModes/CentreAutoMode.h>
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"
#include "../ToggleFrontEnd.h"

CentreAutoMode::CentreAutoMode() {
	// Deliver a gear
	AddParallel(new ToggleFrontEnd());
	AddSequential(new DriveDistance(40.307));
	AddSequential(new GearMechanism());
}
