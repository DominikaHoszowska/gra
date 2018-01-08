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
void Lucznik::atakujZPierwszejLinii()
{
//    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
//    if(przeciwnik!= nullptr)
//        atakujZPierwszejLinii(przeciwnik);
}
void Lucznik::atakujZDrugiejLinii()
{
//    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
//    if(przeciwnik!= nullptr)
//        atakujZDrugiejLinii(przeciwnik);
}
void Lucznik::atakujZPierwszejLinii(Oddzial* przeciwnik)
{
    double obrazenia=(1+0.5*silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
void Lucznik::atakujZDrugiejLinii(Oddzial *przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
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