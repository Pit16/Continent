/*
 * Kontynent.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Kontynent.h"
int Kontynent::liczba_kontynentow=0;

Kontynent::Kontynent(string nazwa)
{
	cout<<"Kontynent::Kontynent()"<<endl;
	this->nazwa=nazwa;
	this->powierzchnia=0;
	this->liczba_panstw=0;
	zwieksz_licznik();

}

Kontynent::Kontynent(const Kontynent& k)
{
	this->nazwa=k.nazwa;
	this->powierzchnia=k.powierzchnia;
	this->liczba_panstw=k.liczba_panstw;
	if(liczba_panstw > 0)
	{
		if(panstwa!=NULL)
			delete []panstwa;

		panstwa = new Panstwo[liczba_panstw];
		for(int i=0; i<liczba_panstw; i++)
			panstwa[i]=k.panstwa[i];
	}
	zwieksz_licznik();
}

Kontynent::~Kontynent()
{
	cout<<"Kontynent::~Kontynent"<<endl;
    //if(liczba_panstw > 0)
    	//delete []panstwa;
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
	return panstwa[0].pobierz_nazwe();
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
	cout<<"koniec: dodaj panstwo"<<endl;
}

void Kontynent::dodaj_pasmo(Pasmo_gorskie& nowe_pasmo)
{
//	this->pasma_gorskie.push_back(nowe_pasmo);
}

void Kontynent::zwieksz_tablice()
{
	liczba_panstw++;

    cout<<"jestem w: zwieksz_tablice"<<endl;
    Panstwo* nowa_tablica = new Panstwo[liczba_panstw];

    for (int i = 0; i < liczba_panstw-1; i++)
    {
        nowa_tablica[i] = panstwa[i];
    }

    if(liczba_panstw >1)
    	delete []panstwa;

    panstwa = nowa_tablica;
    cout<<"koniec: zwieksz_tablice"<<endl;

}

string Kontynent::operator[](int i)
{
	cout<<"operator indeksowania"<<endl;
	if ( i>=liczba_panstw || i<0)
	{
		cout<<"przekroczona tablica"<<endl;
		return "zly indeks";
	}
	else
		return panstwa[i].pobierz_nazwe();
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
	if(liczba_panstw > 0)
	{
		if(panstwa!=NULL)
			delete []panstwa;

		panstwa = new Panstwo[liczba_panstw];
		for(int i=0; i<liczba_panstw; i++)
			panstwa[i]=k.panstwa[i];
	}

	return *this;
}
