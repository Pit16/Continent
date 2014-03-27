#ifndef PANSTWO_H_
#define PANSTWO_H_
#include <iostream>
#include <string>

using namespace std;
class Panstwo
{
public: 
	Panstwo(){}
	Panstwo(string nazwa, int powierzchnia, int populacja);
	Panstwo(const Panstwo& p);
	~Panstwo();

	//gettery
	string pobierz_nazwe();
	int pobierz_powierzchnie();
	int pobierz_populacje();
	string pobierz_stolice();
	string pobierz_jezyk();
	int pobierz_pkb();

	//settery
	void ustaw_stolice(string stolica);
	void ustaw_jezyk(string jezyk);
	void ustaw_pkb(int pkb);

	//operatory
	bool operator<(const Panstwo &p );
	bool operator>(const Panstwo &p );
	bool operator==(const Panstwo &p );
	bool operator!=(const Panstwo &p );
	Panstwo& operator=(const Panstwo& p);
	friend ostream & operator<< (ostream &, Panstwo &);

private:
	string nazwa;
	int powierzchnia;
	int populacja;
	string stolica;
	string jezyk;
	int pkb;
};
ostream& operator<< (ostream& strumien, Panstwo& panstwo);
#endif /* PANSTWO_H_ */
