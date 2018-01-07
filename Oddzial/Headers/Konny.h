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
    void atakujZPierwszejLinii()override;
    void atakujZPierwszejLinii(Oddzial*);/*TODO*/
    void atakujZPierwszehLinii(Zasiegowa*);/*TODO*/
    static const char OZNACZENIE= 'K';
};

#endif //_KONNY_H