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
                String^ sql = "CREATE TABLE IF NOT EXISTS Rezerwacje ("
                    "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "Imie TEXT, "
                    "Nazwisko TEXT, "
                    "Pokoj INTEGER, "
                    "DataOd TEXT, "
                    "DataDo TEXT);";

                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        static void Dodaj(Rezerwacja^ r) {

            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

            try {
                conn->Open();
                String^ sql = "INSERT INTO Rezerwacje (Imie, Nazwisko, Pokoj, DataOd, DataDo) "
                    "VALUES (@imie, @nazwisko, @pokoj, @od, @do)";

                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@imie", r->Imie);
                cmd->Parameters->AddWithValue("@nazwisko", r->Nazwisko);
                cmd->Parameters->AddWithValue("@pokoj", r->Pokoj);

                cmd->Parameters->AddWithValue("@od", r->DataOd.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@do", r->DataDo.ToString("yyyy-MM-dd"));

                cmd->ExecuteNonQuery();
            }
            finally {
                conn->Close();
            }
        }

        static List<Rezerwacja^>^ PobierzWszystkie() {

            List<Rezerwacja^>^ lista = gcnew List<Rezerwacja^>();
            SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);

                try {
                    conn->Open();
                    String^ sql = "SELECT Imie, Nazwisko, Pokoj, DataOd, DataDo FROM Rezerwacje";
                    SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                    SQLiteDataReader^ reader = cmd->ExecuteReader();

                    while (reader->Read()) {
                        Rezerwacja^ r = gcnew Rezerwacja();
                        r->Imie = reader["Imie"]->ToString();
                        r->Nazwisko = reader["Nazwisko"]->ToString();
                        r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                        r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                        r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                        lista->Add(r);
                    }
                }
                finally {
                    conn->Close();
                }
                return lista;
            }
    };
}