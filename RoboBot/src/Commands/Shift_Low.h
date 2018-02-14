#ifndef SHIFT_LOW_H
#define SHIFT_LOW_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Subsystems/Transmission.h"

class Shift_Low: public frc::InstantCommand
{
public:
	Shift_Low();
	void Initialize() override;

private:
};

#endif
