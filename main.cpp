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
/*TODO: operator przypisania dla kontynentu
 * TODO: interfejs u¿ytkownika
 * TODO: _DEBUG
 * TODO: operator strumieniowy
 * TODO: pasma_gorskie

*/
int main(void)
{
	/*test_dodawania_panstw();
	test_operator_mniejszosci_panstwa();
	test_operator_wiekszosci_panstwa();
	test_kopiowanie_kontynentu();
	test_operator_rownosci_panstwa();
	test_operator_nierownosci_panstwa();
	//
	int wejscie=0;
 	while(1) {
 		cout<<endl;
 		cout<<"---------- MENU GLOWNE ----------"<<endl;
  		cout<<"(1) uruchom program"<<endl;
 		cout<<"(0) wyjscie\n"<<endl;
 		cin>> wejscie;
 		if(wejscie == 1) {		//wykonanie programu
 			glowny_program();
 		}
 		else if(wejscie == 0) { //wyjscie z programu
 			return 1;
 		}
 		else { 	//bledna liczba
 			continue;
 		}
 	}
 	*/
	test_kopiowanie_kontynentu();
	return 0;

}

void glowny_program()
{
	int komenda = 0;
	 	while(1)
	 	{
	 		cout<<endl;
	 		cout<<"======== MENU PROGRAMU ========"<<endl;
	 		cout<<"(0) Wyjscie z programu"<<endl;
	 		cout<<"(1) Stworz kontynent"<<endl;
	 		cout<<"(2) Stworz panstwo"<<endl;
	 		cout<<"(3) Modyfikacja kontynentu"<<endl;
	 		cin>> komenda;
	 		switch(komenda)
	 		{
	 		case 0: return;
	 		case 1: test_dodawania_kontynentu(); break;
	 		case 2:	test_dodawania_panstw(); break;
	 		case 3: cout<<"mad kontynentu"<<endl; break;
	 		default: return;

	 		}
	 	}
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

