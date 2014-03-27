/*
 * testy.cpp
 *
 *  Created on: 27 mar 2014
 *      Author: PiotreK
 */

#include "Panstwo.h"
#include "Kontynent.h"
#include "Pasmo_gorskie.h"
#include "Debugowanie.h"

bool test_pobierz_nazwe_panstwa();
void test_operator_mniejszosci_panstwa();
void test_operator_wiekszosci_panstwa();
void test_operator_rownosci_panstwa();
void test_operator_nierownosci_panstwa();
void test_operator_indeksowania();
void test_dodawania_panstw();
void test_dodawania_kontynentu();
void test_kopiowanie_kontynentu();
void test_zliczanie_kontynentow();
void test_operator_strumieniowy_kontynent();
void test_operator_przypisania_kontynent();
void test_srednie_zaludnienie();
void test_usuwanie_panstwa();
void test_dodaj_pasmo();

using namespace std;

/*int main()
{
	test_pobierz_nazwe_panstwa();
	test_operator_mniejszosci_panstwa();
	test_operator_wiekszosci_panstwa();
	test_operator_rownosci_panstwa();
	test_operator_nierownosci_panstwa();
	test_operator_indeksowania();
	test_dodawania_panstw();
	test_dodawania_kontynentu();
	test_kopiowanie_kontynentu();
	test_zliczanie_kontynentow();
	test_operator_strumieniowy_kontynent();
	test_operator_przypisania_kontynent();
	test_srednie_zaludnienie();
	test_usuwanie_panstwa();
	test_dodaj_pasmo();
	return 0;
}
*/

bool test_pobierz_nazwe_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	cout << niemcy.pobierz_nazwe() << endl;
	if("Niemcy" == niemcy.pobierz_nazwe())
		return true;
	else
		return false;
}

void test_operator_mniejszosci_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	Panstwo usa("Usa", 200, 10);
	if(niemcy<usa)
		cout<<"Operator mniejszosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator mniejszosci NIE DZIALA"<<endl;
}


void test_operator_wiekszosci_panstwa()
{
	Panstwo niemcy("Niemcy", 100, 100);
	Panstwo usa("Usa", 200, 10);
	if(usa>niemcy)
		cout<<"Operator wiekszosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator wiekszosci NIE DZIALA"<<endl;
}

void test_operator_rownosci_panstwa()
{
	Panstwo chiny("Chiny", 10, 100);
	Panstwo indie("Indie", 10, 10);
	if(chiny == indie)
		cout<<"Operator rownosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator rownosci NIE DZIALA"<<endl;
}


void test_operator_nierownosci_panstwa()
{
	Panstwo chiny("Chiny", 30, 100);
	Panstwo indie("Indie", 10, 10);
	if(chiny != indie)
		cout<<"Operator nierownosci panstwa DZIALA"<<endl;
	else
		cout<<"Operator nierownosci NIE DZIALA"<<endl;
}

void test_operator_indeksowania()
{
	Panstwo andora("Andora", 100, 10);
	Panstwo polska("Polska", 50, 100);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(polska);
	cout<<europa[1]<<endl;
}

void test_dodawania_panstw()
{

	Panstwo polska("Polska", 50, 100);
	Panstwo andora("Andora", 100, 10);
	Panstwo anglia("Anglia", 90, 10);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(polska);
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	cout<<europa.pobierz_powierzchnie()<<endl;
	cout<<europa.najwieksze_panstwo()<<endl;
}

void test_dodawania_kontynentu()
{
	Kontynent azja("Azja");
	cout<<"dodano azja"<<endl;
}

void test_kopiowanie_kontynentu()
{
	cout<<"=======test kopiowania kontynentu========="<<endl;
	Kontynent k1("pierwszy");
	Panstwo anglia("Anglia", 90, 10);
	k1.dodaj_panstwo(anglia);
	Kontynent k2(k1);
	cout<<k1.pobierz_powierzchnie()<<endl;
	cout<<k2.pobierz_powierzchnie()<<endl;
	cout<<"=======koniec testu kopiowania kontynentu========="<<endl;
}

void test_zliczanie_kontynentow()
{
	Kontynent jeden("jeden");
	Kontynent dwa("dwa");
	Kontynent trzy(dwa);
	cout<<"Liczba kontynentow: "<<Kontynent::pobierz_licznik()<<endl;
}

void test_operator_strumieniowy_kontynent()
{
	Kontynent dwa("Australia");
	cout<<dwa;
}

void test_operator_przypisania_kontynent()
{
	Kontynent k1("Europa");
	Panstwo anglia("Anglia", 90, 10);
	k1.dodaj_panstwo(anglia);
	Kontynent k2("Azja");
	k2=k1;
	cout<<k2;
}

void test_srednie_zaludnienie()
{
	Panstwo andora("Andora", 100, 1056);
	Panstwo anglia("Anglia", 90, 500);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	cout<<"srednie zaludnienie wynosi: "<<europa.srednie_zaludnienie()<<endl;
}

void test_usuwanie_panstwa()
{
	Panstwo andora("Andora", 100, 1056);
	Panstwo anglia("Anglia", 90, 500);
	Panstwo polska("Polska", 200, 400);
	Kontynent europa("Europa");
	europa.dodaj_panstwo(andora);
	europa.dodaj_panstwo(anglia);
	europa.dodaj_panstwo(polska);
	cout<<europa<<endl;
	europa.usun_panstwo(1);
	cout<<europa;
}

void test_dodaj_pasmo()
{
	Pasmo_gorskie tatry("Tatry", 1300);
	Pasmo_gorskie andy("Andy", 1800);
	Kontynent europa("Europa");
	//europa.dodaj_pasmo(tatry);
	//europa.dodaj_pasmo(andy);

}

/*
 * Kontynent k1, k2;
 * k1.dodajPanstwo..
 * k1.dodajPasmo...
 * k2 = k1;
 * k1.pasmo[0].wysokosc = 0;
 * cout << k1 << endl;
 * cout << k2 << endl;
 *
 */
