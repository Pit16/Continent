//============================================================================
// Name        : Continent.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "Panstwo.h"


int main(void) {
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


	return EXIT_SUCCESS;
}
