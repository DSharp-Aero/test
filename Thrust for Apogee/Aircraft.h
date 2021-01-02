#pragma once

class Aircraft {

public:
	double RealMass();
	void Init(int i);
	void UpdateTime();
	double xComp();
	double yComp();
	void UpdateDistTrvlld();
	void UpdateSpeedX();
	void UpdateSpeedY();
	void UpdateSpeed();
	void UpdatePosX();
	void UpdatePosY();
	double angle = 3.1416 / 2;
	double speed = 0;
	double speedX = 0;
	double speedY = 0;
	double distTrvlld = 0;
	double distTrvlldX = 0;
	double distTrvlldY = 0;
	double timestep = 0.1;
	double airDensity();
	double dragForce();
	const double areaStage1 = 0.5;
	const double areaStage2 = 0.5;
	double GetPosX();
	double GetPosY();
	bool test = true;
	double burntime = 0;
	double dt = 0;
	int thrust = 0;
	static constexpr int minThrust = 200;
	const double mass = 20;
	//saved for cutoff Apogee
	double savedSpeed = 0;
	double savedSpeedX = 0;
	double savedSpeedY = 0;
	double savedDistTrvlld = 0;
	double savedDistTrvlldX = 0;
	double savedDistTrvlldY = 0;
	double savedThrust = 0;
	double savedXPos = 0;
	double savedYPos = 0;
	double cutoffApogee();
	double xPos = 0;
	double yPos = 35000;  /////////////////////////////Starting Altitude

private:
	double refTemperature = 293.15;
	double refPressure = 101325;
	double molarMass = 0.02897; 
	double gasConstant = 8.314; 
	double tempLapse = 0.0065; 
	double dragCoefficient = 0.02; //unsure
	float exhaustVel = 2500; //unsure
	float massFrac = 4; ///////////////////////////////Propellant Mass Fraction
};

