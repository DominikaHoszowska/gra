#ifndef _POLEPIERWSZEJLINII_H
#define _POLEPIERWSZEJLINII_H
#include "Pole.h"
#include "../Oddzial/Headers/Kusznik.h"

class PolePierwszejLinii: public Pole {
public:
    void atakuj() override;
};

#endif //_POLEPIERWSZEJLINII_H