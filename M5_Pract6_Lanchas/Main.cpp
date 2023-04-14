#include "Lanchas.h"
#include <iostream>
#include <algorithm>
#include<stdlib.h>
#include<time.h>
#include <vector>
#include <windows.h>
#include <conio.h>


using namespace std;

string dibujo(int);

void main() {
	int turnos = 5;
	int numPlayers = 1 ;	
	cout << "Introduce el numero de jugadores: \n";
	cin >> numPlayers;
	cout << "\n";
	int colour = 0;
	Lancha** ArrayLanchas = new Lancha * [numPlayers];
	for (int i = 0; i != numPlayers; ++i)
	{
		string name;
		cout << "Introduce el nombre del jugador " << i + 1 << ": \n";
		cin >> name;
		colour = 1 + rand() % (14 - 1);
		ArrayLanchas[i] = new Lancha(name, 0, 0, true, colour);
	}

	srand(time(NULL));
	int dado;
	int respuestaNitro = 0;
	int probNitro;
	vector<pair<string, int>> ArrayWinners(numPlayers);
	for (int i = 1; i <= turnos; i++)
	{		
		cout << "|| TURNO " << i << " ||" << "\n";
		for (int j = 0; j <= numPlayers - 1; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ArrayLanchas[j]->getColor());
			cout << "JUGADOR " << j + 1 << " : ";
			ArrayLanchas[j]->printName();
			cout << "\n";
			dado = 1 + rand() % (7 - 1);
			cout << "Vamos a tirar el dado. Has sacado: " << dado << "\n";
			ArrayLanchas[j]->setSpeed(ArrayLanchas[j]->getSpeed() + dado);
			cout << "Velocidad = " << ArrayLanchas[j]->getSpeed() << " m/s\n";
			if (ArrayLanchas[j]->getNitro())
			{
				cout << ArrayLanchas[j]->getDriverName() << " quieres usar el nitro?" << "\n";
				cout << "[1] SI \n";
				cout << "[2] NO \n";
				cin >> respuestaNitro;
			}
			if (respuestaNitro == 1 && ArrayLanchas[j]->getNitro())
			{
				cout << "Has usado tu unica NITRO \n";
				ArrayLanchas[j]->setNitro(false);
				probNitro = rand() % 2;
				if (probNitro == 0)
				{
					cout << "NITRO FALLADA \n";
					ArrayLanchas[j]->setSpeed((ArrayLanchas[j]->getSpeed()) / 2);
				}
				else
				{
					cout << "NITRO CORRECTA \n";
					ArrayLanchas[j]->setSpeed((ArrayLanchas[j]->getSpeed()) * 2);
				}
				cout << "Nueva velocidad = " << ArrayLanchas[j]->getSpeed() << "\n";
			}

			if (respuestaNitro == 2 && ArrayLanchas[j]->getNitro())
			{
				cout << "Te sigue quedando un uso de NITRO \n";
			}

			if (respuestaNitro == 1 && !ArrayLanchas[j]->getNitro())
			{
				cout << "No te queda NITRO \n";
			}

			ArrayLanchas[j]->setDistancia(ArrayLanchas[j]->getDistancia() + (ArrayLanchas[j]->getSpeed() * 100));
			cout << "Jugador " << j + 1 << " ha recorrido " << ArrayLanchas[j]->getDistancia() << " metros. \n";

			string barco = "       |>\n      /|\\ \n     / | \\\n ___/  |  \\___\n \\____________/ \n";
			int veces = ArrayLanchas[j]->getDistancia() / 100;
			int color = ArrayLanchas[j]->getColor();
			cout << dibujo(veces);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
			if (j < numPlayers)
			{
				cout << "_____________________________________________________________________ \n";
			}
		}
		cout << "============================================================== \n";
		if (i < turnos) {
			for (int i = 0; i < numPlayers; i++)
			{
				string valor_string;
				int valor_int;
				valor_string = ArrayLanchas[i]->getDriverName();
				valor_int = ArrayLanchas[i]->getDistancia();
				ArrayWinners[i] = make_pair(valor_string, valor_int);
			}

			sort(ArrayWinners.begin(), ArrayWinners.end(), [](const auto& a, const auto& b) { 
				return a.second > b.second; 
				}
			);
			if (i < turnos) {
				cout << "//CLASIFICACION PROVISIONAL" << "\\" << "\\" << "\n";
				for (int i = 0; i < ArrayWinners.size(); i++) {
					cout << i + 1 << "o -> " << ArrayWinners[i].first << ": " << ArrayWinners[i].second << " metros" << endl;
				}
				cout << "============================================================== \n";
			}
		}
	}
	sort(ArrayWinners.begin(), ArrayWinners.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
		cout << "//CLASIFICACION FINAL" << "\\" << "\\" << "\n";
		for (int i = 0; i < ArrayWinners.size(); i++) {
			cout << i + 1 << "o -> " << ArrayWinners[i].first << ": " << ArrayWinners[i].second << " metros" << endl;
		}
		
}

string dibujo(int pVeces) {
	cout << pVeces << "\n";
	string barco = 
		string(pVeces, ' ') + "       |>\n" +
		string(pVeces, ' ') + "      /|\\ \n" +
		string(pVeces, ' ') + "     / | \\\n" +
		string(pVeces, ' ') + " ___/  |  \\____\n " +
		string(pVeces, '~') + "\\_____________/ \n";
	return barco;
}
