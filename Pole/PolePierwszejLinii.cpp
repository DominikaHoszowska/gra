#include <stdexcept>
#include "PolePierwszejLinii.h"
#include "../Oddzial/Headers/Lucznik.h"
#include "../Oddzial/Headers/Kusznik.h"
#include "../Oddzial/Headers/Miecznik.h"
#include "../Oddzial/Headers/Halabardzista.h"
#include "../Oddzial/Headers/Konny.h"

void PolePierwszejLinii::atakuj()
{
    this->zwrocOddzial()->atakujZPierwszejLinii();
}
//double PolePierwszejLinii::zwrocObrone(Lucznik* lucznik)
//{
//    return lucznik->obrona()*0.5;
//}
//double PolePierwszejLinii::zwrocObrone(Kusznik * kusznik)
//{
//    return kusznik->obrona()*0.7;
//}