#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Baseline_Timed_Auto.h"
#include "Subsystems/Drive_Train.h"
#include "Subsystems/Pneumatic.h"
#include "Subsystems/Transmission.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "OI.h"

// BALLARD RECOMMENDATION
enum PlateLocation
{
	PL_UNSET = 0,
	PL_LEFT  = 1,
	PL_RIGHT = 2,
	PL_END   = 3
};
// BALLARD RECOMMENDATION END


class Robot : public frc::TimedRobot
{
public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;

	static std::shared_ptr<Drive_Train> drive_Train;
	static std::shared_ptr<Pneumatic> pneumatic;
	static std::shared_ptr<Transmission> transmission;
	static std::shared_ptr<Shooter> shooter;

// Hayden:  This had to be changed to lower case because the name conflicted with the class.  Mr. Ballard
	static std::shared_ptr<Intake> intake;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;

// BALLARD RECOMMENDATION
	// Description of Game Data details can be found:
	// http://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details
	void Update_GameData();

	std::string   gameData;
	PlateLocation AllianceSwitch;
	PlateLocation Scale;
	PlateLocation OpposingSwitch;
// BALLARD RECOMMENDATION END
};
#endif
