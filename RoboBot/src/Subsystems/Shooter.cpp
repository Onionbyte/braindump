#include "Shooter.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include "WPILib.h"
#include "../Commands/Shooter_Command.h"

Shooter::Shooter() : frc::Subsystem("Shooter")
{
	Left_Entry_Talon  = RobotMap::Shooter_Entry_Talon_Left;
	Right_Entry_Talon = RobotMap::Shooter_Entry_Talon_Right;
	Left_Exit_Talon   = RobotMap::Shooter_Exit_Talon_Left;
	Right_Exit_Talon  = RobotMap::Shooter_Exit_Talon_Right;
	Shooter_Lifter   = RobotMap::Shooter_Lifter;

	// MDB - Remove all intake components.

	Shooter_Solenoid = RobotMap::Shooter_Solenoid;
	Config();
}
void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Shooter_Command());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Config()
{
	Left_Entry_Talon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Right_Entry_Talon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Left_Exit_Talon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	Right_Exit_Talon->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	
   	// MDB - Remove intake components.


	Left_Entry_Talon->SetInverted(true);
	Right_Entry_Talon->SetInverted(false);
	Left_Exit_Talon->SetInverted(true);
	Right_Exit_Talon->SetInverted(false);
}

// Hayden the next step will be to add an option to set one side's motors to follow the corresponding
// motor on the other side.  Probably should be a separate method to do this i will explain why later.
// Left_Entry_Talon->Set(ControlMode::Follower, SHOOTER_ENTRY_TALON_RIGHT_CANID);

// Probably have three Set Shooter methods.  One like the one you have below. Another that has the
// left side following the right.  Another called Closed_Loop that we will discuss later.

void Shooter::PushCube()
{
	Shooter_Solenoid->Set(true);
}

void Shooter::ResetCube()
{
	Shooter_Solenoid->Set(false);
}

void Shooter::GetRPM()
{
	Left_Entry_Talon->Get();
	Left_Exit_Talon->Get();
	Right_Entry_Talon->Get();
	Right_Exit_Talon->Get();
	//Return RPM value
}

void Shooter::SpinTalons(float percent)
{
	Left_Entry_Talon->Set(ControlMode::PercentOutput, percent);
	Left_Exit_Talon->Set(ControlMode::PercentOutput, percent);

	Right_Entry_Talon->Set(ControlMode::PercentOutput, percent);
	Right_Exit_Talon->Set(ControlMode::PercentOutput, percent);
}
	// MDB - This is not required.

void Shooter::ShooterLifter()
{
	if(Shooter_Lifter->Get() == DoubleSolenoid::kForward)
	{
		Shooter_Lifter->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		Shooter_Lifter->Set(DoubleSolenoid::kForward);
	}
}

	// MDB - Remove all intake components.



void Shooter::StopMotors()
{
	// MDB - Remove all intake components.

	Left_Entry_Talon->StopMotor();
	Right_Entry_Talon->StopMotor();
	Left_Exit_Talon->StopMotor();
	Right_Exit_Talon->StopMotor();
}
