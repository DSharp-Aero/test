#include "Aircraft.h"
#include <cmath>




double Aircraft::cutoffApogee()
{
	savedSpeed = speed;
	savedSpeedX = speedX;
	savedSpeedY = speedY;
	savedDistTrvlld = distTrvlld;
	savedDistTrvlldX = distTrvlldX;
	savedDistTrvlldY = distTrvlldY;
	savedThrust = thrust;
	savedXPos = xPos;
	savedYPos = yPos;

	while (speedY > 0)
	{
		thrust = 0;
		UpdateSpeed();
		UpdateSpeedX();
		UpdateSpeedY();
		UpdatePosX();
		UpdatePosY();
		UpdateDistTrvlld();
	}

	int test = yPos;
	return yPos;

}

double Aircraft::RealMass()
{
	thrust = savedThrust;

	double mass = (thrust / exhaustVel) * massFrac* dt;

	return mass;
}

void Aircraft::Init(int i)
{
	thrust = i + minThrust;
}

void Aircraft::UpdateTime()
{
	dt = dt + timestep;
}


double Aircraft::airDensity()
{
	double temperature = -131.21 + .00299 * yPos;
	double pressure = 2.488 * pow(((temperature + 273.1) / 216.6), -11.388);
	double densityValue = pressure / (0.2869 * (temperature + 273.1));
	return densityValue;
}

double Aircraft::dragForce()
{
	double drag = (dragCoefficient * airDensity() * pow(speed, 2) * (areaStage1 + areaStage2) / 2);
	return drag;
}

double Aircraft::xComp()
{
	double comp = ((cos(angle) * (thrust)) / mass) - ((cos(angle) * dragForce()) / mass);

	return comp;
}

double Aircraft::yComp()
{
	double comp = ((sin(angle) * (thrust)) / mass) - ((sin(angle) * dragForce()) / mass) - 9.8;

	return comp;
}

void Aircraft::UpdateSpeedX()
{
	speedX = speedX + xComp() * timestep;
}

void Aircraft::UpdateSpeedY()
{
	speedY = speedY + yComp() * timestep;
}

void Aircraft::UpdateSpeed()
{
	speed = (sqrt(pow(speedX, 2) + pow(speedY, 2)));
}

void Aircraft::UpdatePosX()
{
	xPos = xPos + (speedX * timestep) + (xComp() * (pow(timestep, 2)) / 2);
}

double Aircraft::GetPosX()
{
	return xPos;
}

void Aircraft::UpdatePosY()
{
	yPos = yPos + (speedY * timestep) + (yComp() * (pow(timestep, 2)) / 2);
}

double Aircraft::GetPosY()
{
	return yPos;
}

void Aircraft::UpdateDistTrvlld()
{
	distTrvlld = distTrvlld + abs((speed * timestep) + ((sqrt(pow(xComp(), 2) + pow(yComp(), 2)))) * (pow(timestep, 2)) / 2);
}
