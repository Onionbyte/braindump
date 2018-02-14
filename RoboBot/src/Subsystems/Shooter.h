#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"

class Shooter : public frc::Subsystem
{
public:
	Shooter();
	void InitDefaultCommand();
	void Config();
	void GetRPM();
	void SpinTalons(float percent = 1);
	void StopMotors();
	void PushCube();
	void ResetCube();
	void ShooterLifter();

private:
	std::shared_ptr<WPI_TalonSRX>        Left_Entry_Talon;
	std::shared_ptr<WPI_TalonSRX>        Right_Entry_Talon;
	std::shared_ptr<WPI_TalonSRX>        Left_Exit_Talon;
	std::shared_ptr<WPI_TalonSRX>        Right_Exit_Talon;
	std::shared_ptr<frc::DoubleSolenoid> Shooter_Lifter;
	// MDB - control system components should be managed by a single subsystem.
	// The intake should have the sole responsibility of these following items.
	// Otherwise there will likely be uncontrolled contention for commanding. 

	std::shared_ptr<frc::Solenoid> Shooter_Solenoid;

};

#endif  // Shooter_H
