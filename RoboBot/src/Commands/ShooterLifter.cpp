/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ShooterLifter.h"

ShooterLifter::ShooterLifter()
{
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterLifter::Initialize()
{
	Robot::shooter->Config();
}

// Called repeatedly when this Command is scheduled to run
void ShooterLifter::Execute()
{
	Robot::shooter->ShooterLifter();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterLifter::IsFinished()
{
	return !Robot::oi->Is_Shooter_SolenoidToggle();
}

// Called once after isFinished returns true
void ShooterLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterLifter::Interrupted()
{

}
