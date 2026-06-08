# System Zarządzania Hotelem

Desktopowa aplikacja okienkowa (Windows Forms) stworzona w języku C++/CLI, służąca do zarządzania rezerwacjami, gośćmi oraz stanem pokoi w obiekcie hotelowym. 

Projekt wykorzystuje lokalną bazę danych **SQLite**, która konfiguruje i tworzy się w pełni automatycznie przy pierwszym uruchomieniu programu.

## Główne funkcjonalności aplikacji

* **Zarządzanie Rezerwacjami:** Rejestrowanie nowych gości z określeniem daty pobytu.
  * System automatycznie filtruje dostępność i przydziela losowy, wolny pokój na podstawie wybranego standardu (DBLQ, DBLT, SGL, 3PPL, 4PPL)
  * Możliwość usuwania rezerwacji z bazy
* **Obsługa Recepcji (Zameldowania / Wymeldowania):**
  * Uzupełnianie danych meldunkowych (typ i numer dokumentu, metoda płatności, kwota)
  * Oznaczanie statusów rezerwacji, które są oznaczane kolorami (Oczekująca, Zameldowany, Wymeldowany)
* **Zarządzanie Stanem Czystości Pokoi:**
  * Przejrzysta lista pokoi z podziałem na statusy ("Czysty" / "Do sprzątania")
  * **Automatyzacja:** System samoczynnie zmienia status pokoju na brudny w momencie wymeldowania gościa
* **Dodatkowe funkcjonalności:**
  * **Dashboard:** Statystyki na żywo dla wybranego dnia (liczba zameldowań, wymeldowań, aktywnych gości i wolnych pokoi)
  * **System Pobudek:** Zlecanie budzenia gości o konkretnych godzinach
  * **Wiadomości Hotelowe:** Wewnętrzna tablica ogłoszeń dla pracowników zarządzana przez Panel Administratora
  * **Lista Pokoi:** Szybki podgląd całego inwentarza hotelu (20 pokoi na 3 piętrach)

## Technologie

* **Język:** C++ / C++/CLI
* **Interfejs graficzny:** Windows Forms (.NET Framework)
* **Baza danych:** SQLite (System.Data.SQLite)
* **Środowisko programistyczne:** Visual Studio

## Skróty klawiszowe w menu głównym
Dla przyspieszenia pracy recepcji, aplikacja obsługuje nawigację za pomocą klawiatury:
* `R` – Nowa rezerwacja
* `Z` – Lista zameldowań
* `W` – Lista wymeldowań
* `C` – Stan czystości pokoi
* `P` – Pełna lista pokoi
* `A` – Panel Administratora (Dodawanie wiadomości)

## Uruchomienie i instalacja
Opisane szczegółowo w Wiki.

*Uwaga: Z racji wykorzystania technologii Windows Forms, aplikacja natywnie działa wyłącznie na systemach rodziny Windows.*
