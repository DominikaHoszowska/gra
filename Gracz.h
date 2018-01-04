/**
 * Project Untitled
 */


#ifndef _GRACZ_H
#define _GRACZ_H

#include "Wojsko.h"

class Gracz {
public:

    Gracz(int id_);
    virtual void atak();/*TODO*/
    virtual ~Gracz();
    virtual Wojsko* zwrocWojsko();
    virtual int zwrocId();
private:
    int id_;
    Wojsko* wojsko_;

};

#endif //_GRACZ_H