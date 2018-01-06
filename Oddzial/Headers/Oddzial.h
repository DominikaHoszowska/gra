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
    virtual void wycofajwsparcie(Tarczownik*);/*TODO*/
    virtual void wycofajwsparcie(Bebniarz*);/*TODO*/

    /*ATAK*/

    virtual void atakuj(PoleDrugiejLinii);/*TODO*/
    virtual void atakuj(PolePierwszejLinii);/*TODO*/
    virtual void atakuj();/*TODO*/
    virtual void atakuj(PolePosilkow);/*TODO*/

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
    int silaAtaku_;
    int obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;
    double straty_;
    double morale_;
    int wspieraj_;
    list<Oddzial*> wsparcie_;

};

#endif //_ODDZIAL_H