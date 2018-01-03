#include "../Headers/Oddzial.h"
#include <iostream>
#include <stdexcept>

void Oddzial::atakuj() {
    throw std::runtime_error("TODO");

}
void Oddzial::atakuj(void PolePosilkow) {
    throw std::runtime_error("TODO");
}

void Oddzial::wspieraj(void PolePierwszejLinii) {
    throw std::runtime_error("TODO");
}

void Oddzial::wspieraj(void PoleDrugiejLinii) {
    throw std::runtime_error("TODO");
}


bool Oddzial::czyPusty() {
    throw std::runtime_error("TODO");
}


virtual void Oddzial::atakuj(void PoleDrugiejLinii)
{
    throw std::runtime_error("TODO");
}

virtual void Oddzial::atakuj(void PolePierwszejLinii) {
    throw std::runtime_error("TODO");
}


virtual void Oddzial::wspieraj(void PolePosilkow) {
    throw std::runtime_error("TODO");
}
Pole*Oddzial:: zwrocPole()
{
    return this->pole_;
}