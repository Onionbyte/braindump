// Onion grace'd this code

#include "ctre/Phoenix.h"
#include <iostream>
#include "Drive_Train.h"
#include "../RobotMap.h"
#include "../Commands/Teleop.h"



Drive_Train::Drive_Train() : frc::Subsystem("Drive_Train") // This is very straightforward
{
	left_Front_Motor  = RobotMap::drive_TrainLeft_Front_Motor;
	left_Rear_Motor   = RobotMap::drive_TrainLeft_Rear_Motor;
	right_Front_Motor = RobotMap::drive_TrainRight_Front_Motor;
	right_Rear_Motor  = RobotMap::drive_TrainRight_Rear_Motor;
	robotDrive        = RobotMap::drive_TrainRobotDrive;
	Config();
	SetVoltageMode();
}

void Drive_Train::InitDefaultCommand()
{
		SetDefaultCommand(new Teleop());
}

void Drive_Train::Periodic()
{
	// Put code here to be run every loop

}

void Drive_Train::Config() // This is where you put your configurations for the robot, for instance what motors are inverted
{
	left_Front_Motor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	right_Front_Motor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

	left_Front_Motor->SetInverted(true);
	left_Rear_Motor->SetInverted(true);
	right_Front_Motor->SetInverted(false);
	right_Rear_Motor->SetInverted(false);
}

void Drive_Train::SetVoltageMode()
{
	left_Front_Motor->Set(ControlMode::PercentOutput, 0);
	right_Front_Motor->Set(ControlMode::PercentOutput, 0);
	left_Rear_Motor->Set(ControlMode::Follower, DRIVE_TALON_LEFT_FRONT_CANID);
	right_Rear_Motor->Set(ControlMode::Follower, DRIVE_TALON_RIGHT_FRONT_CANID);
}


void Drive_Train::TankDrive(float left, float right, bool HighSpeed)
{

}


void Drive_Train::ArcadeDrive(float x, float y, bool HighSpeed) // This simply says "If more/less than a certain variable for this drive, then create new appropriate variable"
{
	float nx = Limit(x); // Notice the common term here "float", this says the variable is undefined.
	float ny = Limit(y);

	if (ny >= 0)
	{
		ny = ny * ny;
	}
	else
	{
		ny = -(ny * ny);
	}

	if (nx >= 0)
	{
		nx = nx * nx;
	}
	else
	{
		nx = -(nx * nx);
	}

	float leftOutput;
	float rightOutput;

	if (ny > 0.0)
	{
		if (nx > 0.0)
		{
			leftOutput = ny - nx;
			rightOutput = std::max(ny, nx);
		}
		else if (nx < 0.0)
		{
			leftOutput = std::max(ny, -nx);
			rightOutput = ny + nx;
		}
		else
		{
			leftOutput = ny;
			rightOutput = ny;
		}
	}
	else
	{
		if (nx > 0.0)
		{
			leftOutput = - std::max(-ny, nx);
			rightOutput = ny + nx;
		}
		else if (nx < 0.0)
		{
			leftOutput = ny - nx;
			rightOutput = - std::max(-ny, -nx);
		}
		else
		{
			leftOutput = ny;
			rightOutput = ny;
		}
	}

	if (!HighSpeed)
	{
		leftOutput *= 0.5;
		rightOutput *= 0.5;
	}

	left_Front_Motor->Set(leftOutput);
	right_Front_Motor->Set(rightOutput);
}

void Drive_Train::StopMotors() // This should be very obvious, it stops the motors.
{
	left_Front_Motor->StopMotor();
	left_Rear_Motor->StopMotor();
	right_Front_Motor->StopMotor();
	right_Rear_Motor->StopMotor();
}

float Drive_Train::Limit(float num) // This basically says "If the undefined integer reaches something more than 1, return the number, if it returns something less than -1, return it, etc.
{
	if (num > 1)
	{
		return 1;
	}
	else if (num < -1)
	{
		return -1;
	}
	else
	{
		return num;
	}
}
