cmake_minimum_required(VERSION 3.8)
project(Model)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Oddzial/SRC/Bebniarz.cpp
        Oddzial/Headers/Bebniarz.h
        Gra.cpp
        Gra.h
        Gracz.cpp
        Gracz.h
        Oddzial/SRC/Halabardzista.cpp
        Oddzial/Headers/Halabardzista.h
        Interface1.h
        Oddzial/SRC/Konny.cpp
        Oddzial/Headers/Konny.h
        Oddzial/SRC/Kusznik.cpp
        Oddzial/Headers/Kusznik.h
        Oddzial/SRC/Lucznik.cpp
        Oddzial/Headers/Lucznik.h
        Oddzial/SRC/Miecznik.cpp
        Oddzial/Headers/Miecznik.h
        Oddzial/SRC/Oddzial.cpp
        Oddzial/Headers/Oddzial.h
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
        Oddzial/SRC/Tarczownik.cpp
        Oddzial/Headers/Tarczownik.h
        Wojsko.cpp
        Wojsko.h
        Oddzial/SRC/Wsparcie.cpp
        Oddzial/Headers/Wsparcie.h
        Oddzial/SRC/Zasiegowa.cpp
        Oddzial/Headers/Zasiegowa.h
        Oddzial/SRC/Zwarcie.cpp
        Oddzial/Headers/Zwarcie.h
        main.cpp)

add_executable(Model ${SOURCE_FILES})