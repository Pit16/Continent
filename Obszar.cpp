/*
 * Obszar.cpp
 *
 *  Created on: 6 maj 2014
 *      Author: PiotreK
 */

#include "Obszar.h"

Obszar::Obszar(string nazwa, int powierzchnia, int populacja)
{

	this->nazwa=nazwa;
	this->powierzchnia=powierzchnia;
	this->populacja=populacja;

}

Obszar::Obszar(const Obszar& o)
{

	//debug("konstruktor kopiujacy kontynentu: " + nazwa);
	this->powierzchnia=o.powierzchnia;
	this->populacja=o.populacja;
}

Obszar::~Obszar()
{
	//debug("destruktor kontynentu: " + nazwa);
}

string Obszar::pobierz_nazwe()
{
	return nazwa;
}

int Obszar::pobierz_powierzchnie()
{
	return powierzchnia;
}

int Obszar::pobierz_populacje()
{
	return populacja;
}
