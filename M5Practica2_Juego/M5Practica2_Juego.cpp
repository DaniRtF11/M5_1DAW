// M5Practica2_Juego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h>
using namespace std; //quita el 'std::' que estaba antes del cout



// enemigo 1
string EnemyName1 = "Creeper";
int EnemyHP1 = 50;
int EnemyDamage1 = rand() % 100 + 1;
bool EnemyIsAlive1 = true;

// enemigo 2
string EnemyName2 = "Zombie";
int EnemyHP2 = 50;
int EnemyDamage2 = rand() % 100 + 1;

//heroe
string HeroName;
int HeroHP = 170;
int HeroDamage;

//tipos ataque Heroe
string weapon;
string espada;
string flechas;
string magia;
int MagicUse = 3;

//Jugador
int PlayerResponseEnemy;
int PlayerResponseWeapon;


//juego//
int main() {
	PlaySound(TEXT("MusicaGeneral.wav"),NULL, SND_FILENAME | SND_ASYNC);
	cout << "Como se llama el heroe?\n";
	cin >> HeroName;
	cout << "Hola " << HeroName << " bienvenido al juego...\n" << "Empecemos esta aventura...";
	cout << "Han aparecido 2 enemigos...\n";
	cout << "El enemigo " << EnemyName1 << " que tiene " << EnemyHP1 << " puntos de vida.\n";
	cout << "El enemigo " << EnemyName2 << " que tiene " << EnemyHP2 << " puntos de vida.\n";

	// Pelea con todos vivos//
	//while (HeroHP > 0 && (EnemyHP1 > 0 || EnemyHP2 > 0)) {
	while (HeroHP > 0 && EnemyHP1 > 0 && EnemyHP2 > 0) {
		cout << "A que enemigo quieres atacar? \n"
			<< "[1]" << EnemyName1 << ".\n"
			<< "[2]" << EnemyName2 << ".\n";
		cin >> PlayerResponseEnemy;
		cout << "Que ataque quieres usar? \n"
			<< "[1] Ataque con espada (35 de dano)\n"
			<< "[2] Ataque con magia (50 de dano)\n"
			<< "[3] Ataque con flechas (15 de dano)\n";
		cin >> PlayerResponseWeapon;
		//Elección ataque//
		if (PlayerResponseWeapon == 1) {
			weapon = "espada";
			HeroDamage = 35;
			cout << "Has usado la espada y has hecho " << HeroDamage << " puntos de dano.\n";
		}
		if (PlayerResponseWeapon == 2) {
			weapon = "magia";
			MagicUse -= 1;
			if (MagicUse >= 0) {
				HeroDamage = 60;
				cout << "Te quedan " << MagicUse << " usos de magia.\n";
				cout << "Has usado la magia y has hecho " << HeroDamage << " puntos de dano.\n";
			}
			if (MagicUse < 0) {
				HeroDamage = 0;
				cout << "No te queda mana.\n" << "Usa otro ataque.\n";
			}
		}
		if (PlayerResponseWeapon == 3) {
			weapon = "flechas";
			HeroDamage = 15;
			cout << "Has usado las flechas y has hecho " << HeroDamage << " puntos de dano.\n";
		}
		//Elección enemigo//
		if (PlayerResponseEnemy == 1) {
			EnemyHP1 = EnemyHP1 - HeroDamage;
		}
		if (PlayerResponseEnemy == 2) {
			EnemyHP2 = EnemyHP2 - HeroDamage;
		}
		if (EnemyHP1 <= 0 || EnemyHP2 <= 0) {
			break;
		}
		cout << "Al " << EnemyName1 << " le quedan " << EnemyHP1 << " puntos de vida.\n";
		cout << "Al " << EnemyName2 << " le quedan " << EnemyHP2 << " puntos de vida.\n";
		//Enemigos atacan//
		if (EnemyHP1 > 0 && EnemyHP2 > 0) {
			EnemyDamage1 = rand() % 100 + 1;
			EnemyDamage2 = rand() % 100 + 1;
			cout << "¡Cuidado!\n" << "¡Los enemigos te atacan!\n";
			cout << "El " << EnemyName1 << " te ha hecho un ataque de " << EnemyDamage1 << ".\n";
			cout << "El " << EnemyName2 << " te ha hecho un ataque de " << EnemyDamage2 << ".\n";
			HeroHP = HeroHP - EnemyDamage1 - EnemyDamage2;
			if (HeroHP <= 0) {
				break;
			}
			cout << "Te quedan " << HeroHP << " puntos de vida.\n";
		}
	}

	//Heroe muerto//
	if (HeroHP <= 0) {
		cout << "Los enemigos te han matado.\n";
		cout << "FIN DEL JUEGO.";
	}

	//2 Enemigos muertos//
	if (EnemyHP1 <= 0 && EnemyHP2 <= 0) {
		cout << "FELICIDADES!! HAS MATADO A LOS 2 ENEMIGOS!!\n";
		cout << "HAS GANADO LA PARTIDA!!";
	}

	//Enemigo 1 muerto//
	if (EnemyHP1 <= 0 && EnemyHP2 > 0) {
		cout << "Al " << EnemyName2 << " le quedan " << EnemyHP2 << " puntos de vida.\n";
		HeroHP = HeroHP - EnemyDamage2;
		cout << "¡Cuidado!\n" << "¡El " << EnemyName2 << " te ataca!\n";
		cout << "El " << EnemyName2 << " te ha hecho un ataque de " << EnemyDamage2 << ".\n";
		cout << "Te quedan " << HeroHP << " puntos de vida.\n";
		cout << "¡¡MUY BIEN!!" << " Has matado al " << EnemyName1 << ".\n";
		cout << "Ahora solo puedes atacar al " << EnemyName2 << "que tiene " << EnemyHP2 << " puntos de vida.\n";
		while (EnemyHP2 > 0) {
			//Elección ataque//
			cout << "Que ataque quieres usar? \n"
				<< "[1] Ataque con espada (35 de dano)\n"
				<< "[2] Ataque con magia (50 de dano)\n"
				<< "[3] Ataque con flechas (15 de dano)\n";
			cin >> PlayerResponseWeapon;
			if (PlayerResponseWeapon == 1) {
				weapon = "espada";
				HeroDamage = 35;
				cout << "Has usado la espada y has hecho " << HeroDamage << " puntos de dano.\n";
			}
			if (PlayerResponseWeapon == 2) {
				weapon = "magia";
				MagicUse -= 1;
				if (MagicUse >= 0) {
					HeroDamage = 60;
					cout << "Te quedan " << MagicUse << " usos de magia.\n";
					cout << "Has usado la magia y has hecho " << HeroDamage << " puntos de dano.\n";
				}
				if (MagicUse < 0) {
					HeroDamage = 0;
					cout << "No te queda mana.\n" << "Usa otro ataque.\n";
				}
			}
			if (PlayerResponseWeapon == 3) {
				weapon = "flechas";
				HeroDamage = 15;
				cout << "Has usado las flechas y has hecho " << HeroDamage << " puntos de dano.\n";
			}
			EnemyHP2 = EnemyHP2 - HeroDamage;
			if (EnemyHP2 <= 0) {
				cout << "Has matado al " << EnemyName1 << ".\n" << "HAS GANADO LA PARTIDA\n" << "FIN DEL JUEGO\n";
				break;
			}
			cout << "El " << EnemyName1 << " esta muerto.\n";
			cout << "Al " << EnemyName2 << " le quedan " << EnemyHP2 << " puntos de vida.\n";
			// Enemigo 2 ataca//
			EnemyDamage2 = rand() % 100 + 1;
			HeroHP = HeroHP - EnemyDamage2;
			if (HeroHP <= 0) {
				break;
			}
			cout << "¡Cuidado!\n" << "¡El " << EnemyName2 << " te ataca!\n";
			cout << "El " << EnemyName2 << " te ha hecho un ataque de " << EnemyDamage2 << ".\n";
			cout << "Te quedan " << HeroHP << " puntos de vida.\n";

		}
	}

	//Enemigo 2 muerto//
	if (EnemyHP2 <= 0 && EnemyHP1 > 0) {
		cout << "Al " << EnemyName1 << " le quedan " << EnemyHP1 << " puntos de vida.\n";
		HeroHP = HeroHP - EnemyDamage1;
		cout << "¡Cuidado!\n" << "¡El " << EnemyName1 << " te ataca!\n";
		cout << "El " << EnemyName1 << " te ha hecho un ataque de " << EnemyDamage1 << ".\n";
		cout << "Te quedan " << HeroHP << " puntos de vida.\n";
		cout << "¡¡MUY BIEN!!" << " Has matado al " << EnemyName2 << ".\n";
		cout << "Ahora solo puedes atacar al " << EnemyName1 << " que tiene " << EnemyHP1 << " puntos de vida.\n";
		while (EnemyHP1 > 0) {
			//Elección ataque//
			cout << "Que ataque quieres usar? \n"
				<< "[1] Ataque con espada (35 de dano)\n"
				<< "[2] Ataque con magia (50 de dano)\n"
				<< "[3] Ataque con flechas (15 de dano)\n";
			cin >> PlayerResponseWeapon;
			if (PlayerResponseWeapon == 1) {
				weapon = "espada";
				HeroDamage = 35;
				cout << "Has usado la espada y has hecho " << HeroDamage << " puntos de dano.\n";
			}
			if (PlayerResponseWeapon == 2) {
				weapon = "magia";
				MagicUse -= 1;
				if (MagicUse >= 0) {
					HeroDamage = 60;
					cout << "Te quedan " << MagicUse << " usos de magia.\n";
					cout << "Has usado la magia y has hecho " << HeroDamage << " puntos de dano.\n";
				}
				if (MagicUse < 0) {
					HeroDamage = 0;
					cout << "No te queda mana.\n" << "Usa otro ataque.\n";
				}
			}
			if (PlayerResponseWeapon == 3) {
				weapon = "flechas";
				HeroDamage = 15;
				cout << "Has usado las flechas y has hecho " << HeroDamage << " puntos de dano.\n";
			}
			EnemyHP1 = EnemyHP1 - HeroDamage;
			if (EnemyHP1 <= 0) {
				cout << "Has matado al " << EnemyName2 << ".\n" << "HAS GANADO LA PARTIDA\n" << "FIN DEL JUEGO\n";
				break;
			}
			cout << "El " << EnemyName2 << " esta muerto.\n";
			cout << "Al " << EnemyName1 << " le quedan " << EnemyHP1 << " puntos de vida.\n";
			// Enemigo 1 ataca//
			EnemyDamage1 = rand() % 100 + 1;
			HeroHP = HeroHP - EnemyDamage1;
			if (HeroHP <= 0) {
				break;
			}
			cout << "¡Cuidado!\n" << "¡El " << EnemyName1 << " te ataca!\n";
			cout << "El " << EnemyName1 << " te ha hecho un ataque de " << EnemyDamage1 << ".\n";

		}
	}
}
