//author: Josie

#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <iostream>

class OI
{
public:
	OI();

// BALLARD RECOMMENDATION
	enum Controller
	{
		Driver_Controller   = 1,
		Operator_Controller = 2,
		Unspecified
	};

// BALLARD RECOMMENDATION END

	enum Xbox_Button
	{
		A 				= 1,
		B 				= 2,
		X 				= 3,
		Y 				= 4,
		Left_Bumper 	= 5,
		Right_Bumper 	= 6,
		Back 			= 7,
		Start 			= 8,
		Left_Stick 		= 9,
		Right_Stick 	= 10
	};

	enum Xbox_Axis
	{
		Xbox_Axis_Left_X 			= 0,	// left: 1, right -1
		Xbox_Axis_Left_Y 			= 1,	// upwards: -1, downwards: 1
		Xbox_Axis_Left_Trigger 		= 2,	// not pressed: 0, pressed: 1
		Xbox_Axis_Right_Trigger		= 3,	// not pressed: 0, pressed: 1
		Xbox_Axis_Right_X 			= 4,	// left: 1, right -1
		Xbox_Axis_Right_Y 			= 5,	// upwards: -1, downwards: 1
		Xbox_Axis_DPad_X 			= 6,
		Xbox_Axis_DPad_Y 			= 7
	};

	std::shared_ptr<frc::XboxController> getDriver_Control();
	std::shared_ptr<frc::XboxController> getOperator_Control();

// BALLARD RECOMMENDATION
	bool Is_IntakeInButtonPressed();
	bool Is_IntakeOutButtonPressed();
	bool Is_ShooterButtonPressed();
	bool Is_Intake_SolenoidToggle();
	bool Is_Shooter_SolenoidToggle();
	bool Is_ButtonPressed(Controller theController, Xbox_Button theButton);
// BALLARD RECOMMENDATION END

	float GetAxisValue(std::shared_ptr<XboxController> controller, int axis);	//gets the axis value of the specified button (with dead zones)
	float No_DeadZone_Value(float value, float deadZone);	                    //returns a value that, which will be 0 if it is in the deadzone value
																				//Ex. if dead zone value is 0.1
																				//-1 will be -1, 0.05 will be 0, -0.05 will be 0, etc

private:
	std::shared_ptr<frc::XboxController> operator_Control;
	std::shared_ptr<frc::XboxController> driver_Control;
	std::shared_ptr<frc::JoystickButton> Driver_Right_Bumper;
	std::shared_ptr<frc::JoystickButton> Driver_Left_Bumper;
	std::shared_ptr<frc::JoystickButton> Operator_Right_Bumper;
	std::shared_ptr<frc::JoystickButton> Operator_Left_Bumper;
	std::shared_ptr<frc::JoystickButton> Operator_B_Button;
	std::shared_ptr<frc::JoystickButton> Operator_Y_Button;

	//dead zones
	float LeftX_min 		= 0.1;
	float LeftY_min 		= 0.1;
	float LeftTrigger_min 	= 0.1;
	float RightTrigger_min 	= 0.1;
	float RightX_min 		= 0.1;
	float RightY_min 		= 0.1;
};

#endif
