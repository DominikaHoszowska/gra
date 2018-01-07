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
    void atakujZPierwszejLinii()override;
    void atakujZDrugiejLinii()override;
    void atakujZPierwszejLinii(Oddzial*);
    void atakujZDrugiejLinii(Oddzial*);
    double zwrocObrone() override;
};

#endif //_KUSZNIK_H