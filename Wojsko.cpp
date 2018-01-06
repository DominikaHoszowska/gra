#include "Wojsko.h"
#include "Oddzial/Headers/Oddzial.h"
#include <stdexcept>
/*WSPARCIE*/
void Wojsko::kogoWspierac(Pole* pole) {
    if (this->gracz_->zwrocId()) {
        kogoWspieracDrugiGracz(pole);
    } else {
        kogoWspieracPierwszyGracz(pole);
    }
}
void Wojsko::kogoWspieracPierwszyGracz(Pole *pole) {
    vector<vector<Pole *>> mojePoleBitwy = this->poleBitwy_->zwrocPoleBitwy(this->zwrocGracza()->zwrocId());
    if (pole->zwrocNrWiersza() != 2) {
        mojePoleBitwy.at(2).at(pole->zwrocNrKolumny())->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;
    }
    if (pole->zwrocNrKolumny() != 0&&mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial() != nullptr)
    {
        mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial() != nullptr)
            mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
            return;

    }

    if (mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() + 1)->zwrocOddzial() != nullptr &&
        pole->zwrocNrKolumny() != this->zwrocPoleBitwy()->zwrocGre()->zwrocDlugoscLinii() - 1)
    {
        mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() + 1)->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;

    }
        pole->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;

    }
void Wojsko::kogoWspieracDrugiGracz(Pole *pole)
{
    vector<vector<Pole *>> mojePoleBitwy = this->poleBitwy_->zwrocPoleBitwy(this->zwrocGracza()->zwrocId());
    if (pole->zwrocNrWiersza() != 0) {
        mojePoleBitwy.at(0).at(pole->zwrocNrKolumny())->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;
    }
    if (pole->zwrocNrKolumny() != 0&&mojePoleBitwy.at(0).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial() != nullptr)
    {
        mojePoleBitwy.at(0).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial() != nullptr)
        mojePoleBitwy.at(0).at(pole->zwrocNrKolumny() - 1)->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;

    }

    if (mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() + 1)->zwrocOddzial() != nullptr &&
        pole->zwrocNrKolumny() != this->zwrocPoleBitwy()->zwrocGre()->zwrocDlugoscLinii() - 1)
    {
        mojePoleBitwy.at(2).at(pole->zwrocNrKolumny() + 1)->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
        return;
    }
    pole->zwrocOddzial()->dodajwsparcie(pole->zwrocOddzial());
    return;

}

void Wojsko::atak() {
    throw std::runtime_error("TODO");
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
