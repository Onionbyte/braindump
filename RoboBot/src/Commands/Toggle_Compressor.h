#ifndef TOGGLE_COMPRESSOR_H
#define TOGGLE_COMPRESSOR_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Toggle_Compressor: public frc::InstantCommand
{
public:
	Toggle_Compressor();
	void Initialize() override;

private:
};

#endif
