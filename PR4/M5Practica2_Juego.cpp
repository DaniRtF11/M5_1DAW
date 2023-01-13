// M5Practica2_Juego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h>
using namespace std;



//Enemigo 1
string EnemyName1 = "Creeper";
int EnemyHP1 = 50;
int EnemyDamage1 = rand() % 100 + 1;
bool Enemy1IsAlive = true;

//Enemigo 2
string EnemyName2 = "Zombie";
int EnemyHP2 = 50;
int EnemyDamage2 = rand() % 100 + 1;
bool Enemy2IsAlive = true;

//Heroe
string HeroName;
int HeroHP = 10000;
int HeroDamage;
bool HeroIsAlive = true;

//Tipos ataque Heroe
string weapon;
string espada;
string flechas;
string magia;
int MagicUse = 3;

//Jugador
int PlayerResponseEnemy;
int PlayerResponseWeapon;
string EnemyAlive;
string EnemyDead;
int EnemyAliveDamage;
int EnemyAliveHP;
bool EnemyAliveStillAlive = true;

//FUNCIONES
void StartGame() {
	cout << "Como se llama el heroe?\n";
	cin >> HeroName;
	cout << "Hola " << HeroName << " bienvenido al juego...\n" << "Empecemos esta aventura...";
	cout << "Han aparecido 2 enemigos...\n";
	cout << "El enemigo " << EnemyName1 << " que tiene " << EnemyHP1 << " puntos de vida.\n";
	cout << "El enemigo " << EnemyName2 << " que tiene " << EnemyHP2 << " puntos de vida.\n";
}
void AtackChooseNoMagic(){
	cout << "Que ataque quieres usar? \n"
		<< "[1] Ataque con espada (35 de dano)\n"
		<< "[2] Ataque con flechas (15 de dano)\n";
	cin >> PlayerResponseWeapon;
	if (PlayerResponseWeapon == 1) {
		weapon = "espada";
		HeroDamage = 35;
	}
	if (PlayerResponseWeapon == 2) {
		weapon = "flechas";
		HeroDamage = 15;
	}
}
void AttackChoose() {	
	cout << "Que ataque quieres usar? \n"
		<< "[1] Ataque con espada (35 de dano)\n"
		<< "[2] Ataque con flechas (15 de dano)\n"
		<< "[3] Ataque con magia (50 de dano)\n";
	cin >> PlayerResponseWeapon;
	if (PlayerResponseWeapon == 1) {
		weapon = "espada";
		HeroDamage = 35;
	}
	if (PlayerResponseWeapon == 2) {
		weapon = "flechas";
		HeroDamage = 15;
	}
	if (PlayerResponseWeapon == 3) {
		weapon = "magia";
		MagicUse -= 1;
		if (MagicUse >= 0) {
			HeroDamage = 50;
			cout << "Te quedan " << MagicUse << " usos de magia.\n";
		}
		if (MagicUse < 0) {
			HeroDamage = 0;
			cout << "No te queda mana.\n" << "Usa otro ataque.\n";
			AtackChooseNoMagic();
		}
	}
	
}
int EnemyChoose() {
	cout << "A que enemigo quieres atacar? \n"
		<< "[1]" << EnemyName1 << ".\n"
		<< "[2]" << EnemyName2 << ".\n";
	cin >> PlayerResponseEnemy;
	return PlayerResponseEnemy;
}
void AttackingBothEnemies(int& EnemyHP, string& EnemyName, bool& EnemyIsAlive) {
		cout << "Has usado " << weapon << " y has hecho " << HeroDamage << " puntos de dano al " << EnemyName << ".\n";
		EnemyHP = EnemyHP - HeroDamage;
		cout << "Al " << EnemyName1 << " le quedan " << EnemyHP1 << " puntos de vida.\n";
		cout << "Al " << EnemyName2 << " le quedan " << EnemyHP2 << " puntos de vida.\n";
		if (EnemyHP <= 0) {
			EnemyIsAlive = false;
			;
		}
		else
		{
			EnemyIsAlive = true;
		}
}
void BothEnemyAtack() {
	EnemyDamage1 = rand() % 100 + 1;
	EnemyDamage2 = rand() % 100 + 1;
	cout << "¡Cuidado!\n" << "¡Los enemigos te atacan!\n";
	cout << "El " << EnemyName1 << " te ha hecho un ataque de " << EnemyDamage1 << ".\n";
	cout << "El " << EnemyName2 << " te ha hecho un ataque de " << EnemyDamage2 << ".\n";
	HeroHP = HeroHP - EnemyDamage1 - EnemyDamage2;
	if (HeroHP <= 0) {
		HeroIsAlive = false;
		;
	}
	else
	{
		HeroIsAlive = true;
		cout << "Te quedan " << HeroHP << " puntos de vida.\n";
	}
	
	
	
}
void HeroDead() {
	HeroHP = 0;
	cout << "Te quedan " << HeroHP << " puntos de vida.\n";
	cout << "Los enemigos te han matado.\n";
	cout << "FIN DEL JUEGO.";
}
void BothEnemyDead() {
	cout << "FELICIDADES!! HAS MATADO A LOS 2 ENEMIGOS!!\n";
	cout << "HAS GANADO LA PARTIDA!!";
}
void EnemyKilled(string& EnemyDead, int& EnemiesDamage, string& EnemyAlive, int& EnemiesHP) {
	cout << "¡¡MUY BIEN!!" << " Has matado al " << EnemyDead << ".\n";	
	cout << "¡Cuidado!\n" << "¡El " << EnemyAlive << " te ataca!\n";
	cout << "El " << EnemyAlive << " te ha hecho un ataque de " << EnemiesDamage << ".\n";
	EnemiesDamage = rand() % 100 + 1;
	HeroHP = HeroHP - EnemiesDamage;
	if (HeroHP <= 0) {
		HeroIsAlive = false;
		;
	}
	else
	{
		cout << "Te quedan " << HeroHP << " puntos de vida.\n";
		cout << "Ahora solo puedes atacar al " << EnemyAlive << " que tiene " << EnemiesHP << " puntos de vida.\n";
	}
	
}
void HeroAtackOneEnemyDead(int& EnemiesHP, string& EnemyDead, string& EnemyAlive, int& EnemyHP) {
	EnemiesHP = EnemiesHP - HeroDamage;
	if (EnemiesHP <= 0) {
		EnemyAliveStillAlive = false;
		;
	}
	else {
		cout << "El " << EnemyDead << " esta muerto.\n";
		cout << "Al " << EnemyAlive << " le quedan " << EnemyHP << " puntos de vida.\n";
		EnemyAliveStillAlive = true;
	}
}
void OneEnemyAttack(int& EnemiesDamage, string& EnemyNames) {
	EnemiesDamage = rand() % 100 + 1;
	HeroHP = HeroHP - EnemiesDamage;
	cout << "¡Cuidado!\n" << "¡El " << EnemyNames << " te ataca!\n";
	cout << "El " << EnemyNames << " te ha hecho un ataque de " << EnemiesDamage << ".\n";
	
	if (HeroHP <= 0) {
		HeroIsAlive = false;
		;
	}
	else
	{
		cout << "Te quedan " << HeroHP << " puntos de vida.\n";
		HeroIsAlive = true;
	}
}

//juego//
int main() {
	PlaySound(TEXT("MusicaGeneral.wav"), NULL, SND_FILENAME | SND_ASYNC);
	StartGame();
	// Pelea con todos vivos//
	while (HeroIsAlive == true && Enemy1IsAlive == true && Enemy2IsAlive == true) {
		//Elección ataque
		AttackChoose();
		//Elección enemigo//
		EnemyChoose();
		if (PlayerResponseEnemy == 1) { AttackingBothEnemies(EnemyHP1, EnemyName1, Enemy1IsAlive); }
		if (PlayerResponseEnemy == 2) { AttackingBothEnemies(EnemyHP2, EnemyName2, Enemy2IsAlive); }
		if (Enemy1IsAlive == false && Enemy2IsAlive == true){
			EnemyDead = EnemyName1;
			EnemyAlive = EnemyName2;
			EnemyAliveDamage = EnemyDamage2;
			EnemyAliveHP = EnemyHP2;
		}
		if (Enemy1IsAlive == true && Enemy2IsAlive == false) {
			EnemyDead = EnemyName2;
			EnemyAlive = EnemyName1;
			EnemyAliveDamage = EnemyDamage1;
			EnemyAliveHP = EnemyHP1;
		}		
		//Enemigos atacan//
		if (Enemy1IsAlive == true && Enemy2IsAlive == true) {
			BothEnemyAtack();
			if (HeroIsAlive = false) {
				break;
				;
			}
		}
		//Enemigo muerto//
		if (Enemy1IsAlive == false || Enemy2IsAlive == false) {
			EnemyKilled(EnemyDead, EnemyAliveDamage, EnemyAlive, EnemyAliveHP);
			if (HeroIsAlive == false) {
				break;
			}
			while (EnemyAliveStillAlive == true) {
				//Elección ataque//
				AttackChoose();
				HeroAtackOneEnemyDead(EnemyAliveHP, EnemyDead, EnemyAlive, EnemyAliveHP);
				if (EnemyAliveStillAlive == false) {
					Enemy1IsAlive = false;
					Enemy2IsAlive = false;
					break;
				}
				// Enemigo 2 ataca//
				OneEnemyAttack(EnemyAliveDamage, EnemyAlive);
				if (HeroIsAlive == false) {
					break;
				}
			}
		}
	}
	//2 Enemigos muertos//
	if (Enemy1IsAlive == false && Enemy2IsAlive == false) {
		BothEnemyDead();
	}
	
	//Heroe muerto//
	if (HeroIsAlive == false) {
		HeroDead();
	}
}