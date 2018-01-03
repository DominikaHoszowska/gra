#include <stdexcept>
#include "PoleBitwy.h"
#include "PoleDrugiejLinii.h"
#include "PolePosilkow.h"
vector<PolePierwszejLinii> PoleBitwy::znajdzPolePrzeciwnika(void Gracz) {
    throw std::runtime_error("TODO");
}

vector<vector<Pole*>> PoleBitwy::znajdzMojePole(const Gracz&) {
    throw std::runtime_error("TODO");
}

PoleBitwy::PoleBitwy(int dlugoscLinii):poleGry_(2) {


    for (int i = 0; i < dlugoscLinii; ++i){
        poleGry_.at(0).at(0).push_back(new PolePierwszejLinii());
        poleGry_.at(0).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(0).at(2).push_back(new PolePosilkow());
        poleGry_.at(1).at(0).push_back(new PolePierwszejLinii());
        poleGry_.at(1).at(1).push_back(new PoleDrugiejLinii());
        poleGry_.at(1).at(2).push_back(new PolePosilkow());
    }

}
