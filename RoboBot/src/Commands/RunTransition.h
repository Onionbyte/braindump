#ifndef RunTransition_H
#define RunTransition_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RunTransition : public frc::Command {
public:
	RunTransition();
	void Initialize()override;
	void Execute()override;
	bool IsFinished()override;
	void End()override;
	void Interrupted()override;
};

#endif  // RunTransition_H
