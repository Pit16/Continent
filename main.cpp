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
void test_dodawania_panstw();

int main(void)
{
	test_dodawania_panstw();
	test_operator_mniejszosci_panstwa();
	test_operator_wiekszosci_panstwa();

	return 0;

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
