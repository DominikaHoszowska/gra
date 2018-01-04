#ifndef _POLE_H
#define _POLE_H
#include "../Oddzial/Headers/Oddzial.h"
class Pole {
private:
    Oddzial* oddzial_;
    int nrGracza_;
    int nrWiersza_;
    int nrKolumny_;
public:

    Pole(Oddzial *oddzial_);
    Pole();
    virtual Oddzial* zwrocOddzial();
    virtual void ustaw(Oddzial*);
    virtual int zwrocNrGracza();
    virtual int zwrocNrWiersza();
    virtual int zwrocNrKolumny();
    virtual void ustawNrGracza(int nrGracza);
    virtual void ustawNrWiersza(int nrWiersza);
    virtual void ustawNrKolumny(int nrKolumny);
    virtual void ustawWspolrzedne(int nrGracza, int nrWiersza, int nrKolumny);
    virtual int odleglosc(Pole drugiePole);
    virtual void wypisz();
    virtual void usunOddzial();
};

#endif //_POLE_H