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
	cout<<"Powierzchnia kontynentu "<<pobierz_nazwe()<<" wynosi: ";
	return powierzchnia;
}

string Kontynent::najwieksze_panstwo()
{
	cout<<"Najwieksze panstwo kontynentu "<<pobierz_nazwe()<<" to: ";
	return panstwa[0].pobierz_nazwe();		// TODO: nazwa najwiekszego panstwa
}

int Kontynent::srednie_zaludnienie()
{
	int liczba_ludnosci=0;
	for(unsigned i=0; i<panstwa.size(); i++) //TODO: co sie stanie gdy wartosci sa rowne 0
		liczba_ludnosci += panstwa[i].pobierz_populacje();
	return liczba_ludnosci/powierzchnia;
}

string Kontynent::najwyzsza_gora()
{
	return 0;		//TODO: pokazac najwyzsza_gora();
}

void Kontynent::dodaj_panstwo(Panstwo& nowe_panstwo)
{
	if(panstwa.empty())
	{
		this->panstwa.push_back(nowe_panstwo);
		cout<<"dodano nowe panstwo"<<endl;
	}
	else
	{
		cout<<"dodano nowe panstwo"<<endl;
		this->panstwa.push_back(nowe_panstwo);
		int i=panstwa.size() - 1;
		while(i>0 && panstwa[i]>panstwa[i-1])
		{
			cout<<"i jest rowne: "<<i<<endl;
			cout<<"porownywane panstwa i "<<panstwa[i].pobierz_nazwe()<<" i-1: "<<panstwa[i-1].pobierz_nazwe()<<endl;
			Panstwo tymczasowe=panstwa[i];
			panstwa[i]=panstwa[i-1];
			panstwa[i-1]=tymczasowe;
			cout<<"po zamianie i-te "<< panstwa[i].pobierz_nazwe()<<" i-1: "<<panstwa[i-1].pobierz_nazwe()<<endl;
			i--;
		}
	}
	this->powierzchnia += nowe_panstwo.pobierz_powierzchnie();

}

void Kontynent::dodaj_pasmo(Pasmo_gorskie& nowe_pasmo)
{
	this->pasma_gorskie.push_back(nowe_pasmo);
}
