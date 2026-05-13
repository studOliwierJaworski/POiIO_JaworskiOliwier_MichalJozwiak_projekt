#pragma once

using namespace System;

namespace AplikacjaHotelowa {

    public ref class Rezerwacja
    {
    public:
        String^ Imie;
        String^ Nazwisko;
        int Pokoj;

        DateTime DataOd;
        DateTime DataDo;

        String^ StanCzystosci;
    };
}