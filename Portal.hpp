#ifndef PORTAL_HPP_INCLUDED
#define PORTAL_HPP_INCLUDED
#include "Korisnik.hpp"
bool daLiIzaci(string izbor)
    {
        if(
            izbor=="q"||izbor=="quit"||
            izbor=="e"||izbor=="exit"||
            izbor=="s"||izbor=="stop"
            )return true;
        else return false;
    }
class Portal
{
private:
    string korisnickiFajl;
    vector<Korisnik*> korisnici;
public:
    Portal(string korisnickiFajl="korisnici.txt")
    {
        this->korisnickiFajl=korisnickiFajl;
        ucitajKorisnike();
    }
    Korisnik* prijaviSe()
    {while(1){
        string korisnickoIme,lozinka;
        cout << "Korisnicko ime: ";
        cin >> korisnickoIme;
        cout << "Lozinka: ";
        cin >> lozinka;
        if(korisnickoIme=="admin" && lozinka=="Veomateskasifra1") //za slucaj da nema korisnika
            return NULL;
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if(((*i)->getKorisnickoIme())==korisnickoIme && ((*i)->getLozinka())==lozinka)
            {
                cout << "Uspesna prijava!\n";
                return *i;
            }
        }
        cout << "Neuspesna prijava! Opet deder.\n";
    }}
    void ucitajKorisnike()
    {
        ifstream file(korisnickiFajl);
        if (file.is_open())
        {
            string ime,prezime,korisnickoIme,email,lozinka,tipKorisnika;
            while(!file.eof())
            {
                file>>ime>>prezime>>korisnickoIme>>email>>lozinka>>tipKorisnika;
                if(file.eof()) break;
                if(tipKorisnika=="admin")
                {
                    Admin* pokazivacNaKorisnika=new Admin(ime,prezime,korisnickoIme,email,lozinka);
                    korisnici.push_back((Korisnik*)pokazivacNaKorisnika);
                }
                else
                {
                    Korisnik* pokazivacNaKorisnika=new Korisnik(ime,prezime,korisnickoIme,email,lozinka);
                    korisnici.push_back(pokazivacNaKorisnika);
                }
            }
            file.close();
        }
        else
        {
            cout << "Neuspesno otvaranje fajla. Pravi se novi " << korisnickiFajl << endl;
            sacuvajKorisnike();
        }
    }
    void listaKorisnika()const
    {
        int KorisnickiID=1;
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
            cout<<KorisnickiID++<<") "<<**i<<endl;
    }
    void sacuvajKorisnike()const
    {
        ofstream file(korisnickiFajl);
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            file<<(*i)->getIme()<<" ";
            file<<(*i)->getPrezime()<<" ";
            file<<(*i)->getKorisnickoIme()<<" ";
            file<<(*i)->getEmail()<<" ";
            file<<(*i)->getLozinka()<<" ";
            string tipKorisnika;
            if((*i)->daLiSamAdmin())
                tipKorisnika="admin";
            else
                tipKorisnika="korisnik";
            file<<tipKorisnika<<endl;
        }
        file.close();
    }
    void sacuvajPromene()
    {
        system(clear);
        sacuvajKorisnike();
        cout << "Uspesno sacuvane promene.\n";
    }
    void napraviKorisnika()
    {
        char tipKorisnika;
        system(clear);
        cout << "Kreiranje korisnika:\n";
        while(1)
        {
            cout << "Da li je ce ovo biti obican korisnik ili admin (k/a)\n";
            cout << "Unos: ";
            char tipKorisnika;
            cin >> tipKorisnika;
            if(tipKorisnika=='k' || tipKorisnika=='a')
                break;
            cout << "Jos jedared.\n";
        }
        if(tipKorisnika=='a')
        {
            Admin* pokazivacNaKorisnika=new Admin;
            pokazivacNaKorisnika->podesiKorisnika();
            korisnici.push_back((Korisnik*)pokazivacNaKorisnika);
        }
        else
        {
            Korisnik* pokazivacNaKorisnika=new Korisnik;
            pokazivacNaKorisnika->podesiKorisnika();
            korisnici.push_back(pokazivacNaKorisnika);
        }
    }
    void ispisKorisnika()const
    {while(1){
        system(clear);
        cout << "Korisnici:\n\n";
        listaKorisnika();
        char gotovo;
        cout << "Gotovo? (d) ";
        cin >> gotovo; 
        if(gotovo=='d')
            break;
    }}
    void pretragaPoImenu()
    {while(1){
        system(clear);
        cout << "Pretraga za: ";
        string trazenoIme;
        cin >> trazenoIme;
        cout << "Korisnici sa istim imenom:\n";
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if(((*i)->getIme())==trazenoIme)
                cout<<**i;
        }
        cout << "Gotovo? (d) ";
        char gotovo;
        cin >> gotovo;
        if(gotovo=='d')
            break;
    }}
    void pretragaPoPrezimenu()
    {while(1){
        system(clear);
        cout << "Pretraga za: ";
        string trazenoPrezime;
        cin >> trazenoPrezime;
        cout << "Korisnici sa istim prezimenom:\n";
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if(((*i)->getPrezime())==trazenoPrezime)
                cout<<**i;
        }
        cout << "Gotovo? (d) ";
        char gotovo;
        cin >> gotovo;
        if(gotovo=='d')
            break;
    }}
    void pretragaPoKorisnickomImenu()
    {while(1){
        system(clear);
        cout << "Pretraga za: ";
        string trazenoKorisnickoIme;
        cin >> trazenoKorisnickoIme;
        cout << "Korisnici sa istim korisnickim imenom:\n";
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if(((*i)->getKorisnickoIme())==trazenoKorisnickoIme)
                cout<<**i;
        }
        cout << "Gotovo? (d) ";
        char gotovo;
        cin >> gotovo;
        if(gotovo=='d')
            break;
    }}
    void pretragaPoEmailu()
    {while(1){
        system(clear);
        cout << "Pretraga za: ";
        string trazeniEmail;
        cin >> trazeniEmail;
        cout << "Korisnici sa istim emailom:\n";
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if(((*i)->getEmail())==trazeniEmail)
                cout<<**i;
        }
        cout << "Gotovo? (d) ";
        char gotovo;
        cin >> gotovo;
        if(gotovo=='d')
            break;
    }}
    void pretragaKorisnika()
    {
    	while(1)
    	{
        	string izbor;
        	cout << "Pretraga korisnika:\n";
        	cout << "1) Po imenu\n2) Po prezumenu\n3) Po korisnickom imenu\n4) Po emailu\n";
        	cout << "q) Zaustavi pretragu\n";
        	cout << "Unos: ";
        	cin >> izbor;
        	if(daLiIzaci(izbor))
            	break;
        	char karakterIzbora=izbor[0];
        	switch(karakterIzbora)
        	{
            	case '1': pretragaPoImenu(); break;
            	case '2': pretragaPoPrezimenu(); break;
            	case '3': pretragaPoKorisnickomImenu(); break;
            	case '4': pretragaPoEmailu(); break;
        	}
    	}
    }
    
    void brisiKorisnike()
    {while(1){
        string izbor;
        cout << "Brisanje korisnika:\n";
        cout << "d) Obrisi korisnika\n";
        cout << "q) Izlaz\n";
        cout << "Unos: ";
        cin >> izbor;
        if(daLiIzaci(izbor))
            break;
        system(clear);
        cout << "Unos korisnickih informacija:\n";
        cout << "     Ime Prezime KorisnickoIme Email\n";
        cout << "Unos: ";
        string ime,prezime,korisnickoIme,email;
        cin >> ime >> prezime >> korisnickoIme >> email;
        system(clear);
        bool obrisan=false;
        for(auto i=korisnici.begin();i!=korisnici.end();i++)
        {
            if((*i)->getIme()==ime){
                if((*i)->getPrezime()==prezime){
                    if((*i)->getKorisnickoIme()==korisnickoIme){
                        if((*i)->getEmail()==email){
                            obrisan=true;
                            korisnici.erase(i);
                        }}}}
            if(obrisan)
                break;
        }
        if(obrisan)
            cout << "Uspesno uklonjen korisnik\n\n";
        else
            cout << "Nije pronadjen trazeni korisnik.\n\n";
    }}
    void izmeniKorisnika()
    {while(1){
        string trazi;
        cout << "Izmena korisnika:\n";
        cout << "c) Izmeni korisnika\n";
        cout << "q) Izlaz\n";
        cout << "Unos: ";
        string izbor;
        cin >> izbor;
        if(daLiIzaci(izbor))
            break;
        system(clear);
        cout << "Izaberite korisnika za izmenu:\n";
        listaKorisnika();
        cout << "Unos: ";
        int idIzbor;
        cin >> idIzbor;
        idIzbor--;
        while(1){
        system(clear);
        cout << "Promena korisnika:\n";
        auto i=korisnici.begin()+idIzbor;
        cout << **i;
        cout << "1) Ime\n2) Preizme\n3) Email\n4) Lozinka\ne) Izlaz\n";
        cout << "Unos: ";
        cin >> izbor;
        if(daLiIzaci(izbor))
            break;
        char karakterIzbora='4';
        if(izbor=="1")
            karakterIzbora='1';
        else if(izbor=="2")
            karakterIzbora='2';
        else if(izbor=="3")
            karakterIzbora='3';
        switch(karakterIzbora)
        {
            case '1':
            {
                string novoIme;
                cout << "Novo ime: ";
                cin >> novoIme;
                (*i)->setIme(novoIme);
                break;
            }
            case '2':
            {
                string novoPrezime;
                cout << "Novo prezime: ";
                cin >> novoPrezime;
                (*i)->setPrezime(novoPrezime);
                break;
            }
            case '3':
            {
                string noviEmail;
                cout << "Nova email adresa: ";
                cin >> noviEmail;
                (*i)->setEmail(noviEmail);
                break;
            }
            case '4':
            {
                (*i)->promeniLozinku();
                break;
            }
        }
    }}}
};
#endif //PORTAL_HPP_INCLUDED