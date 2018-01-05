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


    virtual void wspieraj(PolePierwszejLinii);/*TODO*/
    virtual void wspieraj(PoleDrugiejLinii);/*TODO*/
    virtual void wspieraj(PolePosilkow);/*TODO*/
    virtual void wspieraj();/*TODO*/
    virtual void atakuj(PoleDrugiejLinii);/*TODO*/
    virtual void atakuj(PolePierwszejLinii);/*TODO*/
    virtual void atakuj();/*TODO*/
    virtual void atakuj(PolePosilkow);/*TODO*/

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
    virtual void przeliczStraty();
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