#ifndef _POLEBITWY_H
#define _POLEBITWY_H
#include <vector>
#include <map>
#include "Pole/PolePierwszejLinii.h"
#include "Gracz.h"

using namespace std;

class PoleBitwy {
public: 

    PoleBitwy(int dlugoscLinii);
    vector<PolePierwszejLinii*> znajdzPolePrzeciwnika(const Gracz& );
    <vector<Pole*>> znajdzMojePole(const Gracz&);
    virtual void ustaw(int nrGracza,int nrWiersza,int nrKolumny,Oddzial* oddzial);
private:

    vector<vector<vector<Pole*>>> poleGry_;

};

#endif //_POLEBITWY_H