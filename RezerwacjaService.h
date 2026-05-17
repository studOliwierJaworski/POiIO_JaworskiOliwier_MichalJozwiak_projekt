#pragma once
#include "Rezerwacja.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace AplikacjaHotelowa {

    public ref class RezerwacjaService
    {
    private:
        // Ścieżka do pliku bazy danych (powstanie w folderze z plikiem .exe)
        static String^ connectionString = "Data Source=" + System::Windows::Forms::Application::StartupPath + "\\hotel.db;Version=3;";


    public:
        static void InitializeBase() {  // sprawdzamy czy baza już istnieje, jak nie to tworzymy

            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
            try {
                conn->Open();
                // Tworzymy podstawową tabelę
                String^ sql = "CREATE TABLE IF NOT EXISTS Rezerwacje ("
                    "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "Imie TEXT, "
                    "Nazwisko TEXT, "
                    "Pokoj INTEGER, "
                    "DataOd TEXT, "
                    "DataDo TEXT, "
                    "StanCzystosci TEXT);";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                cmd->ExecuteNonQuery();

                // aktualizujemy
                array<String^>^ noweKolumny = {
                    "ALTER TABLE Rezerwacje ADD COLUMN TypDokumentu TEXT;",
                    "ALTER TABLE Rezerwacje ADD COLUMN NrDokumentu TEXT;",
                    "ALTER TABLE Rezerwacje ADD COLUMN MetodaPlatnosci TEXT;",
                    "ALTER TABLE Rezerwacje ADD COLUMN Kwota REAL;",
                    "ALTER TABLE Rezerwacje ADD COLUMN StatusRezerwacji TEXT;"
                    "ALTER TABLE Rezerwacje ADD COLUMN IloscGosci INTEGER;"
                };

                for each (String ^ alterSql in noweKolumny) {
                    try {
                        SQLiteCommand^ cmdAlter = gcnew SQLiteCommand(alterSql, conn);
                        cmdAlter->ExecuteNonQuery();
                    }
                    catch (...) {
                        // Ignorujemy błędy, jeśli kolumny już istnieją w bazie
                    }
                }
            }
            finally {
                conn->Close();
            }
        }

        static void Dodaj(Rezerwacja^ r) {

            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();
                String^ sql = "INSERT INTO Rezerwacje (Imie, Nazwisko, Pokoj, DataOd, DataDo, StanCzystosci, StatusRezerwacji, Kwota, IloscGosci)"
                    "VALUES (@imie, @nazwisko, @pokoj, @od, @do, @statusC, @statusR, @kwota, @ilosc)";

                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@imie", r->Imie);
                cmd->Parameters->AddWithValue("@nazwisko", r->Nazwisko);
                cmd->Parameters->AddWithValue("@pokoj", r->Pokoj);
                cmd->Parameters->AddWithValue("@od", r->DataOd.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@do", r->DataDo.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@statusC", r->StanCzystosci);
                cmd->Parameters->AddWithValue("@statusR", "Oczekujaca"); // Domyślny status
                cmd->Parameters->AddWithValue("@kwota", 0.0);
                cmd->Parameters->AddWithValue("@ilosc", 1);
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }
        //  walidacja konfliktu rezerwacji.
        static bool CzyPokojDostepny(
            int pokoj,
            DateTime dataOd,
            DateTime dataDo)
        {
            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try
            {
                conn->Open();

                String^ sql =
                    "SELECT COUNT(*) FROM Rezerwacje "
                    "WHERE Pokoj = @pokoj "
                    "AND ("
                    "(@od BETWEEN DataOd AND DataDo) OR "
                    "(@do BETWEEN DataOd AND DataDo) OR "
                    "(DataOd BETWEEN @od AND @do)"
                    ")";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@pokoj", pokoj);

                cmd->Parameters->AddWithValue(
                    "@od",
                    dataOd.ToString("yyyy-MM-dd"));

                cmd->Parameters->AddWithValue(
                    "@do",
                    dataDo.ToString("yyyy-MM-dd"));

                int count = Convert::ToInt32(
                    cmd->ExecuteScalar());

                return count == 0;
            }
            finally
            {
                conn->Close();
            }
        }
        static List<Rezerwacja^>^ PobierzWszystkie() {
         
            List<Rezerwacja^>^ lista = gcnew List<Rezerwacja^>();
            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();
                String^ sql = "SELECT * FROM Rezerwacje";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                SQLiteDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    Rezerwacja^ r = gcnew Rezerwacja();
                    r->Id = Convert::ToInt32(reader["Id"]);
                    r->Imie = reader["Imie"]->ToString();
                    r->Nazwisko = reader["Nazwisko"]->ToString();
                    r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                    r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                    r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                    r->StanCzystosci = reader["StanCzystosci"]->ToString();

                    
                    r->StatusRezerwacji = reader["StatusRezerwacji"]->ToString();
                    r->TypDokumentu = reader["TypDokumentu"]->ToString();
                    r->NrDokumentu = reader["NrDokumentu"]->ToString();
                    r->MetodaPlatnosci = reader["MetodaPlatnosci"]->ToString();
                    r->Kwota = Convert::ToDouble(reader["Kwota"]);
                    if (reader["IloscGosci"]->ToString() != "") // jak puste to przypisujemy 1
                    {
                        r->IloscGosci = Convert::ToInt32(reader["IloscGosci"]);
                    }
                    else
                    {
                        r->IloscGosci = 1;
                    }
                    lista->Add(r);
                }
                reader->Close();
            }
            finally {
                conn->Close();
            }
            return lista;
        }

        static List<Rezerwacja^>^ PobierzWymeldowaniaNaDzien(DateTime data) {
            List<Rezerwacja^>^ lista = gcnew List<Rezerwacja^>();
            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();
                // Pobieramy rezerwacje które kończą się wybranego dnia
                String^ sql = "SELECT * FROM Rezerwacje WHERE DataDo = @data";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@data", data.ToString("yyyy-MM-dd"));
                SQLiteDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    Rezerwacja^ r = gcnew Rezerwacja();
                    r->Id = Convert::ToInt32(reader["Id"]);
                    r->Imie = reader["Imie"]->ToString();
                    r->Nazwisko = reader["Nazwisko"]->ToString();
                    r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                    r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                    r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                    r->StanCzystosci = reader["StanCzystosci"]->ToString();

                    r->StatusRezerwacji = reader["StatusRezerwacji"]->ToString();
                    r->TypDokumentu = reader["TypDokumentu"]->ToString();
                    r->NrDokumentu = reader["NrDokumentu"]->ToString();
                    r->MetodaPlatnosci = reader["MetodaPlatnosci"]->ToString();
                    r->Kwota = Convert::ToDouble(reader["Kwota"]);
                    if (reader["IloscGosci"]->ToString() != "") // jak puste to przypisujemy 1
                    {
                        r->IloscGosci = Convert::ToInt32(reader["IloscGosci"]);
                    }
                    else
                    {
                        r->IloscGosci = 1;
                    }

                    lista->Add(r);
                }
                reader->Close();
            }
            finally {
                conn->Close();
            }
            return lista;
        }
    
        static void Aktualizuj(Rezerwacja^ r) {
            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
            try {
                conn->Open();
                String^ sql = "UPDATE Rezerwacje SET "
                    "TypDokumentu = @typ, NrDokumentu = @nr, "
                    "MetodaPlatnosci = @platnosc, Kwota = @kwota, "
                    "StatusRezerwacji = @status, IloscGosci = @ilosc "
                    "WHERE Id = @id";

                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                cmd->Parameters->AddWithValue("@typ", r->TypDokumentu != nullptr ? r->TypDokumentu : "");
                cmd->Parameters->AddWithValue("@nr", r->NrDokumentu != nullptr ? r->NrDokumentu : "");
                cmd->Parameters->AddWithValue("@platnosc", r->MetodaPlatnosci != nullptr ? r->MetodaPlatnosci : "");
                cmd->Parameters->AddWithValue("@kwota", r->Kwota);
                cmd->Parameters->AddWithValue("@status", r->StatusRezerwacji);
                cmd->Parameters->AddWithValue("@id", r->Id);
                cmd->Parameters->AddWithValue("@ilosc", r->IloscGosci);

                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        static Rezerwacja^ PobierzPoId(int id) {
            Rezerwacja^ r = nullptr;
            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();
                String^ sql = "SELECT * FROM Rezerwacje WHERE Id = @id";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                cmd->Parameters->AddWithValue("@id", id);
                SQLiteDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    r = gcnew Rezerwacja();
                    r->Id = Convert::ToInt32(reader["Id"]);
                    r->Imie = reader["Imie"]->ToString();
                    r->Nazwisko = reader["Nazwisko"]->ToString();
                    r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                    r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                    r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                    r->StatusRezerwacji = reader["StatusRezerwacji"]->ToString();
                    r->TypDokumentu = reader["TypDokumentu"]->ToString();
                    r->NrDokumentu = reader["NrDokumentu"]->ToString();
                    r->MetodaPlatnosci = reader["MetodaPlatnosci"]->ToString();
                    r->Kwota = Convert::ToDouble(reader["Kwota"]);
                    if (reader["IloscGosci"]->ToString() != "") // jak puste to 1
                    {
                        r->IloscGosci = Convert::ToInt32(reader["IloscGosci"]);
                    }
                    else
                    {
                        r->IloscGosci = 1;
                    }
                }
                reader->Close();
            }
            finally {
                conn->Close();
            }
            return r; // Zwracamy jednego konkretnego gościa
        }
    };
}