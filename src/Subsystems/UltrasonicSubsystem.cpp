/*
 * UltrasonicSystem.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: programmer
 */

#include <Subsystems/UltrasonicSubsystem.h>
#include <Subsystems/UltrasonicSubsystem.h>
#include "Commands/GetUltrasonic.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

UltrasonicSubsystem::UltrasonicSubsystem(): Subsystem ("UltrasonicSubsystem"){
	ultrasonic = RobotMap::ultrasonic;

}

void UltrasonicSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new GetUltrasonic());
}

void UltrasonicSubsystem::GetRange(){
	SmartDashboard::PutNumber("Distance-inches", ultrasonic->GetRangeInches());
	SmartDashboard::PutNumber("Distance-feet ",(ultrasonic->GetRangeInches())*0.0833333);
}

void UltrasonicSubsystem::Reset(){
}
