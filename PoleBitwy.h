#ifndef _POLEBITWY_H
#define _POLEBITWY_H


class PoleBitwy;

#include <vector>
#include <map>


//#include "Pole/PolePierwszejLinii.h"

#include "Gracz.h"

#include "Gra.h"

class PoleBitwy {
private:
    using wiersz_t = std::vector<Pole*>;
    using wojsko_t = std::vector<wiersz_t>;
    Gra* gra_;

    std::vector<wojsko_t> poleGry_;

public:

    PoleBitwy(unsigned int);
    PoleBitwy();

    virtual ~PoleBitwy();

    /*WSPARCIE*/

      void wsparcie();/*wywoluje funkcję wspieraj() dla kazdego oddzialu*/
      void wycofajWsparcie();

    /*ATAK*/
    void atak();/*wywoluje funkcje atakuj() dla kazdego oddzialu;


    /*KONSOLIDACJA*/

      void konsolidacjaPierwszyGraczzNrSzeregu(unsigned int);
      void konsolidacjaDrugiGraczzNrSzeregu(unsigned int);
      void konsolidacjaPierwszyGracz();
      void konsolidacjaDrugiGracz();
      void konsolidacjaSzeregow();
      void zamienTarczownik(unsigned int, unsigned int, unsigned int);

    /*PRZESUWANIE*/

      void przesuniecieWojsk(unsigned int);
      void przesunPierwszyGracz();
      void przesunOddzialy();/*Zleca przesuniecie oddzialow obydwu graczy*/
      void przesunDrugiGracz();

    /*USTAWIANIE GRY*/

    void ustaw(unsigned int,unsigned int,unsigned int,Oddzial*);
    void ustawGre(Gra*);


      virtual void wypisz();
      bool czyPuste(unsigned int);/*dostaje nr Gracza i sprawdza czy ma puste wojsko*/
      void aktualizujstan();
      void przeliczStraty();
      void zmniejszMorale(unsigned int,unsigned int);
      void zmniejszMoralePierwszyGracz(unsigned int);
      void zmniejszMoraleDrugiGracz(unsigned int);
      void usunOddzialyIZmniejszMorale();
      void usunOddzialyIZmniejszMoralePierwszyGracz();
      void usunOddzialyIZmniejszMoraleDrugiGracz();

    std::vector<std::vector<Pole*>> zwrocPoleBitwy(unsigned int);
    std::vector<Pole*> zwrocPolePrzeciwnika(unsigned int);/*zwraca pole pierwszej linii gracza*/
    std::vector<Pole*> zwrocPolePrzeciwnikaDrugaLinia(unsigned int);
      Gra* zwrocGre();

};

#endif //_POLEBITWY_H