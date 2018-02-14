#include "ShooterSolenoidActive.h"

ShooterSolenoidActive::ShooterSolenoidActive()
{
	Requires(Robot::shooter.get());
}

// Called once when the command executes
void ShooterSolenoidActive::Initialize()
{
	Robot::shooter->PushCube();
}
bool ShooterSolenoidActive::IsFinished()
{
	if(Shooter_Solenoid->Get() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
