/*
 * KontynentZPasmemGorskim.cpp
 *
 *  Created on: 7 maj 2014
 *      Author: PiotreK
 */

#include "KontynentZPasmemGorskim.h"
#include "Debugowanie.h"
#include <sstream>

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

string KontynentZPasmemGorskim::najwyzsze_pasmo()
{
	int licznik=0;
	for(int i=1; i<pobierz_liczbe_pasm(); i++)
	{
		if(*pasma[licznik]<*pasma[i]) {
			licznik=i;
		}
	}
	return pasma[licznik]->pobierz_nazwe();
}

///wyswietlanie nazwy danego kontynentu, powierzchni, nazwy wszystkich panstw oraz pasm i cechy charakterystyczne
ostream& operator<< (ostream& strumien, KontynentZPasmemGorskim& kontynentZPasmemGorskim)
{
	strumien<<"nazwa kontynentu: "<<kontynentZPasmemGorskim.pobierz_nazwe()<<endl;
	strumien<<"powierzchnia kontynentu wynosi: "<<kontynentZPasmemGorskim.pobierz_powierzchnie()<<endl;
	strumien<<"liczba panstw na tym kontynencie: "<<kontynentZPasmemGorskim.pobierz_liczbe_panstw()<<endl;
	for(int i=0; i<kontynentZPasmemGorskim.pobierz_liczbe_panstw(); i++)
			strumien<<"nazwa panstwa nr: "<<i<<" : "<<kontynentZPasmemGorskim[i]<<endl;
	strumien<<"nazwa najwiekszego panstwa: "<<kontynentZPasmemGorskim.najwieksze_panstwo()<<endl;
	strumien<<"liczba pasm: "<<kontynentZPasmemGorskim.pobierz_liczbe_pasm()<<endl;
	for(int i=0; i<kontynentZPasmemGorskim.pobierz_liczbe_pasm(); i++)
			strumien<<"nazwa pasma nr: "<<i<<" : "<<kontynentZPasmemGorskim.pasma[i]->pobierz_nazwe()<<endl;
	strumien<<"nazwa najwyzszego pasma: "<<kontynentZPasmemGorskim.najwyzsze_pasmo()<<endl;

	return strumien;
}

string KontynentZPasmemGorskim::pokaz_ceche_charakterystyczna()
{
	return "najwyzsze pasmo to: " + najwyzsze_pasmo();
}

void KontynentZPasmemGorskim::zapisz_do_pliku(ofstream& plik)
{
	if(plik)
	{
		plik<<nazwa<<" "<<"2"<<endl;
		for(int i=0; i<liczba_panstw; i++)
		{
			panstwa[i]->zapisz_do_pliku(plik);
		}
		for(int i=0; i<liczba_pasm;i++)
		{
			pasma[i]->zapisz_do_pliku(plik);
		}
		plik<<"#";
	}
	else
		debug("Blad w zapisie kontynentuZpasmemGorskim do pliku");
}
///pozwala na odczytywanie danych z pliku
void KontynentZPasmemGorskim::odczyt_z_pliku(ifstream& plik)
{
	if(plik)
	{
		string linia;
		getline(plik, linia);
		stringstream strumien(linia);
		strumien >> nazwa;

		panstwa.clear();	///< czyszczenie wczesniej dodanych obiektow
		liczba_panstw = 0;	///< po wyczyszczeniu nie ma panstw
		pasma.clear();
		liczba_pasm = 0;
		///wczytywanie danych z pliku
		while(1)
		{
			string line;
			getline(plik,line);
			stringstream linia(line);
			if(line[0]=='#')		///< znak specjalny, ktory oznacza koniec wczytywania
			{
				break;
			}

			if(line[0]=='@')	///< znak specjalny, ktory oznacza koniec wczytywania panstw, a rozpoczyna wczytywanie pasm
			{
				string line;
				getline(plik,line);
				stringstream linia(line);	///< odczytywana jest cala linia
				Pasmo_gorskie* nowe_pasmo=new Pasmo_gorskie("pasmo",0);	///< tworzenie nowego pasma, do ktorego zaraz beda wpisane dane z odczytywanego pliku
				nowe_pasmo->odczyt_z_pliku(linia);
				this->dodaj_pasmo(nowe_pasmo);	///< pasmo, ktore wlasnie zostalo pobrane z pliku, dodajemy do odpowiedniego kontynentu
				continue;
			}

			if(line == "")
				continue;
			Panstwo* nowe_panstwo= new Panstwo("panstwo ", 0, 0);	///< wczytywanie danych dla panstwa
			nowe_panstwo->odczyt_z_pliku(linia);
			this->dodaj_panstwo(nowe_panstwo);		///<dodanie panstwa do kontynentu
		}
	}
	else
		debug("Blad w odczycie kontynentuZpasmem z pliku");
}



