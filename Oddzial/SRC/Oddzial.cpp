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


bool Oddzial::czyPusty() {
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

bool Oddzial::przeliczStraty()
{
    int sumaStrat=(int) straty_;
    if(sumaStrat>liczebnoscOddzialu_)
    {
        return true;
    }
    else
    {
        liczebnoscOddzialu_-=sumaStrat;
        wyzerujStraty();
        return false;
    }

}