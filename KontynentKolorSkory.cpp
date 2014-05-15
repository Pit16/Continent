/*
 * KontynentKolorSkory.cpp
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#include "KontynentKolorSkory.h"
#include "Debugowanie.h"
#include <sstream>

KontynentKolorSkory::KontynentKolorSkory(string nazwa, string kolor_skory)
:Kontynent(nazwa)
{
	this->kolor_skory=kolor_skory;
}

KontynentKolorSkory::KontynentKolorSkory(const KontynentKolorSkory& z)
:Kontynent(z)
{
	this->kolor_skory=z.kolor_skory;
}

KontynentKolorSkory::~KontynentKolorSkory()
{

}

string KontynentKolorSkory::pokaz_kolor_skory()
{
	return this->kolor_skory;
}
ostream& operator<< (ostream& strumien, KontynentKolorSkory& kontynentKolorSkory)
{
	strumien<<"nazwa kontynentu: "<<kontynentKolorSkory.pobierz_nazwe()<<endl;
	strumien<<"powierzchnia kontynentu wynosi: "<<kontynentKolorSkory.pobierz_powierzchnie()<<endl;
	strumien<<"liczba panstw na tym kontynencie: "<<kontynentKolorSkory.pobierz_liczbe_panstw()<<endl;
	for(int i=0; i<kontynentKolorSkory.pobierz_liczbe_panstw(); i++)
			strumien<<"nazwa panstwa nr: "<<i<<" : "<<kontynentKolorSkory[i]<<endl;
	strumien<<"nazwa najwiekszego panstwa: "<<kontynentKolorSkory.najwieksze_panstwo()<<endl;
	strumien<<"dominujacy kolor skory to: "<<kontynentKolorSkory.pokaz_kolor_skory()<<endl;

	return strumien;
}

 string KontynentKolorSkory::pokaz_ceche_charakterystyczna()
{
	return "dominujacy kolor skory to: " + this->kolor_skory;
}

 void KontynentKolorSkory::zapisz_do_pliku(ofstream& plik)
 {
 	if(plik)
 	{
 		plik<<nazwa<<" "<<"3"<<endl;
 		for(int i=0; i<liczba_panstw; i++)
 		{
 			panstwa[i]->zapisz_do_pliku(plik);
 		}
 		plik<<"$"<<endl;
 		plik<<kolor_skory<<endl;
 		plik<<"#";

 	}
 	else
 		debug("Blad w zapisie kontynentuZkoloremSkory do pliku");
 }

 void KontynentKolorSkory::odczyt_z_pliku(ifstream& plik)
 {
 	if(plik)
 	{
 		string linia;
 		getline(plik, linia);
 		stringstream strumien(linia);
 		strumien >> nazwa;

 		while(1)
 		{
 			string line;
 			getline(plik,line);
 			stringstream linia(line);
 			if(line[0]=='#')
 			{
 				break;
 			}

 			if(line[0]=='$')
 			{
 				string line;
 				getline(plik,line);
 				stringstream linia(line);
 				linia>>this->kolor_skory;
 				continue;
 			}

 			if(line == "")
 				continue;
 			Panstwo* nowe_panstwo= new Panstwo("panstwo ", 0, 0);
 			nowe_panstwo->odczyt_z_pliku(linia);
 			this->dodaj_panstwo(nowe_panstwo);
 		}
 	}
 	else
 		debug("Blad w odczycie kontynentuZpasmem z pliku");
 }


