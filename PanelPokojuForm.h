#pragma once

#include "Pobudka.h"
#include "PobudkaService.h"
#include "Rezerwacja.h"
#include "RezerwacjaService.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PanelPokojuForm : public System::Windows::Forms::Form
	{
	public:

		PanelPokojuForm(int pokoj)
		{
			InitializeComponent();

			numerPokoju = pokoj;
			numPokoj->Value = pokoj;

			dtpData->MinDate = DateTime::Now.Date;

			dtpData->Value = DateTime::Now.Date;

		}

	protected:

		~PanelPokojuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int numerPokoju;

		System::Windows::Forms::Panel^ panel1;

		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ Imie;
		System::Windows::Forms::Label^ Nazwisko;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label3;


		System::Windows::Forms::TextBox^ txtNazwisko;

		System::Windows::Forms::NumericUpDown^ numPokoj;

		System::Windows::Forms::DateTimePicker^ dtpData;
		System::Windows::Forms::DateTimePicker^ dtpGodzina;

		System::Windows::Forms::Button^ btnDodajPobudke;
	private: System::Windows::Forms::Button^ usunPobudke;
	private: System::Windows::Forms::TextBox^ txtImie;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->usunPobudke = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Imie = (gcnew System::Windows::Forms::Label());
			this->Nazwisko = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->numPokoj = (gcnew System::Windows::Forms::NumericUpDown());
			this->dtpData = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpGodzina = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnDodajPobudke = (gcnew System::Windows::Forms::Button());
			this->txtImie = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPokoj))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->usunPobudke);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->Imie);
			this->panel1->Controls->Add(this->Nazwisko);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtImie);
			this->panel1->Controls->Add(this->txtNazwisko);
			this->panel1->Controls->Add(this->numPokoj);
			this->panel1->Controls->Add(this->dtpData);
			this->panel1->Controls->Add(this->dtpGodzina);
			this->panel1->Controls->Add(this->btnDodajPobudke);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(675, 695);
			this->panel1->TabIndex = 0;
			// 
			// usunPobudke
			// 
			this->usunPobudke->BackColor = System::Drawing::Color::Red;
			this->usunPobudke->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->usunPobudke->Location = System::Drawing::Point(353, 536);
			this->usunPobudke->Name = L"usunPobudke";
			this->usunPobudke->Size = System::Drawing::Size(274, 66);
			this->usunPobudke->TabIndex = 13;
			this->usunPobudke->Text = L"Usuñ pobudkê";
			this->usunPobudke->UseVisualStyleBackColor = false;
			this->usunPobudke->Click += gcnew System::EventHandler(this, &PanelPokojuForm::usunPobudke_click);
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(673, 80);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Panel pokoju";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Imie
			// 
			this->Imie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Imie->Location = System::Drawing::Point(203, 112);
			this->Imie->Name = L"Imie";
			this->Imie->Size = System::Drawing::Size(102, 50);
			this->Imie->TabIndex = 1;
			this->Imie->Text = L"Imiê";
			// 
			// Nazwisko
			// 
			this->Nazwisko->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Nazwisko->Location = System::Drawing::Point(161, 180);
			this->Nazwisko->Name = L"Nazwisko";
			this->Nazwisko->Size = System::Drawing::Size(174, 57);
			this->Nazwisko->TabIndex = 2;
			this->Nazwisko->Text = L"Nazwisko";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(182, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 42);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Pokój";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(90, 356);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(245, 36);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Data pobudki:";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(41, 437);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(294, 44);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Godzina pobudki:";
			// 
			// txtNazwisko
			// 
			this->txtNazwisko->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txtNazwisko->Location = System::Drawing::Point(385, 180);
			this->txtNazwisko->Name = L"txtNazwisko";
			this->txtNazwisko->Size = System::Drawing::Size(200, 44);
			this->txtNazwisko->TabIndex = 7;
			// 
			// numPokoj
			// 
			this->numPokoj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numPokoj->Location = System::Drawing::Point(385, 262);
			this->numPokoj->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numPokoj->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numPokoj->Name = L"numPokoj";
			this->numPokoj->Size = System::Drawing::Size(120, 44);
			this->numPokoj->TabIndex = 8;
			this->numPokoj->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// dtpData
			// 
			this->dtpData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dtpData->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpData->Location = System::Drawing::Point(385, 348);
			this->dtpData->Name = L"dtpData";
			this->dtpData->Size = System::Drawing::Size(242, 44);
			this->dtpData->TabIndex = 9;
			// 
			// dtpGodzina
			// 
			this->dtpGodzina->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dtpGodzina->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dtpGodzina->Location = System::Drawing::Point(385, 437);
			this->dtpGodzina->Name = L"dtpGodzina";
			this->dtpGodzina->ShowUpDown = true;
			this->dtpGodzina->Size = System::Drawing::Size(200, 44);
			this->dtpGodzina->TabIndex = 10;
			// 
			// btnDodajPobudke
			// 
			this->btnDodajPobudke->BackColor = System::Drawing::Color::LimeGreen;
			this->btnDodajPobudke->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodajPobudke->Location = System::Drawing::Point(48, 536);
			this->btnDodajPobudke->Name = L"btnDodajPobudke";
			this->btnDodajPobudke->Size = System::Drawing::Size(280, 66);
			this->btnDodajPobudke->TabIndex = 12;
			this->btnDodajPobudke->Text = L"Dodaj pobudkê";
			this->btnDodajPobudke->UseVisualStyleBackColor = false;
			this->btnDodajPobudke->Click += gcnew System::EventHandler(this, &PanelPokojuForm::btnDodajPobudke_Click);
			// 
			// txtImie
			// 
			this->txtImie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txtImie->Location = System::Drawing::Point(385, 118);
			this->txtImie->Name = L"txtImie";
			this->txtImie->Size = System::Drawing::Size(200, 44);
			this->txtImie->TabIndex = 6;
			// 
			// PanelPokojuForm
			// 
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(694, 714);
			this->Controls->Add(this->panel1);
			this->Name = L"PanelPokojuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel pokoju";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numPokoj))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		System::Void btnDodajPobudke_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{

			if (txtImie->Text == "" ||
				txtNazwisko->Text == "")
			{
				MessageBox::Show("Uzupe³nij dane goœcia!");
				return;
			}

			bool znaleziono = false;

			List<Rezerwacja^>^ lista =
				RezerwacjaService::PobierzWszystkie();

			for each (Rezerwacja ^ r in lista)
			{
				if (
					r->Imie == txtImie->Text &&
					r->Nazwisko == txtNazwisko->Text &&
					r->Pokoj == (int)numPokoj->Value
					)
				{
					znaleziono = true;
					break;
				}
			}

			if (!znaleziono)
			{
				MessageBox::Show(
					"Brak zgodnoœci z list¹ zameldowañ!");

				return;
			}
			DateTime dataPobudki =
				dtpData->Value.Date +
				dtpGodzina->Value.TimeOfDay;

			if (dataPobudki < DateTime::Now)
			{
				MessageBox::Show(
					"Nie mo¿na ustawiæ pobudki w przesz³oœci!");

				return;
			}

			Pobudka^ p = gcnew Pobudka();

			p->Imie = txtImie->Text;
			p->Nazwisko = txtNazwisko->Text;
			p->Pokoj = (int)numPokoj->Value;
			p->Data = dtpData->Value.Date;
			p->Godzina = dtpGodzina->Value.ToString("HH:mm");

			PobudkaService::Dodaj(p);

			MessageBox::Show("Dodano pobudkê!");

			this->Close();
		}
	private: System::Void usunPobudke_click(System::Object^ sender, System::EventArgs^ e) {
		bool wynikUsuwania =
			PobudkaService::Usun(
				txtImie->Text,
				txtNazwisko->Text,
				(int)numPokoj->Value,
				dtpData->Value.Date);

		if (wynikUsuwania)
		{
			MessageBox::Show(
				"Pobudka zosta³a usuniêta.");

			this->Close();
		}
		else
		{
			MessageBox::Show(
				"Nie znaleziono takiej pobudki.");
		}
	}
};
}
