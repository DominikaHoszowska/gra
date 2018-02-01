/**
 * Project Untitled
 */


#ifndef _KUSZNIK_H
#define _KUSZNIK_H

#include "Zasiegowa.h"


class Kusznik: public Zasiegowa {
public:
    Kusznik();
    static const char OZNACZENIE= 'k';

    void atakuj(PoleDrugiejLinii &linii) override;

    void atakuj(PolePierwszejLinii &linii) override;

    double zwrocObrone() override;
    void wypisz() override ;
};

#endif //_KUSZNIK_H