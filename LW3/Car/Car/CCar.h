#pragma once
#include <iostream>

enum class Direction : int
{
	Stop = 0,
	Forward,
	Backward
};

enum class Gear : int
{
	Reverse = -1,
	Neutral,
	First,
	Second,
	Third,
	Fourth,
	Fifth
};
/*
	границы скоростей:
	reverse speed how to regiester? ну ты и долбоеб русский не знаешь
	Direction(Speed) 
*/
const int SPEED_RANGE[][2] = {
	{-20, 0},
	{-20, 150},
	{0, 30},
	{20, 50},
	{30, 60},
	{40, 90},
	{50, 150}
};

class CCar
{
	public:
		CCar();		

		bool IsTurnedOn() const;
		Direction GetDirection() const;
		int GetSpeed() const;
		Gear GetGear() const;

		bool TurnOnEngine();
		bool TurnOffEngine();
		bool SetGear(Gear gear);
		bool SetSpeed(int speed);

	private:
		bool m_isEngineOn;
		int m_speed;
		Gear m_gear;
		
		bool SetSpeedBackwardOnNewtralGear(const int speed);
		bool SetSpeedForwardOnNewtralGear(const int speed);
		bool SetSpeedReverseGear(const int speed);
		bool SetSpeedForward(const int speed);

		int GearToInt(const Gear& gear);
		bool IsGearInRange(const Gear& gear);
		bool IsSpeedInRange(const int& speed);
};
