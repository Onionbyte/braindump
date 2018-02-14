#include "ShooterSolenoidPassive.h"

ShooterSolenoidPassive::ShooterSolenoidPassive()
{
	Requires(Robot::shooter.get());
}

// Called once when the command executes
void ShooterSolenoidPassive::Initialize()
{
	Robot::shooter->ResetCube();
}
bool ShooterSolenoidPassive::IsFinished()
{
	if(Shooter_Solenoid->Get() == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
