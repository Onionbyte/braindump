#include "Transmission.h"
#include "iostream"
#include "../RobotMap.h"
#include"../Robot.h"

Transmission::Transmission() : frc::Subsystem("Transmission")
{
    DoubleSolenoidShifter = RobotMap::transmissionSolenoid;
    HighGearForward = DoubleSolenoid::kForward;  // To be replaced with configure capability.
}

void Transmission::InitDefaultCommand()
{
}

void Transmission::Periodic()
{
    // Put code here to be run every loop

}

void Transmission::Set_HighGearForward(bool isForward)
{
	if (isForward)
	{
		HighGearForward = DoubleSolenoid::kForward;
	}
	else
	{
		HighGearForward = DoubleSolenoid::kReverse;
	}
}


void Transmission::Shift_High()
{
	if (HighGearForward==DoubleSolenoid::kForward)
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kForward);
	}
	else
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kReverse);
	}
	SmartDashboard::PutBoolean("HighGear", true);
}

void Transmission::Shift_Low()
{
	if (HighGearForward==DoubleSolenoid::kForward)
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kForward);
	}
	SmartDashboard::PutBoolean("HighGear", false);
}

void Transmission::Shift_Toggle()
{
	if (DoubleSolenoidShifter->Get() == DoubleSolenoid::kForward)
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		DoubleSolenoidShifter->Set(DoubleSolenoid::kForward);
	}
	SmartDashboard::PutBoolean("HighGear", In_HighGear());
}

bool Transmission::In_HighGear()
{
	if (DoubleSolenoidShifter->Get() == HighGearForward) return true;
	return false;
}
