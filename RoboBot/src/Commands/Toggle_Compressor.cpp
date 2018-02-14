//author: justice, josie
#include "Toggle_Compressor.h"

Toggle_Compressor::Toggle_Compressor(): InstantCommand()
{
	Requires(Robot::pneumatic.get());
}

// Called once when this command runs
void Toggle_Compressor::Initialize()
{
	Robot::pneumatic.get();
}

