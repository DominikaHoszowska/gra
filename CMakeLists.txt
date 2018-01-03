cmake_minimum_required(VERSION 3.8)
project(Model)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Bebniarz.cpp
        Bebniarz.h
        Gra.cpp
        Gra.h
        Gracz.cpp
        Gracz.h
        Halabardzista.cpp
        Halabardzista.h
        Interface1.h
        Jednostka.cpp
        Jednostka.h
        Konny.cpp
        Konny.h
        Kusznik.cpp
        Kusznik.h
        Lucznik.cpp
        Lucznik.h
        Miecznik.cpp
        Miecznik.h
        Oddzial.cpp
        Oddzial.h
        Pole.cpp
        Pole.h
        PoleBitwy.cpp
        PoleBitwy.h
        PoleDrugiejLinii.cpp
        PoleDrugiejLinii.h
        PolePierwszejLinii.cpp
        PolePierwszejLinii.h
        PolePosilkow.cpp
        PolePosilkow.h
        Tarczownik.cpp
        Tarczownik.h
        Wojsko.cpp
        Wojsko.h
        Wsparcie.cpp
        Wsparcie.h
        Zasiegowa.cpp
        Zasiegowa.h
        Zwarcie.cpp
        Zwarcie.h
        main.cpp)

add_executable(Model ${SOURCE_FILES})