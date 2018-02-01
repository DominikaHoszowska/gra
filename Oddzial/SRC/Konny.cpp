#include <iostream>
#include "../Headers/Konny.h"

Konny:: Konny(): Oddzial(), Zwarcie()
{
    silaAtaku_=50;
    obrona_=10;
    wytrzymalosc_=70;
    liczebnoscOddzialu_=100;
    zasieg_=2;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
}

void Konny::wypisz()
{
    std::cout<<this->OZNACZENIE;
}

void Konny::atakuj(PolePierwszejLinii &pole) {
    Oddzial* przeciwnik=this->zwrocWojsko()->znajdzPrzeciwnika(*this,this->zwrocZasieg());
    przeciwnik->przyjmijAtak(*this);
}

void Konny::przyjmijAtak(Halabardzista &oddzial, PolePierwszejLinii &pole) {
    oddzial.atakuj(*this, pole);
}
void Konny::atakuj(Oddzial & oddzial) {

    oddzial.zadajObrazenia((1+this->silaAtaku_)*liczebnoscOddzialu_);
}
void Konny::atakuj(Zasiegowa &oddzial)
{
    oddzial.zadajObrazenia((1+(this->silaAtaku_*0.25))*liczebnoscOddzialu_);
}





