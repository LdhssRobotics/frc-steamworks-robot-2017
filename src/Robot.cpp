#include "Robot.h"

std::shared_ptr<BallIntake> Robot::ballIntake;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<UltrasonicSubsystem> Robot::ultrasonicSubsystem;
std::shared_ptr<Vision> Robot::vision;

#include "Commands/ToggleReverseDrive.h"

void Robot::VisionThread() {
	if (Robot::vision->gearIsFront) {
		cs::UsbCamera frontCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
		frontCamera.SetResolution(160, 120);
	} else {
		cs::UsbCamera backCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
		backCamera.SetResolution(160, 120);
	}
}

void Robot::RobotInit() {
	RobotMap::init();

	ballIntake.reset(new BallIntake());
	climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
	gear.reset(new Gear());
	shooter.reset(new Shooter());
	ultrasonicSubsystem.reset(new UltrasonicSubsystem());
	vision.reset(new Vision());

	oi.reset(new OI());

	// We need to run our vision program in a separate Thread.
	// If not, our robot program will not run
	std::thread visionThread(VisionThread);
	visionThread.detach();

	chooser.AddDefault("Blue 1", new Blue1AutoMode());
	chooser.AddObject("Blue 2", new Blue2AutoMode());
	chooser.AddObject("Blue 3", new Blue3AutoMode());
	chooser.AddObject("Red 1", new Red1AutoMode());
	chooser.AddObject("Red 2", new Red2AutoMode());
	chooser.AddObject("Red 3", new Red3AutoMode());
	SmartDashboard::PutData("Auto Modes:", &chooser);
}

void Robot::DisabledInit() {
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(chooser.GetSelected());
	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Cancel();
	}

	// Reverse drive to show SmartDashboard
	ToggleReverseDrive();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
