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
    virtual Oddzial& kogoWspierac(Oddzial&);/*TODO*/
    virtual Oddzial& kogoAtakowac(Oddzial&);/*TODO*/
    virtual Gracz* zwrocGracza();

private: 
    

    void konsolidacjaSzeregow();
    void przesuniecieWojsk();
    bool czyPuste();
    PoleBitwy* poleBitwy_;
    Gracz* gracz_;

};

#endif //_WOJSKO_H