#include "../Headers/Lucznik.h"

Lucznik::Lucznik()
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
    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
    atakujZPierwszejLinii(przeciwnik);
}
void Lucznik::atakujZDrugiejLinii()
{
    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
    atakujZDrugiejLinii(przeciwnik);
}
