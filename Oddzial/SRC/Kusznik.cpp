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
    atakujZPierwszejLinii(przeciwnik);
}
void Kusznik::atakujZDrugiejLinii()
{
    Oddzial *przeciwnik = zwrocWojsko()->znajdzPrzeciwnika(this, this->zwrocZasieg());
    atakujZDrugiejLinii(przeciwnik);
}
