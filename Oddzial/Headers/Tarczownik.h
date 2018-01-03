/**
 * Project Untitled
 */


#ifndef _TARCZOWNIK_H
#define _TARCZOWNIK_H

#include "Wsparcie.h"
#include "Zwarcie.h"


class Tarczownik: public Wsparcie, public Zwarcie {
public:
    Tarczownik();

public:
    static const char OZNACZENIE = 'T';
};

#endif //_TARCZOWNIK_H