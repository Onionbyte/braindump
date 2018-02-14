#include "IntakeInCommand.h"


IntakeInCommand::IntakeInCommand()
{
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeInCommand::Initialize()
{
	Robot::intake->Config();
}

// Called repeatedly when this Command is scheduled to run
void IntakeInCommand::Execute()
{
	Robot::intake->RunIn();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeInCommand::IsFinished()
{
	// Hayden: I think you might want to do this.  Mr. Ballard
	return !Robot::oi->Is_IntakeInButtonPressed();
}

// Called once after isFinished returns true
void IntakeInCommand::End()
{
	// Hayden: I think you might want to do this.  Mr. Ballard
		Robot::intake->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeInCommand::Interrupted()
{

}
