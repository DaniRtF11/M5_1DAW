#pragma once
#include  <iostream>
using namespace std;

class Personaje
{

private:
	int hp;
	string name;
	int attack;
	int posicionX;
	int posicionY;

public:
	//constructor
	Personaje(int pHp, string pName, int pAttack, int pPosicionX, int pPosicionY);
	Personaje();

	//getters
	int getHp();
	string getName();
	int getAttack();
	int getPosicionX(); 
	int getPosicionY();


	//setters
	void setHp(int php);

	void setName(string pname);

	void setAttack(int pattack);

	void setPosicionX(int pPosicionX);

	void setPosicionY(int pPosicionY);


	//metodos propios
	void printStatus();

};

