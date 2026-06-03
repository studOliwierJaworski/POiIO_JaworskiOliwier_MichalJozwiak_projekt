#pragma once

#include "DashboardStats.h"
#include "RezerwacjaService.h"

using namespace System;
using namespace System::Collections::Generic;

namespace AplikacjaHotelowa {

    public ref class DashboardService
    {
    public:

        static DashboardStats^ PobierzStatystyki(DateTime data)
        {
            DashboardStats^ stats =
                gcnew DashboardStats();

            List<Rezerwacja^>^ lista =
                RezerwacjaService::PobierzWszystkie();

            int zajetePokoje = 0;

            for each (Rezerwacja ^ r in lista)
            {
                // zameldowania danego dnia
                if (r->DataOd.Date == data.Date)
                {
                    stats->liczbaZameldowan++;
                }

                // wymeldowania danego dnia
                if (r->DataDo.Date == data.Date)
                {
                    stats->liczbaWymeldowan++;
                }

                // aktywni goście
                if (data.Date >= r->DataOd.Date &&
                    data.Date <= r->DataDo.Date &&
                    r->StatusRezerwacji != "Wymeldowany")
                {
                    stats->liczbaGosci +=
                        r->IloscGosci;

                    zajetePokoje++;
                }
            }

            stats->liczbaWolnychPokoi =
                20 - zajetePokoje;

            return stats;
        }
    };
}