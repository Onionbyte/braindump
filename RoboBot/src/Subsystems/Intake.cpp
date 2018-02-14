#include "Intake.h"
#include "../RobotMap.h"
#include <iostream>
#include "WPILib.h" // I looked over your code again and again, and the problem was that you need to include WPILib for a lot of the commands. - Justice

Intake::Intake() : Subsystem("Intake")
{
	Intake_Talon_Left  = RobotMap::Intake_Talon_Left;
	Intake_Talon_Right = RobotMap::Intake_Talon_Right;
	Transition_Talon_Left = RobotMap::Transition_Talon_Left;
	Transition_Talon_Right = RobotMap::Transition_Talon_Right;
}

void Intake::InitDefaultCommand()
{
}

void Intake::Config()
{
	Intake_Talon_Left->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Intake_Talon_Right->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Transition_Talon_Left->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Transition_Talon_Right->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

	Intake_Talon_Left->SetInverted(true);
	Intake_Talon_Right->SetInverted(false);
	Transition_Talon_Left->SetInverted(true);
	Transition_Talon_Right->SetInverted(false);
}

// MDB - A separate method to command the transition motors is required.
void Intake::RunIn(float percentin)
{
	Intake_Talon_Left->Set(ControlMode::PercentOutput, percentin);
	Intake_Talon_Right->Set(ControlMode::PercentOutput, percentin);
}

void Intake::RunOut(float percentout)
{
	Intake_Talon_Left->Set(ControlMode::PercentOutput, percentout);
	Intake_Talon_Right->Set(ControlMode::PercentOutput, percentout);
	Transition_Talon_Left->Set(ControlMode::PercentOutput, percentout);
	Transition_Talon_Right->Set(ControlMode::PercentOutput, percentout);
}

void Intake::RunTransition(float percenttrans)
{
	Transition_Talon_Left->Set(ControlMode::PercentOutput, percenttrans);
	Transition_Talon_Right->Set(ControlMode::PercentOutput, percenttrans);
}

void Intake::Intake_SolenoidToggle()
{
	if
	(Intake_Solenoid->Get()== DoubleSolenoid::kForward)
	{
		Intake_Solenoid->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		Intake_Solenoid->Set(DoubleSolenoid::kForward);
	}
}

void Intake::StopMotors()
{
	Intake_Talon_Left->StopMotor();
	Intake_Talon_Right->StopMotor();
	Transition_Talon_Left->StopMotor();
	Transition_Talon_Right->StopMotor();
}
