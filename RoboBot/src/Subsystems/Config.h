#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"

// Be sure to comment on my work so far and tell me if I'm on the right path - Justice


class Config
{

public:
	
	
	std::shared_ptr<std::ofstream> inFile;
	std::shared_ptr<std::ofstream> outFile;
	std::shared_ptr<std::ofstream> ConfigSet;
	void CheckValue();

	void GetTimeStuff();
	
	void SetValue(std::string ConfigSet, int ValueConfig);
	
	void InputConfig(std::string file);

private:
	
	SetConfigPref (std::string method, std::string file);
	
	RetConfigPref (std::string method);



};

#endif
