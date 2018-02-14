#ifndef SHIFT_HIGH_H
#define SHIFT_HIGH_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Subsystems/Transmission.h"

class Shift_High: public frc::InstantCommand
{
public:
	Shift_High();
	void Initialize() override;

private:
};

#endif
