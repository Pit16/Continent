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

	//gettery
	static int pobierz_licznik();
	string pobierz_nazwe();
	int pobierz_powierzchnie();
	int pobierz_liczbe_panstw();
	int pobierz_liczbe_pasm();
	Panstwo& pokaz_panstwo(int i);

	//operatory
	string operator[](int i);
	Kontynent& operator=(const Kontynent& k);
	friend ostream & operator<< (ostream &, Kontynent &);
	string najwieksze_panstwo();


	int srednie_zaludnienie();
	string najwyzsza_gora();
	void dodaj_panstwo(Panstwo& nowe_panstwo);
	void dodaj_pasmo(Pasmo_gorskie& nowe_pasmo);
	void usun_panstwo(int);
	
private:
	static int liczba_kontynentow;
	string nazwa;
	Panstwo* panstwa;
	Pasmo_gorskie* pasma_gorskie;
	int powierzchnia;
	int liczba_panstw;
	int liczba_pasm;

	void zwieksz_tablice();
	void zwieksz_pasma();
	static void zwieksz_licznik();

};

ostream& operator<< (ostream& strumien, Kontynent& kontynent);

#endif /* KONTYNENT_H_ */
