#ifndef _ODDZIAL_H
#define _ODDZIAL_H
#include "../../Pole/PolePosilkow.h"
#include "../../Pole/PolePierwszejLinii.h"
#include "../../Pole/PoleDrugiejLinii.h"
#include "../../Pole/Pole.h"

class Oddzial {

public:

    Oddzial();

    virtual void atakuj();
    virtual void atakuj(PolePosilkow);
    virtual void wspieraj(PolePierwszejLinii);
    virtual void wspieraj(PoleDrugiejLinii);
    virtual Pole* zwrocPole();
    virtual bool czyPusty();
    virtual void ustawPole(Pole*);
    virtual char OZNACZENIE;
    virtual int obrazenia();
    virtual double zwrocMorale();
    virtual void wyzerujStraty();
    bool przeliczStraty();/*zwraca prawde jezeli trzeba usunac oddzial bo liczba strat przewyzsza liczebnosc oddzialu*/
protected:
    int silaAtaku_;
    int obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;
    int obrazenia_;
    double straty_;
    double morale_;
    int wspieraj_;
    virtual void atakuj(PoleDrugiejLinii);
    virtual void atakuj(PolePierwszejLinii);
    virtual void wspieraj(PolePosilkow);

private:

    Pole* pole_;

};

#endif //_ODDZIAL_H