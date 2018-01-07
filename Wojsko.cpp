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

}

Oddzial* Wojsko::znajdzPrzeciwnika(Oddzial* atakujacy, int zasieg)
{
    unsigned  int nrPrzeciwnika;
    if(this->zwrocGracza()->zwrocId()==0)
    {
        nrPrzeciwnika=1;
    }
    else
    {
        nrPrzeciwnika=0;
    }
    vector<Pole*> polePrzeciwnika=this->poleBitwy_->zwrocPolePrzeciwnika(nrPrzeciwnika);
    unsigned int nrKolumny=atakujacy->zwrocPole()->zwrocNrKolumny();
    if(polePrzeciwnika.at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return polePrzeciwnika.at(nrKolumny)->zwrocOddzial();
    }
    int odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(nrKolumny-odleglosc>=0&& polePrzeciwnika.at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnika.at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<this->zwrocPoleBitwy()->zwrocGre()->zwrocDlugoscLinii()&&
           polePrzeciwnika.at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnika.at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    return nullptr;
}
Oddzial* Wojsko::znajdzPrzeciwnika(Lucznik* atakujacy, int zasieg)
{
    unsigned  int nrPrzeciwnika;
    if(this->zwrocGracza()->zwrocId()==0)
    {
        nrPrzeciwnika=1;
    }
    else
    {
        nrPrzeciwnika=0;
    }
    vector<Pole*> polePrzeciwnikaDrugaLinia=this->poleBitwy_->zwrocPolePrzeciwnikaDrugaLinia(nrPrzeciwnika);
    unsigned int nrKolumny=atakujacy->zwrocPole()->zwrocNrKolumny();
    if(polePrzeciwnikaDrugaLinia.at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return polePrzeciwnikaDrugaLinia.at(nrKolumny)->zwrocOddzial();
    }
    int odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(nrKolumny-odleglosc>=0&& polePrzeciwnikaDrugaLinia.at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnikaDrugaLinia.at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<this->zwrocPoleBitwy()->zwrocGre()->zwrocDlugoscLinii()&&
           polePrzeciwnikaDrugaLinia.at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnikaDrugaLinia.at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    vector<Pole*> polePrzeciwnika=this->poleBitwy_->zwrocPolePrzeciwnika(nrPrzeciwnika);
    if(polePrzeciwnika.at(nrKolumny)->zwrocOddzial()!= nullptr)
    {
        return polePrzeciwnika.at(nrKolumny)->zwrocOddzial();
    }
    odleglosc=1;
    while(odleglosc<=zasieg)
    {
        if(nrKolumny-odleglosc>=0&& polePrzeciwnika.at(nrKolumny-odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnika.at(nrKolumny-odleglosc)->zwrocOddzial();
        }
        if(nrKolumny+odleglosc<this->zwrocPoleBitwy()->zwrocGre()->zwrocDlugoscLinii()&&
           polePrzeciwnika.at(nrKolumny+odleglosc)->zwrocOddzial()!= nullptr)
        {
            return polePrzeciwnika.at(nrKolumny+odleglosc)->zwrocOddzial();
        }
        odleglosc++;
    }
    return nullptr;
}







bool Wojsko::czyPuste() {
    return this->poleBitwy_->czyPuste(this->zwrocGracza()->zwrocId());
}




Gracz* Wojsko::zwrocGracza()
{
    return this->gracz_;
}
PoleBitwy* Wojsko::zwrocPoleBitwy()
{
    return this->poleBitwy_;
}
void Wojsko::przesuniecieWojsk()
{
    this->poleBitwy_->przesuniecieWojsk(this->zwrocGracza()->zwrocId());
}
