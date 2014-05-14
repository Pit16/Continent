#ifndef PANSTWO_H_
#define PANSTWO_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/// Klasa implementujaca
class Panstwo
{
public: 
	/// Konstruktor domyslny
	Panstwo(){}
	/// Konstruktor z parametrami
	/**
	 * umozliwia utorzenie panstwa o konkretnej nazwie, powierzchni i populacji
	 \param nazwa
	 \param powierzchnia
	 \param populacja
	 */
	Panstwo(string nazwa, int powierzchnia, int populacja);
	///Konstruktor kopiujacy
	Panstwo(const Panstwo& p);
	///Destruktor
	~Panstwo();

	//gettery
	///Funkcja zwraca nazwe panstwa
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

	void zapisz_do_pliku(ofstream&);
	void odczyt_z_pliku(istream& plik);
	void odczyt_ze_strumienia(istream& stream);

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
