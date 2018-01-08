#ifndef _GRA_H
#define _GRA_H


class Gra;
#include "Gracz.h"
#include "PoleBitwy.h"


class Gra {
public:

    Gra(unsigned int liczbaTur_, unsigned int dlugoscLinii_);

    bool czyKoniec();

    void rozegrajTure();

    unsigned int zwrocLiczbeTur();

    unsigned int zwrocDlugoscLinii();

    void stworzPoleBitwy(std::vector<std::vector<char>>);

    virtual Gracz* zwrocPierwszegoGracza();
    virtual Gracz* zwrocDrugiegoGracza();
    PoleBitwy* zwrocPoleBitwy();

    virtual ~Gra();

    void inicjalizuj(std::vector<std::vector<char>>);
    virtual void wypisz();
    void wypiszPrzerywnik(unsigned int);
private:
    int liczbaTur_;
    unsigned int aktualnyNrTury_;
    unsigned int dlugoscLinii_;
    PoleBitwy* poleBitwy_;
    Gracz* pierwszyGracz_;
    Gracz* drugiGracz_;
};

#endif //_GRA_H