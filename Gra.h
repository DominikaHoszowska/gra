/**
 * Project Untitled
 */

#ifndef _GRA_H
#define _GRA_H

#include "PoleBitwy.h"
#include "Gracz.h"

class Gra {
public:

    Gra(int liczbaTur_, int dlugoscLinii_);

    bool czyKoniec();

    void tura();

    int zwrocLiczbeTur();

    int zwrocDlugoscLinii();

    void stworzPoleBitwy();

    void stworzGraczy();

    virtual Gracz* zwrocPierwszegoGracza();
    virtual Gracz* zwrocDrugiegoGracza();
    PoleBitwy* zwrocPoleBitwy();

    virtual ~Gra() {
        delete poleBitwy_;
        delete pierwszyGracz_;
        delete drugiGracz_;
    }

    void inicjalizuj();

private:
    int liczbaTur_;
    int dlugoscLinii_;
    PoleBitwy* poleBitwy_;
    Gracz* pierwszyGracz_;
    Gracz* drugiGracz_;
};

#endif //_GRA_H