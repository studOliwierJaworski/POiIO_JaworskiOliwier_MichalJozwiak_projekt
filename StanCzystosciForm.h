#pragma once
#include "RezerwacjaService.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class StanCzystosciForm : public System::Windows::Forms::Form
	{
	public:
		StanCzystosciForm(void)
		{
			InitializeComponent();

			KonfigurujTabele();
			OdswiezDane();
		}

	protected:
		~StanCzystosciForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::DataGridView^ dgvLista;
		System::Windows::Forms::Button^ btnCzysty;
		System::Windows::Forms::Button^ btnDoSprzatania;

		System::ComponentModel::Container^ components;

#pragma region Funkcje

		void KonfigurujTabele()
		{
			this->dgvLista->ColumnCount = 4;

			this->dgvLista->Columns[0]->Name = L"Pokój";
			this->dgvLista->Columns[1]->Name = L"Status";
			this->dgvLista->Columns[2]->Name = L"Data Od";
			this->dgvLista->Columns[3]->Name = L"Data Do";

			this->dgvLista->RowTemplate->Height = 40;
			this->dgvLista->ColumnHeadersHeight = 45;

			this->dgvLista->DefaultCellStyle->Font =
				(gcnew System::Drawing::Font(L"Segoe UI", 11));

			this->dgvLista->ColumnHeadersDefaultCellStyle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					11,
					System::Drawing::FontStyle::Bold));

			this->dgvLista->AutoSizeColumnsMode =
				DataGridViewAutoSizeColumnsMode::Fill;

			this->dgvLista->ReadOnly = false;
			this->dgvLista->AllowUserToAddRows = false;
			this->dgvLista->SelectionMode =
				DataGridViewSelectionMode::FullRowSelect;
		}

		void OdswiezDane()
		{
			this->dgvLista->Rows->Clear();

			List<Rezerwacja^>^ rezerwacje =
				RezerwacjaService::PobierzWszystkie();

			for each (Rezerwacja ^ r in rezerwacje)
			{
				// jeœli status pusty
				if (String::IsNullOrEmpty(r->StanCzystosci))
				{
					r->StanCzystosci = "Czysty";
				}

				array<String^>^ row = {
					r->Pokoj.ToString(),
					r->StanCzystosci,
					r->DataOd.ToString("dd.MM.yyyy"),
					r->DataDo.ToString("dd.MM.yyyy")
				};

				int rowIndex = this->dgvLista->Rows->Add(row);

				// kolorowanie statusów
				if (r->StanCzystosci == "Czysty")
				{
					dgvLista->Rows[rowIndex]
						->Cells[1]
						->Style
						->BackColor = System::Drawing::Color::LightGreen;
				}
				else
				{
					dgvLista->Rows[rowIndex]
						->Cells[1]
						->Style
						->BackColor = System::Drawing::Color::LightCoral;
				}
			}
		}

#pragma endregion

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->btnCzysty = (gcnew System::Windows::Forms::Button());
			this->btnDoSprzatania = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dgvLista))->BeginInit();

			this->SuspendLayout();

			// 
			// dgvLista
			// 
			this->dgvLista->Location = System::Drawing::Point(12, 12);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->Size = System::Drawing::Size(760, 420);
			this->dgvLista->TabIndex = 0;

			// 
			// btnCzysty
			// 
			this->btnCzysty->BackColor = System::Drawing::Color::LightGreen;
			this->btnCzysty->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10,
					System::Drawing::FontStyle::Bold));

			this->btnCzysty->Location = System::Drawing::Point(12, 450);
			this->btnCzysty->Name = L"btnCzysty";
			this->btnCzysty->Size = System::Drawing::Size(180, 45);
			this->btnCzysty->TabIndex = 1;
			this->btnCzysty->Text = L"Oznacz jako czysty";
			this->btnCzysty->UseVisualStyleBackColor = false;
			this->btnCzysty->Click +=
				gcnew System::EventHandler(
					this,
					&StanCzystosciForm::btnCzysty_Click);

			// 
			// btnDoSprzatania
			// 
			this->btnDoSprzatania->BackColor = System::Drawing::Color::LightCoral;
			this->btnDoSprzatania->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10,
					System::Drawing::FontStyle::Bold));

			this->btnDoSprzatania->Location =
				System::Drawing::Point(220, 450);

			this->btnDoSprzatania->Name = L"btnDoSprzatania";
			this->btnDoSprzatania->Size = System::Drawing::Size(220, 45);
			this->btnDoSprzatania->TabIndex = 2;
			this->btnDoSprzatania->Text = L"Oznacz do sprz¹tania";
			this->btnDoSprzatania->UseVisualStyleBackColor = false;

			this->btnDoSprzatania->Click +=
				gcnew System::EventHandler(
					this,
					&StanCzystosciForm::btnDoSprzatania_Click);

			// 
			// StanCzystosciForm
			// 
			this->AutoScaleDimensions =
				System::Drawing::SizeF(6, 13);

			this->AutoScaleMode =
				System::Windows::Forms::AutoScaleMode::Font;

			this->ClientSize = System::Drawing::Size(784, 521);

			this->Controls->Add(this->btnDoSprzatania);
			this->Controls->Add(this->btnCzysty);
			this->Controls->Add(this->dgvLista);

			this->Name = L"StanCzystosciForm";
			this->Text = L"Stan czystoœci pokoi";

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dgvLista))->EndInit();

			this->ResumeLayout(false);
		}

#pragma endregion

	private:
		System::Void btnCzysty_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (dgvLista->CurrentRow != nullptr)
			{
				int pokoj =
					Convert::ToInt32(
						dgvLista->CurrentRow->Cells[0]->Value);

				RezerwacjaService::AktualizujStanCzystosci(
					pokoj,
					"Czysty");

				OdswiezDane();

				dgvLista->CurrentRow
					->Cells[1]
					->Style
					->BackColor = System::Drawing::Color::LightGreen;
			}
		}

	private:
		System::Void btnDoSprzatania_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (dgvLista->CurrentRow != nullptr)
			{
				int pokoj =
					Convert::ToInt32(
						dgvLista->CurrentRow->Cells[0]->Value);

				RezerwacjaService::
					AktualizujStanCzystosci(
						pokoj,
						"Do sprz¹tania");

				OdswiezDane();
				dgvLista->CurrentRow
					->Cells[1]
					->Style
					->BackColor = System::Drawing::Color::LightCoral;
			}
		}
	};
}