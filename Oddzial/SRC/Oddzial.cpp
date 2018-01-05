#include "../Headers/Oddzial.h"
#include <iostream>
#include <stdexcept>

void Oddzial::atakuj() {
    throw std::runtime_error("TODO");

}
void Oddzial::atakuj(void PolePosilkow) {
    throw std::runtime_error("TODO");
}

void Oddzial::wspieraj(void PolePierwszejLinii) {
    throw std::runtime_error("TODO");
}

void Oddzial::wspieraj(void PoleDrugiejLinii) {
    throw std::runtime_error("TODO");
}

virtual void Oddzial::atakuj(void PoleDrugiejLinii)
{
    throw std::runtime_error("TODO");
}

virtual void Oddzial::atakuj(void PolePierwszejLinii) {
    throw std::runtime_error("TODO");
}


virtual void Oddzial::wspieraj(void PolePosilkow) {
    throw std::runtime_error("TODO");
}
Pole*Oddzial:: zwrocPole()
{
    return this->pole_;
}
void Oddzial:: ustawPole(Pole* pole)
{
    this->pole_=pole;
}

Oddzial::Oddzial()
{
    morale_=0;
}
int Oddzial::obrazenia()
{
    return (1+this->silaAtaku_)*this->liczebnoscOddzialu_;
}
double Oddzial::zwrocMorale()
{
    return this->morale_;
}
void Oddzial:: wyzerujStraty()
{
    this->straty_=0;
}

void Oddzial::przeliczStraty()
{
    int sumaStrat=(int)straty_;

        morale_-=sumaStrat/liczebnoscOddzialu_;
        liczebnoscOddzialu_-=sumaStrat;
        wyzerujStraty();
}

double Oddzial::stratyZadanePrzezOddzial(Oddzial* atakowanyOddzial)
{
    double straty=(this->obrazenia()*(1-2*atakowanyOddzial->morale_)
                         /(1-atakowanyOddzial->morale_))
                         /(atakowanyOddzial->wytrzymalosc_*(1+atakowanyOddzial->obrona_));
    if(straty>0)
    {
        return straty;
    }
    return 0;
}
void Oddzial::usun()
{
    delete this;
}

void Oddzial::zmniejszMorale()
{
    double morale=this->zwrocMorale();
    if(morale<0)
    {
        morale*=-1;
    }
    if(morale>1)
    {
        this->morale_-=morale*0.25;
        return;
    }
    else
    {
        this->morale_-=0.25;
        return;
    }

}
int Oddzial::zwrocLiczebnoscPoczatkowa()
{
    return this->liczebnoscPoczatkowa;
}
int Oddzial::zwrocliczebnosc()
{
    return liczebnoscOddzialu_;
}