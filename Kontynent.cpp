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
	this->liczba_panstw=0;

}
Kontynent::~Kontynent()
{
	cout<<"Kontynent::Kontynent"<<endl;
}

/*Kontynent::Kontynent(const Kontynent& k)
{
	strcpy(nazwa, k.nazwa);
}*/

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

/*int Kontynent::srednie_zaludnienie()
{
	int liczba_ludnosci=0;
	for(unsigned i=0; i<panstwa.size(); i++) //TODO: co sie stanie gdy wartosci sa rowne 0
		liczba_ludnosci += panstwa[i].pobierz_populacje();
	return liczba_ludnosci/powierzchnia;
}*/

string Kontynent::najwyzsza_gora()
{
	return 0;		//TODO: pokazac najwyzsza_gora();
}

void Kontynent::dodaj_panstwo(Panstwo& nowe_panstwo)
{
	cout<<"jestem w: dodaj_panstwo"<<endl;
	zwieksz_tablice();
	panstwa[liczba_panstw-1]=nowe_panstwo;
	this->powierzchnia += nowe_panstwo.pobierz_powierzchnie();
	if(liczba_panstw == 1)
	{
		return;
	}
	else
	{
		int i=liczba_panstw - 1;
		while(i>0 && panstwa[i]>panstwa[i-1])
		{
		 Panstwo tymczasowe=panstwa[i];
		 panstwa[i]=panstwa[i-1];
		 panstwa[i-1]=tymczasowe;
		 i--;
		}
	}
}

void Kontynent::dodaj_pasmo(Pasmo_gorskie& nowe_pasmo)
{
//	this->pasma_gorskie.push_back(nowe_pasmo);
}

/*void Kontynent::zwieksz_static()
{
	liczba_kontynentow++;
}*/

void Kontynent::zwieksz_tablice()
{
	liczba_panstw++;

    cout<<"jestem w zwieksz_tablice"<<endl;
    Panstwo* nowa_tablica = new Panstwo[liczba_panstw];

    for (int i = 0; i < liczba_panstw-1; i++)
    {
        nowa_tablica[i] = panstwa[i];
    }

    if(liczba_panstw > 1)
    	delete []panstwa;

    panstwa = nowa_tablica;
    cout<<"jestem w zwieksz_tablice"<<endl;

}
