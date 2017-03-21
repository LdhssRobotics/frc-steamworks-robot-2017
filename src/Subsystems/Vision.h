#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision : public Subsystem {
public:
	bool gearIsFront;

	Vision();
};

#endif  // Vision_H
