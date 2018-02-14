#ifndef ShooterSolenoidActive_H
#define ShooterSolenoidActive_H

#include "Subsystems/Shooter.h"
#include "Commands/InstantCommand.h"
#include "Robot.h"
#include "../RobotMap.h"

class ShooterSolenoidActive : public InstantCommand {

public:
	ShooterSolenoidActive();
	void Initialize();
	bool IsFinished();

private:
	std::shared_ptr<frc::DoubleSolenoid> Shooter_Solenoid;
};


#endif  // ShooterSolenoidActive_H
