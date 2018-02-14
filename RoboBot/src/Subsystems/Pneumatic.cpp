#include "Pneumatic.h"
#include "../RobotMap.h"

Pneumatic::Pneumatic() : frc::Subsystem("Pneumatic")
{
    compressor = RobotMap::pneumaticCompressor;
}

void Pneumatic::InitDefaultCommand()
{
}

void Pneumatic::Periodic()
{
    // Put code here to be run every loop

}
