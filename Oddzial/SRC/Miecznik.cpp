#include <iostream>
#include "../Headers/Miecznik.h"

Miecznik::Miecznik(): Oddzial(), Zwarcie()
{
    silaAtaku_=30;
    obrona_=20;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=1;
}
void Miecznik::atakujZPierwszejLinii() {
//    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
//    if(przeciwnik!= nullptr)
//        atakujZPierwszejLinii(przeciwnik);
}
void Miecznik::atakujZPierwszejLinii(Oddzial *przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
void Miecznik::wypisz()
{
    std::cout<<this->OZNACZENIE;
}


