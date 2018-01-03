#include <iostream>
#include <stdexcept>
#include "Gra.h"
#include "Oddzial/Headers/Lucznik.h"
#include "Oddzial/Headers/Tarczownik.h"


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
void Gra::stworzPoleBitwy() {
    poleBitwy_ = new PoleBitwy(zwrocDlugoscLinii());
    char znak;
    for (int nrGracza = 0; nrGracza < 2; nrGracza++)
    {
        for (int nrWiersza=0;nrWiersza<6;nrWiersza++)
        {
            Oddzial* oddzial = nullptr;
            switch(char a){
                case Tarczownik::OZNACZENIE:
                    oddzial = new Tarczownik();
                    break;
                default:
                    throw std::invalid_argument("Nieprawidlowy znak na planszy");
            }
        }
    }

}


Gra::Gra(int liczbaTur, int dlugoscLinii) : liczbaTur_(liczbaTur), dlugoscLinii_(dlugoscLinii) {
}
