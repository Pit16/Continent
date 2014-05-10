/*
 * KontynentZPasmemGorskim.h
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#ifndef KONTYNENTZPasmemGorskim_H_
#define KONTYNENTZPasmemGorskim_H_

#include <iostream>
#include <string>
#include "Kontynent.h"
#include "Pasmo_gorskie.h"

using namespace std;

class KontynentZPasmemGorskim: public Kontynent
{
public:
	KontynentZPasmemGorskim(string nazwa);
	KontynentZPasmemGorskim(const KontynentZPasmemGorskim& g);
	~KontynentZPasmemGorskim();

	//gettery
	int pobierz_liczbe_pasm();
	Pasmo_gorskie* pokaz_pasmo(int i);

	//operatory
	string najwyzsze_pasmo();
	friend ostream & operator<< (ostream &, KontynentZPasmemGorskim &);
	void dodaj_pasmo(Pasmo_gorskie* nowe_pasmo);
	void usun_pasmo(int);

private:
	vector<Pasmo_gorskie*> pasma;
	int liczba_pasm;

};
ostream& operator<< (ostream& strumien, KontynentZPasmemGorskim& kontynentZPasmemGorskim);

#endif /* KONTYNENTZPasmemGorskim_H_ */
