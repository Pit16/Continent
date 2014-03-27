/*
 * Pasmo_gorskie.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Pasmo_gorskie.h"

Pasmo_gorskie::Pasmo_gorskie(string nazwa, int srednia_wysokosc)
{
	//cout<<"Pasmo_gorskie::Pasmo_gorskie()"<<endl;
	this->nazwa=nazwa;
	this->srednia_wysokosc=srednia_wysokosc;
	this->najwyzszy_szczyt="";
	this->wysokosc_szczytu=0;
}

Pasmo_gorskie::Pasmo_gorskie(const Pasmo_gorskie& pg)
{
	//cout<<"Pasmo_gorskie::Pasmo_gorskie()"<<endl;
	this->nazwa=pg.nazwa;
	this->srednia_wysokosc=pg.srednia_wysokosc;
	this->najwyzszy_szczyt=pg.najwyzszy_szczyt;
	this->wysokosc_szczytu=pg.wysokosc_szczytu;
}

Pasmo_gorskie::~Pasmo_gorskie()
{
	//cout<<"Pasmo_gorskie::~Pasmo_gorskie()"<<endl;
}


string Pasmo_gorskie::pobierz_nazwe()
{
	return nazwa;
}

int Pasmo_gorskie::pobierz_srednia_wysokosc()
{
	return srednia_wysokosc;
}

string Pasmo_gorskie::pobierz_najwyzszy_szczyt()
{
	return najwyzszy_szczyt;
}

int Pasmo_gorskie::pobierz_wysokosc_najwyzszy_szczyt()
{
	return wysokosc_szczytu;
}

void Pasmo_gorskie::ustaw_najwyzszy_szczyt(string najwyzszy_szczyt)
{
	this->najwyzszy_szczyt=najwyzszy_szczyt;
}

void Pasmo_gorskie::ustaw_wysokosc(int wysokosc_szczytu)
{
	this->wysokosc_szczytu=wysokosc_szczytu;
}

bool Pasmo_gorskie::operator ==(const Pasmo_gorskie &pg)
{
	return this->srednia_wysokosc == pg.srednia_wysokosc;
}
