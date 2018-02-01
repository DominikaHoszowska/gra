#include <iostream>
#include "../Headers/Halabardzista.h"

Halabardzista::Halabardzista():Oddzial(), Zwarcie()
{
    silaAtaku_=40;
    obrona_=20;
    wytrzymalosc_=40;
    liczebnoscOddzialu_=150;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Halabardzista::wypisz()
{
    std::cout<<this->OZNACZENIE;
}