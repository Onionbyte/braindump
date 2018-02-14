#ifndef Shooter_Command_H
#define Shooter_Command_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../RobotMap.h"
#include "Robot.h"
// MDB - Now with the addition of a transition motor on the intake, and a solenoid that injects the 
// cube into the shooter,  this implementation of the shooter command is no longer valid.
// Shooting will require multiple commands and a command group to be created.  We will discuss in person.

class Shooter_Command : public frc::Command
{
public:
	Shooter_Command();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	bool isShooting;
};

#endif  // Shooter_Command_H
