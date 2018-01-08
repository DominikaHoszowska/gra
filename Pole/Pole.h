#ifndef _POLE_H
#define _POLE_H
class Pole;

#include "../PoleBitwy.h"
#include "../Oddzial/Headers/Oddzial.h"

class Pole {
private:
    Oddzial* oddzial_;
    PoleBitwy* poleBitwy_;
    unsigned int nrGracza_;
    unsigned int nrWiersza_;
    unsigned int nrKolumny_;
public:

    Pole(Oddzial* = nullptr);

    /*ATAK*/
    virtual void atakuj(){}

    /*USTAWIANIE*/

    virtual void ustaw(Oddzial*);


    Oddzial* zwrocOddzial();
    PoleBitwy* zwrocPoleBitwy();
    virtual void zmniejszMoralenaSasiednich();

    unsigned int zwrocNrGracza();
    unsigned int zwrocNrWiersza();
    unsigned int zwrocNrKolumny();
    virtual void ustawNrGracza(unsigned int);
    virtual void ustawNrWiersza(unsigned int);
    virtual void ustawNrKolumny(unsigned int);
    virtual void ustawWspolrzedne(unsigned int,unsigned int, unsigned int);
    virtual int odleglosc(Pole drugiePole);
    virtual void wypisz();
    virtual void usunOddzial();
//    virtual double zwrocObrone(Lucznik*);
//    virtual double zwrocObrone(Kusznik*);
};

#endif //_POLE_H