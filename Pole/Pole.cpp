#include <stdexcept>
#include <iostream>
#include "Pole.h"

Oddzial* Pole::zwrocOddzial() {
    return this->oddzial_;
}
void Pole::ustaw(Oddzial* oddzial)
{
    this->oddzial_=oddzial;
    oddzial->ustawPole(this);
}
unsigned int Pole::zwrocNrGracza()
{
    return this->nrGracza_;
}

unsigned int Pole::zwrocNrWiersza()
{
    return this->nrWiersza_;
}
unsigned int Pole::zwrocNrKolumny()
{
    return this->nrKolumny_;
}
void Pole::ustawNrGracza(unsigned int nrGracza)
{
    this->nrGracza_=nrGracza;
}
void Pole::ustawNrWiersza(unsigned int nrWiersza)
{
    this->nrWiersza_=nrWiersza;
}
void Pole::ustawNrKolumny(unsigned int nrKolumny)
{
    this->nrKolumny_-nrKolumny;
}
void Pole::ustawWspolrzedne(unsigned int nrGracza,unsigned int nrWiersza,unsigned  int nrKolumny)
{
    this->nrGracza_=nrGracza;
    this->nrWiersza_=nrWiersza;
    this->nrKolumny_=nrKolumny;
}
int Pole::odleglosc(Pole drugiePole)
{
    int odleglosc_=this->nrKolumny_-drugiePole.zwrocNrKolumny();
    if (odleglosc_<0)
    {
        return odleglosc_*(-1);
    }
    return odleglosc_;
}

void Pole::wypisz()
{
    std::cout<<this->zwrocOddzial()->OZNACZENIE<<":";
    int liczba=this->zwrocOddzial()->zwrocliczebnosc()/this->zwrocOddzial()->zwrocLiczebnoscPoczatkowa();
    if(liczba==1)
    {
        std::cout<<"00";
        return;
    }
    if(liczba<10)
    {
        std::cout<<0<<liczba;
        return;
    }
    std::cout<<liczba;

}
Pole::Pole(Oddzial *oddzial_) : oddzial_(oddzial_) {};
Pole::Pole():
{
    oddzial_= nullptr;
}
void Pole::usunOddzial()
{

    this->zwrocOddzial()->usun();
    this->zmniejszMoralenaSasiednich();
    this->oddzial_= nullptr;
}
PoleBitwy* Pole::zwrocPoleBitwy()
{
    return this->poleBitwy_;
}

void Pole::zmniejszMoralenaSasiednich()
{
    this->zwrocPoleBitwy()->zmniejszMorale(nrGracza_,nrKolumny_);
}
double zwrocObrone(Lucznik* lucznik)
{
    return lucznik->obrona();
}
double zwrocObrone(Kusznik* kusznik)
{
    return kusznik->obrona();
}
