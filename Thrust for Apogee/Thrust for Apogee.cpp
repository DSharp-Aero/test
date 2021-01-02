// Thrust for Apogee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cmath>
#include "Aircraft.h"

using namespace std;

static constexpr int maxThrust = 5000;                                           //Set le nombre de "simulations" (une avec chaque thrust)
                                                                                 //
static constexpr int minThrust = 200;                                            //
                                                                                 //
static constexpr int simNum = maxThrust - minThrust;                             //
                                                                                 //
static constexpr int apogee = 47000;                                            //
                                                                                 //
Aircraft craft[simNum];                                                          //Créer l'array d'objets, donc de simulations

double optThrust;

double optBurntime;

int main()
{
    double ref = 100000;
    int good;
    for (int i = 0; i < simNum; ++i)
    {
        craft[i].Init(i); // Set la thrust de la simulation qui va suivre

        while ( craft[i].cutoffApogee() < apogee) //Check "si on coupe le moteur là, est-ce que l'apogée voulue est atteinte ?"
        {

            craft[i].speed = craft[i].savedSpeed;                                  //cutoffApogee a besoin des données, donc je les save avant de faire les calculs dans la fonction pour, ici, les réassignier à leur bonne valeur
            craft[i].speedX = craft[i].savedSpeedX;                                //
            craft[i].speedY = craft[i].savedSpeedY;                                //
            craft[i].distTrvlld = craft[i].savedDistTrvlld;                        //
            craft[i].distTrvlldX = craft[i].savedDistTrvlldX;                      //
            craft[i].distTrvlldY = craft[i].savedDistTrvlldY;                      //
            craft[i].thrust = craft[i].savedThrust;                                //
            craft[i].xPos = craft[i].savedXPos;                                    //
            craft[i].yPos = craft[i].savedYPos;                                    //
            
            craft[i].UpdateTime();
            craft[i].UpdateSpeed();
            craft[i].UpdateSpeedX();
            craft[i].UpdateSpeedY();
            craft[i].UpdatePosX();
            craft[i].UpdatePosY();
            craft[i].UpdateDistTrvlld();

        }

        if (craft[i].RealMass() <= craft[i].mass) //check si la masse nécessaire pour produire la thrust pendant tout le burntime est en dessous de la masse utilisée pour la simulation. Si oui, ca display les résultats
        {
            craft[i].thrust = craft[i].savedThrust;
            cout << "---------------------------------------------" << endl; 
            cout << "Air Density = " << craft[i].airDensity() << endl;
            cout << "Acceleration Vector X = " << craft[i].xComp() << endl;
            cout << "Acceleration Vector Y = " << craft[i].yComp() << endl;
            cout << "Angle of Attack = " << craft[i].angle << endl;
            cout << "Distance Travelled = " << craft[i].distTrvlld << endl;
            cout << "Speed = " << craft[i].speed << endl;
            cout << "Drag Force = " << craft[i].dragForce() << endl;
            cout << "Position in X = " << craft[i].GetPosX() << endl;
            cout << "Altitude = " << craft[i].GetPosY() << endl;
            cout << "Thrust = " << craft[i].thrust << endl;
            cout << "Burntime = " << craft[i].dt << endl;
            cout << "RealMass = " << craft[i].RealMass() << endl;
            cout << "Cutoff Apogee = " << craft[i].cutoffApogee() << endl;


        }
        
        if (craft[i].RealMass() < ref) //cherche la valeur minimum de RealMass, donc thrust et burntime qui utilisent le moins de carburants
        {
            ref = craft[i].RealMass();
            optThrust = craft[i].thrust;
            optBurntime = craft[i].dt;
            good = i;
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Air Density = " << craft[good].airDensity() << endl;
    cout << "Acceleration Vector X = " << craft[good].xComp() << endl;
    cout << "Acceleration Vector Y = " << craft[good].yComp() << endl;
    cout << "Angle of Attack = " << craft[good].angle << endl;
    cout << "Distance Travelled = " << craft[good].distTrvlld << endl;
    cout << "Speed = " << craft[good].speed << endl;
    cout << "Drag Force = " << craft[good].dragForce() << endl;
    cout << "Position in X = " << craft[good].GetPosX() << endl;
    cout << "Altitude = " << craft[good].GetPosY() << endl;
    cout << "Thrust = " << craft[good].thrust << endl;
    cout << "Burntime = " << craft[good].dt << endl;
    cout << "RealMass = " << craft[good].RealMass() << endl;
    cout << "Cutoff Apogee = " << craft[good].cutoffApogee() << endl;
    cout << "--------^ Optimal Results ^--------"<< endl;
    cout << "Optimal Thrust = " << optThrust << endl;
    cout << "Optimal Burntime = " << optBurntime << endl;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
