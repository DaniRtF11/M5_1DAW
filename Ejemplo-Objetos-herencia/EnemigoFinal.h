#pragma once
#include "Enemigo.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int superAttack;
	int criticAttack;

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	EnemigoFinal(int pHp,
				 string pName,
				 int pAttack,
				 int pPosicionX,
				 int pPosicionY,
				 int pSuperAttack,
				 int pCriticAttack);

	//GETTERS
	int getSuperAttack();
	int getCriticAttack();

	//SETTERS
	void setFireAttack(int pSuperAttack);
	void setFrozenAttack(int pCriticAttack);

	//METODOS PROPIOS
	void printAllStats();


};

