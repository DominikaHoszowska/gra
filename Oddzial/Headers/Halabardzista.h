/**
 * Project Untitled
 */


#ifndef _HALABARDZISTA_H
#define _HALABARDZISTA_H

#include "Zwarcie.h"


class Halabardzista: public Zwarcie {
public:
    Halabardzista();

public:
    static const char OZNACZENIE = 'H';
    void atakujZPierwszejLinii()override;
    void atakujZPierwszejLinii(Oddzial*);/*TODO*/

};

#endif //_HALABARDZISTA_H