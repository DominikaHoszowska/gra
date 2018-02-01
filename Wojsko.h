/**
 * Project Untitled
 */


#ifndef _WOJSKO_H
#define _WOJSKO_H

class Wojsko;

#include "Oddzial/Headers/Oddzial.h"
#include "Gracz.h"
#include "PoleBitwy.h"

//#include "Oddzial/Headers/Lucznik.h"

class Wojsko {
public: 
    
    void atak();
    virtual void kogoWspierac(Pole*);
    virtual void kogoWspieracPierwszyGracz(Pole*);
    virtual void kogoWspieracDrugiGracz(Pole*);
    virtual Gracz* zwrocGracza();
    virtual Oddzial* znajdzPrzeciwnika(Oddzial*,int);
//    virtual Oddzial* znajdzPrzeciwnika(Lucznik*,int);
    PoleBitwy* zwrocPoleBitwy();
    void ustawGracza(Gracz*);
    void ustawPoleBitwy(PoleBitwy*);
private:

    void przesuniecieWojsk();
    bool czyPuste();
    PoleBitwy* poleBitwy_;
    Gracz* gracz_ ;

};

#endif //_WOJSKO_H