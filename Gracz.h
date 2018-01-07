/**
 * Project Untitled
 */


#ifndef _GRACZ_H
#define _GRACZ_H

class Gracz;

#include "Wojsko.h"

class Gracz {
public:

    Gracz(unsigned int id_);
    void atak();/*TODO*/
    virtual ~Gracz();
    Wojsko* zwrocWojsko();
    unsigned int zwrocId();
private:
    unsigned int id_;
    Wojsko* wojsko_;

};

#endif //_GRACZ_H