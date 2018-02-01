/**
 * Project Untitled
 */


#ifndef _WSPARCIE_H
#define _WSPARCIE_H

#include "Oddzial.h"


class Wsparcie: virtual public Oddzial {
    void wspieraj();

public:
    void atakuj(PoleDrugiejLinii &linii) override=0;

    void atakuj(PolePierwszejLinii &linii) override=0;
};

#endif //_WSPARCIE_H