#include "Wojsko.h"
#include "Oddzial/Headers/Oddzial.h"
#include <stdexcept>

void Wojsko::atak() {
    throw std::runtime_error("TODO");
}

Oddzial& Wojsko::kogoWspierac(void Oddzial&)
{
    throw std::runtime_error("TODO");
}

Oddzial& Wojsko::kogoAtakowac(void Oddzial&) {
    throw std::runtime_error("TODO");
}

void Wojsko::aktualizujStan() {
    throw std::runtime_error("TODO");
}

void Wojsko::konsolidacjaSzeregow() {
    throw std::runtime_error("TODO");
}

bool Wojsko::czyPuste() {
    throw std::runtime_error("TODO");
}

Gracz* Wojsko::zwrocGracza()
{
    return  this->gracz_;
}