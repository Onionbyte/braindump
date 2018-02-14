#include "Shift_Low.h"

Shift_Low::Shift_Low(): InstantCommand()
{
	Requires(Robot::transmission.get());
}

// Called once when this command runs
void Shift_Low::Initialize()
{
	Robot::transmission->Shift_Low();
}

