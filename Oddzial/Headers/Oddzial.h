#ifndef _ODDZIAL_H
#define _ODDZIAL_H
#include "../../Pole/PolePosilkow.h"
#include "../../Pole/PolePierwszejLinii.h"
#include "../../Pole/PoleDrugiejLinii.h"
#include "../../Pole/Pole.h"
#include "../../Wojsko.h"
#include "Tarczownik.h"
#include "Bebniarz.h"

#include <list>
class Oddzial {

public:

    Oddzial();

    /*WSPARCIE*/
    virtual void wspieraj();/*TODO*/
    void dodajwsparcie(Oddzial*);

    virtual void wycofajwsparcie();/*TODO*/
    /*ATAK*/
    virtual void atakujZPierwszejLinii();/*TODO*/
    virtual void atakujZDrugiejLinii();/*TODO*/

    /*ZWRACANIE WARTOŚCI*/
    virtual Pole* zwrocPole();
    virtual int zwrocZasieg();
    virtual int zwrocLiczebnoscPoczatkowa();
    virtual double zwrocMorale();
    virtual int zwrocliczebnosc();
    virtual Wojsko* zwrocWojsko();


    /*INNE*/
    virtual void ustawPole(Pole*);
    virtual char OZNACZENIE;
    virtual int obrazenia();
    virtual double stratyZadanePrzezOddzial(Oddzial*);
    virtual void wyzerujStraty();
    virtual void usun();
    virtual void zmniejszMorale();
    virtual void przeliczStraty();


private:

    Pole* pole_;
    Wojsko* wojsko_;

    double straty_;
    double morale_;
    list<Oddzial*> wsparcie_;

protected:
    int silaAtaku_;
    double obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;
};

#endif //_ODDZIAL_H