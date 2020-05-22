#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
const char clear[]="cls";
#include "Portal.hpp"
#include "Media.hpp"
int Admin::brojAdmina=0;
void ispisiLogin()
{
	system(clear);
	cout << "Dobrodosli:\n";
	cout << "p) Prijava\n";
	cout << "q) Izlaz\n";
	cout << "Unos: ";
}
void ispisiAdminMeni()
{
	system(clear);
	cout << "Admin meni:\n";
	cout << "1) Napravi novog korisnika\n2) Ispisi korisnike\n3) Trazi korisnike\n4) Brisi korisnike\n5) Menjaj polja korisnika\n";
	cout << "q) Izlaz\n";
	cout << "Unos: ";
}
void ispisiKorisnickiMeni()
{
	system(clear);
	cout << "----- Korisnicki meni -----\n";
	cout << "1) Napravi\n2) Ispisi\n3) Brisi\n";
	cout << "q) Izlaz\n";
	cout << "Unos: ";
}
int main()
{
	Portal portal;
	Media media;
	while(1){
		ispisiLogin();
		string izbor;
		cin >> izbor;
		if(daLiIzaci(izbor))
			break;
		Korisnik* k=portal.prijaviSe();
		if(k->daLiSamAdmin())
		{while(1){
		ispisiAdminMeni();
		cin >> izbor;
		if(daLiIzaci(izbor))
			break;
		char karakterIzbora=izbor[0];
		switch(karakterIzbora)
		{
			case '1': portal.napraviKorisnika(); break;
			case '2': portal.ispisKorisnika(); break;
			case '3': portal.pretragaKorisnika(); break;
			case '4': portal.brisiKorisnike(); break;
			case '5': portal.izmeniKorisnika(); break;
		}}}
		else{
			{while(1){
			ispisiKorisnickiMeni();
			cin >> izbor;
			if(daLiIzaci(izbor))
				break;
			char karakterIzbora=izbor[0];
			switch(karakterIzbora)
			{
				case '1': media.dodaj(); break;
				case '2': media.ispisi(); break;
				case '3': media.brisi(); break;
		}}}
		}}
	portal.sacuvajPromene();
	media.sacuvajPromene();
	return 0;
}
