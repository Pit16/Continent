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
	Obszar(int powierzchnia, int populacja);
	Obszar(const Obszar& o);
	~Obszar();

	int pobierz_populacje();
	int pobierz_powierzchnie();
protected:
	int powierzchnia;
	int populacja;


};

#endif /* OBSZAR_H_ */
