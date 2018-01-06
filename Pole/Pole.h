#ifndef _POLE_H
#define _POLE_H
#include "../Oddzial/Headers/Oddzial.h"
class Pole {
private:
    Oddzial* oddzial_;
    PoleBitwy* poleBitwy_;
    unsigned int nrGracza_;
    unsigned int nrWiersza_;
    unsigned int nrKolumny_;
public:

    Pole(Oddzial *oddzial_);
    Pole();
    /*ATAK*/
    virtual void atakuj();/*DO POPRAWY*/
    virtual Oddzial* zwrocOddzial();
    virtual PoleBitwy* zwrocPoleBitwy();
    virtual void zmniejszMoralenaSasiednich();
    virtual void ustaw(Oddzial*);
    virtual unsigned int zwrocNrGracza();
    virtual unsigned int zwrocNrWiersza();
    virtual unsigned int zwrocNrKolumny();
    virtual void ustawNrGracza(unsigned int);
    virtual void ustawNrWiersza(unsigned int);
    virtual void ustawNrKolumny(unsigned int);
    virtual void ustawWspolrzedne(unsigned int,unsigned int, unsigned int);
    virtual int odleglosc(Pole drugiePole);
    virtual void wypisz();
    virtual void usunOddzial();
};

#endif //_POLE_H