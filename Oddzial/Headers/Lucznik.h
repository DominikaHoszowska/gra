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
    void atakujZPierwszejLinii(Oddzial*);/*TODO*/
    void atakujZDrugiejLinii()override;/*TODO*/
    void atakujZDrugiejLinii(Oddzial*);/*TODO*/
};

#endif //_LUCZNIK_H