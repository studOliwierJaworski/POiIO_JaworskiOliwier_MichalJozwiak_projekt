# System Zarządzania Hotelem

Desktopowa aplikacja okienkowa (Windows Forms) stworzona w języku C++/CLI, służąca do zarządzania rezerwacjami, gośćmi oraz stanem pokoi w obiekcie hotelowym. 

Projekt wykorzystuje lokalną bazę danych **SQLite**, która konfiguruje i tworzy się w pełni automatycznie przy pierwszym uruchomieniu programu.

<img width="1000" height="644" alt="Zrzut ekranu 2026-06-09 002513" src="https://github.com/user-attachments/assets/b8a3b57b-95b8-492e-a698-cccd8945cd0b" />



## Główne funkcjonalności aplikacji

* **Zarządzanie Rezerwacjami:**
  * Rejestrowanie nowych gości z określeniem daty pobytu
  * System automatycznie filtruje dostępność i przydziela losowy, wolny pokój na podstawie wybranego standardu (DBLQ, DBLT, SGL, 3PPL, 4PPL)
  * Możliwość usuwania rezerwacji z bazy
  
    <img width="678" height="498" alt="Zrzut ekranu 2026-06-09 003149" src="https://github.com/user-attachments/assets/9b4a10a1-efe2-44aa-9118-2d24ed7b5e19" />

* **Obsługa Recepcji (Zameldowania / Wymeldowania):**
  * Uzupełnianie danych meldunkowych (typ i numer dokumentu, metoda płatności, kwota)
  * Oznaczanie statusów rezerwacji, które są oznaczane kolorami (Oczekująca, Zameldowany, Wymeldowany)
  

<img width="1000" height="435" alt="Zrzut ekranu 2026-06-09 004213" src="https://github.com/user-attachments/assets/ddf21feb-e467-4d4c-80e7-77d344ae27a8" />


* **Zarządzanie Stanem Czystości Pokoi:**
  * Przejrzysta lista pokoi z podziałem na statusy ("Czysty" / "Do sprzątania")
  * **Automatyzacja:** System samoczynnie zmienia status pokoju na brudny w momencie wymeldowania gościa
  

  <img width="787" height="559" alt="Zrzut ekranu 2026-06-09 003124" src="https://github.com/user-attachments/assets/3bebe044-330d-4aa2-a769-6b9edfc26bf2" />

* **Dodatkowe funkcjonalności:**
  * **Dashboard:** Statystyki na żywo dla wybranego dnia (liczba zameldowań, wymeldowań, aktywnych gości i wolnych pokoi)
  * **System Pobudek:** Zlecanie budzenia gości o konkretnych godzinach
  * **Wiadomości Hotelowe:** Wewnętrzna tablica ogłoszeń dla pracowników zarządzana przez Panel Administratora
  * **Lista Pokoi:** Szybki podgląd całego inwentarza hotelu (20 pokoi na 3 piętrach)
 
<img width="800" height="614" alt="Zrzut ekranu 2026-06-09 004402" src="https://github.com/user-attachments/assets/e67736b2-6c9a-455a-b77b-c033a803cbea" />


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
