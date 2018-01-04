#include <stdexcept>
#include <iostream>
#include "PoleBitwy.h"
#include "Pole/PoleDrugiejLinii.h"
#include "Pole/PolePosilkow.h"
vector<PolePierwszejLinii> PoleBitwy::znajdzPolePrzeciwnika(void Gracz) {
    throw std::runtime_error("TODO");
}

vector<vector<Pole*>> PoleBitwy::znajdzMojePole(const Gracz&) {
    throw std::runtime_error("TODO");
}

PoleBitwy::PoleBitwy(int dlugoscLinii):poleGry_(2) {
    for (int i = 0; i < dlugoscLinii; ++i){
        poleGry_.at(0).at(0).push_back(new PolePosilkow());
        poleGry_.at(0).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(0).at(2).push_back(new PolePierwszejLinii());
        poleGry_.at(1).at(0).push_back(new PolePierwszejLinii());
        poleGry_.at(1).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(1).at(2).push_back(new PolePosilkow());
    }
}
void PoleBitwy:: ustaw(int nrGracza,int nrWiersza,int nrKolumny,Oddzial* oddzial)
{
    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustaw(oddzial);

}
void PoleBitwy::ustawGre(Gra* gra)
{
    this->gra_=gra;
}
void PoleBitwy::wypisz()
{
    for(int nrGracza=0;nrGracza<2;nrGracza++)
    {
        for(int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
            for (int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->wypisz();
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }

        Gra::wypiszPrzerywnik();
    }
}

