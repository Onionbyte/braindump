#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "Subsystems/Transmission.h"
#include "WPILib.h"
#include <iostream>

std::shared_ptr<WPI_TalonSRX> RobotMap::drive_TrainLeft_Front_Motor;
std::shared_ptr<WPI_TalonSRX> RobotMap::drive_TrainLeft_Rear_Motor;
std::shared_ptr<WPI_TalonSRX> RobotMap::drive_TrainRight_Front_Motor;
std::shared_ptr<WPI_TalonSRX> RobotMap::drive_TrainRight_Rear_Motor;
std::shared_ptr<frc::RobotDrive> RobotMap::drive_TrainRobotDrive;
std::shared_ptr<frc::Compressor> RobotMap::pneumaticCompressor;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::transmissionSolenoid;
std::shared_ptr<WPI_TalonSRX> RobotMap::Intake_Talon_Left;
std::shared_ptr<WPI_TalonSRX> RobotMap::Intake_Talon_Right;
std::shared_ptr<WPI_TalonSRX> RobotMap::Shooter_Entry_Talon_Left;
std::shared_ptr<WPI_TalonSRX> RobotMap::Shooter_Entry_Talon_Right;
std::shared_ptr<WPI_TalonSRX> RobotMap::Shooter_Exit_Talon_Left;
std::shared_ptr<WPI_TalonSRX> RobotMap::Shooter_Exit_Talon_Right;

// MDB - These do not need the static modifier in front of them.
std::shared_ptr<WPI_TalonSRX> RobotMap::Transition_Talon_Left;
std::shared_ptr<WPI_TalonSRX> RobotMap::Transition_Talon_Right;
std::shared_ptr<frc::Solenoid> RobotMap::Shooter_Solenoid;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::Shooter_Lifter;
std::shared_ptr<frc::PowerDistributionPanel> RobotMap::PowerDistributionPanel;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::Intake_Solenoid;


void RobotMap::init()
{
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    PowerDistributionPanel.reset(new frc::PowerDistributionPanel());
    //frc::Error pdperr =  PowerDistributionPanel->GetError();
    PowerDistributionPanel->ClearError();
    PowerDistributionPanel->ClearStickyFaults();

    drive_TrainLeft_Front_Motor.reset(new WPI_TalonSRX(DRIVE_TALON_LEFT_FRONT_CANID));
    drive_TrainLeft_Rear_Motor.reset(new WPI_TalonSRX(DRIVE_TALON_LEFT_REAR_CANID));
    drive_TrainRight_Front_Motor.reset(new WPI_TalonSRX(DRIVE_TALON_RIGHT_FRONT_CANID));
    drive_TrainRight_Rear_Motor.reset(new WPI_TalonSRX(DRIVE_TALON_RIGHT_REAR_CANID));
    
    drive_TrainRobotDrive.reset(new frc::RobotDrive(drive_TrainLeft_Front_Motor, drive_TrainLeft_Rear_Motor,
                                                    drive_TrainRight_Front_Motor, drive_TrainRight_Rear_Motor));
    
    drive_TrainRobotDrive->SetSafetyEnabled(false);
    drive_TrainRobotDrive->SetExpiration(0.1);
    drive_TrainRobotDrive->SetSensitivity(0.5);
    drive_TrainRobotDrive->SetMaxOutput(1.0);
    drive_TrainRobotDrive->SetInvertedMotor(frc::RobotDrive::kFrontLeftMotor, true);
    drive_TrainRobotDrive->SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, true);
    pneumaticCompressor.reset(new frc::Compressor(0));
    lw->frc::LiveWindow::AddActuator("Pneumatic", "Compressor", pneumaticCompressor);
    
    // MDB - Think about using a defined name for the pneumatic channels.
    transmissionSolenoid.reset(new frc::DoubleSolenoid(0, 1));
    lw->frc::LiveWindow::AddActuator("Transmission", "DoubleSolenoid", transmissionSolenoid);
    

    Intake_Talon_Left.reset(new WPI_TalonSRX(INTAKE_TALON_LEFT_CANID));
    Intake_Talon_Right.reset(new WPI_TalonSRX(INTAKE_TALON_RIGHT_CANID));


	// Hayden: The issue was that you had cut and pasted Shooter_Entry_Talon_Left for every
    // reset statement. The other three pointers were never assigned.
    // This resulted in what is called a Segmentation Fault.  That is why your code
    // was not working.  Mr. Ballard
    Shooter_Entry_Talon_Left.reset(new WPI_TalonSRX(SHOOTER_ENTRY_TALON_LEFT_CANID));
    Shooter_Entry_Talon_Right.reset(new WPI_TalonSRX(SHOOTER_ENTRY_TALON_RIGHT_CANID));
    Shooter_Exit_Talon_Left.reset(new WPI_TalonSRX(SHOOTER_EXIT_TALON_LEFT_CANID));
    Shooter_Exit_Talon_Right.reset(new WPI_TalonSRX(SHOOTER_EXIT_TALON_RIGHT_CANID));
	
    // MDB - Think about using a defined name for the pneumatic channels.
    Shooter_Lifter.reset(new frc::DoubleSolenoid(2, 3));
    Transition_Talon_Left.reset(new WPI_TalonSRX(TRANSITION_TALON_LEFT_CANID));
    Transition_Talon_Right.reset(new WPI_TalonSRX(TRANSITION_TALON_RIGHT_CANID));
	
    // MDB - Think about using a defined name for the pneumatic channels.
    Shooter_Solenoid.reset(new frc::Solenoid(4));
    Intake_Solenoid.reset(new frc::DoubleSolenoid(5, 6));
}
