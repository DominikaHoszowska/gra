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
        return 1;
    }
    if(this->poleBitwy_->czyPuste(1))
    {
        std::cout<<"Wygrał pierwszy gracz!!!";
        return 1;
    }
    if(aktualnyNrTury_==liczbaTur_)
    {
        std::cout<<"REMIS";
        return true;
    }
    return false;
}
void Gra::inicjalizuj(char tabPole[6][zwrocDlugoscLinii()]) {
    stworzPoleBitwy(tabPole[6][zwrocDlugoscLinii());
    stworzGraczy();
}
void Gra::stworzGraczy()
{/*TODO
    this->pierwszyGracz_= Gracz(0);
    this->drugiGracz_= Gracz(1);
    */
}
void Gra::rozegrajTure() {
    this->aktualnyNrTury_+=1;
    this->pierwszyGracz_->atak();
    this->drugiGracz_->atak();
    this->poleBitwy_->aktualizujstan();
    this->wypisz();

}
int Gra::zwrocLiczbeTur(){
    return this->liczbaTur_;
}

int Gra::zwrocDlugoscLinii()
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
    char znak;
    for (int nrGracza = 0; nrGracza < 2; nrGracza++) {
        for (int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
            for(int nrKolumny=0;nrKolumny<zwrocDlugoscLinii();nrKolumny++) {
                Oddzial *oddzial = nullptr;
                int wiersz=nrGracza*2+nrWiersza;
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
Gra::Gra(int liczbaTur, int dlugoscLinii) : liczbaTur_(liczbaTur), dlugoscLinii_(dlugoscLinii) {
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
