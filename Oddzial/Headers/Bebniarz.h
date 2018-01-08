/**
 * Project Untitled
 */


#ifndef _BEBNIARZ_H
#define _BEBNIARZ_H

#include "Zasiegowa.h"
#include "Wsparcie.h"


class Bebniarz: public Zasiegowa, public Wsparcie {
public:
    Bebniarz();
    static const char OZNACZENIE ='B';
    void wypisz() override ;
};

#endif //_BEBNIARZ_H