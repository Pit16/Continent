/*
 * Obszar.cpp
 *
 *  Created on: 6 maj 2014
 *      Author: PiotreK
 */

#include "Obszar.h"

Obszar::Obszar(int powierzchnia, int populacja)
{

	//debug("konstruktor z parametrem kontynentu: " + nazwa);
	this->powierzchnia=0;
	this->populacja=0;

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


int Obszar::pobierz_powierzchnie()
{
	return powierzchnia;
}

int Obszar::pobierz_populacje()
{
	return populacja;
}
