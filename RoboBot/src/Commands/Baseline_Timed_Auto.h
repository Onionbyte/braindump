#ifndef BASELINE_TIMED_AUTO_H
#define BASELINE_TIMED_AUTO_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Baseline_Timed_Auto: public frc::TimedCommand
{
public:

	Baseline_Timed_Auto(double timeout);
	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
};

#endif
