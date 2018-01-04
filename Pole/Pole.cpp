#include <stdexcept>
#include "Pole.h"

Oddzial* Pole::zwrocOddzial() {
    return this->oddzial_;
}
void Pole::ustaw(Oddzial* oddzial)
{
    this->oddzial_=oddzial;
    oddzial->ustawPole(this);
}
int Pole::zwrocNrGracza()
{
    return this->nrGracza_;
}

int Pole::zwrocNrWiersza()
{
    return this->zwrocNrWiersza();
}
int Pole::zwrocNrKolumny()
{
    return this->zwrocNrKolumny();
}
void Pole::ustawNrGracza(int nrGracza)
{
    this->nrGracza_=nrGracza;
}
void Pole::ustawNrWiersza(int nrWiersza)
{
    this->nrWiersza_=nrWiersza;
}
void Pole::ustawNrKolumny(int nrKolumny)
{
    this->nrKolumny_-nrKolumny;
}
void Pole::ustawWspolrzedne(int nrGracza, int nrWiersza, int nrKolumny)
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

Pole::Pole(Oddzial *oddzial_) : oddzial_(oddzial_) {};
Pole::Pole():
{
    oddzial_= nullptr;
}
