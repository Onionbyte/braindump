#ifndef IntakeInCommand_H
#define IntakeInCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakeInCommand : public frc::Command
{
public:
	IntakeInCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // IntakeInCommand_H
