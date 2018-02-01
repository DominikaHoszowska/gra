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
    static const char OZNACZENIE = 'H';
    void wypisz() override ;

    void atakuj(Konny &konny, PolePierwszejLinii &linii) override;

    void atakuj(PolePierwszejLinii &linii) override;
};

#endif //_HALABARDZISTA_H