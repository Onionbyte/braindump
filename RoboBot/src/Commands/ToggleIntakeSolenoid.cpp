/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ToggleIntakeSolenoid.h"

ToggleIntakeSolenoid::ToggleIntakeSolenoid()
{
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void ToggleIntakeSolenoid::Initialize()
{
	Robot::intake->Config();
}

// Called repeatedly when this Command is scheduled to run
void ToggleIntakeSolenoid::Execute()
{
	Robot::intake->Intake_SolenoidToggle();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleIntakeSolenoid::IsFinished()
{
	return !Robot::oi->Is_Intake_SolenoidToggle();
}

// Called once after isFinished returns true
void ToggleIntakeSolenoid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleIntakeSolenoid::Interrupted()
{

}
