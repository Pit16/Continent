//============================================================================
// Name        : Continent.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include "Panstwo.h"
#include "Pasmo_gorskie.h"
#include "Kontynent.h"

#define _DEBUG_FLAG 1
#include "Debugowanie.h"

using namespace std;

bool test_pobierz_nazwe_panstwa();
void test_operator_mniejszosci_panstwa();
void test_operator_wiekszosci_panstwa();
void test_operator_rownosci_panstwa();
void test_operator_nierownosci_panstwa();
void test_operator_indeksowania();
void test_dodawania_panstw();
void test_dodawania_kontynentu();
void test_kopiowanie_kontynentu();
void glowny_program();
void test_zliczanie_kontynentow();
void test_operator_strumieniowy_kontynent();
void test_operator_przypisania_kontynent();
void test_srednie_zaludnienie();
void zmiana_parametrow(Kontynent&);
void test_usuwanie_panstwa();
void dodaj_panstwo(Kontynent&);
void test_dodaj_pasmo();
/* TODO: interfejs u¿ytkownika - co z wyswieltleniem panstw??
 * TODO: _DEBUG
 * TODO: pasma_gorskie

*/
int main(void)
{
	_debug("Debugger dziala");
	//test_usuwanie_panstwa();
	glowny_program();
	return 0;

}

void glowny_program()
{
	Kontynent kontynent("Afryka");
	Panstwo niemcy("Niemcy", 100, 1600);
	Panstwo usa("Usa", 200, 6100);
	Panstwo chiny("Chiny", 200, 10000);
	Panstwo indie("Indie", 100, 30000);
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
	 		cout<<"(4) Pokaz srednie zaludnienie"<<endl;				// to jest dodatkowa opcja, ktora wybralem
	 		cin>> komenda;
	 		switch(komenda)
	 		{
	 		case 0: return;
	 		case 1: cout<<kontynent; break;
	 		case 2:	zmiana_parametrow(kontynent); break;
	 		case 3: dodaj_panstwo(kontynent); break;
	 		case 4: cout<<kontynent.srednie_zaludnienie()<<endl; break;
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
			Panstwo nowe_panstwo(nazwa, powierzchnia, populacja);
			nowe_panstwo.ustaw_stolice(stolica);
			nowe_panstwo.ustaw_jezyk(jezyk);
			nowe_panstwo.ustaw_pkb(pkb);
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
	Panstwo nowe_panstwo(nazwa, powierzchnia, populacja);
	nowe_panstwo.ustaw_stolice(stolica);
	nowe_panstwo.ustaw_jezyk(jezyk);
	nowe_panstwo.ustaw_pkb(pkb);
	kontynent.dodaj_panstwo(nowe_panstwo);
}

bool test_pobierz_nazwe_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	cout << niemcy.pobierz_nazwe() << endl;
	if("Niemcy" == niemcy.pobierz_nazwe())
		return true;
	else
		return false;
}

void test_operator_mniejszosci_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	Panstwo usa("Usa", 200, 10);
	if(niemcy<usa)
		cout<<"Operator mniejszosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator mniejszosci NIE DZIALA"<<endl;
}


void test_operator_wiekszosci_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	Panstwo usa("Usa", 200, 10);
	if(usa>niemcy)
		cout<<"Operator wiekszosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator wiekszosci NIE DZIALA"<<endl;
}

void test_operator_rownosci_panstwa()
{
	Panstwo chiny("Chiny", 10, 100);
	Panstwo indie("Indie", 10, 10);
	if(chiny == indie)
		cout<<"Operator rownosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator rownosci NIE DZIALA"<<endl;
}


void test_operator_nierownosci_panstwa()
{
	Panstwo chiny("Chiny", 30, 100);
	Panstwo indie("Indie", 10, 10);
	if(chiny != indie)
		cout<<"Operator nierownosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator nierownosci NIE DZIALA"<<endl;
}

void test_operator_indeksowania()
{
	Panstwo andora("Andora", 100, 10);
	Panstwo polska("Polska", 50, 100);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(polska);
	cout<<europa[1]<<endl;
}

void test_dodawania_panstw()
{

	Panstwo polska("Polska", 50, 100);
	Panstwo andora("Andora", 100, 10);
	Panstwo anglia("Anglia", 90, 10);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(polska);
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	cout<<europa.pobierz_powierzchnie()<<endl;
	cout<<europa.najwieksze_panstwo()<<endl;
}

void test_dodawania_kontynentu()
{
	Kontynent azja("Azja");
	cout<<"dodano azja"<<endl;
}

void test_kopiowanie_kontynentu()
{
	cout<<"=======test kopiowania kontynentu========="<<endl;
	Kontynent k1("pierwszy");
	Panstwo anglia("Anglia", 90, 10);
	k1.dodaj_panstwo(anglia);
	Kontynent k2(k1);
	cout<<k1.pobierz_powierzchnie()<<endl;
	cout<<k2.pobierz_powierzchnie()<<endl;
	cout<<"=======koniec testu kopiowania kontynentu========="<<endl;
}

void test_zliczanie_kontynentow()
{
	Kontynent jeden("jeden");
	Kontynent dwa("dwa");
	Kontynent trzy(dwa);
	cout<<"Liczba kontynentow: "<<Kontynent::pobierz_licznik()<<endl;
}

void test_operator_strumieniowy_kontynent()
{
	Kontynent dwa("Australia");
	cout<<dwa;
}

void test_operator_przypisania_kontynent()
{
	Kontynent k1("Europa");
	Panstwo anglia("Anglia", 90, 10);
	k1.dodaj_panstwo(anglia);
	Kontynent k2("Azja");
	k2=k1;
	cout<<k2;
}

void test_srednie_zaludnienie()
{
	Panstwo andora("Andora", 100, 1056);
	Panstwo anglia("Anglia", 90, 500);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	cout<<"srednie zaludnienie wynosi: "<<europa.srednie_zaludnienie()<<endl;
}

void test_usuwanie_panstwa()
{
	Panstwo andora("Andora", 100, 1056);
	Panstwo anglia("Anglia", 90, 500);
	Panstwo polska("Polska", 200, 400);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	europa.dodaj_panstwo(polska);
	cout<<europa<<endl;
	europa.usun_panstwo(1);
	cout<<europa;
}

void test_dodaj_pasmo()
{
	Pasmo_gorskie tatry("Tatry", 1300);
	Pasmo_gorskie andy("Andy", 1800);
	Kontynent europa("Europa");
	//europa.dodaj_pasmo(tatry);
	//europa.dodaj_pasmo(andy);

}
/*
 * Kontynent k1, k2;
 * k1.dodajPanstwo..
 * k1.dodajPasmo...
 * k2 = k1;
 * k1.pasmo[0].wysokosc = 0;
 * cout << k1 << endl;
 * cout << k2 << endl;
 *
 */

