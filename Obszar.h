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

using namespace std;

/*
 * TODO: zrobic testy
 */

class Obszar
{
public:
	Obszar() {}
	Obszar(string nazwa, int powierzchnia, int populacja);
	Obszar(const Obszar& o);
	~Obszar();

	string pobierz_nazwe();
	int pobierz_populacje();
	int pobierz_powierzchnie();
protected:
	string nazwa;
	int powierzchnia;
	int populacja;


};

#endif /* OBSZAR_H_ */
