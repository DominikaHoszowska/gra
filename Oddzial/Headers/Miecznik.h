/**
 * Project Untitled
 */


#ifndef _MIECZNIK_H
#define _MIECZNIK_H

#include "Zwarcie.h"


class Miecznik: public Zwarcie {
public:
    Miecznik();
    static const char OZNACZENIE = 'M';
    void atakujZPierwszejLinii()override;
    void atakujZPierwszejLinii(Oddzial*);

};

#endif //_MIECZNIK_H