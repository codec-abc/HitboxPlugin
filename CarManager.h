#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "Hitbox.h"
#include <vector>
#include <string>

class CarManager
{
public:
	CarManager();
	static const std::string getHelpText();
	static Hitbox getHitbox(CarWrapper& car);
	~CarManager();
};

