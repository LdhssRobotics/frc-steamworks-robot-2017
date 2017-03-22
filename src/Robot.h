/*
 * Robot.h
 *
 *  Created on: Feb 7, 2017
 *      Author: programmer
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// Vision includes
#include <thread>
#include <CameraServer.h>

// Autonomous mode includes
#include "Commands/AutoModes/Blue1AutoMode.h"
#include "Commands/AutoModes/Blue2AutoMode.h"
#include "Commands/AutoModes/Blue3AutoMode.h"
#include "Commands/AutoModes/Red1AutoMode.h"
#include "Commands/AutoModes/Red2AutoMode.h"
#include "Commands/AutoModes/Red3AutoMode.h"

// Subsystem includes
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Gear.h"
#include "Subsystems/UltrasonicSubsystem.h"

#include "OI.h"


class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	static std::shared_ptr<Climber> climber;
	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<Gear> gear;
	static std::shared_ptr<UltrasonicSubsystem> ultrasonicSubsystem;

	static void VisionThread();
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

#endif /* SRC_ROBOT_H_ */
