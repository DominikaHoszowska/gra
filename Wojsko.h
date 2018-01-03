/**
 * Project Untitled
 */


#ifndef _WOJSKO_H
#define _WOJSKO_H

class Wojsko {
public: 
    
    void atak();

    Oddzial& kogoWspierac(void Oddzial&);
    
    /**
     * @param Oddzial&
     */
    Oddzial& kogoAtakowac(void Oddzial&);
    class AssociationClass1 {
    };
private: 
    
    void aktualizujStan();
    
    void konsolidacjaSzeregow();
    
    bool czyPuste();
};

#endif //_WOJSKO_H