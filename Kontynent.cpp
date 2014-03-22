/*
 * Kontynent.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Kontynent.h"

Kontynent::Kontynent(string nazwa)
{
	cout<<"Kontynent::Kontynent()"<<endl;
	this->nazwa=nazwa;
	this->powierzchnia=0;

}
Kontynent::~Kontynent()
{
	cout<<"Kontynent::Kontynent"<<endl;
}

string Kontynent::pobierz_nazwe()
{
	return nazwa;
}

int Kontynent::pobierz_powierzchnie()
{
	return powierzchnia;
}

string Kontynent::najwieksze_panstwo()
{
	return 0;		// TODO: nazwa najwiekszego panstwa
}

int Kontynent::srednie_zaludnienie()
{
	int liczba_ludnosci=0;
	for(unsigned i=0; i<panstwa.size(); i++) //TODO: co sie stanie gdy wartosci sa rowne 0
		liczba_ludnosci += panstwa[i]->pobierz_populacje();
	return liczba_ludnosci/powierzchnia;
}

string Kontynent::najwyzsza_gora()
{
	return 0;		//TODO: pokazac najwyzsza_gora();
}

void Kontynent::dodaj_panstwo(Panstwo* nowe_panstwo)
{
	this->panstwa.push_back(nowe_panstwo);
	this->powierzchnia += nowe_panstwo->pobierz_powierzchnie();
}

void Kontynent::dodaj_pasmo(Pasmo_gorskie* nowe_pasmo)
{
	this->pasma_gorskie.push_back(nowe_pasmo);
}
