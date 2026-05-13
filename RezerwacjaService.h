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
                    "DataDo TEXT, "
                    "StanCzystosci TEXT);";

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
                String^ sql = "INSERT INTO Rezerwacje (Imie, Nazwisko, Pokoj, DataOd, DataDo, StanCzystosci) "
                    "VALUES (@imie, @nazwisko, @pokoj, @od, @do, @status)";

                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@imie", r->Imie);
                cmd->Parameters->AddWithValue("@nazwisko", r->Nazwisko);
                cmd->Parameters->AddWithValue("@pokoj", r->Pokoj);

                cmd->Parameters->AddWithValue("@od", r->DataOd.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@do", r->DataDo.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@status", r->StanCzystosci);
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
                String^ sql = "SELECT Imie, Nazwisko, Pokoj, DataOd, DataDo, StanCzystosci FROM Rezerwacje";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
                SQLiteDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    Rezerwacja^ r = gcnew Rezerwacja();
                    r->Imie = reader["Imie"]->ToString();
                    r->Nazwisko = reader["Nazwisko"]->ToString();
                    r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                    r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                    r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                    r->StanCzystosci = reader["StanCzystosci"]->ToString();
                    lista->Add(r);
                }
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
                // Pobieramy rezerwacje, które kończą się (wymeldowanie) wybranego dnia
                String^ sql = "SELECT Imie, Nazwisko, Pokoj, DataOd, DataDo, StanCzystosci FROM Rezerwacje WHERE DataDo = @data";
                SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);

                cmd->Parameters->AddWithValue("@data", data.ToString("yyyy-MM-dd"));
                SQLiteDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    Rezerwacja^ r = gcnew Rezerwacja();
                    r->Imie = reader["Imie"]->ToString();
                    r->Nazwisko = reader["Nazwisko"]->ToString();
                    r->Pokoj = Convert::ToInt32(reader["Pokoj"]);
                    r->DataOd = DateTime::Parse(reader["DataOd"]->ToString());
                    r->DataDo = DateTime::Parse(reader["DataDo"]->ToString());
                    r->StanCzystosci = reader["StanCzystosci"]->ToString();
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