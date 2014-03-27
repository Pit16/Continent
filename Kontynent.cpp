/*
 * Kontynent.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Kontynent.h"
#define _DEBUG_FLAG

int Kontynent::liczba_kontynentow=0;

Kontynent::Kontynent(string nazwa)
{
#ifdef _DEBUG_FLAG
	cout<<"[tryb debug] konstruktor z parametrem kontynentu: "<<nazwa<<endl;
#endif
	this->nazwa=nazwa;
	this->powierzchnia=0;
	this->liczba_panstw=0;
	this->panstwa=NULL;
	zwieksz_licznik();

}

Kontynent::Kontynent(const Kontynent& k)
{
#ifdef _DEBUG_FLAG
	cout<<"[tryb debug] konstruktor kopiujacy kontynentu: "<<k.nazwa<<endl;
#endif
	this->nazwa=k.nazwa;
	this->powierzchnia=k.powierzchnia;
	this->liczba_panstw=k.liczba_panstw;
	if(liczba_panstw > 0 && k.panstwa!=NULL )
	{
		panstwa = new Panstwo[liczba_panstw];
		for(int i=0; i<liczba_panstw; i++)
			panstwa[i]=k.panstwa[i];
	}
	zwieksz_licznik();
}

Kontynent::~Kontynent()
{
#ifdef _DEBUG_FLAG
	cout<<"[tryb debug] destruktor kontynentu: "<<nazwa<<endl;
#endif
}

string Kontynent::pobierz_nazwe()
{
	return nazwa;
}

int Kontynent::pobierz_powierzchnie()
{
	//cout<<"Powierzchnia kontynentu "<<pobierz_nazwe()<<" wynosi: ";
	return powierzchnia;
}

string Kontynent::najwieksze_panstwo()
{
	//cout<<"Najwieksze panstwo kontynentu "<<pobierz_nazwe()<<" to: "<<endl;
	if(panstwa!=NULL)
		return panstwa[0].pobierz_nazwe();
	else
		return "nie ma panstw";
}

int Kontynent::srednie_zaludnienie()
{

	int liczba_ludnosci=0;
	if(liczba_panstw!=0)
	{
		//cout<<"jestem w: srednie zaludnienie"<<endl;
		for(int i=0; i<liczba_panstw; i++)
			liczba_ludnosci += panstwa[i].pobierz_populacje();
		/*cout<<"liczba ludnosci: "<<liczba_ludnosci<<endl;
		 * cout<<"powierzchnia: "<<pobierz_powierzchnie()<<endl;
		 */
		cout<<"srednie zaludnienie wynosi: ";
		return (liczba_ludnosci/powierzchnia);
	}
	else
		{
		cout<<"nie ma panstw - brak ludnosci";
		return 0;
		}
}
string Kontynent::najwyzsza_gora()
{
	return 0;		//TODO: pokazac najwyzsza_gora();
}

void Kontynent::dodaj_panstwo(Panstwo& nowe_panstwo)
{
	//cout<<"jestem w: dodaj_panstwo"<<endl;
	zwieksz_tablice();
	panstwa[liczba_panstw-1]=nowe_panstwo;
	this->powierzchnia += nowe_panstwo.pobierz_powierzchnie();
	if(liczba_panstw == 1)
	{
		//cout<<"koniec: dodaj panstwo"<<endl;
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
	//cout<<"koniec: dodaj panstwo"<<endl;
}

/*void Kontynent::dodaj_pasmo(Pasmo_gorskie& nowe_pasmo)
{
	//cout<<"jestem w: dodaj_pasmo"<<endl;
	zwieksz_tablice();
	pasma_gorskie[liczba_pasm-1]=nowe_pasmo;
	if(liczba_pasm == 1)
	{
		//cout<<"koniec: dodaj pasmo"<<endl;
		return;
	}
	else
	{
		int i=liczba_pasm - 1;
		while(i>0 && pasma_gorskie[i]>pasma_gorskie[i-1])
		{
		 Pasmo_gorskie tymczasowe=pasma_gorskie[i];
		 pasma_gorskie[i]=pasma_gorskie[i-1];
		 pasma_gorskie[i-1]=tymczasowe;
		 i--;
		}
	}
}
void Kontynent::zwieksz_pasma()
{
	liczba_pasm++;
	Pasmo_gorskie* nowa_tablica = new Pasmo_gorskie[liczba_pasm];
    for (int i = 0; i < liczba_pasm-1; i++)
    {
        nowa_tablica[i] = pasma_gorskie[i];
    }

    if(liczba_pasm >1)
    	delete []pasma_gorskie;

    pasma_gorskie = nowa_tablica;
}*/

void Kontynent::zwieksz_tablice()
{
	liczba_panstw++;

    //cout<<"jestem w: zwieksz_tablice"<<endl;
    Panstwo* nowa_tablica = new Panstwo[liczba_panstw];

    for (int i = 0; i < liczba_panstw-1; i++)
    {
        nowa_tablica[i] = panstwa[i];
    }

    if(liczba_panstw >1)
    	delete []panstwa;

    panstwa = nowa_tablica;
    //cout<<"koniec: zwieksz_tablice"<<endl;

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

	Panstwo* tymaczasowe = new Panstwo[liczba_panstw-1];
	for(int i=0; i<indeks_panstwa; i++)
		tymaczasowe[i] = panstwa[i];
	for(int i=indeks_panstwa; i<liczba_panstw-1; i++)
	{
		tymaczasowe[i] = panstwa[i+1];
	}
	powierzchnia-=panstwa[indeks_panstwa].pobierz_powierzchnie();
	delete []panstwa;
	panstwa=tymaczasowe;
	liczba_panstw--;
}
Panstwo& Kontynent::pokaz_panstwo(int i)
{
	//Panstwo tymczasowe = panstwa[i];
	return panstwa[i];
}
