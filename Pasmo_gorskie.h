#ifndef PASMO_GORSKIE_H_
#define PASMO_GORSKIE_H_
#include <iostream>
#include <string>

using namespace std;
class Pasmo_gorskie
{
public:
	Pasmo_gorskie(string nazwa, int srednia_wysokosc);
	Pasmo_gorskie(const Pasmo_gorskie& pg);
	~Pasmo_gorskie();
	string pobierz_nazwe();
	int pobierz_srednia_wysokosc();
	string pobierz_najwyzszy_szczyt();
	int pobierz_wysokosc_najwyzszy_szczyt();
	void ustaw_najwyzszy_szczyt(string najwyzszy_szczyt);
	void ustaw_wysokosc(int wysokosc_szczytu);
	bool operator ==(const Pasmo_gorskie &g);
private:
	string nazwa;
	int srednia_wysokosc;
	string najwyzszy_szczyt;
	int wysokosc_szczytu;

};
#endif /*PASMO_GORSKIE_H_ */
