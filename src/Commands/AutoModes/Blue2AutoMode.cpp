#include "Blue2AutoMode.h"
#include "../DriveDistance.h"
#include "../SetHeading.h"
#include "../GearMechanism.h"

Blue2AutoMode::Blue2AutoMode() {
	AddSequential(new DriveDistance(-93.307));
	AddSequential(new GearMechanism());
	AddSequential(new DriveDistance(20));
}
