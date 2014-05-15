/*
 * Pasmo_gorskie.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Pasmo_gorskie.h"
#include "Debugowanie.h"

Pasmo_gorskie::Pasmo_gorskie(string nazwa, int srednia_wysokosc)
{
	//cout<<"Pasmo_gorskie::Pasmo_gorskie()"<<endl;
	this->nazwa=nazwa;
	this->srednia_wysokosc=srednia_wysokosc;
	this->najwyzszy_szczyt="";
	debug("utworzono nowe pasmo " + nazwa);
}

Pasmo_gorskie::Pasmo_gorskie(const Pasmo_gorskie& pg)
{
	//cout<<"Pasmo_gorskie::Pasmo_gorskie()"<<endl;
	this->nazwa=pg.nazwa;
	this->srednia_wysokosc=pg.srednia_wysokosc;
	this->najwyzszy_szczyt=pg.najwyzszy_szczyt;
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

void Pasmo_gorskie::ustaw_najwyzszy_szczyt(string najwyzszy_szczyt)
{
	this->najwyzszy_szczyt=najwyzszy_szczyt;
}

bool Pasmo_gorskie::operator ==(const Pasmo_gorskie &pg)
{
	return this->srednia_wysokosc == pg.srednia_wysokosc;
}

bool Pasmo_gorskie::operator<(const Pasmo_gorskie& p1)
{
	return this->srednia_wysokosc < p1.srednia_wysokosc;
}

ostream& operator<< (ostream& strumien, Pasmo_gorskie& pasmo_gorskie)
{
	strumien<<"nazwa pasma: "<<pasmo_gorskie.pobierz_nazwe()<<endl;
	strumien<<"srednia wysokosc wynosi: "<<pasmo_gorskie.pobierz_srednia_wysokosc()<<endl;
	strumien<<"najwyzszy szczyt to: "<<pasmo_gorskie.pobierz_najwyzszy_szczyt()<<endl;

	return strumien;
}

void Pasmo_gorskie::zapisz_do_pliku(ofstream& plik)
{
	if(plik)
	{
		plik<<nazwa<<" "<<srednia_wysokosc<<" "<<najwyzszy_szczyt<<endl;
	}
	else
		debug("Blad w zapisie pasma do pliku");
}

void Pasmo_gorskie::odczyt_z_pliku(istream& plik)
{
	if(plik)
	{
		plik>>this->nazwa;
		plik>>this->srednia_wysokosc;
	}
	else
		debug("Blad w odczycie pasma z pliku");
}

void Pasmo_gorskie::odczyt_ze_strumienia(istream& stream)
{
	stream>>this->nazwa;
	stream>>this->srednia_wysokosc;
}

