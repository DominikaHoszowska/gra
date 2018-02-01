#include <iostream>
#include "../Headers/Kusznik.h"

Kusznik::Kusznik():Oddzial(), Zasiegowa()
{
    silaAtaku_=50;
    obrona_=8;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    zasieg_=1;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

double Kusznik::zwrocObrone()
{
//    return this->zwrocPole()->zwrocObrone(this);
}
void Kusznik::wypisz()
{
    std::cout<<this->OZNACZENIE;
}

void Kusznik::atakuj(PoleDrugiejLinii &pole) {
//    TODO

}

void Kusznik::atakuj(PolePierwszejLinii &pole) {
//TODO
}
