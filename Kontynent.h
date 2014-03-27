#ifndef KONTYNENT_H_
#define KONTYNENT_H_

#include <iostream>
#include <string>
#include "Panstwo.h"
#include "Pasmo_gorskie.h"

using namespace std;



class Kontynent
{
public:
	Kontynent(string nazwa);
	Kontynent(const Kontynent& k);
	~Kontynent();
	string pobierz_nazwe();
	int pobierz_powierzchnie();
	string najwieksze_panstwo();
	int srednie_zaludnienie();
	string najwyzsza_gora();
	void dodaj_panstwo(Panstwo& nowe_panstwo);
	void dodaj_pasmo(Pasmo_gorskie& nowe_pasmo);
	string operator[](int i);
	Kontynent& operator=(const Kontynent& k);
	static int pobierz_licznik();
	friend ostream & operator<< (ostream &, Kontynent &);
	int pobierz_liczbe_panstw();
	void usun_panstwo(int);
	
private:
	void zwieksz_tablice();
	static void zwieksz_licznik();
	static int liczba_kontynentow;
	string nazwa;
	Panstwo* panstwa;
	// Pasmo_gorskie* pasma_gorskie;
	int powierzchnia;
	int liczba_panstw;

};

ostream& operator<< (ostream& strumien, Kontynent& kontynent);

#endif /* KONTYNENT_H_ */
