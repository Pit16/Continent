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

	//gettery
	string pobierz_nazwe();
	int pobierz_srednia_wysokosc();
	string pobierz_najwyzszy_szczyt();

	//settery
	void ustaw_najwyzszy_szczyt(string najwyzszy_szczyt);

	//operatory
	bool operator ==(const Pasmo_gorskie &g);
	bool operator<(const Pasmo_gorskie &p);
	friend ostream & operator<< (ostream &, Pasmo_gorskie &);

private:
	string nazwa;
	int srednia_wysokosc;
	string najwyzszy_szczyt;

};
ostream& operator<< (ostream& strumien, Pasmo_gorskie& pasmo_gorskie);
#endif /*PASMO_GORSKIE_H_ */
