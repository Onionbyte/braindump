#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctre/Phoenix.h"

#define DRIVE_TALON_LEFT_FRONT_CANID    1
#define DRIVE_TALON_LEFT_REAR_CANID     2
#define DRIVE_TALON_RIGHT_FRONT_CANID   3
#define DRIVE_TALON_RIGHT_REAR_CANID    4
#define INTAKE_TALON_LEFT_CANID         5
#define INTAKE_TALON_RIGHT_CANID        6
#define SHOOTER_ENTRY_TALON_LEFT_CANID  7
#define SHOOTER_ENTRY_TALON_RIGHT_CANID 8
#define SHOOTER_EXIT_TALON_LEFT_CANID   9
#define SHOOTER_EXIT_TALON_RIGHT_CANID  10
#define TRANSITION_TALON_LEFT_CANID		11
#define TRANSITION_TALON_RIGHT_CANID	12

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap
{
public:
	static std::shared_ptr<WPI_TalonSRX> drive_TrainLeft_Front_Motor;
	static std::shared_ptr<WPI_TalonSRX> drive_TrainLeft_Rear_Motor;
	static std::shared_ptr<WPI_TalonSRX> drive_TrainRight_Front_Motor;
	static std::shared_ptr<WPI_TalonSRX> drive_TrainRight_Rear_Motor;
	static std::shared_ptr<frc::RobotDrive> drive_TrainRobotDrive;
	static std::shared_ptr<frc::Compressor> pneumaticCompressor;
	static std::shared_ptr<frc::DoubleSolenoid> transmissionSolenoid;
	static std::shared_ptr<WPI_TalonSRX> Intake_Talon_Right;
	static std::shared_ptr<WPI_TalonSRX> Intake_Talon_Left;
	static std::shared_ptr<WPI_TalonSRX> Shooter_Entry_Talon_Left;
	static std::shared_ptr<WPI_TalonSRX> Shooter_Entry_Talon_Right;
	static std::shared_ptr<WPI_TalonSRX> Shooter_Exit_Talon_Left;
	static std::shared_ptr<WPI_TalonSRX> Shooter_Exit_Talon_Right;
	static std::shared_ptr<WPI_TalonSRX> Transition_Talon_Left;
	static std::shared_ptr<WPI_TalonSRX> Transition_Talon_Right;
	static std::shared_ptr<frc::Solenoid> Shooter_Solenoid;
	static std::shared_ptr<frc::DoubleSolenoid> Shooter_Lifter;
	static std::shared_ptr<frc::PowerDistributionPanel> PowerDistributionPanel;
	static std::shared_ptr<frc::DoubleSolenoid> Intake_Solenoid;
	static void init();
};
#endif
