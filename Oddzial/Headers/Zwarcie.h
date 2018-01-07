/**
 * Project Untitled
 */


#ifndef _ZWARCIE_H
#define _ZWARCIE_H

#include "Oddzial.h"


class Zwarcie: virtual public Oddzial {
public:
    void atakujZDrugiejLinii() override ;
};

#endif //_ZWARCIE_H