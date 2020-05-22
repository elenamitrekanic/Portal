#ifndef METADATA_HPP_INCLUDED
#define METADATA_HPP_INCLUDED
class FilmMeta
{
private:
	string jezik,zemlja,bazaPodataka;
public:
	FilmMeta(string jezik="Srpski",string zemlja="Srbija",string bazaPodataka="iMDB")
	{
		this->jezik=jezik;
		this->zemlja=zemlja;
		this->bazaPodataka=bazaPodataka;
	}
};
class SerijaMeta:public FilmMeta
{
private:
	string sezonskaBazaPodataka;
public:
	SerijaMeta(string jezik="Srpski",string zemlja="Srbija",string bazaPodataka="iMDB",string sezonskaBazaPodataka="TVDB")
	:FilmMeta(jezik,zemlja,bazaPodataka)
	{
		this->sezonskaBazaPodataka=sezonskaBazaPodataka;
	}
};
#endif //METADATA_HPP_INCLUDED