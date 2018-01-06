#include "../Headers/Konny.h"

Konny::Konny()
{
    silaAtaku_=50;
    obrona_=10;
    wytrzymalosc_=70;
    liczebnoscOddzialu_=100;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}
void Konny::atakujZPierwszejLinii() {
    Oddzial* przeciwnik=zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
    atakujZPierwszejLinii(przeciwnik);
}


