#include "Robot.h"

std::shared_ptr<BallIntake> Robot::ballIntake;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<UltrasonicSubsystem> Robot::ultrasonicSubsystem;

void Robot::RobotInit() {
	RobotMap::init();

	ballIntake.reset(new BallIntake());
	climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
	gear.reset(new Gear());
	shooter.reset(new Shooter());
	oi.reset(new OI());
	ultrasonicSubsystem.reset(new UltrasonicSubsystem());

	chooser.AddDefault("Blue 1", new Blue1AutoMode());
	chooser.AddObject("Blue 2", new Blue2AutoMode());
	chooser.AddObject("Blue 3", new Blue3AutoMode());
	chooser.AddObject("Red 1", new Red1AutoMode());
	chooser.AddObject("Red 2", new Red2AutoMode());
	chooser.AddObject("Red 3", new Red3AutoMode());
	SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit() {
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(chooser.GetSelected());
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
