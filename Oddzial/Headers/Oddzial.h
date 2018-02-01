#ifndef _ODDZIAL_H
#define _ODDZIAL_H
class Oddzial;

#include "../../Pole/Pole.h"
#include "../../Wojsko.h"
#include "../../Pole/PoleDrugiejLinii.h"
#include "../../Pole/PolePierwszejLinii.h"


//#include "Tarczownik.h"
//#include "Bebniarz.h"

//#include "../../Pole/PolePosilkow.h"
//#include "../../Pole/PolePierwszejLinii.h"
//#include "../../Pole/PoleDrugiejLinii.h"

#include <list>
class Oddzial {

public:

    Oddzial();

    /*WSPARCIE*/
    virtual void wspieraj();/*TODO*/
    void dodajwsparcie(Oddzial*);

    virtual void wycofajwsparcie();/*TODO*/
    /*ATAK*/
    virtual void atakuj(PoleDrugiejLinii&)=0;
    virtual void atakuj(PolePierwszejLinii&)=0;
    virtual void zadajObrazenia(double);

    /*ZWRACANIE WARTOŚCI*/
    Pole* zwrocPole();
    virtual int zwrocZasieg();
    virtual int zwrocLiczebnoscPoczatkowa();
    virtual double zwrocMorale();
    virtual int zwrocliczebnosc();
    virtual Wojsko* zwrocWojsko();
    virtual double zwrocObrone();
    virtual double obrona();


    /*INNE*/
    virtual void ustawPole(Pole*);
    char OZNACZENIE;
    virtual void wyzerujStraty();
    virtual void usun();
    virtual void zmniejszMorale();
    virtual void przeliczStraty();
    void ustawWojsko(Wojsko*);
    virtual void wypisz();

    virtual ~Oddzial()= default;


private:

    Pole* pole_;
    Wojsko* wojsko_;
    double straty_;
    double morale_;
    std::list<Oddzial*> wsparcie_;

protected:
    int silaAtaku_;
    double obrona_;
    int wytrzymalosc_;
    int liczebnoscOddzialu_;
    int liczebnoscPoczatkowa;
    int zasieg_;
};

#endif //_ODDZIAL_H