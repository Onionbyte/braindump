//author: Jocelyn

#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Pneumatic.h"
#include "Transmission.h"

class Drive_Train: public frc::Subsystem
{
public:
	Drive_Train();
	void InitDefaultCommand() override;

	void Config();
	void SetVoltageMode();

	void Periodic() override;
	
	void TankDrive(float left, float right, bool HighSpeed = false);
	void ArcadeDrive(float x, float y, bool HighSpeed = false);        //arcade drive also works as a split drive
    void StopMotors();

	float Limit(float num);

private:
	std::shared_ptr<WPI_TalonSRX> left_Front_Motor;
	std::shared_ptr<WPI_TalonSRX> left_Rear_Motor;
	std::shared_ptr<WPI_TalonSRX> right_Front_Motor;
	std::shared_ptr<WPI_TalonSRX> right_Rear_Motor;
	std::shared_ptr<frc::RobotDrive> robotDrive;

};
#endif
