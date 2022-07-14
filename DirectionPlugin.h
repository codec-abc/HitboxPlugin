#pragma once
#include <memory>
#pragma comment( lib, "pluginsdk.lib" )
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "Hitbox.h"

/*
Colors the prediction line can have
*/
struct LineColor
{
	unsigned char r, g, b, a; //rgba can be a value of 0-255
};

/*Predicted point in 3d space*/
struct PredictedPoint
{
	/*Location of the predicted ball*/
	Vector location;
	/*States whether it as its highest point or bounces*/
	bool isApex = false;
	Vector apexLocation = { 0,0,0 };
	Vector velocity;
	Vector angVel;
};

class DirectionPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
private:
	std::shared_ptr<int> directionOn;
	std::shared_ptr<int> directionType;
	std::shared_ptr<LinearColor> directionColor;
	LineColor colors[2] = { {0, 255, 255, 240}, {75, 255, 130, 240} };
	std::vector<Hitbox> hitboxes;
public:
	DirectionPlugin();
	~DirectionPlugin();
	virtual void onLoad();
	virtual void onUnload();
	
	void OnFreeplayLoad(std::string eventName);
	void OnFreeplayDestroy(std::string eventName);
	void OnHitboxOnValueChanged(std::string oldValue, CVarWrapper cvar);
	void OnHitboxTypeChanged(std::string oldValue, CVarWrapper cvar);
	void Render(CanvasWrapper canvas);
};

// utility function
Vector Rotate(Vector aVec, double roll, double yaw, double pitch);
