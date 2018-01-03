#include "Gracz.h"
#include <iostream>
#include <stdexcept>

void Gracz::atak() {
    throw std::runtime_error("TODO");
}

Gracz::~Gracz() {
    delete wojsko;
}

Gracz::Gracz(int id_) : id_(id_) {}
