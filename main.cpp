//============================================================================
// Name        : Continent.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "KontynentZPasmemGorskim.h"
#include "KontynentKolorSkory.h"
#include "Kontynent.h"

#include "Debugowanie.h"

using namespace std;

void glowny_program();
void zmiana_parametrow(Kontynent&);
void dodaj_panstwo(Kontynent&);
void pokaz_panstwa(Kontynent&);


int main(void)
{
	debug("Debugger dziala");
	//test_usuwanie_panstwa();
	//glowny_program();
	KontynentZPasmemGorskim* kontynentZpasmemGorskim = new KontynentZPasmemGorskim("Australia");
	Pasmo_gorskie* tatry = new Pasmo_gorskie("Tatry", 1300);
	Pasmo_gorskie* andy = new Pasmo_gorskie("Andy", 1800);
	kontynentZpasmemGorskim->dodaj_pasmo(tatry);
	kontynentZpasmemGorskim->dodaj_pasmo(andy);
	KontynentKolorSkory* kontynentKolorSkory = new KontynentKolorSkory("Afryka", "czarny");
	Kontynent* kontynent = new Kontynent("Azja");
	Panstwo* usa = new Panstwo("Usa", 200, 6100);
	kontynent->dodaj_panstwo(usa);

	/*Panstwo* austria = new Panstwo("Austria", 500, 500);
	ifstream plik("panstwa.txt");
	austria->odczyt_z_pliku(plik);
	cout<<*austria;
	*/
	Kontynent* kontynent_odczyt = new Kontynent("Do.odczytu");
	ifstream plik("kontynent.txt");
	kontynent_odczyt->odczyt_z_pliku(plik);
	cout<<*kontynent_odczyt;
/*
	vector <Obszar*> kontynenty;
	kontynenty.push_back(kontynentKolorSkory);
	kontynenty.push_back(kontynentZpasmemGorskim);
	kontynenty.push_back(kontynent);
	for(int i=0; i<kontynenty.size(); i++)
		cout<<kontynenty[i]->pokaz_ceche_charakterystyczna()<<endl;
	*/

	return 0;

}

void glowny_program()
{
	Kontynent kontynent("Afryka");
	Panstwo* niemcy = new Panstwo("Niemcy", 100, 1600);
	Panstwo* usa = new Panstwo("Usa", 200, 6100);
	Panstwo* chiny = new Panstwo("Chiny", 200, 10000);
	Panstwo* indie = new Panstwo("Indie", 100, 30000);
	kontynent.dodaj_panstwo(niemcy);
	kontynent.dodaj_panstwo(usa);
	kontynent.dodaj_panstwo(chiny);
	kontynent.dodaj_panstwo(indie);

	int komenda = 0;
	 	while(1)
	 	{
	 		cout<<endl;
	 		cout<<"======== MENU PROGRAMU ========"<<endl;
	 		cout<<"(0) Wyjscie z programu"<<endl;
	 		cout<<"(1) Wyswietl aktualny stan obiektu"<<endl;
	 		cout<<"(2) Zmiana parametru obiektu"<<endl;
	 		cout<<"(3) Dodaj panstwo"<<endl;
	 		cout<<"(4) Pokaz srednie zaludnienie"<<endl; // to jest dodatkowa opcja, ktora wybralem
	 		cout<<"(5) Pokaz szczegoly panstwa"<<endl;
	 		cin>> komenda;
	 		switch(komenda)
	 		{
	 		case 0: return;
	 		case 1: cout<<kontynent; break;
	 		case 2:	zmiana_parametrow(kontynent); break;
	 		case 3: dodaj_panstwo(kontynent); break;
	 		case 4: cout<<kontynent.srednie_zaludnienie()<<endl; break;
	 		case 5: pokaz_panstwa(kontynent); break;
	 		default: cout<<"zla komenda"<<endl; break;
	 		}
	 	}
}

void zmiana_parametrow(Kontynent& kontynent)
{
	if(kontynent.pobierz_liczbe_panstw()==0)
	{
		cout<<"brak panstw"<<endl;
		return;
	}
	for(int i=0; i<kontynent.pobierz_liczbe_panstw(); i++)
		cout<<"nazwa panstwa nr: "<<i<<" : "<<kontynent[i]<<endl;

	int indeks_panstwa=0;
	while(1)
	{
		cout<<"WYBIERZ PANSTWO"<<endl;
		cin>>indeks_panstwa;
		if(indeks_panstwa<kontynent.pobierz_liczbe_panstw() && indeks_panstwa >= 0)
			{
			string nazwa = " ", stolica= " ", jezyk = " ";
			int powierzchnia=0, populacja=0, pkb=0;

			kontynent.usun_panstwo(indeks_panstwa);
			cout<<"Podaj nowa nazwe panstwa: "<<endl;
			cin>>nazwa;
			cout<<"Podaj nowa powierzchnie panstwa: "<<endl;
			cin>>powierzchnia;
			cout<<"Podaj nowa liczbe mieszkancow panstwa: "<<endl;
			cin>>populacja;
			cout<<"Podaj nowa nazwe stolicy panstwa: "<<endl;
			cin>>stolica;
			cout<<"Podaj nowy jezyk dla tego panstwa: "<<endl;
			cin>>jezyk;
			cout<<"Podaj nowe pkb dla tego panstwa: "<<endl;
			cin>>pkb;
			Panstwo* nowe_panstwo = new Panstwo(nazwa, powierzchnia, populacja);
			nowe_panstwo->ustaw_stolice(stolica);
			nowe_panstwo->ustaw_jezyk(jezyk);
			nowe_panstwo->ustaw_pkb(pkb);
			kontynent.dodaj_panstwo(nowe_panstwo);
			break;
			}

		else
			cout<<"zly indeks"<<endl;
		break;
	}
}

void dodaj_panstwo(Kontynent& kontynent)
{
	string nazwa = " ", stolica= " ", jezyk = " ";
	int powierzchnia=0, populacja=0, pkb=0;
	cout<<"Podaj nowa nazwe panstwa: "<<endl;
	cin>>nazwa;
	cout<<"Podaj nowa powierzchnie panstwa: "<<endl;
	cin>>powierzchnia;
	cout<<"Podaj nowa liczbe mieszkancow panstwa: "<<endl;
	cin>>populacja;
	cout<<"Podaj nowa nazwe stolicy panstwa: "<<endl;
	cin>>stolica;
	cout<<"Podaj nowy jezyk dla tego panstwa: "<<endl;
	cin>>jezyk;
	cout<<"Podaj nowe pkb dla tego panstwa: "<<endl;
	cin>>pkb;
	Panstwo* nowe_panstwo = new Panstwo(nazwa, powierzchnia, populacja);
	nowe_panstwo->ustaw_stolice(stolica);
	nowe_panstwo->ustaw_jezyk(jezyk);
	nowe_panstwo->ustaw_pkb(pkb);
	kontynent.dodaj_panstwo(nowe_panstwo);
}


void pokaz_panstwa(Kontynent& kontynent)
{
	for(int i=0; i<kontynent.pobierz_liczbe_panstw(); i++)
		cout<<*kontynent.pokaz_panstwo(i);
}
