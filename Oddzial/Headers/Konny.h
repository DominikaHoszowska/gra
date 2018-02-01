/**
 * Project Untitled
 */


#ifndef _KONNY_H
#define _KONNY_H

#include "Zwarcie.h"
#include "Zasiegowa.h"


class Konny: public Zwarcie {
public:


    Konny();

    static const char OZNACZENIE= 'K';
    void wypisz() override ;
};

#endif //_KONNY_H