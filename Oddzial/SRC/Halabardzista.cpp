#include <iostream>
#include "../Headers/Halabardzista.h"

Halabardzista::Halabardzista():Oddzial(), Zwarcie()
{
    silaAtaku_=40;
    obrona_=20;
    wytrzymalosc_=40;
    liczebnoscOddzialu_=150;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}
void Halabardzista::atakujZPierwszejLinii() {
//    Oddzial* przeciwnik = zwrocWojsko()->znajdzPrzeciwnika(this,this->zwrocZasieg());
//    if(przeciwnik!= nullptr)
//        atakujZPierwszejLinii(przeciwnik);
}
void Halabardzista::atakujZPierwszejLinii(Oddzial * przeciwnik)
{
    double obrazenia=(1+silaAtaku_)*zwrocliczebnosc();
    przeciwnik->zadajObrazenia(obrazenia);
}
void Halabardzista::atakujZPierwszejLinii(Konny * konik)

{
    double obrazenia=(1+1.5*silaAtaku_)*zwrocliczebnosc();
    konik->zadajObrazenia(obrazenia);
}


void Halabardzista::wypisz()
{
    std::cout<<this->OZNACZENIE;
}