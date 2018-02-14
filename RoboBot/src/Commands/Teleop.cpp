//author: justice, josie

#include "Teleop.h"
#include "WPILib.h"
#include <iostream>
#include "../OI.h"

Teleop::Teleop(): frc::Command()
{
	Requires(Robot::drive_Train.get());
}

// Called just before this Command runs the first time
void Teleop::Initialize()
{
	Robot::drive_Train->SetVoltageMode();
}

// Called repeatedly when this Command is scheduled to run
void Teleop::Execute()
{
	float axisX, axisY, axisTrigger;
	bool hs = false;
	axisX = Robot::oi->GetAxisValue(Robot::oi->getDriver_Control(),(int)OI::Xbox_Axis_Right_X);
	axisY = Robot::oi->GetAxisValue(Robot::oi->getDriver_Control(),(int)OI::Xbox_Axis_Left_Y);

	axisTrigger = Robot::oi->GetAxisValue(Robot::oi->getDriver_Control(),(int)OI::Xbox_Axis_Right_Trigger);

	if (axisTrigger != 0) hs = true;

		//control motors
	Robot::drive_Train->ArcadeDrive(axisX, axisY, hs); //ArcadeDrive(x, y)

//tank drive to be added
}

// Make this return true when this Command no longer needs to run execute()
bool Teleop::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void Teleop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Teleop::Interrupted()
{

}
