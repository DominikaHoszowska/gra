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

public:
    static const char OZNACZENIE ='B';
};

#endif //_BEBNIARZ_H