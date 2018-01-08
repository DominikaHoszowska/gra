#include <iostream>
#include "../Headers/Oddzial.h"



/*Wsparcie*/

void Oddzial::wspieraj() {

}
void Oddzial::dodajwsparcie(Oddzial *oddzial)
{
//    if(oddzial->OZNACZENIE==Tarczownik::OZNACZENIE)
//    {
//        this->obrona_*=1.5;
//    }
//    else
//    {
//        this->morale_*=1.5;
//    }
//    this->wsparcie_.push_back(oddzial);
}

void Oddzial::wycofajwsparcie()
{
//    while(!this->wsparcie_.empty())
//    {
//        if(this->wsparcie_.front()->OZNACZENIE==Bebniarz::OZNACZENIE)
//        {
//            this->straty_/=1.5;
//            this->morale_/=1.5;
//        }
//        else
//        {
//            this->obrona_/=1.5;
//        }
//        this->wsparcie_.pop_front();
//    }
}

/*ATAK*/
void Oddzial::zadajObrazenia(double obrazenia)
{
    double straty= obrazenia*(1-(zwrocMorale()/(1-zwrocMorale())))
                   /(wytrzymalosc_*(1+zwrocObrone()));
    if(straty>0)
    {
        this->straty_+=straty;
    }
}
void Oddzial::atakujZPierwszejLinii()
{
    /*nie atakuj*/
}
void Oddzial::atakujZDrugiejLinii()
{
    /*nie atakuj*/
}

/*ZWRACANIE WARTOŚCI*/

Pole*Oddzial:: zwrocPole()
{
    return this->pole_;
}
double Oddzial::zwrocMorale()
{
    return this->morale_;
}
int Oddzial::zwrocLiczebnoscPoczatkowa()
{
    return this->liczebnoscPoczatkowa;
}
int Oddzial::zwrocliczebnosc()
{
    return liczebnoscOddzialu_;
}
int Oddzial::zwrocZasieg()
{
    return this->zasieg_;
}
Wojsko* Oddzial::zwrocWojsko()
{
    return this->wojsko_;
}
double Oddzial::obrona()
{
    return this->obrona_;
}
double Oddzial::zwrocObrone()
{
    return this->obrona_;
}




/*INNE*/
void Oddzial:: ustawPole(Pole* pole)
{
    this->pole_=pole;

}

void Oddzial::ustawWojsko(Wojsko *wojsko)
{
    this->wojsko_=wojsko;
}
Oddzial::Oddzial()
{
    morale_=0;
}

void Oddzial:: wyzerujStraty()
{
    this->straty_=0;
}

void Oddzial::przeliczStraty()
{
    int sumaStrat=(int)straty_;

        morale_-=sumaStrat/liczebnoscOddzialu_;
        liczebnoscOddzialu_-=sumaStrat;
        wyzerujStraty();
}

void Oddzial::usun()
{
    delete this;
}

void Oddzial::zmniejszMorale()
{
    double morale=this->zwrocMorale();
    if(morale<0)
    {
        morale*=-1;
    }
    if(morale>1)
    {
        this->morale_-=morale*0.25;
        return;
    }
    else
    {
        this->morale_-=0.25;
        return;
    }

}

void Oddzial::wypisz()
{
}