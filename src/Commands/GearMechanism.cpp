#include "GearMechanism.h"
#include "Commands/PlaceGear.h"
#include "Commands/GoBackGear.h"

GearMechanism::GearMechanism() {
	AddSequential(new PlaceGear());
	Wait(2);
	AddSequential(new GoBackGear(2));
}
