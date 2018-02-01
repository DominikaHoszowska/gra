#include <iostream>
#include "../Headers/Lucznik.h"

Lucznik::Lucznik():Oddzial(), Zasiegowa()
{
    silaAtaku_=30;
    obrona_=5;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=5;
}

double Lucznik::zwrocObrone()
{
    //TODO
    throw std::runtime_error("Not implemented");
//    return this->zwrocPole()->zwrocObrone(this);
}
void Lucznik::wypisz()
{
    std::cout<<this->OZNACZENIE;
}