Krok 1: Ręczne pobranie paczki z NuGet.org
nuget.org/packages/Stub.System.Data.SQLite.Core.NetFramework
- pobieramy plik nupkg z about po prawej

Krok 2: Magia z archiwum ZIP
- zmieniamy format nupkg pliku na zip
- wrzucamy folder z zipa do folderu projektu

Krok 3: Wyciągnięcie odpowiednich plików
	1.	Główna biblioteka (dla Visual Studio):
- wchodzimy w wypakowanym folderze do: lib ➔ net46
- szukamy pliku System.Data.SQLite.dll
- Visual Studio ➔ Eksplorator rozwiązań ➔ Odwołania ➔ Dodaj odwołanie ➔ Przeglądaj i wskazujemy ten plik
	2.	Plik tłumaczący Interop:
- wchodzimy do: build ➔ net46 ➔ x64
- szukamy plik SQLite.Interop.dll.
- kopiujemy ten plik i wklejamy go do folderu, w którym Visual Studio generuje plik .exe - x64\Debug\
