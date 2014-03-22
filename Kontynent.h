#ifndef KONTYNENT_H_
#define KONTYNENT_H_

#include <iostream>
#include <string>
using namespace std;

class Kontynent
{
public:
	
	Kontynent(string nazwa);
	~Kontynent();
	string pobierz_nazwe();
	int pobierz_powierzchnie();
	string najwieksze_panstwo();
	int srednie_zaludnienie();
	string najwyzsza_gora();
	void dodaj_panstwo(Panstwo* nowe_panstwo);
	void dodaj_pasmo(Pasmo_gorskie* nowe_pasmo);
	
	
	
private:
	string nazwa;
	Panstwo* panstwa[];
	Pasmo_gorskie* pasma_gorskie[];
	int powierzchnia;
	
};

#endif /* KONTYNENT_H_ */