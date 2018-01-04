#ifndef _GRA_H
#define _GRA_H
#include "PoleBitwy.h"
#include "Gracz.h"

class Gra {
public:

    Gra(int liczbaTur_, int dlugoscLinii_);

    bool czyKoniec();

    void rozegrajTure();

    int zwrocLiczbeTur();

    int zwrocDlugoscLinii();

    void stworzPoleBitwy(char tabPole[6][zwrocDlugoscLinii()]);

    void stworzGraczy();
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
    int liczbaTur_;
    int aktualnyNrTury_;
    int dlugoscLinii_;
    PoleBitwy* poleBitwy_;
    Gracz* pierwszyGracz_;
    Gracz* drugiGracz_;
};

#endif //_GRA_H