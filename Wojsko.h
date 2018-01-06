/**
 * Project Untitled
 */


#ifndef _WOJSKO_H
#define _WOJSKO_H

#include "Oddzial/Headers/Oddzial.h"
#include "Gracz.h"
#include "PoleBitwy.h"

class Wojsko {
public: 
    
    void atak();
    virtual void kogoWspierac(Pole*);
    virtual void kogoWspieracPierwszyGracz(Pole*);
    virtual void kogoWspieracDrugiGracz(Pole*);
    PoleBitwy* zwrocPoleBitwy();
    virtual Oddzial& kogoAtakowac(Oddzial*);/*TODO*/
    virtual Gracz* zwrocGracza();
private:

    void przesuniecieWojsk();
    bool czyPuste();
    PoleBitwy* poleBitwy_;
    Gracz* gracz_ ;

};

#endif //_WOJSKO_H