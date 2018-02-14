#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"


class Intake : public frc::Subsystem
{
public:
	Intake();
	void InitDefaultCommand();
	void Config();
	// MDB - You will need to add a separate set of run commands for the transition motors as they will be
	// controlled independant of the other intake motors.
	void RunIn(float percentin = 0.5);
	void RunOut(float percentout = -0.5);
	void RunTransition(float percenttrans = 0.5);
	void Shooter_SolenoidToggle();
	void Intake_SolenoidToggle();
	void StopMotors();

private:
	std::shared_ptr<WPI_TalonSRX> Intake_Talon_Right;
	std::shared_ptr<WPI_TalonSRX> Intake_Talon_Left;
	std::shared_ptr<WPI_TalonSRX> Transition_Talon_Left;
	std::shared_ptr<WPI_TalonSRX> Transition_Talon_Right;
	std::shared_ptr<frc::DoubleSolenoid> Intake_Solenoid;
};

#endif  // Intake_H
