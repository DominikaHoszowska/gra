cmake_minimum_required(VERSION 3.8)
project(Model)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Oddzial/Bebniarz.cpp
        Oddzial/Bebniarz.h
        Gra.cpp
        Gra.h
        Gracz.cpp
        Gracz.h
        Oddzial/Halabardzista.cpp
        Oddzial/Halabardzista.h
        Interface1.h
        Oddzial/Konny.cpp
        Oddzial/Konny.h
        Oddzial/Kusznik.cpp
        Oddzial/Kusznik.h
        Oddzial/Lucznik.cpp
        Oddzial/Lucznik.h
        Oddzial/Miecznik.cpp
        Oddzial/Miecznik.h
        Oddzial/Oddzial.cpp
        Oddzial/Oddzial.h
        Pole/Pole.cpp
        Pole/Pole.h
        PoleBitwy.cpp
        PoleBitwy.h
        Pole/PoleDrugiejLinii.cpp
        Pole/PoleDrugiejLinii.h
        Pole/PolePierwszejLinii.cpp
        Pole/PolePierwszejLinii.h
        Pole/PolePosilkow.cpp
        Pole/PolePosilkow.h
        Oddzial/Tarczownik.cpp
        Oddzial/Tarczownik.h
        Wojsko.cpp
        Wojsko.h
        Oddzial/Wsparcie.cpp
        Oddzial/Wsparcie.h
        Oddzial/Zasiegowa.cpp
        Oddzial/Zasiegowa.h
        Oddzial/Zwarcie.cpp
        Oddzial/Zwarcie.h
        main.cpp)

add_executable(Model ${SOURCE_FILES})