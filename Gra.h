#ifndef _GRA_H
#define _GRA_H
#include "PoleBitwy.h"
#include "Gracz.h"

class Gra {
public:

    Gra(unsigned int liczbaTur_, unsigned int dlugoscLinii_);

    bool czyKoniec();

    void rozegrajTure();

    unsigned int zwrocLiczbeTur();

    unsigned int zwrocDlugoscLinii();

    void stworzPoleBitwy(char tabPole[6][zwrocDlugoscLinii()]);

    void stworzGraczy();/*TODO*/
    virtual Gracz* zwrocPierwszegoGracza();
    virtual Gracz* zwrocDrugiegoGracza();
    PoleBitwy* zwrocPoleBitwy();
    virtual ~Gra() {
        delete poleBitwy_;
        delete pierwszyGracz_;
        delete drugiGracz_;
    }
    void inicjalizuj(char tabPole[6][zwrocDlugoscLinii()]);
    virtual void wypisz();
    virtual static void wypiszPrzerywnik();
private:
    unsigned int liczbaTur_;
    unsigned int aktualnyNrTury_;
    unsigned int dlugoscLinii_;
    PoleBitwy* poleBitwy_;
    Gracz* pierwszyGracz_;
    Gracz* drugiGracz_;
};

#endif //_GRA_H