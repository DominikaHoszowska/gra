//
// Created by Dominika on 02.01.2018.
//
#include <iostream>
#include <vector>
#include "Gra.h"
#include "Oddzial/Headers/Lucznik.h"
#include "Oddzial/Headers/Kusznik.h"
#include "Oddzial/Headers/Miecznik.h"
#include "Oddzial/Headers/Halabardzista.h"
#include "Oddzial/Headers/Konny.h"
#include "Oddzial/Headers/Bebniarz.h"
#include "Oddzial/Headers/Tarczownik.h"

bool sprawdzDlugoscLinii(unsigned int dlugoscLinii)
{
    if(dlugoscLinii>0 && dlugoscLinii%2==0)
    {
        return true;
    }
    return false;
}
bool sprawdzMaksymalnaLiczbeTur(int liczbaTur)
{
    if(liczbaTur>0)
    {
        return true;
    }
    return false;
}
bool sprawdzZnak(char znak)
{

    if(znak==Lucznik::OZNACZENIE
       ||znak==Kusznik::OZNACZENIE
       ||znak==Miecznik::OZNACZENIE
       ||znak==Halabardzista::OZNACZENIE
       ||znak==Konny::OZNACZENIE
       ||znak==Bebniarz::OZNACZENIE
       ||znak==Tarczownik::OZNACZENIE
       ||znak=='X')
        return true;

    return false;
}
int main() {

    int dlugoscLinii=2;
    int liczbaTur=2;

//    std::cout << "Wprowadz dlugosc linii" << std::endl;
//    std::cin >> dlugoscLinii;
//
//    while (!sprawdzDlugoscLinii(dlugoscLinii))
//    {
//        std::cout << "Wprowadz dodatnia liczbe parzysta oznaczajaca dlugosc linii" << std::endl;
//        std::cin >> dlugoscLinii;
//    }
//    std::cout << "Wprowadz maksymalna liczbe tur" << std::endl;
//    std::cin >> liczbaTur;
//    while (!sprawdzMaksymalnaLiczbeTur(liczbaTur))
//    {
//        std::cout << "Wprowadz dodatnia liczbe oznaczajaca maksymalna liczbe tur" << std::endl;
//        std::cin >> liczbaTur;
//    }

    Gra gra(dlugoscLinii, liczbaTur);
    /*Wczytanie wojsk*/
    std::vector<std::vector<char> > tabPole /*(6)*/ = {{'K', 'B'},{'T', 'k'},{'K', 'L'},{'L', 'K'},{'K', 'K'},{'K', 'K'}};
//    char znak;
//    std::cout<<"Wprowadz wojska";
//    for (int nrWiersza = 0; nrWiersza< 6; nrWiersza++) {
//        for (int nrKolumny = 0; nrKolumny < dlugoscLinii; nrKolumny++) {
//            std::cin >> znak;
//            while (!sprawdzZnak(znak)) {
//                std::cout <<"Wprowadz poprawny znak";
//                std::cin >> znak;
//            }
//            tabPole.at(nrWiersza).push_back(znak);
//        }
//    }
    gra.inicjalizuj(tabPole);
    gra.wypisz();
//    while(!gra.czyKoniec())
//    {
//        gra.rozegrajTure();
//    }
    return 0;
}
