/**
 * Project Untitled
 */


#ifndef _HALABARDZISTA_H
#define _HALABARDZISTA_H

#include "Zwarcie.h"
#include "Konny.h"


class Halabardzista: public Zwarcie {
public:
    Halabardzista();

public:
    static const char OZNACZENIE = 'H';

    void wypisz() override ;
};

#endif //_HALABARDZISTA_H