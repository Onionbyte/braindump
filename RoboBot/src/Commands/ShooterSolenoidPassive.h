#ifndef ShooterSolenoidPassive_H
#define ShooterSolenoidPassive_H

#include "Subsystems/Shooter.h"
#include "Commands/InstantCommand.h"
#include "Robot.h"
#include "../RobotMap.h"

class ShooterSolenoidPassive : public frc::Command
{
public:
	ShooterSolenoidPassive();
	void Initialize();
	bool IsFinished();

private:
	std::shared_ptr<frc::DoubleSolenoid> Shooter_Solenoid;
};

#endif  // ShooterSolenoidPassive_H
