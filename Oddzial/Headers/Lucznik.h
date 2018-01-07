/**
 * Project Untitled
 */


#ifndef _LUCZNIK_H
#define _LUCZNIK_H

#include "Zasiegowa.h"


class Lucznik: public Zasiegowa {
public:
    Lucznik();
    static const char OZNACZENIE = 'L';
    void atakujZPierwszejLinii()override;
    void atakujZPierwszejLinii(Oddzial*);
    void atakujZDrugiejLinii()override;
    void atakujZDrugiejLinii(Oddzial*);
    double zwrocObrone() override;
};

#endif //_LUCZNIK_H