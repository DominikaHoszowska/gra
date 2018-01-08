#include <iostream>
#include "../Headers/Bebniarz.h"

Bebniarz::Bebniarz():Oddzial(), Zasiegowa(), Wsparcie()
{
    silaAtaku_=0;
    obrona_=1;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=40;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=4;
}
void Bebniarz::wypisz()
{
    std::cout<<this->OZNACZENIE;
}
