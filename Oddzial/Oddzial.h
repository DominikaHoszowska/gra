/**
 * Project Untitled
 */


#ifndef _ODDZIAL_H
#define _ODDZIAL_H

#include "../Pole/PolePierwszejLinii.h"

class Oddzial {
public: 
    
    void atakuj();
    
    /**
     * @param PolePosilkow
     */
    void atakuj(void PolePosilkow);
    
    /**
     * @param PolePierwszejLinii
     */
    void wspieraj(PolePierwszejLinii);
    
    /**
     * @param PoleDrugiejLinii
     */
    void wspieraj(void PoleDrugiejLinii);
    
    bool czyPusty();

protected:
    int silaAtaku_;
    int obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int zasieg_;
    int obrazenia_;
    int straty_;
    int morale_;
    int wspieraj_;

    
    /**
     * @param PoleDrugiejLinii
     */
    virtual void atakuj(void PoleDrugiejLinii) = 0;
    
    /**
     * @param PolePierwszejLinii
     */
    virtual void atakuj(void PolePierwszejLinii) = 0;
    
    /**
     * @param PolePosilkow
     */
    virtual void wspieraj(void PolePosilkow) = 0;


private:

    Pole* pole_;

};

#endif //_ODDZIAL_H