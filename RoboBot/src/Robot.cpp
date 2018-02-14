#include "Robot.h"

std::shared_ptr<Drive_Train>  Robot::drive_Train;
std::shared_ptr<Pneumatic>    Robot::pneumatic;
std::shared_ptr<Transmission> Robot::transmission;
std::shared_ptr<Intake>       Robot::intake;
std::shared_ptr<Shooter>	  Robot::shooter;
std::unique_ptr<OI>           Robot::oi;

void Robot::RobotInit()
{
	RobotMap::init();

// BALLARD RECOMMENDATION
	AllianceSwitch = PL_UNSET;
	Scale          = PL_UNSET;
	OpposingSwitch = PL_UNSET;
// BALLARD RECOMMENDATION END

    drive_Train.reset(new Drive_Train());
    pneumatic.reset(new Pneumatic());
    transmission.reset(new Transmission());
    shooter.reset(new Shooter());
    intake.reset(new Intake());

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	CameraServer::GetInstance()->StartAutomaticCapture();

	// Add commands to Autonomous Sendable Chooser
	//chooser.AddObject("Baseline_Timed_Auto", new Baseline_Timed_Auto());
	chooser.AddDefault("Autonomous Command", new AutonomousCommand());

	frc::SmartDashboard::PutData("Auto Modes", &chooser);

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
// BALLARD RECOMMENDATION
	Update_GameData();
// BALLARD RECOMMENDATION END
}

// BALLARD RECOMMENDATION
void Robot::Update_GameData()
{
	// Description of Game Data details can be found:
	// http://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details

	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	if (!gameData.empty())
	{
		if (gameData[0] == 'L')
		{
			AllianceSwitch = PL_LEFT;
		} else if (gameData[0] == 'R')
		{
			AllianceSwitch = PL_RIGHT;
		} else
		{
			AllianceSwitch = PL_UNSET;
		}

		if (gameData[1] == 'L')
		{
			Scale = PL_LEFT;
		} else if (gameData[1] == 'R')
		{
			Scale = PL_RIGHT;
		} else
		{
			Scale = PL_UNSET;
		}

		if (gameData[2] == 'L')
		{
			OpposingSwitch = PL_LEFT;
		} else if (gameData[2] == 'R')
		{
			OpposingSwitch = PL_RIGHT;
		} else
		{
			OpposingSwitch = PL_UNSET;
		}

		if (AllianceSwitch!=PL_UNSET)
		{
			SmartDashboard::PutString("AllianceSwitch", (AllianceSwitch == PL_LEFT) ? "Left" : "Right");
		}
		else
		{
			SmartDashboard::PutString("AllianceSwitch", "Not Set");
		}

		if (Scale!=PL_UNSET)
		{
			SmartDashboard::PutString("Scale", (Scale == PL_LEFT) ? "Left" : "Right");
		}
		else
		{
			SmartDashboard::PutString("Scale", "Not Set");
		}

		if (OpposingSwitch != PL_UNSET)
		{
			SmartDashboard::PutString("OpposingSwitch", (OpposingSwitch == PL_LEFT) ? "Left" : "Right");
		}
		else
		{
			SmartDashboard::PutString("OpposingSwitch","Not Set");
		}
	}
}
// BALLARD RECOMMENDATION END


void Robot::AutonomousInit()
{
// BALLARD RECOMMENDATION
	if ((AllianceSwitch == PL_UNSET) || (Scale == PL_UNSET)) Update_GameData();
// BALLARD RECOMMENDATION END

	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}



START_ROBOT_CLASS(Robot);

