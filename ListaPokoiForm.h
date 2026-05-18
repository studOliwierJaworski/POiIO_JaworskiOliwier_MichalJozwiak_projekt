#pragma once

namespace AplikacjaHotelowa {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ListaPokoiForm : public System::Windows::Forms::Form
	{
	public:
		ListaPokoiForm(void)
		{
			InitializeComponent();
			WypelnijTabele();
		}

	protected:
		~ListaPokoiForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dgvPokoje;
	private: System::Windows::Forms::Label^ lblTytul;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->dgvPokoje = (gcnew System::Windows::Forms::DataGridView());
			   this->lblTytul = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPokoje))->BeginInit();
			   this->SuspendLayout();

			   // 
			   // lblTytul
			   // 
			   this->lblTytul->Dock = System::Windows::Forms::DockStyle::Top;
			   this->lblTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			   this->lblTytul->Location = System::Drawing::Point(0, 0);
			   this->lblTytul->Name = L"lblTytul";
			   this->lblTytul->Size = System::Drawing::Size(484, 50);
			   this->lblTytul->TabIndex = 1;
			   this->lblTytul->Text = L"Lista wszystkich pokoi w hotelu";
			   this->lblTytul->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			   // 
			   // dgvPokoje
			   // 
			   this->dgvPokoje->AllowUserToAddRows = false;
			   this->dgvPokoje->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->dgvPokoje->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dgvPokoje->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->dgvPokoje->Location = System::Drawing::Point(0, 50);
			   this->dgvPokoje->Name = L"dgvPokoje";
			   this->dgvPokoje->ReadOnly = true;
			   this->dgvPokoje->RowHeadersVisible = false;
			   this->dgvPokoje->Size = System::Drawing::Size(484, 411);
			   this->dgvPokoje->TabIndex = 0;
			   this->dgvPokoje->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			   this->dgvPokoje->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			   this->dgvPokoje->RowTemplate->Height = 35;

			   // Konfiguracja kolumn
			   this->dgvPokoje->ColumnCount = 3;
			   this->dgvPokoje->Columns[0]->Name = L"Numer pokoju";
			   this->dgvPokoje->Columns[1]->Name = L"Typ pokoju";
			   this->dgvPokoje->Columns[2]->Name = L"Piêtro";

			   // 
			   // ListaPokoiForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(484, 461);
			   this->Controls->Add(this->dgvPokoje);
			   this->Controls->Add(this->lblTytul);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"ListaPokoiForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Lista pokoi";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPokoje))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private:
		void WypelnijTabele() {
			// Tablica z zapisanymi danymi: "Numer|Typ|Piêtro"
			array<String^>^ pokojeHotelowe = {
				"101|DBLQ|1", "102|DBLQ|1", "103|DBLQ|1", "104|DBLT|1", "105|DBLT|1", "106|SGL|1", "107|SGL|1",
				"201|DBLQ|2", "202|DBLQ|2", "203|DBLQ|2", "204|DBLT|2", "205|DBLT|2", "206|SGL|2", "207|SGL|2",
				"301|DBLQ|3", "302|DBLQ|3", "303|DBLT|3", "304|SGL|3", "305|3PPL|3", "306|4PPL|3"
			};

			for each (String ^ info in pokojeHotelowe) {
				// Dzielimy tekst po pionowej kresce '|' na tablicê 3 elementów i wrzucamy do tabeli
				array<String^>^ dane = info->Split('|');
				this->dgvPokoje->Rows->Add(dane);
			}
		}
	};
}