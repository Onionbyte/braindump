#include "RunTransition.h"

RunTransition::RunTransition()
{

	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void RunTransition::Initialize()
{
	Robot::intake->Config();
}

// Called repeatedly when this Command is scheduled to run
void RunTransition::Execute()
{
	Robot::intake->RunTransition();
}

// Make this return true when this Command no longer needs to run execute()
bool RunTransition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunTransition::End()
{
	Robot::intake->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunTransition::Interrupted() {

}
