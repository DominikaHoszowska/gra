#include "../Headers/Miecznik.h"

Miecznik::Miecznik()
{
    silaAtaku_=30;
    obrona_=20;
    wytrzymalosc_=50;
    liczebnoscOddzialu_=200;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=1;
}
void Miecznik::atakujZPierwszejLinii() {
    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
    atakujZPierwszejLinii(przeciwnik);
}
void Miecznik::atakujZPierwszejLinii(Oddzial *przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}


