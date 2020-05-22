#ifndef MEDIA_HPP_INCLUDED
#define MEDIA_HPP_INCLUDED
#include "Zanr.hpp"
#include "Komentar.hpp"
#include "Metadata.hpp"
class Film
{
private:
	string ime,opis;
	double ocena;
	int trajanje;
	Zanr zanr;
	vector<Komentar> komentari;
public:
	Film(string ime="",string opis="",double ocena=0.0,int trajanje=0,string imeZanra="",string opisZanra="")
	:zanr(imeZanra,opisZanra)
	{
		this->ime=ime;
		this->opis=opis;
		this->ocena=ocena;
		this->trajanje=trajanje;
	}
	string getIme()const {return ime;}
	string getOpis()const {return opis;}
	double getOcena()const {return ocena;}
	double getTrajanje()const {return trajanje;}
	string getZanrIme()const {return zanr.getIme();}

	void setIme(string ime) {this->ime=ime;}
	void setOpis(string opis) {this->opis=opis;}
	void setOcena(double ocena) {this->ocena=ocena;}
	void setTrajanje(int trajanje) {this->trajanje=trajanje;}

	void dodajKomentar()
	{
		string naslov,poruka,autor;
		cout << "Naslov: ";
		cin >> naslov;
		cout << "Poruka: ";
		cin >> poruka;
		cout << "Autor: ";
		cin >> autor;
		Komentar komentar(naslov,poruka,autor);
		komentari.push_back(komentar);
	}
	void ispisKomentara()
	{
		cout << "Komentari:" << endl;
		for(auto i=komentari.begin();i!=komentari.end();i++)
			cout << *i << endl;
		cout << endl;
	}

	friend ostream& operator<<(ostream& izlaz, const Film f)
    {
        izlaz<<f.ime<<" ";
        izlaz<<f.opis<<" ";
        izlaz<<f.ocena<<" ";
        izlaz<<f.trajanje<<" ";
        izlaz<<f.getZanrIme()<<endl;
        return izlaz;
    }
};
class Serija
{
protected:
	string ime,opis;
	double ocena;
	int brojSezona,brojEpizoda;
	Zanr zanr;
	vector<Komentar> komentari;
public:
	Serija(string ime="",string opis="",double ocena=0.0,int brojSezona=0,int brojEpizoda=0,string imeZanra="",string opisZanra="")
	:zanr(imeZanra,opisZanra)
	{
		this->ime=ime;
		this->opis=opis;
		this->ocena=ocena;
		this->brojSezona=brojSezona;
		this->brojEpizoda=brojEpizoda;
	}
	string getIme()const {return ime;}
	string getOpis()const {return opis;}
	double getOcena()const {return ocena;}
	int getBrojSezona()const {return brojSezona;}
	int getBrojEpizoda()const {return brojEpizoda;}
	string getZanrIme()const {return zanr.getIme();}

	void setIme(string ime) {this->ime=ime;}
	void setOpis(string opis) {this->opis=opis;}
	void setOcena(double ocena) {this->ocena=ocena;}
	void setBrojSezona(int brojSezona) {this->brojSezona=brojSezona;}
	void setBrojEpizoda(int brojEpizoda) {this->brojEpizoda=brojEpizoda;}

	void dodajKomentar()
	{
		string naslov,poruka,autor;
		cout << "Naslov: ";
		cin >> naslov;
		cout << "Poruka: ";
		cin >> poruka;
		cout << "Autor: ";
		cin >> autor;
		Komentar komentar(naslov,poruka,autor);
		komentari.push_back(komentar);
	}
	void ispisKomentara()
	{
		cout << "Komentari:" << endl;
		for(auto i=komentari.begin();i!=komentari.end();i++)
			cout << *i << endl;
		cout << endl;
	}

	friend ostream& operator<<(ostream& izlaz, const Serija s)
    {
        izlaz<<s.ime<<" ";
        izlaz<<s.opis<<" ";
        izlaz<<s.ocena<<" ";
        izlaz<<s.brojSezona<<" ";
        izlaz<<s.brojEpizoda<<" ";
        izlaz<<s.getZanrIme()<<endl;
        return izlaz;
    }
};
class Anime:public Serija
{
private:
	string studio;
	bool hentai;
public:
	Anime(string studio="",bool hentai=true,string ime="",string opis="",double ocena=0.0,int brojSezona=0,int brojEpizoda=0,string imeZanra="",string opisZanra="")
	:Serija(ime,opis,ocena,brojSezona,brojEpizoda,imeZanra,opisZanra)
	{
		this->studio=studio;
		this->hentai=hentai;
	}
	string getStudio()const {return studio;}
	bool getHentai()const {return hentai;}
	string getIme()const {return Serija::ime;}
	string getOpis()const {return Serija::opis;}
	double getOcena()const {return Serija::ocena;}
	int getBrojSezona()const {return Serija::brojSezona;}
	int getBrojEpizoda()const {return Serija::brojEpizoda;}
	string getZanrIme()const {return Serija::getZanrIme();}

	void setStudio(string studio) {this->studio=studio;}
	void setHentai(bool hentai) {this->hentai=hentai;}
	void setIme(string ime) {Serija::ime=ime;}
	void setOpis(string opis) {Serija::opis=opis;}
	void setOcena(double ocena) {Serija::ocena=ocena;}
	void setBrojSezona(int brojSezona) {Serija::brojSezona=brojSezona;}
	void setBrojEpizoda(int brojEpizoda) {Serija::brojEpizoda=brojEpizoda;}

	friend ostream& operator<<(ostream& izlaz, const Anime& a)
    {
        izlaz<<a.ime<<" ";
        izlaz<<a.opis<<" ";
        izlaz<<a.ocena<<" ";
        izlaz<<a.brojSezona<<" ";
        izlaz<<a.brojEpizoda<<" ";
        izlaz<<a.getZanrIme()<<" ";
        izlaz<<a.studio<<" ";
        if(a.hentai)
        	izlaz<<"hentai"<<endl;
        else
        	izlaz<<"anime"<<endl;
        return izlaz;
    }
};
class Media
{
private:
	vector<Film*> filmovi;
	vector<Serija*> serije;
public:
	void sacuvajPromene()const
    {
        ofstream file1("Novi filmovi.txt");
        for(auto i=filmovi.begin();i!=filmovi.end();i++)
            file1<<**i;
        file1.close();
        ofstream file2("Nove serije.txt");
        for(auto i=serije.begin();i!=serije.end();i++)
            file2<<**i;
        file2.close();
    }
    void dodaj()
    {
    	while(1){
    	char izbor;
    	cout << "f) Dodaj film\ns) Dodaj seriju\na) Dodaj anime\n";
    	cout << "i) Izlaz\n";
    	cout << "Unos: ";
    	cin >> izbor;
    	switch(izbor)
    	{
    		case 'i': return;
    		case 'f': dodajFilm(); break;
    		case 's': dodajSeriju(); break;
    		case 'a': dodajAnime(); break;
    	}
    }}
    void dodajFilm()
    {
    	string ime,opis,imeZanra,opisZanra="";
		double ocena;
		int trajanje;
		cout << "Dodavanje filma" << endl;
		cout << "Ime: ";
		cin >> ime;
		cout << "Opis: ";
		cin >> opis;
		cout << "Ocena: ";
		cin >> ocena;
		cout << "Trajanje: ";
		cin >> trajanje;
		cout << "Zanr: ";
		cin >> imeZanra;
		Film* film=new Film(ime,opis,ocena,trajanje,imeZanra,opisZanra);
		filmovi.push_back(film);
    }
    void dodajSeriju()
    {
    	string ime,opis,imeZanra,opisZanra="";
		double ocena;
		int brojSezona,brojEpizoda;
		cout << "Dodavanje serije" << endl;
		cout << "Ime: ";
		cin >> ime;
		cout << "Opis: ";
		cin >> opis;
		cout << "Ocena: ";
		cin >> ocena;
		cout << "Broj sezona: ";
		cin >> brojSezona;
		cout << "Broj epizoda: ";
		cin >> brojEpizoda;
		cout << "Zanr: ";
		cin >> imeZanra;
		Serija* serija=new Serija(ime,opis,ocena,brojSezona,brojEpizoda,imeZanra,opisZanra);
		serije.push_back(serija);
    }
    void dodajAnime()
    {
    	string studio,ime,opis,imeZanra,opisZanra="";
    	bool hentai;
		double ocena;
		int brojSezona,brojEpizoda;
		cout << "Dodavanje animea" << endl;
		cout << "Studio: ";
		cin >> studio;
		cout << "Hentai? d/n: ";
		char dane;
		cin >> dane;
		if(dane=='d')
			hentai=true;
		else
			hentai=false;
		cout << "Ime: ";
		cin >> ime;
		cout << "Opis: ";
		cin >> opis;
		cout << "Ocena: ";
		cin >> ocena;
		cout << "Broj sezona: ";
		cin >> brojSezona;
		cout << "Broj epizoda: ";
		cin >> brojEpizoda;
		cout << "Zanr: ";
		cin >> imeZanra;
		Anime* anime=new Anime(studio,hentai,ime,opis,ocena,brojSezona,brojEpizoda,imeZanra,opisZanra);
		serije.push_back((Serija*)anime);
    }
    void ispisi()
    {
    	while(1){
    	char izbor;
    	cout << "f) Ispisi filmove\ns) Ispisi serije\n";
    	cout << "i) Izlaz\n";
    	cout << "Unos: ";
    	cin >> izbor;
    	switch(izbor)
    	{
    		case 'i': return;
    		case 'f': cout << "Ispis filmova:" << endl; ispisiFilmove(); break;
    		case 's': cout << "Ispis serija i animea:" << endl; ispisiSerije(); break;
    	}
    }}
    void ispisiFilmove()
    {
    	int ID=1;
    	for(auto i=filmovi.begin();i!=filmovi.end();i++)
    		cout << ID++ << ") " << **i;
    }
    void ispisiSerije()
    {
    	int ID=1;
    	for(auto i=serije.begin();i!=serije.end();i++)
    		cout << ID++ << ") " << **i;
    }
    void brisi()
    {
    	while(1){
    	char izbor;
    	cout << "f) Obrisi film\ns) Obrisi seriju\n";
    	cout << "i) Izlaz\n";
    	cout << "Unos: ";
    	cin >> izbor;
    	switch(izbor)
    	{
    		case 'i': return;
    		case 'f':
    		{
    			cout << "Izaberite film:" << endl;
    			ispisiFilmove();
    			int izbor;
    			cout << "Unos: ";
    			cin >> izbor;
    			izbor--;
    			filmovi.erase(filmovi.begin()+izbor);
    			break;
    		}
    		case 's':
    		{
    			cout << "Izaberite seriju ili anime:" << endl;
    			ispisiSerije();
    			int izbor;
    			cout << "Unos: ";
    			cin >> izbor;
    			izbor--;
    			serije.erase(serije.begin()+izbor);
    			break;
    		}
    	}
    }}
};
#endif //MEDIA_HPP_INCLUDED