#include <stdexcept>
#include "Pole.h"

Oddzial* Pole::zwrocOddzial() {
    return this->oddzial_;
}
void Pole::ustaw(Oddzial* oddzial)
{
    this->oddzial_=oddzial;
    oddzial->ustawPole(this);
}
