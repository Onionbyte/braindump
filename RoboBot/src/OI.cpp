//author: Josie (hah not)

#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "ctre/Phoenix.h"
#include <iostream>

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Baseline_Timed_Auto.h"
#include "Commands/Toggle_Transmission.h"
#include "Commands/Shift_High.h"
#include "Commands/Shift_Low.h"
#include "Commands/Teleop.h"
#include "Commands/Toggle_Compressor.h"
#include "Commands/IntakeInCommand.h"
#include "Commands/IntakeOutCommand.h"
#include "Commands/GetRPM.h"
#include "Commands/RunTransition.h"
#include "Commands/ShooterSolenoidActive.h"
#include "Commands/ShooterSolenoidPassive.h"
#include "Commands/ToggleIntakeSolenoid.h"
#include "Commands/ShooterLifter.h"
#include <cmath>	//dead zones


OI::OI()
{
    // Process operator interface input here.
	 operator_Control.reset(new XboxController(1));
	 driver_Control.reset(new XboxController(0));

	 Driver_Right_Bumper.reset(new frc::JoystickButton(driver_Control.get(), Right_Bumper));
	 Driver_Left_Bumper.reset(new frc::JoystickButton(driver_Control.get(), Left_Bumper));
	 Operator_Right_Bumper.reset(new frc::JoystickButton(operator_Control.get(), Right_Bumper));
	 Operator_Left_Bumper.reset(new frc::JoystickButton(operator_Control.get(), Left_Bumper));
	 Operator_B_Button.reset(new frc::JoystickButton(operator_Control.get(), B));
	 Operator_Y_Button.reset(new frc::JoystickButton(operator_Control.get(), Y));

	 Driver_Right_Bumper->WhenPressed(new Toggle_Transmission());
	 Operator_Right_Bumper->WhenPressed(new IntakeInCommand);
	 Operator_Left_Bumper->WhenPressed(new IntakeOutCommand);
	 Operator_B_Button->WhenPressed(new ToggleIntakeSolenoid); //
	 Operator_Y_Button->WhenPressed(new ShooterLifter);


    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("Toggle_Compressor", new Toggle_Compressor());
    frc::SmartDashboard::PutData("Shift_Low", new Shift_Low());
    frc::SmartDashboard::PutData("Shift_High", new Shift_High());
    frc::SmartDashboard::PutData("Toggle_Transmission", new Toggle_Transmission());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
}


std::shared_ptr<frc::XboxController> OI::getDriver_Control()
{
   return driver_Control;
}

std::shared_ptr<frc::XboxController> OI::getOperator_Control()
{
   return operator_Control;
}

// BALLARD RECOMMENDATION
bool OI::Is_Shooter_SolenoidToggle()
{
	return Is_ButtonPressed(Operator_Controller, Y);
}

bool OI::Is_IntakeInButtonPressed()
{
	return Is_ButtonPressed(Operator_Controller, Left_Bumper);
}

bool OI::Is_IntakeOutButtonPressed()
{
	return Is_ButtonPressed(Operator_Controller, Right_Bumper);
}
bool OI::Is_Intake_SolenoidToggle()
{
	return Is_ButtonPressed(Operator_Controller, B);
}
bool OI::Is_ShooterButtonPressed()
{
	// Hayden:  The trigger unfortunately is not a button but an axis.
	// You would need to use the following logic.
	float value = GetAxisValue(operator_Control, Xbox_Axis_Right_Trigger);
	if (value != 0) return true;
	return false;
}

bool OI::Is_ButtonPressed(Controller theController, Xbox_Button theButton)
{
	bool retval = false;
	if (theController==Driver_Controller)
	{
		retval = driver_Control->GetRawButton(theButton);
	}

	if (theController==Operator_Controller)
	{
		retval = operator_Control->GetRawButton(theButton);
	}
	return retval;
}
// BALLARD RECOMMENDATION END


float OI::GetAxisValue(std::shared_ptr<XboxController> controller, int axis)
{
	float value;

	switch (axis)
	{
	case Xbox_Axis::Xbox_Axis_Left_X:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), LeftX_min);
		if (value == 0.0) { value = 0.0; }	//so value isn't -0, but is 0
		break;

	case Xbox_Axis::Xbox_Axis_Left_Y:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), LeftY_min);	//y axis shouldn't be inverted
																			//as the arcade drive code is tailored to
																			//the y axis not being inverted
		if (value == 0.0) { value = 0.0; }
		break;

	case Xbox_Axis::Xbox_Axis_Left_Trigger:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), LeftTrigger_min);
		break;

	case Xbox_Axis::Xbox_Axis_Right_Trigger:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), RightTrigger_min);
		break;

	case Xbox_Axis::Xbox_Axis_Right_X:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), RightX_min);
		if (value == 0.0) { value = 0.0; }
		break;

	case Xbox_Axis::Xbox_Axis_Right_Y:
		value = No_DeadZone_Value(controller->GetRawAxis(axis), RightY_min);	//y axis shouldn't be inverted
		if (value == 0.0) { value = 0.0; }
		break;

	case Xbox_Axis::Xbox_Axis_DPad_X:
		value = controller->GetRawAxis(axis);
		break;

	case Xbox_Axis::Xbox_Axis_DPad_Y:
		value = controller->GetRawAxis(axis);
		break;

	default:
		std::cerr << "Unhandled axis: " << __LINE__ << " value " << axis << std::endl;
		value = 0;
	}

	return value;
}

float OI::No_DeadZone_Value(float value, float deadZone)
{	//works with all axes
	if ( fabs(value) < deadZone )
	{
		return 0.0;
	}
	else
	{
		return value;
	}
}

