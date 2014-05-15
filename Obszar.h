/*
 * Obszar.h
 *
 *  Created on: 6 maj 2014
 *      Author: PiotreK
 */

#ifndef OBSZAR_H_
#define OBSZAR_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/// Klasa abstrakcyjna
class Obszar
{
public:
	Obszar() {}
	/// Konstruktor z parametrami
	Obszar(string nazwa, int powierzchnia, int populacja);
	///Konstruktor kopiujacy
	Obszar(const Obszar& o);
	///Destruktor
	~Obszar();

	string pobierz_nazwe();
	int pobierz_populacje();
	int pobierz_powierzchnie();

	virtual string pokaz_ceche_charakterystyczna()=0;
	virtual void zapisz_do_pliku(ofstream&) = 0;
protected:
	string nazwa;
	int powierzchnia;
	int populacja;


};

#endif /* OBSZAR_H_ */
