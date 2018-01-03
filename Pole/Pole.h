#ifndef _POLE_H
#define _POLE_H
#include "../Oddzial/Headers/Oddzial.h"
class Pole {
private:
    Oddzial* oddzial_;
public: 
    
    virtual Oddzial* zwrocOddzial();
};

#endif //_POLE_H