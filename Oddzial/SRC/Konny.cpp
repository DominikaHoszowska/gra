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
    if(przeciwnik!= nullptr)
        atakujZPierwszejLinii(przeciwnik);
}
void Konny::atakujZPierwszejLinii(Oddzial *przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
void Konny::atakujZPierwszehLinii(Zasiegowa *przeciwnik)
{
    double obrazenia=(1+1.25*silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}


