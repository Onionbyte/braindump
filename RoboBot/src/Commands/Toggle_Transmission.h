#ifndef TOGGLE_TRANSMISSION_H
#define TOGGLE_TRANSMISSION_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Subsystems/Transmission.h"

class Toggle_Transmission: public frc::InstantCommand
{
public:
	Toggle_Transmission();
	void Initialize() override;

private:

};

#endif
