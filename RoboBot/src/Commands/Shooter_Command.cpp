#include "Shooter_Command.h"
#include <iostream>

Shooter_Command::Shooter_Command()
{
	Requires(Robot::shooter.get());
	isShooting = false;
}
// Called just before this Command runs the first time
void Shooter_Command::Initialize()
{
	// Robot::shooter->Config();
}
// Called repeatedly when this Command is scheduled to run
void Shooter_Command::Execute()
{
	if (Robot::oi->Is_ShooterButtonPressed())
	{
		Robot::shooter->SpinTalons();
		isShooting = true;
	}
	else
	{
		if (isShooting) Robot::shooter->StopMotors();
		isShooting = false;
	}
}
// Make this return true when this Command no longer needs to run execute()
bool Shooter_Command::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Shooter_Command::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shooter_Command::Interrupted()
{

}
