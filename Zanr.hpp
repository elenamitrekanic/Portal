#ifndef ZANR_HPP_INCLUDED
#define ZANR_HPP_INCLUDED
class Zanr
{
private:
	string ime;
	string opis;
public:
	Zanr(string ime="", string opis="")
	{
		this->ime=ime;
		this->opis=opis;
	}
	
	string getIme()const {return ime;}
	string getOpis()const {return opis;}

	void setIme(string ime) {this->ime=ime;}
	void setOpis(string opis) {this->opis=opis;}

	friend ostream& operator<<(ostream& izlaz, const Zanr zanr)
    {
        izlaz<<zanr.ime<<" ";
        izlaz<<zanr.opis;
        return izlaz;
    }

};

#endif //ZANR_HPP_INCLUDED