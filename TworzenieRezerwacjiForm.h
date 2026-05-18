#pragma once
#include "Rezerwacja.h"
#include "RezerwacjaService.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o RezerwacjaForm
	/// </summary>
	public ref class TworzenieRezerwacjiForm : public System::Windows::Forms::Form
	{
	public:
		TworzenieRezerwacjiForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~TworzenieRezerwacjiForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ Nazwisko;

	private: System::Windows::Forms::Label^ Imiê;
	private: System::Windows::Forms::TextBox^ txtNazwisko;

	private: System::Windows::Forms::TextBox^ txtImie;
	private: System::Windows::Forms::ComboBox^ cmbTypPokoju;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnZapisz;

	private: System::Windows::Forms::DateTimePicker^ dtpDo;

	private: System::Windows::Forms::DateTimePicker^ dtpOd;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnZapisz = (gcnew System::Windows::Forms::Button());
			this->dtpDo = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpOd = (gcnew System::Windows::Forms::DateTimePicker());
			this->cmbTypPokoju = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->txtImie = (gcnew System::Windows::Forms::TextBox());
			this->Nazwisko = (gcnew System::Windows::Forms::Label());
			this->Imiê = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->btnZapisz);
			this->panel1->Controls->Add(this->dtpDo);
			this->panel1->Controls->Add(this->dtpOd);
			this->panel1->Controls->Add(this->cmbTypPokoju);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->txtNazwisko);
			this->panel1->Controls->Add(this->txtImie);
			this->panel1->Controls->Add(this->Nazwisko);
			this->panel1->Controls->Add(this->Imiê);
			this->panel1->Location = System::Drawing::Point(225, 94);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(251, 240);
			this->panel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(249, 27);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Tworzenie rezerwacji";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(135, 197);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Anuluj";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TworzenieRezerwacjiForm::button1_Click);
			// 
			// btnZapisz
			// 
			this->btnZapisz->BackColor = System::Drawing::Color::LimeGreen;
			this->btnZapisz->Location = System::Drawing::Point(13, 197);
			this->btnZapisz->Margin = System::Windows::Forms::Padding(2);
			this->btnZapisz->Name = L"btnZapisz";
			this->btnZapisz->Size = System::Drawing::Size(100, 28);
			this->btnZapisz->TabIndex = 11;
			this->btnZapisz->Text = L"Zapisz";
			this->btnZapisz->UseVisualStyleBackColor = false;
			this->btnZapisz->Click += gcnew System::EventHandler(this, &TworzenieRezerwacjiForm::btnZapisz_Click);
			// 
			// dtpDo
			// 
			this->dtpDo->Location = System::Drawing::Point(75, 164);
			this->dtpDo->Margin = System::Windows::Forms::Padding(2);
			this->dtpDo->Name = L"dtpDo";
			this->dtpDo->Size = System::Drawing::Size(102, 20);
			this->dtpDo->TabIndex = 10;
			// 
			// dtpOd
			// 
			this->dtpOd->Location = System::Drawing::Point(75, 136);
			this->dtpOd->Margin = System::Windows::Forms::Padding(2);
			this->dtpOd->Name = L"dtpOd";
			this->dtpOd->Size = System::Drawing::Size(102, 20);
			this->dtpOd->TabIndex = 9;
			this->dtpOd->ValueChanged += gcnew System::EventHandler(this, &TworzenieRezerwacjiForm::dtpOd_ValueChanged);
			// 
			// cmbTypPokoju
			// 
			this->cmbTypPokoju->Location = System::Drawing::Point(75, 102);
			this->cmbTypPokoju->Name = L"cmbTypPokoju";
			this->cmbTypPokoju->Size = System::Drawing::Size(102, 21);
			this->cmbTypPokoju->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTypPokoju->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"DBLQ", L"DBLT", L"SGL", L"3PPL", L"4PPL" });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 164);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Do";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 136);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Od";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 103);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Typ pokoju";
			// 
			// txtNazwisko
			// 
			this->txtNazwisko->Location = System::Drawing::Point(75, 73);
			this->txtNazwisko->Margin = System::Windows::Forms::Padding(2);
			this->txtNazwisko->Name = L"txtNazwisko";
			this->txtNazwisko->Size = System::Drawing::Size(102, 20);
			this->txtNazwisko->TabIndex = 4;
			// 
			// txtImie
			// 
			this->txtImie->Location = System::Drawing::Point(75, 45);
			this->txtImie->Margin = System::Windows::Forms::Padding(2);
			this->txtImie->Name = L"txtImie";
			this->txtImie->Size = System::Drawing::Size(102, 20);
			this->txtImie->TabIndex = 3;
			// 
			// Nazwisko
			// 
			this->Nazwisko->AutoSize = true;
			this->Nazwisko->Location = System::Drawing::Point(3, 76);
			this->Nazwisko->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Nazwisko->Name = L"Nazwisko";
			this->Nazwisko->Size = System::Drawing::Size(53, 13);
			this->Nazwisko->TabIndex = 13;
			this->Nazwisko->Text = L"Nazwisko";
			// 
			// Imiê
			// 
			this->Imiê->AutoSize = true;
			this->Imiê->Location = System::Drawing::Point(3, 48);
			this->Imiê->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Imiê->Name = L"Imiê";
			this->Imiê->Size = System::Drawing::Size(26, 13);
			this->Imiê->TabIndex = 1;
			this->Imiê->Text = L"Imiê";
			// 
			// TworzenieRezerwacjiForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(678, 465);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"TworzenieRezerwacjiForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tworzenie rezerwacji";
			this->Load += gcnew System::EventHandler(this, &TworzenieRezerwacjiForm::TworzenieRezerwacjiForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		// ZAPISZ-PRZYCISK
private: System::Void btnZapisz_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtImie->Text == "" || txtNazwisko->Text == "" || cmbTypPokoju->Text == "")
	{
		MessageBox::Show("Uzupe³nij dane!");
		return;
	}

	// DODAJ TEN WARUNEK:
	if (dtpDo->Value.Date < dtpOd->Value.Date)
	{
		MessageBox::Show("Data wyjazdu nie mo¿e byæ wczeœniejsza ni¿ data przyjazdu!");
		return;
	}

	Rezerwacja^ r = gcnew Rezerwacja();
	r->Imie = txtImie->Text;
	r->Nazwisko = txtNazwisko->Text;
	r->DataOd = dtpOd->Value;
	r->DataDo = dtpDo->Value;
	r->StanCzystosci = "Czysty";

	// wywo³ujemy przydzielenie pokoju po typie
	int przydzielonyPokoj = RezerwacjaService::ZnajdzWolnyPokojZTypu(cmbTypPokoju->Text, r->DataOd, r->DataDo);

	if (przydzielonyPokoj == -1)
	{
		MessageBox::Show(
			L"Niestety, brak wolnych pokoi typu " + cmbTypPokoju->Text + L" w podanym terminie!",
			L"Brak dostêpnoœci",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		return;
	}

	// przypisujemy wylosowany i wolny numer pokoju do rezerwacji
	r->Pokoj = przydzielonyPokoj;

	RezerwacjaService::Dodaj(r);

	MessageBox::Show("Utworzono rezerwacjê! System przydzieli³ pokój numer: " + przydzielonyPokoj.ToString(), L"Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);

	WyczyscFormularz();

}
	  // PRZYCISK_ANULUJ
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	WyczyscFormularz();
}
	   void WyczyscFormularz()
	   {
		   txtImie->Text = "";
		   txtNazwisko->Text = "";
		   cmbTypPokoju->SelectedIndex = -1;
		   dtpOd->Value = DateTime::Now;
		   dtpDo->MinDate = dtpOd->Value.Date; // Aktualizujemy limit
		   dtpDo->Value = DateTime::Now;
	   }
private: System::Void TworzenieRezerwacjiForm_Load(System::Object^ sender, System::EventArgs^ e) {
	dtpDo->MinDate = dtpOd->Value.Date;
}

private: System::Void dtpOd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	// Ustawia minimaln¹ datê w dtpDo na tê wybran¹ w dtpOd
	dtpDo->MinDate = dtpOd->Value.Date;
}
};
}
