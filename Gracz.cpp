#include "Gracz.h"
#include <iostream>
#include <stdexcept>

void Gracz::atak() {
    throw std::runtime_error("TODO");
}

Gracz::~Gracz() {
    delete wojsko_;
}
Gracz::Gracz(int id_) : id_(id_) {}

Wojsko* Gracz::zwrocWojsko()
{
    return this->wojsko_;
}
int Gracz:: zwrocId()
{
    return this->id_;
}