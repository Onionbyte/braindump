#ifndef TRANSMISSION_H
#define TRANSMISSION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Transmission: public frc::Subsystem
{
public:
	Transmission();
	void InitDefaultCommand() override;
	void Periodic() override;
    void Set_HighGearForward(bool isForward=true);

	void Shift_High();
	void Shift_Low();
	void Shift_Toggle();

	bool In_HighGear();

private:
	std::shared_ptr<frc::DoubleSolenoid> DoubleSolenoidShifter;
	frc::DoubleSolenoid::Value HighGearForward;  // Will be used to modify config.

};

#endif
