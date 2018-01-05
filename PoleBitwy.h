#ifndef _POLEBITWY_H
#define _POLEBITWY_H
#include <vector>
#include <map>
#include "Pole/PolePierwszejLinii.h"
#include "Gracz.h"
#include "Gra.h"

using namespace std;

class PoleBitwy {
public: 

    PoleBitwy(unsigned int dlugoscLinii);
    vector<PolePierwszejLinii*> znajdzPolePrzeciwnika(const Gracz& );/*TODO*/
    <vector<Pole*>> znajdzMojePole(const Gracz&);/*TODO*/
    virtual void ustaw(unsigned int,unsigned int,unsigned int,Oddzial*);
    virtual void wypisz();
    virtual void ustawGre(Gra*);
    virtual bool czyPuste(unsigned int);/*dostaje nr Gracza i sprawdza czy ma puste wojsko*/
    virtual void przesuniecieWojsk(unsigned int);
    virtual void przesunPierwszyGracz();
    virtual void przesunOddzialy();/*Zleca przesuniecie oddzialow obydwu graczy*/
    virtual void przesunDrugiGracz();
    virtual void konsolidacjaPierwszyGraczzNrSzeregu(unsigned int);
    virtual void konsolidacjaDrugiGraczzNrSzeregu(unsigned int);
    virtual void konsolidacjaPierwszyGracz();
    virtual void konsolidacjaDrugiGracz();
    virtual void konsolidacjaSzeregow();
    virtual void aktualizujstan();
    virtual void przeliczStraty();
    virtual void zmniejszMorale(unsigned int,unsigned int);
    virtual void zmniejszMoralePierwszyGracz(unsigned int);
    virtual void zmniejszMoraleDrugiGracz(unsigned int);
    virtual void usunOddzialyIZmniejszMorale();
    virtual void usunOddzialyIZmniejszMoralePierwszyGracz();/*TODO*/
    virtual void usunOddzialyIZmniejszMoraleDrugiGracz();/*TODO*/



private:
    Gra* gra_;

    vector<vector<vector<Pole*>>> poleGry_;

};

#endif //_POLEBITWY_H