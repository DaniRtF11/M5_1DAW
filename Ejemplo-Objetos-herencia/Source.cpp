#include <iostream>
#include <string>
#include "Enemigo.h"
#include "EnemigoFinal.h"
#include <conio.h>
#include <windows.h>
#include <cstring>
using namespace std;

//FUNCIONES
void endGame();
int chooseAttack();
void printTablero();
int tipoDañoBoss();
void gameWin();

//ARRAY PERSONAJES + TABLERO
Personaje** ArrayPersonaje;
string tablero[5][5];

//CELDAS
string celdaVictoria = " \033[31m\033[40m| + |\033[0m ";
string celdaDerrota = " \033[31m|\033[0m \033[37mX\033[0m \033[31m|\033[0m ";
string celdaVacia = " |   | ";
string celdaEnemigo = " |\033[31m E \033[0m| ";
string celdaEnemigoOculto = " |\033[30m E \033[0m| ";
string celdaBoss = " |\033[35m B \033[0m| ";
string celdaBossOculto = " |\033[30m B \033[0m| ";
string celdaCombate = " \033[31m\033[42m|H-E|\033[0m ";
string celdaCombateFinal = " \033[31m\033[45m|H-E|\033[0m ";

//VARIABLES
int usosMagia = 3;
int numEnemigoEncontrado;
int numEnemigos = 4;
int a = 1;




int main() {
	ArrayPersonaje = new Personaje * [5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tablero[j][i] = celdaVacia; 
		}
	}
	srand(time(nullptr));	
	
	//CREAMOS AL HEROE
	cout << "Introduce el nombre del heroe : ";
	string heroName;
	cin >> heroName;
	ArrayPersonaje[0] = new Personaje(1000, heroName, 0, 0, 0);
	cout << "Buenas " << heroName << " bienvenido al juego \n";
	string celdaHeroe = " |\033[32m H \033[0m| ";
	tablero[ArrayPersonaje[0]->getPosicionY()][ArrayPersonaje[0]->getPosicionX()] = celdaHeroe;
	int ataque = 0;
	bool heroAlive = true;
	bool bossAlive = true;

	//CREAMOS ENEMIGOS
	int posicionX;
	int posicionY;
	cout << "Hay "<< numEnemigos << " enemigos en el  tablero : \n";
	string nombre = "Goomba ";
	for (int i = 1; i < 5; i++)
	{
		string nombre_completo = nombre + to_string(i);
		posicionX = (rand() % 4) + 1;
		posicionY = (rand() % 3) + 1;
		if (i == 1)
		{			
			ArrayPersonaje[i] = new Personaje(100, nombre_completo, 50, posicionX, posicionY);
		}

		else {
			ArrayPersonaje[i] = new Personaje(100, nombre_completo, 50, posicionX, posicionY);
			for (int j = 0; j < i; j++)
			{
				if ((posicionX == ArrayPersonaje[j]->getPosicionX()) && (posicionY == ArrayPersonaje[j]->getPosicionY())) {
					do
					{
						posicionX = (rand() % 4) + 1;
						posicionY = (rand() % 3) + 1;
						ArrayPersonaje[i]->setPosicionX(posicionX);
						ArrayPersonaje[i]->setPosicionY(posicionY);
					} while ((ArrayPersonaje[i]->getPosicionX() == ArrayPersonaje[j]->getPosicionX()) && (ArrayPersonaje[i]->getPosicionY() == ArrayPersonaje[j]->getPosicionY()));
				}
			}
		}
		tablero[ArrayPersonaje[i]->getPosicionX()][ArrayPersonaje[i]->getPosicionY()] = celdaEnemigoOculto;
	}

	//CREAMOS UN ENEMIGO FINAL QUE HEREDA DE ENEMIGO
	posicionX = rand() % 5;
	EnemigoFinal Bowser(1000, "Bowser", 100, posicionX, 4, 300, 700);
	tablero[posicionX][4] = celdaBossOculto;	
	
	//EMPIEZA EL JUEGO
	cout << "Empieza la aventura \n" << "Usa las flechas para moverte por el tablero\n" 
		<< "TUS DATOS: \n"
		<< "	VIDA: " << ArrayPersonaje[0]->getHp() << "\n" 
		<< "	TUS ATAQUES: \n"
		<< "		Punos: 20 puntos de dano.\n" 
		<< "		Espada: 50 puntos de dano.\n" 
		<< "		Magia: 100 puntos de dano - 3 usos.\n";
	
	Sleep(3000);
	printTablero();
	int posicionesMuertos [3][4];
	memset(posicionesMuertos, 0, sizeof(posicionesMuertos));
	while (heroAlive && bossAlive)
	{
		int posicionAnteriorX;
		int posicionAnteriorY;
		int key = _getch();
		posicionAnteriorX = ArrayPersonaje[0]->getPosicionX();
		posicionAnteriorY = ArrayPersonaje[0]->getPosicionY();
		
		int numMuertos = 0;
			switch (key) {
				key = _getch();
			case 75: // Flecha izquierda
				ArrayPersonaje[0]->setPosicionX((ArrayPersonaje[0]->getPosicionX() - 1));
				break;
			case 77: // Flecha derecha
				ArrayPersonaje[0]->setPosicionX((ArrayPersonaje[0]->getPosicionX() + 1));
				break;
			case 72: // Flecha arriba
				ArrayPersonaje[0]->setPosicionY((ArrayPersonaje[0]->getPosicionY() - 1));
				break;
			case 80: // Flecha abajo
				ArrayPersonaje[0]->setPosicionY((ArrayPersonaje[0]->getPosicionY() + 1));
				break;
			default:
				break;
			}
			if ((ArrayPersonaje[0]->getPosicionX() < 0) || (ArrayPersonaje[0]->getPosicionX() > 4) || (ArrayPersonaje[0]->getPosicionY() < 0) || (ArrayPersonaje[0]->getPosicionY() > 4))
			{
				cout << "Movimiento no valido\n";
				ArrayPersonaje[0]->setPosicionX(posicionAnteriorX);
				ArrayPersonaje[0]->setPosicionY(posicionAnteriorY);
			}

			tablero[posicionAnteriorX][posicionAnteriorY] = celdaVacia;

			for (int i = 0; i < 4; i++)
			{
				if (posicionesMuertos[2][i] == 1)
				{
					tablero[(posicionesMuertos[0][i])][(posicionesMuertos[1][i])] = celdaVictoria;
				}
				
			}

			int comparador = tablero[ArrayPersonaje[0]->getPosicionX()][ArrayPersonaje[0]->getPosicionY()].compare(celdaEnemigoOculto);
			int comparadorBoss = tablero[ArrayPersonaje[0]->getPosicionX()][ArrayPersonaje[0]->getPosicionY()].compare(celdaBossOculto);
			bool enemyAlive = true;
			

			//ENCUENTRA ENEMIGO 
			if (comparador == 0)
			{
				tablero[ArrayPersonaje[0]->getPosicionX()][ArrayPersonaje[0]->getPosicionY()] = celdaEnemigo;
				printTablero();
				Sleep(2000);
				tablero[ArrayPersonaje[0]->getPosicionX()][ArrayPersonaje[0]->getPosicionY()] = celdaCombate;
				printTablero();
				for (int i = 1; i < 5; i++)
				{
					if ((ArrayPersonaje[i]->getPosicionX() == ArrayPersonaje[0]->getPosicionX()) && (ArrayPersonaje[i]->getPosicionY() == ArrayPersonaje[0]->getPosicionY())) {
						numEnemigoEncontrado = i;
					}
				}
				
				//BATALLA ENEMIGO NORMAL
				cout << "HAS ENCONTRADO A UN ENEMIGO!\n" << "EMPIEZA EL COMBATE\n";				
				do
				{
					cout << "DATOS DEL ENEMIGO: \n"
						<< "	NOMBRE: " << ArrayPersonaje[numEnemigoEncontrado]->getName() << "\n"
						<< "	VIDA: " << ArrayPersonaje[numEnemigoEncontrado]->getHp() << "\n"
						<< "	DANO: " << ArrayPersonaje[numEnemigoEncontrado]->getAttack() << "\n";
					ArrayPersonaje[0]->setAttack(chooseAttack());
					ArrayPersonaje[numEnemigoEncontrado]->setHp((ArrayPersonaje[numEnemigoEncontrado]->getHp()) - ArrayPersonaje[0]->getAttack());
					cout << "Al " << ArrayPersonaje[numEnemigoEncontrado]->getName() << " le quedan " << ArrayPersonaje[numEnemigoEncontrado]->getHp() << " puntos de vida.\n";

					if ((ArrayPersonaje[numEnemigoEncontrado]->getHp() <= 0))
					{
						tablero[ArrayPersonaje[numEnemigoEncontrado]->getPosicionX()][ArrayPersonaje[numEnemigoEncontrado]->getPosicionY()] = celdaVictoria;
						posicionesMuertos[0][numMuertos] = ArrayPersonaje[numEnemigoEncontrado]->getPosicionX();
						posicionesMuertos[1][numMuertos] = ArrayPersonaje[numEnemigoEncontrado]->getPosicionY();
						posicionesMuertos[2][numMuertos] = 1;
						numMuertos++;
						numEnemigos--;
						cout << "Has conseguido matar al " << ArrayPersonaje[numEnemigoEncontrado]->getName() << "\n Quedan " << numEnemigos << " enemigos vivos.\n";						
						enemyAlive = false;
						//printTablero();
					}
					else {
						cout << "CUIDADO!! \n" << "El " << ArrayPersonaje[numEnemigoEncontrado]->getName() << " va a atacar.\n"
							<< "Te ha hecho un ataque de " << ArrayPersonaje[numEnemigoEncontrado]->getAttack() << "\n";
						ArrayPersonaje[0]->setHp(ArrayPersonaje[0]->getHp() - ArrayPersonaje[numEnemigoEncontrado]->getAttack());
						if (ArrayPersonaje[0]->getHp() <= 0){ ArrayPersonaje[0]->setHp(0); }
					}
					cout << "Te quedan " << ArrayPersonaje[0]->getHp() << " puntos de vida.\n";
					
					if(ArrayPersonaje[0]->getHp() <= 0)
					{		
						a++;
						Sleep(1000);
						heroAlive = false;
						tablero[ArrayPersonaje[numEnemigoEncontrado]->getPosicionX()][ArrayPersonaje[numEnemigoEncontrado]->getPosicionY()] = celdaDerrota;
						endGame();
					}
				} while (enemyAlive && heroAlive);
			}

			//ENCUENTRA BOSS FINAL				
			if (comparadorBoss == 0)
			{
				cout << "HAS ENCONTRADO AL FINAL BOSS!!\n" << "EMPIEZA LA BATALLA FINAL\n";
				tablero[Bowser.getPosicionX()][Bowser.getPosicionY()] = celdaBoss;
				printTablero();
				Sleep(2000);
				tablero[Bowser.getPosicionX()][Bowser.getPosicionY()] = celdaCombateFinal;
				printTablero();
				Bowser.printAllStats();
				//BATALLA FINAL
				do
				{
					ArrayPersonaje[0]->setAttack(chooseAttack());
					Bowser.setHp(Bowser.getHp() - ArrayPersonaje[0]->getAttack());
					cout << "Al enemigo final le quedan " << Bowser.getHp() << " puntos de vida.\n";
					if ((Bowser.getHp() <= 0))
					{
						tablero[Bowser.getPosicionX()][Bowser.getPosicionY()] = celdaVictoria;
						bossAlive = false;
						a++;
						gameWin();
					}
					else {
						cout << "CUIDADO!! \n" << Bowser.getName() << " va a atacar.\n";
						int dañoBoss = 0;
						int opcionAtaqueBoss = tipoDañoBoss();
						string tipoAtaque;
						switch (opcionAtaqueBoss)
						{
						case 1:
							dañoBoss = Bowser.getAttack();
							tipoAtaque = " ATAQUE NORMAL ";
							break;
						case 2:
							dañoBoss = Bowser.getSuperAttack();
							tipoAtaque = " SUPER ATAQUE ";
							break;
						case 3:
							dañoBoss = Bowser.getCriticAttack();
							tipoAtaque = " ATAQUE CRITICO ";
							break;
						}

						cout << "Te ha hecho un" << tipoAtaque << "de " << dañoBoss << " \n";
						ArrayPersonaje[0]->setHp(ArrayPersonaje[0]->getHp() - dañoBoss);
						if (ArrayPersonaje[0]->getHp() <= 0) 
						{ 
							ArrayPersonaje[0]->setHp(0); 
						}
					}
					if (a == 1)
					{
						cout << "Te quedan " << ArrayPersonaje[0]->getHp() << " puntos de vida.\n";
					}

					if (ArrayPersonaje[0]->getHp() <= 0)
					{
						a++;						
						Sleep(1000);
						heroAlive = false;
						tablero[Bowser.getPosicionX()][Bowser.getPosicionY()] = celdaDerrota;
						endGame();
					}
				} while (bossAlive && heroAlive);
			}
			else
			{
				tablero[ArrayPersonaje[0]->getPosicionX()][ArrayPersonaje[0]->getPosicionY()] = celdaHeroe;
			}
			if (a == 1)
			{
				printTablero();
			}
						
	}
	return 0;
}

void endGame() {
	printTablero();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	cout << "Has muerto, se acabo el juego\n";
	SetConsoleTextAttribute(hConsole, 15);
}

int chooseAttack() {
	int ataque;
	int daño = 0;
	cout << "Tienes 3 ataques: \n"
		<< "[1] Punos [" << "20" << " de dano] \n"
		<< "[2] Espada [" << "50" << " de dano] \n"
		<< "[3] Magia [" << "100" << " de dano] [" << usosMagia << " usos] \n";
	cout << "Que ataque quieres usar? \n";
	cin >> ataque;
	if (ataque == 1)
	{
		daño = 20;

	}
	else if (ataque == 2)
	{
		daño = 50;
	}
	else if (ataque == 3)
	{
		if (usosMagia >= 1)
		{
			daño = 100;
			usosMagia--;
			cout << "Te quedan " << usosMagia << " usos de magia.\n";
		}
		else
		{
			cout << "No te queda usos de magina.\n";
			chooseAttack();
		}
		
	}
	else
	{
		cout << "Opcion no valida. \n";
	}
	return daño;
}

void printTablero() {
	system("cls");
	cout << "TABLERO\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << tablero[j][i] << " ";
		}
		cout << endl;
	}
	cout << "Quedan " << numEnemigos << " enemigos vivos.\n";
}
int tipoDañoBoss() {
	int probabilidad = rand() % 10 + 1;
	int daño = 0;
	if (probabilidad <= 6)
	{
		daño = 1;
	}
	else if ((probabilidad > 6) && (probabilidad < 9))
	{
		daño = 2;
	}
	else if ((probabilidad >= 9))
	{
		daño = 3;
	}
	return daño;
}

void gameWin() {
	printTablero();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "VICTORIA, HAS GANADO LA PARTIDA!!.\n";
	SetConsoleTextAttribute(hConsole, 15);
	
	
}