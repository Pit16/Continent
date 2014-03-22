/*
 * Panstwo.cpp
 *
 *  Created on: 22 mar 2014
 *      Author: PiotreK
 */

#include "Panstwo.h"

Panstwo::Panstwo(string nazwa, int powierzchnia, int populacja)
{

	cout<<"Panstwo::Panstwo() "<<endl;
	this->nazwa=nazwa;
	this->powierzchnia=powierzchnia;
	this->populacja=populacja;
	this->stolica="";
	this->jezyk="";
	this->pkb=0;
}

Panstwo::~Panstwo()
{
	cout<<"Panstwo::~Panstwo(void) "<<endl;
}

string Panstwo::pobierz_nazwe()
{
	return nazwa;
}

int Panstwo::pobierz_powierzchnie()
{
	return powierzchnia;
}

int Panstwo::pobierz_populacje()
{
	return populacja;
}

string Panstwo::pobierz_stolice()
{
	return stolica;
}

string Panstwo::pobierz_jezyk()
{
	return jezyk;
}

int Panstwo::pobierz_pkb()
{
	return pkb;
}

void Panstwo::ustaw_stolice(string stolica)
{
	this->stolica=stolica;
}

void Panstwo::ustaw_jezyk(string jezyk)
{
	this->jezyk=jezyk;
}

void Panstwo::ustaw_pkb(int pkb)
{
	this->pkb=pkb;
}

