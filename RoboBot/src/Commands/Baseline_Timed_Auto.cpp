#include "Baseline_Timed_Auto.h"

Baseline_Timed_Auto::Baseline_Timed_Auto(double timeout) : frc::TimedCommand(timeout)
{
	Requires(Robot::drive_Train.get());
}

// Called just before this Command runs the first time
void Baseline_Timed_Auto::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Baseline_Timed_Auto::Execute()
{

}

// Called once after command times out
void Baseline_Timed_Auto::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Baseline_Timed_Auto::Interrupted()
{

}
