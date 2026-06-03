#pragma once
#include "RezerwacjaService.h"
#include "SzczegolyRezerwacjiForm.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o ZameldowaniaListaForm
	/// </summary>
	public ref class ZameldowaniaListaForm : public System::Windows::Forms::Form
	{
	public:
		ZameldowaniaListaForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			KonfigurujTabele();
			OdswiezDane();

		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~ZameldowaniaListaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvLista;
	protected:

	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ btnUsunRezerwacje;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;
		// Rêczne ustawienie kolumn
		void KonfigurujTabele() {
			this->dgvLista->ColumnCount = 7;
			this->dgvLista->Columns[0]->Name = L"Id";
			this->dgvLista->Columns[0]->Visible = false;	// id do bazy niewidoczne
			this->dgvLista->Columns[1]->Name = L"Goœæ";
			this->dgvLista->Columns[2]->Name = L"Pokój";
			this->dgvLista->Columns[3]->Name = L"Data Od";
			this->dgvLista->Columns[4]->Name = L"Data Do";
			this->dgvLista->Columns[5]->Name = L"Status";
			this->dgvLista->Columns[6]->Name = L"Osoby";
			this->dgvLista->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLista->RowTemplate->Height = 40;
			this->dgvLista->ColumnHeadersHeight = 45;
			this->dgvLista->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->dgvLista->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->dgvLista->ReadOnly = true;
			this->dgvLista->AllowUserToAddRows = false;
			this->dgvLista->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->dgvLista->MultiSelect = false; // Pozwala usun¹æ tylko jedn¹ rezerwacjê na raz
		}

		// Pobranie danych z bazy przez serwis
		void OdswiezDane() {
			this->dgvLista->Rows->Clear();

			// Korzystamy z metody, któr¹ ju¿ mamy w serwisie
			List<Rezerwacja^>^ rezerwacje = RezerwacjaService::PobierzWszystkie();

			for each (Rezerwacja ^ r in rezerwacje) {
				// problem z wyœwietleniem ¹ w statusie - naprawiony
				String^ ladnyStatus = (r->StatusRezerwacji == "Oczekujaca") ? L"Oczekuj¹ca" : r->StatusRezerwacji;

				String^ typPokoju = RezerwacjaService::PobierzTypDlaNumeruPokoju(r->Pokoj);
				String^ wyswietlanyPokoj = r->Pokoj.ToString() + " (" + typPokoju + ")";

				array<String^>^ row = {
					r->Id.ToString(),
					r->Imie + " " + r->Nazwisko,
					wyswietlanyPokoj,
					r->DataOd.ToString("dd.MM.yyyy"),
					r->DataDo.ToString("dd.MM.yyyy"),
					ladnyStatus,
					r->IloscGosci.ToString()
				};
				this->dgvLista->Rows->Add(row);
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->btnUsunRezerwacje = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvLista
			// 
			this->dgvLista->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvLista->Location = System::Drawing::Point(0, 0);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->Size = System::Drawing::Size(957, 560);
			this->dgvLista->TabIndex = 1;
			this->dgvLista->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ZameldowaniaListaForm::dgvLista_CellDoubleClick);
			// 
			// dataGridView2
			// 
			this->dataGridView2->Location = System::Drawing::Point(217, 289);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(240, 150);
			this->dataGridView2->TabIndex = 0;
			// 
			// btnUsunRezerwacje
			// 
			this->btnUsunRezerwacje->BackColor = System::Drawing::Color::IndianRed;
			this->btnUsunRezerwacje->Location = System::Drawing::Point(12, 525);
			this->btnUsunRezerwacje->Name = L"btnUsunRezerwacje";
			this->btnUsunRezerwacje->Size = System::Drawing::Size(138, 23);
			this->btnUsunRezerwacje->TabIndex = 2;
			this->btnUsunRezerwacje->Text = L"Usuñ wybran¹ rezerwacjê";
			this->btnUsunRezerwacje->UseVisualStyleBackColor = false;
			this->btnUsunRezerwacje->Click += gcnew System::EventHandler(this, &ZameldowaniaListaForm::btnUsunRezerwacje_Click);
			// 
			// ZameldowaniaListaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 560);
			this->Controls->Add(this->btnUsunRezerwacje);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->dataGridView2);
			this->Name = L"ZameldowaniaListaForm";
			this->Text = L"Lista zameldowañ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dgvLista_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) { // Sprawdzamy czy klikniêto wiersz, a nie nag³ówek tabeli
			// Wyci¹gamy Id z ukrytej komórki wybranego wiersza
			int wybraneId = Convert::ToInt32(dgvLista->Rows[e->RowIndex]->Cells[L"Id"]->Value);

			// Otwieramy okno szczegó³ów przekazuj¹c mu to Id (kod okna stworzymy w Kroku 2)
			SzczegolyRezerwacjiForm^ szczegolyForm = gcnew SzczegolyRezerwacjiForm(wybraneId);

			// Jeœli w oknie szczegó³ów coœ zmieniono i zamkniêto je poprawnie (OK), odœwie¿amy tabelê
			if (szczegolyForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				OdswiezDane();
			}
		}
	}

private: System::Void btnUsunRezerwacje_Click(System::Object^ sender, System::EventArgs^ e) {

	// jeœli zaznaczony jakiœ wiersz (rezerwacja)
	if (this->dgvLista->SelectedRows->Count > 0) {

		// bierzemy id rezerwacji
		int idDoUsuniecia = Convert::ToInt32(this->dgvLista->SelectedRows[0]->Cells[0]->Value);

		// potwierdzenie usuwania
		System::Windows::Forms::DialogResult wynik = MessageBox::Show(L"Czy na pewno chcesz anulowaæ wybran¹ rezerwacjê?",
			L"Potwierdzenie usuniêcia", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

		// jeœli tak
		if (wynik == System::Windows::Forms::DialogResult::Yes) {

			RezerwacjaService::Usun(idDoUsuniecia);

			MessageBox::Show(L"Rezerwacja zosta³a pomyœlnie usuniêta");

			OdswiezDane();
		}
	}
	else {
		MessageBox::Show(L"Najpierw nale¿y oznaczyæ rezerwacjê na liœcie", L"Informacja", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
};
}
