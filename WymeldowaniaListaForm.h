#pragma once
#include "RezerwacjaService.h"
#include "SzczegolyRezerwacjiForm.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o WymeldowaniaListaForm
	/// </summary>
	public ref class WymeldowaniaListaForm : public System::Windows::Forms::Form
	{
	public:
		WymeldowaniaListaForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			KonfigurujTabele();
			OdswiezDane(); // Pobranie danych na domyœlny, dzisiejszy dzieñ
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~WymeldowaniaListaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Windows::Forms::DataGridView^ dgvLista;
		System::Windows::Forms::Panel^ panelTop;
		System::Windows::Forms::DateTimePicker^ dtpData;
		System::Windows::Forms::Label^ lblData;



		void KonfigurujTabele() {
			this->dgvLista->ColumnCount = 5;
			this->dgvLista->Columns[0]->Name = L"Id";
			this->dgvLista->Columns[0]->Visible = false;

			this->dgvLista->Columns[1]->Name = L"Goœæ";
			this->dgvLista->Columns[2]->Name = L"Pokój";
			this->dgvLista->Columns[3]->Name = L"Status";
			this->dgvLista->Columns[4]->Name = L"Osoby";
			this->dgvLista->RowTemplate->Height = 40; 
			this->dgvLista->ColumnHeadersHeight = 45; 
			this->dgvLista->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12)); 
			this->dgvLista->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->dgvLista->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLista->ReadOnly = true;
			this->dgvLista->AllowUserToAddRows = false;
			this->dgvLista->EnableHeadersVisualStyles = false;
		}

		void OdswiezDane() {
			this->dgvLista->Rows->Clear();

			// U¿ywamy metody z serwisu, która szuka daty wymeldowania
			List<Rezerwacja^>^ rezerwacje = RezerwacjaService::PobierzWymeldowaniaNaDzien(dtpData->Value);

			for each (Rezerwacja ^ r in rezerwacje) {
				String^ ladnyStatus = (r->StatusRezerwacji == "Oczekujaca") ? L"Oczekuj¹ca" : r->StatusRezerwacji;

				String^ typPokoju = RezerwacjaService::PobierzTypDlaNumeruPokoju(r->Pokoj);
				String^ wyswietlanyPokoj = r->Pokoj.ToString() + " (" + typPokoju + ")";

				array<String^>^ row = {
					r->Id.ToString(),
					r->Imie + " " + r->Nazwisko,
					wyswietlanyPokoj,
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
			this->panelTop = (gcnew System::Windows::Forms::Panel());
			this->lblData = (gcnew System::Windows::Forms::Label());
			this->dtpData = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->panelTop->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvLista
			// 
			this->dgvLista->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvLista->Location = System::Drawing::Point(0, 50);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->Size = System::Drawing::Size(957, 510);
			this->dgvLista->TabIndex = 1;
			this->dgvLista->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &WymeldowaniaListaForm::dgvLista_CellDoubleClick);
			// 
			// panelTop
			// 
			this->panelTop->Controls->Add(this->lblData);
			this->panelTop->Controls->Add(this->dtpData);
			this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTop->Location = System::Drawing::Point(0, 0);
			this->panelTop->Name = L"panelTop";
			this->panelTop->Size = System::Drawing::Size(957, 50);
			this->panelTop->TabIndex = 2;
			// 
			// lblData
			// 
			this->lblData->AutoSize = true;
			this->lblData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->lblData->Location = System::Drawing::Point(12, 16);
			this->lblData->Name = L"lblData";
			this->lblData->Size = System::Drawing::Size(191, 15);
			this->lblData->TabIndex = 0;
			this->lblData->Text = L"Wybierz datê wymeldowania:";
			// 
			// dtpData
			// 
			this->dtpData->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpData->Location = System::Drawing::Point(210, 12);
			this->dtpData->MaxDate = System::DateTime(2027, 12, 31, 0, 0, 0, 0);
			this->dtpData->Name = L"dtpData";
			this->dtpData->Size = System::Drawing::Size(200, 20);
			this->dtpData->TabIndex = 1;
			this->dtpData->ValueChanged += gcnew System::EventHandler(this, &WymeldowaniaListaForm::dtpData_ValueChanged);
			// 
			// WymeldowaniaListaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 560);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->panelTop);
			this->Name = L"WymeldowaniaListaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Lista wymeldowañ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->panelTop->ResumeLayout(false);
			this->panelTop->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void dtpData_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		OdswiezDane(); // Odœwie¿a tabelê przy zmianie kalendarza
	}

	private: System::Void dgvLista_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			int wybraneId = Convert::ToInt32(dgvLista->Rows[e->RowIndex]->Cells[L"Id"]->Value);
			SzczegolyRezerwacjiForm^ szczegolyForm = gcnew SzczegolyRezerwacjiForm(wybraneId);
			
			if (szczegolyForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				OdswiezDane(); // Odœwie¿a listê wymeldowañ po zamkniêciu okna
			}
		}
	}
	};
}