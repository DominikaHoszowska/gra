#include "Wojsko.h"
#include "Oddzial/Headers/Oddzial.h"
#include <stdexcept>

void Wojsko::atak() {
    throw std::runtime_error("TODO");
}

Oddzial& Wojsko::kogoWspierac(Oddzial* oddzial)
{
}
Oddzial& Wojsko::kogoAtakowac(Oddzial* oddzial) {

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
