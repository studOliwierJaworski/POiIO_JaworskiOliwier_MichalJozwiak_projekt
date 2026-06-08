#pragma once

#include "Pobudka.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace AplikacjaHotelowa {

    public ref class PobudkaService
    {
    private:
        // Ścieżka do bazy danych
        static String^ connectionString =
            "Data Source=" +
            System::Windows::Forms::Application::StartupPath +
            "\\hotel.db;Version=3;";

    public:

        // Tworzenie tabeli Pobudki
        static void InitializeBase() {

            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();

                String^ sql =
                    "CREATE TABLE IF NOT EXISTS Pobudki ("
                    "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "Imie TEXT, "
                    "Nazwisko TEXT, "
                    "Pokoj INTEGER, "
                    "Data TEXT, "
                    "Godzina TEXT);";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // Dodawanie pobudki
        static void Dodaj(Pobudka^ p) {

            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();

                String^ sql =
                    "INSERT INTO Pobudki "
                    "(Imie, Nazwisko, Pokoj, Data, Godzina) "
                    "VALUES "
                    "(@imie, @nazwisko, @pokoj, @data, @godzina)";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue(
                    "@imie", p->Imie);

                cmd->Parameters->AddWithValue(
                    "@nazwisko", p->Nazwisko);

                cmd->Parameters->AddWithValue(
                    "@pokoj", p->Pokoj);

                cmd->Parameters->AddWithValue(
                    "@data",
                    p->Data.ToString("yyyy-MM-dd"));

                cmd->Parameters->AddWithValue(
                    "@godzina",
                    p->Godzina);

                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        // Pobieranie wszystkich pobudek
        static List<Pobudka^>^ PobierzWszystkie() {

            List<Pobudka^>^ lista =
                gcnew List<Pobudka^>();

            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();

                String^ sql =
                    "SELECT Imie, Nazwisko, Pokoj, Data, Godzina "
                    "FROM Pobudki";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                SQLiteDataReader^ reader =
                    cmd->ExecuteReader();

                while (reader->Read()) {

                    Pobudka^ p = gcnew Pobudka();

                    p->Imie =
                        reader["Imie"]->ToString();

                    p->Nazwisko =
                        reader["Nazwisko"]->ToString();

                    p->Pokoj =
                        Convert::ToInt32(reader["Pokoj"]);

                    p->Data =
                        DateTime::Parse(
                            reader["Data"]->ToString());

                    p->Godzina =
                        reader["Godzina"]->ToString();

                    lista->Add(p);
                }
            }
            finally {
                conn->Close();
            }

            return lista;
        }
        // Usuwanie pobudki
        static bool Usun(
            String^ imie,
            String^ nazwisko,
            int pokoj,
            DateTime data)
        {
            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try
            {
                conn->Open();

                String^ sql =
                    "DELETE FROM Pobudki "
                    "WHERE Imie=@imie "
                    "AND Nazwisko=@nazwisko "
                    "AND Pokoj=@pokoj " 
                    "AND Data=@data ";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue(
                    "@imie", imie);

                cmd->Parameters->AddWithValue(
                    "@nazwisko", nazwisko);

                cmd->Parameters->AddWithValue(
                    "@pokoj", pokoj);

                cmd->Parameters->AddWithValue(
                    "@data",
                    data.ToString("yyyy-MM-dd"));

                int usuniete =
                    cmd->ExecuteNonQuery();

                return usuniete > 0;
            }
            finally
            {
                conn->Close();
            }
        }
        static void UsunWszystkieDlaPokoju(
            int pokoj)
        {
            SQLiteConnection^ conn =
                gcnew SQLiteConnection(connectionString);

            try
            {
                conn->Open();

                String^ sql =
                    "DELETE FROM Pobudki "
                    "WHERE Pokoj=@pokoj";

                SQLiteCommand^ cmd =
                    gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue(
                    "@pokoj", pokoj);

                cmd->ExecuteNonQuery();
            }
            finally
            {
                conn->Close();
            }
        }
    };
}