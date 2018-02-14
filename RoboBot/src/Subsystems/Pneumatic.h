#ifndef PNEUMATIC_H
#define PNEUMATIC_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pneumatic: public frc::Subsystem
{
public:
	Pneumatic();
	void InitDefaultCommand() override;
	void Periodic() override;

private:
	std::shared_ptr<frc::Compressor> compressor;

};

#endif
