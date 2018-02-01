#ifndef _POLEPOSILKOW_H
#define _POLEPOSILKOW_H
class PolePosilkow;
#include "Pole.h"


class PolePosilkow: public Pole {
public:
    void atakuj() override=0;
};

#endif //_POLEPOSILKOW_H