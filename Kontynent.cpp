/*
 * Kontynent.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Kontynent.h"
#include "Debugowanie.h"

int Kontynent::liczba_kontynentow=0;

Kontynent::Kontynent(string nazwa)
{
//#ifdef _DEBUG_FLAG
//	cout<<"konstruktor z parametrem kontynentu: "<<nazwa<<endl;
//#endif
	debug("konstruktor z parametrem kontynentu: " + nazwa);
	this->nazwa=nazwa;
	this->powierzchnia=0;
	this->liczba_panstw=0;
	//this->panstwa=NULL;
	zwieksz_licznik();

}

Kontynent::Kontynent(const Kontynent& k)
{
//#ifdef _DEBUG_FLAG
//	cout<<"konstruktor kopiujacy kontynentu: "<<k.nazwa<<endl;
//#endif
	debug("konstruktor kopiujacy kontynentu: " + nazwa);
	this->nazwa=k.nazwa;
	this->powierzchnia=k.powierzchnia;
	this->liczba_panstw=k.liczba_panstw;
	if(liczba_panstw > 0 && panstwa.size()>0 )
	{
			panstwa=k.panstwa;
	}
	zwieksz_licznik();
}

Kontynent::~Kontynent()
{
//#ifdef _DEBUG_FLAG
//	cout<<"destruktor kontynentu: "<<nazwa<<endl;
//#endif
	debug("destruktor kontynentu: " + nazwa);
}


string Kontynent::najwieksze_panstwo()		//TODO: poprawic, przeszukanie tablicy
{
	//cout<<"Najwieksze panstwo kontynentu "<<pobierz_nazwe()<<" to: "<<endl;
	if(panstwa.size()!=0)
		return panstwa[0]->pobierz_nazwe();
	else
		return "nie ma panstw";
}

int Kontynent::srednie_zaludnienie()
{

	int liczba_ludnosci=0;
	if(liczba_panstw!=0)
	{
		for(unsigned i=0; i<panstwa.size(); i++) //TODO: czy dobrze dzia³a gdy wartosci sa rowne 0
		liczba_ludnosci += panstwa[i]->pobierz_populacje();
		return liczba_ludnosci/powierzchnia;
	}
	else
		{
		cout<<"nie ma panstw - brak ludnosci";
		return 0;
		}
}

void Kontynent::dodaj_panstwo(Panstwo* nowe_panstwo)
 {
 	this->panstwa.push_back(nowe_panstwo);
 	this->powierzchnia += nowe_panstwo->pobierz_powierzchnie();
 	liczba_panstw++;
 }

string Kontynent::operator[](int i)
{
	//cout<<"operator indeksowania"<<endl;
	if ( i>=liczba_panstw || i<0)
	{
		cout<<"przekroczona tablica"<<endl;
		return "zly indeks";
	}
	else
		return panstwa[i]->pobierz_nazwe();
}

void Kontynent::zwieksz_licznik()
{
	liczba_kontynentow++;
}

int Kontynent::pobierz_licznik()
{
	return liczba_kontynentow;
}

Kontynent& Kontynent::operator=(const Kontynent& k)
{
	this->nazwa=k.nazwa;
	this->powierzchnia=k.powierzchnia;
	this->liczba_panstw=k.liczba_panstw;
	if(panstwa.size() > 0)
	{
			panstwa=k.panstwa;
	}

	return *this;
}

int Kontynent::pobierz_liczbe_panstw()
{
	return this->liczba_panstw;
}

ostream& operator<< (ostream& strumien, Kontynent& kontynent)
{
	strumien<<"nazwa kontynentu: "<<kontynent.pobierz_nazwe()<<endl;
	strumien<<"powierzchnia kontynentu wynosi: "<<kontynent.pobierz_powierzchnie()<<endl;
	strumien<<"liczba panstw na tym kontynencie: "<<kontynent.pobierz_liczbe_panstw()<<endl;
	for(int i=0; i<kontynent.pobierz_liczbe_panstw(); i++)
		strumien<<"nazwa panstwa nr: "<<i<<" : "<<kontynent[i]<<endl;
	strumien<<"nazwa najwiekszego panstwa: "<<kontynent.najwieksze_panstwo()<<endl;
	return strumien;
}

void Kontynent::usun_panstwo(int indeks_panstwa)
{
	if(indeks_panstwa<0 || indeks_panstwa>liczba_panstw-1)
		return;
	panstwa.erase (panstwa.begin()+indeks_panstwa);
	liczba_panstw--;
}
Panstwo* Kontynent::pokaz_panstwo(int i)
{
	//Panstwo tymczasowe = panstwa[i];
	return panstwa[i];
}
