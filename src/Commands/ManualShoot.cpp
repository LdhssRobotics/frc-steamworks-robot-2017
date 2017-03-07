#include "ManualShoot.h"
#include "StartShooters.h"
#include "OpenBlocker.h"

ManualShoot::ManualShoot()
{
	AddSequential(new StartShooters());
	AddSequential(new OpenBlocker());
}
