#ifndef KONTYNENT_H_
#define KONTYNENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Panstwo.h"
#include "Obszar.h"

using namespace std;
/// Klasa
class Kontynent: public Obszar
{
public:
	Kontynent(string nazwa);
	Kontynent(const Kontynent& k);
	~Kontynent();

	//gettery
	static int pobierz_licznik();
	int pobierz_liczbe_panstw();
	Panstwo* pokaz_panstwo(int i);

	//operatory
	string operator[](int i);
	Kontynent& operator=(const Kontynent& k);
	friend ostream & operator<< (ostream &, Kontynent &);
	string najwieksze_panstwo();
	int srednie_zaludnienie();
	void dodaj_panstwo(Panstwo* nowe_panstwo);
	void usun_panstwo(int);
	
	virtual string pokaz_ceche_charakterystyczna();

	virtual void zapisz_do_pliku(ofstream&);
	void odczyt_z_pliku(ifstream&);
protected:
	static int liczba_kontynentow;
	vector<Panstwo*> panstwa;
	int liczba_panstw;
	static void zwieksz_licznik();

};
ostream& operator<< (ostream& strumien, Kontynent& kontynent);

#endif /* KONTYNENT_H_ */
