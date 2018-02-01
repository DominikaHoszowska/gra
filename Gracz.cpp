#include "Gracz.h"
#include <iostream>
#include <stdexcept>

Gracz::~Gracz() {
    delete wojsko_;
}
Gracz::Gracz(unsigned int id_) : id_(id_) {
    wojsko_=new Wojsko();
    wojsko_->ustawGracza(this);
}

Wojsko* Gracz::zwrocWojsko()
{
    return this->wojsko_;
}
unsigned int Gracz:: zwrocId()
{
    return this->id_;
}