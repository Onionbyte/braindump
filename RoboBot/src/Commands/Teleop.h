#ifndef TELEOP_H
#define TELEOP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Teleop: public frc::Command
{
public:
	Teleop();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
