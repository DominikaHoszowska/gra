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
    return this->poleBitwy_->czyPuste(this->zwrocGracza()->zwrocId());
}

Gracz* Wojsko::zwrocGracza()
{
    return this->gracz_;
}
void Wojsko::przesuniecieWojsk()
{
    this->poleBitwy_->przesuniecieWojsk(this->zwrocGracza()->zwrocId());
}