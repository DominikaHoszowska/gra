#include <iostream>
#include "../Headers/Konny.h"

Konny:: Konny(): Oddzial(), Zwarcie()
{
    silaAtaku_=50;
    obrona_=10;
    wytrzymalosc_=70;
    liczebnoscOddzialu_=100;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Konny::wypisz()
{
    std::cout<<this->OZNACZENIE;
}

void Konny::atakuj(PolePierwszejLinii &pole) {
//    TODO

}






