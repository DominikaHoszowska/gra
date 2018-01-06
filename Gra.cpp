#include <iostream>
#include <stdexcept>
#include "Gra.h"
#include "Oddzial/Headers/Lucznik.h"
#include "Oddzial/Headers/Tarczownik.h"
#include "Oddzial/Headers/Kusznik.h"
#include "Oddzial/Headers/Halabardzista.h"
#include "Oddzial/Headers/Konny.h"
#include "Oddzial/Headers/Bebniarz.h"

bool Gra::czyKoniec() {
    if(this->poleBitwy_->czyPuste(0))
    {
        std::cout<<"Wygrał drugi gracz!!!";
        return true;
    }
    if(this->poleBitwy_->czyPuste(1))
    {
        std::cout<<"Wygrał pierwszy gracz!!!";
        return true;
    }
    if(aktualnyNrTury_==liczbaTur_)
    {
        std::cout<<"REMIS";
        return true;
    }
    return false;
}
void Gra::inicjalizuj(char tabPole[6][zwrocDlugoscLinii()]) {
    stworzPoleBitwy(tabPole[6][this->zwrocDlugoscLinii()]);
    stworzGraczy();
}
void Gra::stworzGraczy()
{/*
    this->pierwszyGracz_= Gracz(0);
    this->drugiGracz_= Gracz(1);
    */
}
void Gra::rozegrajTure() {
    this->aktualnyNrTury_+=1;
    this->poleBitwy_->wsparcie();
    this->poleBitwy_->atak();
    this->poleBitwy_->wycofajWsparcie();
    this->poleBitwy_->aktualizujstan();
    this->wypisz();

}
unsigned int Gra::zwrocLiczbeTur(){
    return this->liczbaTur_;
}

unsigned int Gra::zwrocDlugoscLinii()
{
    return this->dlugoscLinii_;
}
PoleBitwy* Gra::zwrocPoleBitwy()
{
    return this->poleBitwy_;
}
Gracz* Gra:: zwrocPierwszegoGracza()
{
    return this->pierwszyGracz_;
}
Gracz* Gra::zwrocDrugiegoGracza()
{
    return this->drugiGracz_;
}
void Gra::stworzPoleBitwy(char tabPole[6][zwrocDlugoscLinii()]) {

    poleBitwy_ = new PoleBitwy(zwrocDlugoscLinii());
    poleBitwy_->ustawGre(this);
    for (unsigned int nrGracza = 0; nrGracza < 2; nrGracza++) {
        for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
            for(unsigned int nrKolumny=0;nrKolumny<zwrocDlugoscLinii();nrKolumny++) {
                Oddzial *oddzial = nullptr;
                unsigned int wiersz=nrGracza*2+nrWiersza;
                switch (tabPole[wiersz][nrKolumny]) {
                    case Tarczownik::OZNACZENIE:
                        oddzial = new Tarczownik();
                        break;
                    case Lucznik::OZNACZENIE:
                        oddzial=new Lucznik;
                        break;
                    case Kusznik::OZNACZENIE:
                        oddzial=new Kusznik;
                        break;
                    case Halabardzista::OZNACZENIE:
                        oddzial= new Halabardzista;
                        break;
                    case Konny::OZNACZENIE:
                        oddzial=new Konny;
                        break;
                    case Bebniarz::OZNACZENIE:
                        oddzial=new Bebniarz;
                        break;
                    case 'X':
                        break;
                    default:
                        throw std::invalid_argument("Nieprawidlowy znak na planszy");
                }
                poleBitwy_->ustaw(nrGracza,nrWiersza,nrKolumny,oddzial);
            }
        }
    }
}
Gra::Gra(unsigned int liczbaTur, unsigned int dlugoscLinii) : liczbaTur_(liczbaTur), dlugoscLinii_(dlugoscLinii) {
    aktualnyNrTury_=0;
}
void Gra::wypisz()
{   wypiszPrzerywnik();
    wypiszPrzerywnik();
    std::cout<<"Tura "<<this->aktualnyNrTury_<<" z "<<liczbaTur_<<std::endl;
    this->poleBitwy_->wypisz();
}
static void Gra::wypiszPrzerywnik()
{
    for (int a=0;a<20;a++)
        std::cout<<"-";
    std::cout<<endl;
}
