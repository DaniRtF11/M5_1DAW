#include "EnemigoFinal.h"
using namespace std;


//CONSTRUCTOR
//TIENE COMO PARÁMETROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PARÁMETROS DE LA CLASE QUE HEREDA SE PASAN COMO PARÁMETROS DE ENTRADA
//AL CONSTRUCTOR HEREDADO
EnemigoFinal::EnemigoFinal(int pHp, string pName, int pAttack, int pPosicionX, int pPosicionY, int pSuperAttack, int pCriticAttack):
	Personaje(pHp, pName, pAttack, pPosicionX, pPosicionY) {superAttack = pSuperAttack; criticAttack = pCriticAttack; }

//GETTERS
int EnemigoFinal::getSuperAttack() {
	return superAttack;
}
int EnemigoFinal::getCriticAttack() {
	return criticAttack;
}

//SETTERS
void EnemigoFinal::setFireAttack(int pSuperAttack)
{
	superAttack = pSuperAttack;
}

void EnemigoFinal::setFrozenAttack(int pCriticAttack)
{
	criticAttack = pCriticAttack;
}

//METODOS PROPIOS
void EnemigoFinal::printAllStats() {
	cout << "DATOS DEL BOSS:"
		<< "	NOMBRE: " << getName() << endl
		<< "	VIDA: " << getHp() << endl
		<< "	ATAQUE: " << getAttack() << endl
		<< "	SUPER ATAQUE: " << getSuperAttack() << endl
		<< "	ATAQUE CRITICO " << getCriticAttack() << endl;
}