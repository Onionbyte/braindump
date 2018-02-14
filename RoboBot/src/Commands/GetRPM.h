#ifndef GetRPM_H
#define GetRPM_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class GetRPM : public frc::Command {
public:
	GetRPM();
	void Initialize()override;
	void Execute()override;
	bool IsFinished()override;
	void End()override;
	void Interrupted()override;
};

#endif  // GetRPM_H
