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
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)== nullptr)
                {
                    std::cout<<" X ";
                }
                else {
                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->wypisz();

                }
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }

        Gra::wypiszPrzerywnik();
    }
}

bool PoleBitwy::czyPuste(int nrGracza);
void PoleBitwy::przesunOddzialy(){
    przesunPierwszyGracz();
    przesunDrugiGracz();
}
{
    int nrWiersza;
    if(nrGracza==0)
    {
        nrWiersza=2;
    }
    else
        nrWiersza=0;
    for(int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
        if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            return false;
        }
    }
    return true;

}
void PoleBitwy::przesuniecieWojsk(int nrGracza)
{
    if(nrGracza==0)
    {
        przesunPierwszyGracz();
    }
    else
    {
        przesunDrugiGracz();
    }
}
void PoleBitwy::przesunPierwszyGracz()
{
    for(int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
         if(poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()== nullptr)
         {
             if(poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial()!= nullptr)
             {
                 poleGry_.at(0).at(2).at(nrKolumny)->ustaw(poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial());
                 if(poleGry_.at(0).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
                 {
                     poleGry_.at(0).at(1).at(nrKolumny)->ustaw(poleGry_.at(0).at(0).at(nrKolumny)->zwrocOddzial());
                     poleGry_.at(0).at(0).at(nrKolumny)->ustaw(nullptr);
                 }
                 else
                 {
                     poleGry_.at(0).at(1).at(nrKolumny)->ustaw(nullptr);
                 }
             }
         }
    }
}
void PoleBitwy::przesunDrugiGracz()
{
    for(int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
        if(poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()== nullptr)
        {
            if(poleGry_.at(1).at(1).at(nrKolumny)->zwrocOddzial()!= nullptr)
            {
                poleGry_.at(1).at(0).at(nrKolumny)->ustaw(poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial());
                if(poleGry_.at(1).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
                {
                    poleGry_.at(1).at(1).at(nrKolumny)->ustaw(poleGry_.at(0).at(0).at(nrKolumny)->zwrocOddzial());
                    poleGry_.at(1).at(2).at(nrKolumny)->ustaw(nullptr);
                }
                else
                {
                    poleGry_.at(1).at(1).at(nrKolumny)->ustaw(nullptr);
                }
            }
        }
    }
}
void PoleBitwy::konsolidacjaPierwszyGraczzNrSzeregu(int nrSzeregu)
{
    if(nrSzeregu==0||nrSzeregu==gra_->zwrocDlugoscLinii()-1)
    {
        return;
    }
    if(nrSzeregu<this->gra_->zwrocDlugoscLinii()/2)
    {
        int nrKolumny=nrSzeregu-1;
        while(nrKolumny>0&&poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int nrWiersza=2;
            while(nrWiersza>=0&& poleGry_.at(0).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
            {
                poleGry_.at(0).at(nrWiersza).at(nrKolumny+1)->ustaw(poleGry_.at(0).at(nrWiersza).at(nrKolumny)->zwrocOddzial());
                poleGry_.at(0).at(nrWiersza).at(nrKolumny)->ustaw(nullptr);
                nrWiersza--;
            }
            nrKolumny--;
        }

    } else
    {
        int nrKolumny=nrSzeregu+1;
        while(nrKolumny<this->gra_->zwrocDlugoscLinii()-1&&poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int nrWiersza=2;
            while(nrWiersza>=0&& poleGry_.at(0).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
            {
                poleGry_.at(0).at(nrWiersza).at(nrKolumny-1)->ustaw(poleGry_.at(0).at(nrWiersza).at(nrKolumny)->zwrocOddzial());
                poleGry_.at(0).at(nrWiersza).at(nrKolumny)->ustaw(nullptr);
                nrWiersza--;
            }
            nrKolumny++;
        }
    }
}
void PoleBitwy::konsolidacjaPierwszyGracz()
{
    int prog=this->gra_->zwrocDlugoscLinii()/2;
    for(int i=0;i<prog;i++)
    {
        if(poleGry_.at(0).at(2).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
    for(int i=prog*2-1;i>=prog;i--)
    {
        if(poleGry_.at(0).at(2).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
}
void PoleBitwy::konsolidacjaDrugiGracz()
{
    int prog=this->gra_->zwrocDlugoscLinii()/2;
    for(int i=0;i<prog;i++)
    {
        if(poleGry_.at(1).at(0).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
    for(int i=prog*2-1;i>=prog;i--)
    {
        if(poleGry_.at(1).at(0).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
}
void PoleBitwy::konsolidacjaDrugiGraczzNrSzeregu(int nrSzeregu)
{
    if(nrSzeregu==0||nrSzeregu==gra_->zwrocDlugoscLinii()-1)
    {
        return;
    }


    if(nrSzeregu<(this->gra_->zwrocDlugoscLinii()/2))
    {
        int nrKolumny=nrSzeregu-1;
        while(nrKolumny>=0&&poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int nrWiersza=0;
            while(nrWiersza<=2&& poleGry_.at(1).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
            {
                poleGry_.at(1).at(nrWiersza).at(nrKolumny+1)->ustaw(poleGry_.at(1).at(nrWiersza).at(nrKolumny)->zwrocOddzial());
                poleGry_.at(1).at(nrWiersza).at(nrKolumny)->ustaw(nullptr);
                nrWiersza++;
            }
            nrKolumny--;
        }
    }
    else
    {
        int nrKolumny=nrSzeregu+1;
        while(nrKolumny<this->gra_->zwrocDlugoscLinii()&&poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int nrWiersza=0;
            while(nrWiersza<=2&& poleGry_.at(1).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
            {
                poleGry_.at(1).at(nrWiersza).at(nrKolumny-1)->ustaw(poleGry_.at(0).at(nrWiersza).at(nrKolumny)->zwrocOddzial());
                poleGry_.at(1).at(nrWiersza).at(nrKolumny)->ustaw(nullptr);
                nrWiersza++;
            }
            nrKolumny++;
        }
    }
}
void PoleBitwy::konsolidacjaSzeregow() {
    konsolidacjaPierwszyGracz();
    konsolidacjaDrugiGracz();
}