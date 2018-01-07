#include "../Headers/Kusznik.h"

Kusznik::Kusznik()
{
    silaAtaku_=50;
    obrona_=8;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    zasieg_=1;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}
void Kusznik::atakujZPierwszejLinii() {
    Oddzial *przeciwnik = zwrocWojsko()->znajdzPrzeciwnika(this, this->zwrocZasieg());
    if(przeciwnik!= nullptr)
        atakujZPierwszejLinii(przeciwnik);
}
void Kusznik::atakujZDrugiejLinii()
{
    Oddzial *przeciwnik = zwrocWojsko()->znajdzPrzeciwnika(this, this->zwrocZasieg());
    if(przeciwnik!= nullptr)
        atakujZDrugiejLinii(przeciwnik);
}
void Kusznik::atakujZPierwszejLinii(Oddzial* przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
void Kusznik::atakujZDrugiejLinii(Oddzial *przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
double Kusznik::zwrocObrone()
{
    return this->zwrocPole()->zwrocObrone(this);
}
