#pragma once
#include "Rezerwacja.h"

using namespace System::Collections::Generic;

namespace AplikacjaHotelowa {

    public ref class RezerwacjaService
    {
    private:
        static List<Rezerwacja^>^ lista = gcnew List<Rezerwacja^>();

    public:
        static void Dodaj(Rezerwacja^ r)
        {
            lista->Add(r);
        }

        static List<Rezerwacja^>^ Pobierz()
        {
            return lista;
        }
    };
}