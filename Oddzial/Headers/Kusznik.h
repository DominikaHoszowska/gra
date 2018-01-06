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
    void atakujZDrugiejLinii()override;/*TODO*/
    void atakujZPierwszejLinii(Oddzial*);/*TODO*/
    void atakujZDrugiejLinii(Oddzial*);/*TODO*/
};

#endif //_KUSZNIK_H