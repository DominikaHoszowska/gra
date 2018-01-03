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
bool sprawdzZnak(char znak)
{
    if(znak=='L'||znak=='k'||znak=='M'||znak=='H'||znak=='K'||znak=='B'||znak=='T')
    {
        return 1;
    }
    return 0;
}
int main() {

    int dlugoscLinii, liczbaTur;
    std::cout << "Wprowadz dlugosc linii" << std::endl;
    std::cin >> dlugoscLinii;

    while (!sprawdzDlugoscLinii(dlugoscLinii)) {
        std::cout << "Wprowadz dodatnia liczbe parzysta oznaczajaca dlugosc linii" << std::endl;
        std::cin >> dlugoscLinii;
    }
    std::cout << "Wprowadz maksymalna liczbe tur" << std::endl;
    std::cin >> liczbaTur;
    while (!sprawdzMaksymalnaLiczbeTur(liczbaTur)) {
        std::cout << "Wprowadz dodatnia liczbe oznaczajaca maksymalna liczbe tur" << std::endl;
        std::cin >> liczbaTur;
    }
    Gra gra(dlugoscLinii, liczbaTur);
    char tabPole[6][dlugoscLinii];
    char znak;
    std::cout<<"Wprowadz wojska";
    for (int nrWiersza = 0; nrWiersza< 6; nrWiersza++)
    {
        for(int nrKolumny=0;nrKolumny<dlugoscLinii;nrKolumny++)
        {
            std::cin>>znak;
            while(!sprawdzZnak(znak))
            {
                std::cout<<"Wprowadz poprawny znak";
                std::cin>>znak;
            }
            tabPole[nrWiersza][nrKolumny]=znak;
        }
    }

    while(!gra.czyKoniec())
    {
        gra.tura();
    }
    return 0;
}
