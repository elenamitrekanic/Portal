
#ifndef KOMENTAR_HPP_INCLUDED
#define KOMENTAR_HPP_INCLUDED
class Komentar
{
private:
	string naslov,poruka,autor;
public:
	Komentar(string naslov="",string poruka="",string autor="")
	{
		this->naslov=naslov;
		this->poruka=poruka;
		this->autor=autor;
	}
	friend ostream& operator<<(ostream& izlaz, const Komentar& k)
    {
        izlaz<<k.naslov<<endl;
        izlaz<<k.poruka<<endl;
        izlaz<<k.autor<<endl;
        return izlaz;
    }
};
#endif //KOMENTAR_HPP_INCLUDED
