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
    return this->zwrocPole()->zwrocObrone(this);
}