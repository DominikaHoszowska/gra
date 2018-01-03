/**
 * Project Untitled
 */


#ifndef _POLEBITWY_H
#define _POLEBITWY_H


#include <vector>
#include <map>
#include "PolePierwszejLinii.h"
#include "Gracz.h"

using namespace std;

class PoleBitwy {
public: 

    PoleBitwy(int dlugoscLinii);

    /**
     * @param Gracz
     */
    vector<PolePierwszejLinii*> znajdzPolePrzeciwnika(const Gracz& );
    
    /**
     * @param Gracz
     */
    vector<vector<Pole*>> znajdzMojePole(const Gracz&);

private:

    vector<vector<vector<Pole*>>> poleGry_;

};

#endif //_POLEBITWY_H