#include "Shift_High.h"

Shift_High::Shift_High(): InstantCommand()
{
	Requires(Robot::transmission.get());
}

// Called once when this command runs
void Shift_High::Initialize()
{
	Robot::transmission->Shift_High();
}

