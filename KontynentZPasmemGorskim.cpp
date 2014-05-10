/*
 * KontynentZPasmemGorskim.cpp
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#include "KontynentZPasmemGorskim.h"
#include "Debugowanie.h"

KontynentZPasmemGorskim::KontynentZPasmemGorskim(string nazwa)
:Kontynent(nazwa)
{
	this->liczba_pasm=0;
}

KontynentZPasmemGorskim::KontynentZPasmemGorskim(const KontynentZPasmemGorskim& g)
:Kontynent(g)
{
	this->liczba_pasm=g.liczba_pasm;
	if(liczba_pasm>0 && pasma.size()>0)
	{
		pasma=g.pasma;
	}
}

KontynentZPasmemGorskim::~KontynentZPasmemGorskim()
{

}

void KontynentZPasmemGorskim::dodaj_pasmo(Pasmo_gorskie* nowe_pasmo)
{
	this->pasma.push_back(nowe_pasmo);
	debug("dodano nowe pasmo " + nowe_pasmo->pobierz_nazwe());
	liczba_pasm++;
}

void KontynentZPasmemGorskim::usun_pasmo(int indeks_pasma)
{
	if(indeks_pasma<0 || indeks_pasma>liczba_pasm-1)
		return;
	pasma.erase (pasma.begin()+indeks_pasma);
}

int KontynentZPasmemGorskim::pobierz_liczbe_pasm()
{
	return this->liczba_pasm;
}

Pasmo_gorskie* KontynentZPasmemGorskim::pokaz_pasmo(int i)
{
	return pasma[i];
}

string KontynentZPasmemGorskim::najwyzsze_pasmo()	//TODO: zrobic to
{
	return "cos";
}
ostream& operator<< (ostream& strumien, KontynentZPasmemGorskim& kontynentZPasmemGorskim)
{
	strumien<<"nazwa kontynentu: "<<kontynentZPasmemGorskim.pobierz_nazwe()<<endl;
	strumien<<"liczba pasm: "<<kontynentZPasmemGorskim.pobierz_liczbe_pasm()<<endl;
	for(int i=0; i<kontynentZPasmemGorskim.pobierz_liczbe_pasm(); i++)
			strumien<<"nazwa pasma nr: "<<i<<" : "<<kontynentZPasmemGorskim.pasma[i]->pobierz_nazwe()<<endl;
	strumien<<"nazwa najwyzszego pasma: "<<kontynentZPasmemGorskim.najwyzsze_pasmo()<<endl;

	return strumien;
}

