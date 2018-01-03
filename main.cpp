//
// Created by Dominika on 02.01.2018.
//
#include <iostream>
#include "Gra.h"

bool sprawdzDlugoscLinii(int dlugoscLinii)
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

int main(){

    int dlugoscLinii, liczbaTur;
    std::cout<<"Wprowadz dlugosc linii"<<std::endl;
    std::cin>>dlugoscLinii;

    while(!sprawdzDlugoscLinii(dlugoscLinii))
    {
        std::cout<<"Wprowadz dodatnia liczbe parzysta oznaczajaca dlugosc linii"<<std::endl;
        std::cin>>dlugoscLinii;
    }
    std::cout<<"Wprowadz maksymalna liczbe tur"<<std::endl;
    std::cin>>liczbaTur;
    while(!sprawdzMaksymalnaLiczbeTur(liczbaTur))
    {
        std::cout<<"Wprowadz dodatnia liczbe oznaczajaca maksymalna liczbe tur"<<std::endl;
        std::cin>>liczbaTur;
    }
    Gra gra(dlugoscLinii,liczbaTur);
    bool zainicjalizowano;
    do {
        zainicjalizowano = true;



        try {
            gra.inicjalizuj();
        }
        catch (std::invalid_argument e) {
            std::cerr << e.what() << std::endl;
            zainicjalizowano = false;
        }
    }while(!zainicjalizowano);

    while(!gra.czyKoniec())
    {
        gra.tura();
    }
    return 0;
}
