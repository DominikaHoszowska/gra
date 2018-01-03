/**
 * Project Untitled
 */


#ifndef _WOJSKO_H
#define _WOJSKO_H

#include "Oddzial/Headers/Oddzial.h"
#include "Gracz.h"

class Wojsko {
public: 
    
    void atak();
    virtual Oddzial& kogoWspierac(Oddzial&);
    virtual Oddzial& kogoAtakowac(Oddzial&);
    virtual Gracz* zwrocGracza();

private: 
    
    void aktualizujStan();
    void konsolidacjaSzeregow();
    void przesuniecieWojsk();
    bool czyPuste();
    Gracz* gracz_;

};

#endif //_WOJSKO_H