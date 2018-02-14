#include "IntakeOutCommand.h"

IntakeOutCommand::IntakeOutCommand()
{
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeOutCommand::Initialize()
{
	Robot::intake->Config();
}

// Called repeatedly when this Command is scheduled to run
void IntakeOutCommand::Execute()
{
	Robot::intake->RunOut();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOutCommand::IsFinished()
{
// Hayden: I think you might want to do this.  Mr. Ballard
	return !Robot::oi->Is_IntakeOutButtonPressed();
}

// Called once after isFinished returns true
void IntakeOutCommand::End()
{
// Hayden: I think you might want to do this.  Mr. Ballard
	Robot::intake->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOutCommand::Interrupted()
{

}
