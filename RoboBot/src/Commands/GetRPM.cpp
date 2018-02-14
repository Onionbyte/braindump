#include "GetRPM.h"

GetRPM::GetRPM()
{
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void GetRPM::Initialize()
{
	Robot::shooter->Config();
}

// Called repeatedly when this Command is scheduled to run
void GetRPM::Execute()
{
	Robot::shooter->GetRPM();
}

// Make this return true when this Command no longer needs to run execute()
bool GetRPM::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GetRPM::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetRPM::Interrupted()
{

}
