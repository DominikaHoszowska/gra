/**
 * Project Untitled
 */


#ifndef _ZASIEGOWA_H
#define _ZASIEGOWA_H
class Zasiegowa;
#include "Oddzial.h"


class Zasiegowa: virtual public Oddzial {
public:
    void przyjmijAtak(Konny &konny) override;
};

#endif //_ZASIEGOWA_H