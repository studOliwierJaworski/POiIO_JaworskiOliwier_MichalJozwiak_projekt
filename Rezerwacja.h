#pragma once

using namespace System;

namespace AplikacjaHotelowa {

    public ref class Rezerwacja
    {
    public:
        int Id;
        String^ Imie;
        String^ Nazwisko;
        int Pokoj;
        int IloscGosci;

        DateTime DataOd;
        DateTime DataDo;

        String^ StanCzystosci;

        // szczegóły już po wejściu w rezerwację
        String^ TypDokumentu;
        String^ NrDokumentu;

        // na razie prosta obsługa na zasadzie wyświetlania jaka ma być płatność
        String^ MetodaPlatnosci;
        double Kwota;

        String^ StatusRezerwacji;   // oczekujący, zameldowany, wymeldowany
    };
}