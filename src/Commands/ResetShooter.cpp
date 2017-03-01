#include "ResetShooter.h"
#include "CloseBlocker.h"
#include "StopShooters.h"

ResetShooter::ResetShooter()
{
	AddSequential(new CloseBlocker());
	AddSequential(new StopShooters());
	//Super Minty Texturizing Program
}
