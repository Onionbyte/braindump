#include "Toggle_Transmission.h"

Toggle_Transmission::Toggle_Transmission(): InstantCommand()
{
	Requires(Robot::transmission.get());
}

// Called once when this command runs
void Toggle_Transmission::Initialize()
{
	Robot::transmission->Shift_Toggle();
}

