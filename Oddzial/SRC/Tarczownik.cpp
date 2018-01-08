#include "../Headers/Tarczownik.h"

Tarczownik::Tarczownik():Oddzial(), Zwarcie(), Wsparcie()
{
    silaAtaku_=0;
    obrona_=20;
    wytrzymalosc_=100;
    liczebnoscOddzialu_=100;
    liczebnoscPoczatkowa=liczebnoscOddzialu_;
    zasieg_=2;
}

