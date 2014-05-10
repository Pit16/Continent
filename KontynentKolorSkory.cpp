/*
 * KontynentKolorSkory.cpp
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#include "KontynentKolorSkory.h"

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
	strumien<<"dominujacy kolor skory to: "<<kontynentKolorSkory.pokaz_kolor_skory()<<endl;

	return strumien;
}
