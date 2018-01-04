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

    PoleBitwy(int dlugoscLinii);
    vector<PolePierwszejLinii*> znajdzPolePrzeciwnika(const Gracz& );
    <vector<Pole*>> znajdzMojePole(const Gracz&);
    virtual void ustaw(int,int,int,Oddzial*);
    virtual void wypisz();
    virtual void ustawGre(Gra*);
    virtual bool czyPuste(int);/*dostaje nr Gracza i sprawdza czy ma puste wojsko*/
    virtual void przesuniecieWojsk(int);
    virtual void przesunPierwszyGracz();
    virtual void przesunOddzialy();/*Zleca przesuniecie oddzialow obydwu graczy*/
    virtual void przesunDrugiGracz();
    virtual void konsolidacjaPierwszyGraczzNrSzeregu(int);
    virtual void konsolidacjaDrugiGraczzNrSzeregu(int);
    virtual void konsolidacjaPierwszyGracz();
    virtual void konsolidacjaDrugiGracz();
    virtual void konsolidacjaSzeregow();
private:
    Gra* gra_;

    vector<vector<vector<Pole*>>> poleGry_;

};

#endif //_POLEBITWY_H