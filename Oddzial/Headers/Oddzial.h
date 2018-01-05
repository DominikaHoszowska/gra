#ifndef _ODDZIAL_H
#define _ODDZIAL_H
#include "../../Pole/PolePosilkow.h"
#include "../../Pole/PolePierwszejLinii.h"
#include "../../Pole/PoleDrugiejLinii.h"
#include "../../Pole/Pole.h"
#include "../../Wojsko.h"

class Oddzial {

public:

    Oddzial();

    virtual void atakuj();/*TODO*/
    virtual void atakuj(PolePosilkow);/*TODO*/
    virtual void wspieraj(PolePierwszejLinii);/*TODO*/
    virtual void wspieraj(PoleDrugiejLinii);/*TODO*/
    virtual void atakuj(PoleDrugiejLinii);
    virtual void atakuj(PolePierwszejLinii);
    virtual void wspieraj(PolePosilkow);
    virtual Pole* zwrocPole();
    virtual int zwrocLiczebnoscPoczatkowa();
    virtual void ustawPole(Pole*);
    virtual char OZNACZENIE;
    virtual int obrazenia();
    virtual double stratyZadanePrzezOddzial(Oddzial*);
    virtual double zwrocMorale();
    virtual int zwrocliczebnosc();
    virtual void wyzerujStraty();
    virtual void usun();
    virtual void zmniejszMorale();
    virtual void przeliczStraty();/*zwraca prawde jezeli trzeba usunac oddzial bo liczba strat przewyzsza liczebnosc oddzialu*/
private:

    Pole* pole_;
    Wojsko* wojsko_;
    int silaAtaku_;
    int obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;
    double straty_;
    double morale_;
    int wspieraj_;


};

#endif //_ODDZIAL_H