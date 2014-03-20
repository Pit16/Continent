
class Panstwo
{
public: 
	Panstwo(string nazwa);
	~Panstwo();
	string pobierz_nazwe();
	int pobierz_powierzchnie();
	int pobierz_popolacje();
	string pobierz_stolice();
	string pobierz_jezyk();
	int pobierz_pkb();
	
private:
	string nazwa;
	int powierzchnia;
	int populacja;
	string stolica;
	string jezyk;
	int pkb;

};