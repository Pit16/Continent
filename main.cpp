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
#include "testy.h"

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
	glowny_program();


	return 0;

}

void glowny_program()
{
	Panstwo* niemcy = new Panstwo("Niemcy", 100, 200);
	Panstwo* usa = new Panstwo("Usa", 200, 600);
	Panstwo* chiny = new Panstwo("Chiny", 200, 100);
	Panstwo* indie = new Panstwo("Indie", 100, 300);

	Kontynent* kontynent = new Kontynent("Afryka");
	kontynent->dodaj_panstwo(niemcy);
	kontynent->dodaj_panstwo(usa);
	kontynent->dodaj_panstwo(chiny);
	kontynent->dodaj_panstwo(indie);

	KontynentZPasmemGorskim* kontynentZpasmemGorskim = new KontynentZPasmemGorskim("Australia");
	kontynentZpasmemGorskim->dodaj_panstwo(niemcy);
	kontynentZpasmemGorskim->dodaj_panstwo(usa);
	kontynentZpasmemGorskim->dodaj_panstwo(chiny);
	kontynentZpasmemGorskim->dodaj_panstwo(indie);
	Pasmo_gorskie* tatry = new Pasmo_gorskie("Tatry", 1300);
	Pasmo_gorskie* andy = new Pasmo_gorskie("Andy", 1800);
	Pasmo_gorskie* karpaty = new Pasmo_gorskie("Karpaty", 1700);
	kontynentZpasmemGorskim->dodaj_pasmo(tatry);
	kontynentZpasmemGorskim->dodaj_pasmo(andy);
	kontynentZpasmemGorskim->dodaj_pasmo(karpaty);

	KontynentKolorSkory* kontynentKolorSkory = new KontynentKolorSkory("Afryka", "czarny");
	kontynentKolorSkory->dodaj_panstwo(niemcy);
	kontynentKolorSkory->dodaj_panstwo(usa);
	kontynentKolorSkory->dodaj_panstwo(chiny);
	kontynentKolorSkory->dodaj_panstwo(indie);

	vector <Obszar*> kontynenty;
	kontynenty.push_back(kontynent);
	kontynenty.push_back(kontynentZpasmemGorskim);
	kontynenty.push_back(kontynentKolorSkory);

	int komenda = 0;
	 	while(1)
	 	{
	 		cout<<endl;
	 		cout<<"======== MENU PROGRAMU ========"<<endl;
	 		cout<<"(0) Wyjscie z programu"<<endl;
	 		cout<<"(1) Wyswietl aktualny stan obiektow"<<endl;
	 		cout<<"(2) Zmiana parametru obiektu"<<endl;
	 		cout<<"(3) Dodaj panstwo do kontynentu"<<endl;
	 		cout<<"(4) Pokaz srednie zaludnienie"<<endl; // to jest dodatkowa opcja, ktora wybralem
	 		cout<<"(5) Pokaz szczegoly panstw kontynentu"<<endl;
	 		cout<<"(6) Wyswietl cechy charakterystyczne obszarow" <<endl;
	 		cout<<"(7) Wczytaj z plikow dane dla kontynentow" <<endl;
	 		cout<<"(8) Zapisz do plikow dane kontynentow"<<endl;
	 		cin>> komenda;
	 		switch(komenda)
	 		{
	 		case 0: return;
	 		case 1:
			{
				cout << "\nZwykly kontynent: \n" << *kontynent; 
				cout << "\nKontynent z pasmem gorskim: \n" << *kontynentZpasmemGorskim;
				cout << "\nKontynent z kolorem skory: \n" << *kontynentKolorSkory;
				break;
			}
	 		case 2:	zmiana_parametrow(*kontynent); break;
	 		case 3:
			{
				cout << "Wybierz kontynent, do ktorego chcesz dodac: " << endl;
				cout << "(1) Kontynent zwykly" << endl;
				cout << "(2) Kontynent z pasmem" << endl;
				cout << "(3) Kontynent z kolorem skory" << endl;
				int komenda;
				cin >> komenda;
				Kontynent* wybrany_kontynent = NULL;
				switch(komenda)
				{
				case 1: wybrany_kontynent = kontynent; break;
				case 2: wybrany_kontynent = kontynentZpasmemGorskim; break;
				case 3: wybrany_kontynent = kontynentKolorSkory; break;
				default: "zla komenda"; break;
				}
				if(wybrany_kontynent != NULL)
				{
					dodaj_panstwo(*wybrany_kontynent); 
				}
				break;
			}
	 		case 4: cout<<kontynent->srednie_zaludnienie()<<endl; break;
	 		case 5: pokaz_panstwa(*kontynent); break;
	 		case 6:
	 		{
				for(int i=0; i<kontynenty.size(); i++)
					cout<<kontynenty[i]->pokaz_ceche_charakterystyczna()<<endl;
				break;
	 		}
	 		case 7:
	 		{
	 			ifstream plik1("kontynent.txt");
	 			kontynent->odczyt_z_pliku(plik1);
	 			ifstream plik2("kontynentzpasmem.txt");
	 			kontynentZpasmemGorskim->odczyt_z_pliku(plik2);
	 			ifstream plik3("kontynentKolorSkory.txt");
	 			kontynentKolorSkory->odczyt_z_pliku(plik3);
	 			break;
	 		}	 		case 8:
	 		{
	 			ofstream plik1("kontynent.txt");
	 			kontynenty[0]->zapisz_do_pliku(plik1);
	 			ofstream plik2("kontynentzpasmem.txt");
	 			kontynenty[1]->zapisz_do_pliku(plik2);
	 			ofstream plik3("kontynentKolorSkory.txt");
	 			kontynenty[2]->zapisz_do_pliku(plik3);
				break;
	 		}
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
