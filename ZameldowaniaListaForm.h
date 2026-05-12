#pragma once
#include "RezerwacjaService.h"

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

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;
		// Rêczne ustawienie kolumn
		void KonfigurujTabele() {
			this->dgvLista->ColumnCount = 4;
			this->dgvLista->Columns[0]->Name = L"Goœæ";
			this->dgvLista->Columns[1]->Name = L"Pokój";
			this->dgvLista->Columns[2]->Name = L"Data Od";
			this->dgvLista->Columns[3]->Name = L"Data Do";
			this->dgvLista->RowTemplate->Height = 40;
			this->dgvLista->ColumnHeadersHeight = 45;
			this->dgvLista->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->dgvLista->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->dgvLista->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLista->ReadOnly = true;
			this->dgvLista->AllowUserToAddRows = false;
		}

		// Pobranie danych z bazy przez serwis
		void OdswiezDane() {
			this->dgvLista->Rows->Clear();

			// Korzystamy z metody, któr¹ ju¿ mamy w serwisie
			List<Rezerwacja^>^ rezerwacje = RezerwacjaService::PobierzWszystkie();

			for each (Rezerwacja ^ r in rezerwacje) {
				array<String^>^ row = {
					r->Imie + " " + r->Nazwisko,
					r->Pokoj.ToString(),
					r->DataOd.ToString("dd.MM.yyyy"),
					r->DataDo.ToString("dd.MM.yyyy")
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
			// 
			// dataGridView2
			// 
			this->dataGridView2->Location = System::Drawing::Point(217, 289);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(240, 150);
			this->dataGridView2->TabIndex = 0;
			// 
			// ZameldowaniaListaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 560);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->dataGridView2);
			this->Name = L"ZameldowaniaListaForm";
			this->Text = L"Lista zameldowañ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView2_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
}
