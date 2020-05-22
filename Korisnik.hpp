#ifndef KORISNIK_HPP_INCLUDED
#define KORISNIK_HPP_INCLUDED
class Korisnik
{
protected:
	string ime,prezime,korisnickoIme,email,lozinka;
public:
	Korisnik(string ime="",string prezime="",string korisnickoIme="",string email="",string lozinka="")
	{
		this->ime=ime;
        this->prezime=prezime;
        this->korisnickoIme=korisnickoIme;
        this->email=email;
        this->lozinka=lozinka;
	}
    virtual void podesiKorisnika()
    {
    	cout << "Ime: ";
    	cin >> ime;
    	cout << "Prezime: ";
    	cin >> prezime;
    	cout << "Korisnicko ime: ";
    	cin >> korisnickoIme;
        bool validan=false;
    	while(1)
        {
            cout << "Email: ";
            cin >> email;
            for(int i=0;i<email.size();i++)
                if(email[i]=='@') {validan=true; break;}
            if(validan) break;
            cout << "Email adresa nije validna!" << endl;
        }
    	promeniLozinku();
    }
    bool daLiSamAdmin()const {return false;}
	string getIme()const
	{
		return ime;
	}
	string getPrezime()const
	{
		return prezime;
	}
	string getKorisnickoIme()const
	{
		return korisnickoIme;
	}
	string getEmail()const
	{
		return email;
	}
    string getLozinka()const
    {
        return lozinka;
    }
	void setIme(string ime)
	{
		this->ime=ime;
	}
	void setPrezime(string Prezime)
	{
		this->prezime=prezime;
	}
	void setKorinickoIme(string korisnickoIme)
	{
		this->korisnickoIme=korisnickoIme;
	}
	void setEmail(string email)
	{
		this->email=email;
	}
	void promeniLozinku()
	{
		string sifra;
        while(1)
        {
            cout << "Sifra(Minimalno jedno veliko, malo slovo i broj): ";
            cin >> sifra;
            int duzinaLozinke=sifra.size();
            bool velikoSlovo=false,maloSlovo=false,broj=false;
            for(int i=0;i<duzinaLozinke;i++)
            {
                if(velikoSlovo&&maloSlovo&&broj)
                    break;
                if(!velikoSlovo)
                {
                    if(sifra[i]>='A' && sifra[i]<='Z')
                        velikoSlovo=true;
                }
                if(!maloSlovo)
                {
                    if(sifra[i]>='a' && sifra[i]<='z')
                        maloSlovo=true;
                }
                if(!broj)
                {
                    if(sifra[i]>='0' && sifra[i]<='9')
                        broj=true;
                }
            }
            fflush(stdin);
            if(velikoSlovo&&maloSlovo&&broj)
                break;
            cout << endl << "Slabo, slabo, mozete Vi i bolje." << endl;
        }
        lozinka=sifra;
	}
    friend ostream& operator<<(ostream& izlaz, const Korisnik& korisnik)
    {
        izlaz<<korisnik.ime<<" "<<korisnik.prezime<<" "<<korisnik.korisnickoIme<<" "<<korisnik.email<<" "<<endl;
        return izlaz;
    }
};
class Admin:public Korisnik
{
protected:
    static int brojAdmina;
public:
    Admin(string ime="",string prezime="",string korisnickoIme="",string email="",string lozinka="")
    :Korisnik(ime,prezime,korisnickoIme,email,lozinka)
    {
    	brojAdmina++;
    }
    bool daLiSamAdmin()const {return true;}
    void podesiKorisnika()
    {
        Korisnik::podesiKorisnika();
    }
    friend ostream& operator<<(ostream& izlaz, const Admin& admin)
    {
        izlaz<<admin.ime<<" ";
        izlaz<<admin.prezime<<" ";
        izlaz<<admin.korisnickoIme<<" ";
        izlaz<<admin.email<<endl;
        return izlaz;
    }
};

#endif // USER_HPP_INCLUDED
