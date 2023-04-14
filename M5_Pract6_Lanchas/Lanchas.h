#pragma once
#include <iostream>
using namespace std;

class Lancha
{
private:
	string driverName;
	int speed;
	int distancia;
	bool nitro;
	int color;

public:
	//constructor
	Lancha(string pDriverName, int pSpeed, int pDistancia, bool pNitro, int color);
	Lancha();


	//getters
	string getDriverName();
	int getSpeed();
	int getDistancia();
	bool getNitro();
	int getColor();


	//setters
	void setDriverName(string pDriverName);
	void setSpeed(int pSpeed);
	void setDistancia(int pDistancia);
	void setNitro(bool pNitro);
	void setColor(int pColor);


	//methods
	void printName();
};