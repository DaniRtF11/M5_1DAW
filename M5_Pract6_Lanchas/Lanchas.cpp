#include "Lanchas.h"
using namespace std;

//constructor
Lancha::Lancha(string pDriverName, int pSpeed, int pDistancia, bool pNitro, int pColor)
{
	driverName = pDriverName,
	speed = pSpeed;
	distancia = pDistancia;
	nitro = pNitro;
	color = pColor;
}

Lancha::Lancha() {

};

//getters	
string Lancha::getDriverName()
{
	return driverName;
}

int Lancha::getSpeed()
{
	return speed;
}

int Lancha::getDistancia()
{
	return distancia;
}

bool Lancha::getNitro()
{
	return nitro;
}

int Lancha::getColor()
{
	return color;
}


//setters
void Lancha::setDriverName(string pName)
{
	driverName = pName;
}

void Lancha::setSpeed(int pSpeed)
{
	speed = pSpeed;
}

void Lancha::setDistancia(int pDistancia)
{
	distancia = pDistancia;
}

void Lancha::setNitro(bool pNitro)
{
	nitro = pNitro;
}

void Lancha::setColor(int pColor)
{
	color = pColor;
}


//methods
void Lancha::printName()
{
	cout << getDriverName();
}