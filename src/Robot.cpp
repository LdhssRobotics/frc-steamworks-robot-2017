#include "Robot.h"

std::shared_ptr<BallIntake> Robot::ballIntake;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Gear> Robot::gear;
std::shared_ptr<Shooter> Robot::shooter;
std::unique_ptr<OI> Robot::oi;

void Robot::VisionThread() {
	// Get the USB camera from CameraServer
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
		// Set the resolution
		camera.SetResolution(640, 480);

		// Get a CvSink. This will capture Mats from the Camera
		cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
		// Setup a CvSource. This will send images back to the Dashboard
		cs::CvSource outputStream = CameraServer::GetInstance()->
				PutVideo("Rectangle", 640, 480);

		// Mats are very memory expensive. Let's reuse this Mat.
		cv::Mat mat;

		while (true) {
			// Tell the CvSink to grab a frame from the camera and put it
			// in the source mat.  If there is an error notify the output.
			if (cvSink.GrabFrame(mat) == 0) {
				// Send the output the error.
				outputStream.NotifyError(cvSink.GetError());
				// skip the rest of the current iteration
				continue;
			}
			// Put a rectangle on the image
			rectangle(mat, cv::Point(100, 100), cv::Point(400, 400),
					cv::Scalar(255, 255, 255), 5);
			// Give the output stream a new image to display
			outputStream.PutFrame(mat);
		}
}

void Robot::RobotInit() {
	// Initialize the speed controllers and sensors
	RobotMap::init();

	// Initialize the subsystems
	ballIntake.reset(new BallIntake());
	climber.reset(new Climber());
	drivetrain.reset(new Drivetrain());
	gear.reset(new Gear());
	shooter.reset(new Shooter());
	oi.reset(new OI());

	// The different autonomous modes, blue 1 will be selected by default
	chooser.AddDefault("Blue 1", new Blue1AutoMode());
	chooser.AddObject("Blue 2", new Blue2AutoMode());
	chooser.AddObject("Blue 3", new Blue3AutoMode());
	chooser.AddObject("Red 1", new Red1AutoMode());
	chooser.AddObject("Red 2", new Red2AutoMode());
	chooser.AddObject("Red 3", new Red3AutoMode());
	SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit() {
	// Reset all the subsystems (ex. moving servos)
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
