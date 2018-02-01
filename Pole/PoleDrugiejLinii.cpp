#include "PoleDrugiejLinii.h"
#include "../Oddzial/Headers/Lucznik.h"
#include "../Oddzial/Headers/Kusznik.h"
#include "../Oddzial/Headers/Miecznik.h"
#include "../Oddzial/Headers/Halabardzista.h"
#include "../Oddzial/Headers/Konny.h"

void PoleDrugiejLinii::atakuj() {
this->zwrocOddzial()->atakuj(*this);
}
