#include <iostream>
#include <vector>
#include "PoleBitwy.h"
#include "Pole/PolePosilkow.h"
#include "Pole/PoleDrugiejLinii.h"
#include "Pole/PolePierwszejLinii.h"


/*WSPARCIE*/

void PoleBitwy::wsparcie()
{
    for(unsigned int nrGracza=0;nrGracza<=1;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<=2;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->wspieraj();
            }
        }
    }
}
void PoleBitwy::wycofajWsparcie()
{
    for(unsigned int nrGracza=0;nrGracza<=1;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<=2;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->wycofajwsparcie();
            }
        }
    }
}

/*ATAK*/
void PoleBitwy::atak()
{
    for(unsigned int nrGracza=0;nrGracza<=1;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<=2;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->atakuj();
            }
        }
    }
}

/*ZWRACANIE WARTOSCI*/
std::vector<Pole*> PoleBitwy::zwrocPolePrzeciwnika(unsigned int nrGracza)
{
    if(nrGracza==0)
    {
        return poleGry_.at(0).at(2);
    }
    return poleGry_.at(1).at(0);
}

std::vector<Pole*> PoleBitwy::zwrocPolePrzeciwnikaDrugaLinia(unsigned int nrGracza)
{
    if(nrGracza==0)
    {
        return poleGry_.at(0).at(1);
    }
    return poleGry_.at(1).at(1);
}

PoleBitwy::PoleBitwy(unsigned int dlugoscLinii):poleGry_(2) {
    for(int i=0;i<3;i++) {
        poleGry_.at(0).push_back(std::vector<Pole *>(0));
        poleGry_.at(1).push_back(std::vector<Pole *>(0));
    }
    for (int i = 0; i < dlugoscLinii; ++i){
        poleGry_.at(0).at(0).push_back(new PolePosilkow());
        poleGry_.at(0).at(0).at(i)->ustawWspolrzedne(0,0,i);

        poleGry_.at(0).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(0).at(1).at(i)->ustawWspolrzedne(0,1,i);

        poleGry_.at(0).at(2).push_back(new PolePierwszejLinii());
        poleGry_.at(0).at(2).at(i)->ustawWspolrzedne(0,2,i);

        poleGry_.at(1).at(0).push_back(new PolePierwszejLinii());
        poleGry_.at(1).at(0).at(i)->ustawWspolrzedne(1,0,i);

        poleGry_.at(1).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(1).at(1).at(i)->ustawWspolrzedne(1,1,i);

        poleGry_.at(1).at(2).push_back(new PolePosilkow());
        poleGry_.at(1).at(2).at(i)->ustawWspolrzedne(1,2,i);
    }
}
void PoleBitwy:: ustaw(unsigned int nrGracza,unsigned int nrWiersza,unsigned int nrKolumny,Oddzial* oddzial)
{
        poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->ustaw(oddzial);
}
void PoleBitwy::ustawGre(Gra* gra)
{
    this->gra_=gra;
}
void PoleBitwy::wypisz()
{
    for(unsigned int nrGracza=0;nrGracza<2;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
            std::cout<<"            ";
            for (unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
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

        this->zwrocGre()->wypiszPrzerywnik(zwrocGre()->zwrocDlugoscLinii());
    }
}
void PoleBitwy::przesunOddzialy(){
    przesunPierwszyGracz();
    przesunDrugiGracz();
}
bool PoleBitwy::czyPuste(unsigned int nrGracza)
{
    unsigned int nrWiersza;
    if(nrGracza==0)
    {
        nrWiersza=2;
    }
    else
        nrWiersza=0;
    for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
        if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            return false;
        }
    }
    return true;

}
void PoleBitwy::przesuniecieWojsk(unsigned int nrGracza)
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
    for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
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
                     if(poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial()->OZNACZENIE=='T')
                     {
                         zamienTarczownik(0,2,nrKolumny);
                     }
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
    for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
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
                    if(poleGry_.at(1).at(1).at(nrKolumny)->zwrocOddzial()->OZNACZENIE=='T')
                    {
                        zamienTarczownik(1,0,nrKolumny);
                    }
                }
                else
                {
                    poleGry_.at(1).at(1).at(nrKolumny)->ustaw(nullptr);
                }
            }
        }
    }
}
void PoleBitwy:: zamienTarczownik(unsigned int nrGracza, unsigned int nrWiersza, unsigned int nrKolumny)
{
    Pole poleZastepcze;
    poleZastepcze.ustaw(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial());
    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->
            ustawPole(&poleZastepcze);
    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->
            ustaw(poleGry_.at(nrGracza).at(1).at(nrKolumny)->zwrocOddzial());
    poleGry_.at(nrGracza).at(1).at(nrKolumny)->zwrocOddzial()->ustawPole(poleGry_.at(nrGracza).at(1).at(nrKolumny));
    poleGry_.at(nrGracza).at(1).at(nrKolumny)->ustaw(poleZastepcze.zwrocOddzial());
    poleGry_.at(nrGracza).at(1).at(nrKolumny)->zwrocOddzial()->ustawPole(poleGry_.at(nrGracza).at(1).at(nrKolumny));
}

void PoleBitwy::konsolidacjaPierwszyGraczzNrSzeregu(unsigned int nrSzeregu)
{
    if(nrSzeregu==0||nrSzeregu==gra_->zwrocDlugoscLinii()-1)
    {
        return;
    }
    if(nrSzeregu<this->gra_->zwrocDlugoscLinii()/2)
    {
        unsigned int nrKolumny=nrSzeregu-1;
        while(nrKolumny>0&&poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            unsigned int nrWiersza=2;
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
        unsigned int nrKolumny=nrSzeregu+1;
        while(nrKolumny<this->gra_->zwrocDlugoscLinii()-1&&poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            unsigned int nrWiersza=2;
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
    unsigned int prog=this->gra_->zwrocDlugoscLinii()/2;
    for(unsigned int i=0;i<prog;i++)
    {
        if(poleGry_.at(0).at(2).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
    for(unsigned int i=prog*2-1;i>=prog;i--)
    {
        if(poleGry_.at(0).at(2).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaPierwszyGraczzNrSzeregu(i);
        }
    }
}
void PoleBitwy::konsolidacjaDrugiGracz()
{
    unsigned int prog=this->gra_->zwrocDlugoscLinii()/2;
    for(unsigned int i=0;i<prog;i++)
    {
        if(poleGry_.at(1).at(0).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaDrugiGraczzNrSzeregu(i);
        }
    }
    for(unsigned int i=prog*2-1;i>=prog;i--)
    {
        if(poleGry_.at(1).at(0).at(i)->zwrocOddzial()== nullptr)
        {
            konsolidacjaDrugiGraczzNrSzeregu(i);
        }
    }
}
void PoleBitwy::konsolidacjaDrugiGraczzNrSzeregu(unsigned int nrSzeregu)
{
    if(nrSzeregu==0||nrSzeregu==gra_->zwrocDlugoscLinii()-1)
    {
        return;
    }


    if(nrSzeregu<(this->gra_->zwrocDlugoscLinii()/2))
    {
        int unsigned nrKolumny=nrSzeregu-1;
        while(nrKolumny>=0&&poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int unsigned nrWiersza=0;
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
        unsigned int nrKolumny=nrSzeregu+1;
        while(nrKolumny<this->gra_->zwrocDlugoscLinii()&&poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            int unsigned nrWiersza=0;
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
void PoleBitwy::aktualizujstan()
{
    przeliczStraty();
    usunOddzialyIZmniejszMorale();
    przesunOddzialy();
    konsolidacjaSzeregow();
}
void PoleBitwy::przeliczStraty()
{
    for(unsigned int nrGracza=0;nrGracza<=1;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<=2;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
                {
                    poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()->przeliczStraty();
                }
            }
        }
    }
}
void PoleBitwy::zmniejszMorale(unsigned int nrGracza, unsigned int nrKolumy)
{
    if(nrGracza==0)
    {
        zmniejszMoralePierwszyGracz(nrKolumy);
    }
    else
    {
        zmniejszMoraleDrugiGracz(nrKolumy);
    }
}
void PoleBitwy::zmniejszMoralePierwszyGracz(unsigned int nrKolumny)
{
    if( nrKolumny>0)
    {
        if(poleGry_.at(0).at(2).at(nrKolumny-1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(0).at(2).at(nrKolumny-1)->zwrocOddzial()->zmniejszMorale();
        }
        if(poleGry_.at(0).at(1).at(nrKolumny-1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(0).at(1).at(nrKolumny-1)->zwrocOddzial()->zmniejszMorale();
        }
    }
    if(nrKolumny<this->gra_->zwrocDlugoscLinii()-1)
    {
        if(poleGry_.at(0).at(2).at(nrKolumny+1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(0).at(2).at(nrKolumny+1)->zwrocOddzial()->zmniejszMorale();
        }
        if(poleGry_.at(0).at(1).at(nrKolumny+1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(0).at(1).at(nrKolumny+1)->zwrocOddzial()->zmniejszMorale();
        }
    }
    if(poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        poleGry_.at(0).at(1).at(nrKolumny)->zwrocOddzial()->zmniejszMorale();
    }

}
void PoleBitwy::zmniejszMoraleDrugiGracz(unsigned int nrKolumny)
{
    if( nrKolumny>0)
    {
        if(poleGry_.at(1).at(0).at(nrKolumny-1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(1).at(0).at(nrKolumny-1)->zwrocOddzial()->zmniejszMorale();
        }
        if(poleGry_.at(1).at(1).at(nrKolumny-1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(1).at(1).at(nrKolumny-1)->zwrocOddzial()->zmniejszMorale();
        }
    }
    if(nrKolumny<this->gra_->zwrocDlugoscLinii()-1)
    {
        if(poleGry_.at(1).at(0).at(nrKolumny+1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(1).at(0).at(nrKolumny+1)->zwrocOddzial()->zmniejszMorale();
        }
        if(poleGry_.at(1).at(1).at(nrKolumny+1)->zwrocOddzial()!= nullptr)
        {
            poleGry_.at(1).at(1).at(nrKolumny+1)->zwrocOddzial()->zmniejszMorale();
        }
    }
    if(poleGry_.at(1).at(1).at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        poleGry_.at(1).at(1).at(nrKolumny)->zwrocOddzial()->zmniejszMorale();
    }
}
void PoleBitwy::usunOddzialyIZmniejszMorale()
{
    this->usunOddzialyIZmniejszMoralePierwszyGracz();
    this->usunOddzialyIZmniejszMoraleDrugiGracz();
}
void PoleBitwy:: usunOddzialyIZmniejszMoralePierwszyGracz()
{
    for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
        if(poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            if(poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()->zwrocliczebnosc()<=0)
            {
                poleGry_.at(0).at(2).at(nrKolumny)->zwrocOddzial()->usun();
                zmniejszMoralePierwszyGracz(nrKolumny);
            }
        }
    }
}
void PoleBitwy:: usunOddzialyIZmniejszMoraleDrugiGracz()
{
    for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
    {
        if(poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()!= nullptr)
        {
            if(poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()->zwrocliczebnosc()<=0)
            {
                poleGry_.at(1).at(0).at(nrKolumny)->zwrocOddzial()->usun();
                zmniejszMoraleDrugiGracz(nrKolumny);
            }
        }
    }
}
std::vector<std::vector<Pole*>> PoleBitwy::zwrocPoleBitwy(unsigned int nrGracza)
{
    return poleGry_.at(nrGracza);
}
Gra* PoleBitwy::zwrocGre()
{
    return this->gra_;
}

PoleBitwy::~PoleBitwy() {
    for(unsigned int nrGracza=0;nrGracza<=1;nrGracza++)
    {
        for(unsigned int nrWiersza=0;nrWiersza<3;nrWiersza++)
        {
            for(unsigned int nrKolumny=0;nrKolumny<this->gra_->zwrocDlugoscLinii();nrKolumny++)
            {
                if(poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial()!= nullptr)
                {
                    delete poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny)->zwrocOddzial();
                    delete poleGry_.at(nrGracza).at(nrWiersza).at(nrKolumny);
                }
            }
        }
    }

}
