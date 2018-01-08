#include <iostream>
#include <vector>
#include <stdexcept>
#include "Gra.h"
#include "Oddzial/Headers/Lucznik.h"
#include "Oddzial/Headers/Tarczownik.h"
#include "Oddzial/Headers/Kusznik.h"
#include "Oddzial/Headers/Halabardzista.h"
#include "Oddzial/Headers/Konny.h"
#include "Oddzial/Headers/Bebniarz.h"
#include "Pole/PolePosilkow.h"

/*INICJALIZACJA*/

void Gra::inicjalizuj(std::vector<std::vector<char>> tabPole) {
    stworzPoleBitwy(tabPole);
}
void Gra::stworzPoleBitwy(std::vector<std::vector<char>> tabPole) {

    poleBitwy_ = new PoleBitwy(zwrocDlugoscLinii());
    poleBitwy_->ustawGre(this);
    for (unsigned int nrGracza = 0; nrGracza < 2; nrGracza++) {
        for (unsigned int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
            for(unsigned int nrKolumny=0;nrKolumny<zwrocDlugoscLinii();nrKolumny++) {
                Oddzial *oddzial = nullptr;
                switch (tabPole.at(nrWiersza).at(nrKolumny)) {
                    case Tarczownik::OZNACZENIE:
                        oddzial = new Tarczownik();
                        break;
                    case Lucznik::OZNACZENIE:
                        oddzial=new Lucznik();
                        break;
                    case Kusznik::OZNACZENIE:
                        oddzial=new Kusznik();
                        break;
                    case Halabardzista::OZNACZENIE:
                        oddzial= new Halabardzista();
                        break;
                    case Konny::OZNACZENIE:
                        oddzial=new Konny();
                        break;
                    case Bebniarz::OZNACZENIE:
                        oddzial = new Bebniarz();
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
    return pierwszyGracz_;
}
Gracz* Gra::zwrocDrugiegoGracza()
{
    return drugiGracz_;
}

Gra::Gra(unsigned int liczbaTur, unsigned int dlugoscLinii) :
        liczbaTur_(liczbaTur), dlugoscLinii_(dlugoscLinii),
        pierwszyGracz_(new Gracz(0)), drugiGracz_(new Gracz(1)),aktualnyNrTury_(0)
{
    poleBitwy_= nullptr;
}

void Gra::wypisz()
{   wypiszPrzerywnik();
    wypiszPrzerywnik();
    std::cout<<"Tura "<<this->aktualnyNrTury_<<" z "<<liczbaTur_<<std::endl;
    this->poleBitwy_->wypisz();
}
void Gra::wypiszPrzerywnik()
{
    for (int a=0;a<20;a++)
        std::cout<<"-";
    std::cout<<std::endl;
}


Gra::~Gra(){
    delete poleBitwy_;
    delete pierwszyGracz_;
    delete drugiGracz_;
}
