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
    void atakuj(PoleDrugiejLinii &linii) override;

    void atakuj(PolePierwszejLinii &linii) override;

    double zwrocObrone() override;
    void wypisz() override ;
};

#endif //_LUCZNIK_H