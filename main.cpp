//============================================================================
// Name        : Continent.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include "Panstwo.h"
#include "Pasmo_gorskie.h"

using namespace std;

int main(void)
{
	Panstwo* niemcy=new Panstwo("Niemcy", 100, 34);
	cout<<niemcy->pobierz_nazwe()<<endl;
	cout<<niemcy->pobierz_powierzchnie()<<endl;
	cout<<niemcy->pobierz_populacje()<<endl;
	cout<<niemcy->pobierz_stolice()<<endl;
	niemcy->ustaw_stolice("Berlin");
	niemcy->ustaw_jezyk("niemiecki");
	niemcy->ustaw_pkb(2);
	cout<<niemcy->pobierz_stolice()<<endl;
	cout<<niemcy->pobierz_jezyk()<<endl;
	cout<<niemcy->pobierz_pkb()<<endl;
	Pasmo_gorskie* tatry=new Pasmo_gorskie("Tatry", 1300);
	cout<<tatry->pobierz_nazwe()<<endl;
	cout<<tatry->pobierz_srednia_wysokosc()<<endl;
	tatry->ustaw_najwyzszy_szczyt("Rysy");
	cout<<tatry->pobierz_najwyzszy_szczyt()<<endl;
	cout<<tatry->pobierz_wysokosc_najwyzszy_szczyt()<<endl;
	tatry->ustaw_wysokosc(2499);
	cout<<tatry->pobierz_wysokosc_najwyzszy_szczyt()<<endl;

	return 0;
}
