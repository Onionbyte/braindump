#ifndef IntakeOutCommand_H
#define IntakeOutCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakeOutCommand : public frc::Command
{
public:
	IntakeOutCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // IntakeOutCommand_H
