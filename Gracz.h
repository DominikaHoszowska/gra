/**
 * Project Untitled
 */


#ifndef _GRACZ_H
#define _GRACZ_H

#include "Wojsko.h"

class Gracz {
public:

    Gracz(int id_);

    void atak();

    virtual ~Gracz();

private:
    int id_;
    Wojsko* wojsko;

};

#endif //_GRACZ_H