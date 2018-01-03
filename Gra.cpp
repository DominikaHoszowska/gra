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
    if(zwrocLiczbeTur()<=0)
    {
        return false;
    }
    /*TODO sprawdzic czy wojska nie sa puste*/

}
void Gra::inicjalizuj() {
    stworzPoleBitwy();
    stworzGraczy();
}

void Gra::stworzGraczy()
{
    this->pierwszyGracz_= Gracz(0);
    this->drugiGracz_= Gracz(1);

}

void Gra::tura() {
    this->pierwszyGracz_->atak();
    this->drugiGracz_->atak();
    /*TODO aktualizacja stanu, konsolidacja szeregów*/
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
void Gra::stworzPoleBitwy(char *tabPole) {

    poleBitwy_ = new PoleBitwy(zwrocDlugoscLinii());
    char znak;
    for (int nrGracza = 0; nrGracza < 2; nrGracza++) {
        for (int nrWiersza = 0; nrWiersza < 3; nrWiersza++) {
            for(int nrKolumny=0;nrKolumny<zwrocDlugoscLinii();nrKolumny++) {
                Oddzial *oddzial = nullptr;
                switch (tabPole[nrGracza*2+nrWiersza][nrKolumny]) {
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
                    default:
                        throw std::invalid_argument("Nieprawidlowy znak na planszy");
                }
                poleBitwy_->ustaw(nrGracza,nrWiersza,nrKolumny,oddzial);

            }
        }
    }
}


Gra::Gra(int liczbaTur, int dlugoscLinii) : liczbaTur_(liczbaTur), dlugoscLinii_(dlugoscLinii) {
}
