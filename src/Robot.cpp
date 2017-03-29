#include "Robot.h"

std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Gear> Robot::gear;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<UltrasonicSubsystem> Robot::ultrasonicSubsystem;

cs::UsbCamera gearCamera;
cs::UsbCamera climberCamera;
cs::VideoSink server;

void Robot::VisionThread() {
	climberCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	climberCamera.SetResolution(160, 120);

	// Gear camera must be 1 because 0 is overloaded by server
	gearCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
	gearCamera.SetResolution(160, 120);

	// By default, overloads camera 0 stream
	server = CameraServer::GetInstance()->GetServer();

	// cscore disconnects any cameras not in use so dummy
	// cvSinks are created to keep the camera connected
	// This reduces lag when switching between cameras
	cs::CvSink gearCvSink;
	gearCvSink.SetSource(gearCamera);
	gearCvSink.SetEnabled(true);

	cs::CvSink climberCvSink;
	climberCvSink.SetSource(climberCamera);
	climberCvSink.SetEnabled(true);
}

void Robot::RobotInit() {
	// We need to run our vision program in a separate Thread.
	// If not, our robot program will not run
	std::thread visionThread(VisionThread);
	visionThread.detach();

	// Build components (motors, sensors, etc.)
	RobotMap::init();

	// Build subsystems
	climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
	gear.reset(new Gear());
	ultrasonicSubsystem.reset(new UltrasonicSubsystem());

	// Must be built last
	oi.reset(new OI());

	// Select the autonomous mode using SmartDashboard
	chooser.AddDefault("Left Auto Mode", new LeftAutoMode());
	chooser.AddObject("Centre Auto Mode", new CentreAutoMode());
	chooser.AddObject("Right Auto Mode", new RightAutoMode());
}

void Robot::DisabledInit() {
	// Reset sensors when robot is disabled
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	// Get the selected autonomous mode
	autonomousCommand.reset(chooser.GetSelected());

	if (autonomousCommand != nullptr) {
		autonomousCommand->Start();
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

	// Checks which side is at the front to determine which camera stream to display
	if (Robot::drivetrain->isGearFront) {
		server.SetSource(gearCamera);
	} else {
		server.SetSource(climberCamera);
	}
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
