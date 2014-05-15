/*
 * KontynentKolorSkory.h
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#ifndef KONTYNENTKolorSkory_H_
#define KONTYNENTKolorSkory_H_

#include <iostream>
#include <string>
#include "Kontynent.h"

using namespace std;

class KontynentKolorSkory: public Kontynent
{
public:
	KontynentKolorSkory(string nazwa, string kolor_skory);
	KontynentKolorSkory(const KontynentKolorSkory& z);
	~KontynentKolorSkory();

	string pokaz_kolor_skory();

	friend ostream & operator<< (ostream &, KontynentKolorSkory &);

	virtual string pokaz_ceche_charakterystyczna();
	void zapisz_do_pliku(ofstream&);
	void odczyt_z_pliku(ifstream&);

private:
	string kolor_skory;

};
ostream& operator<< (ostream& strumien, KontynentKolorSkory& kontynentKolorSkory);

#endif /* KONTYNENTKolorSkory_H_ */
