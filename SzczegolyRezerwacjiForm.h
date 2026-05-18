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

	public ref class SzczegolyRezerwacjiForm : public System::Windows::Forms::Form
	{
	private:
		int idRezerwacji;
		Rezerwacja^ rezerwacja;

	public:
		SzczegolyRezerwacjiForm(int id)
		{
			InitializeComponent();
			idRezerwacji = id;
			WczytajDaneGoscia();
		}

	protected:
		~SzczegolyRezerwacjiForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelTop;
	private: System::Windows::Forms::Label^ lblTytul;
	private: System::Windows::Forms::GroupBox^ groupInformacje;
	private: System::Windows::Forms::GroupBox^ groupMeldunek;
	private: System::Windows::Forms::Label^ lblGosc;
	private: System::Windows::Forms::Label^ lblPokoj;
	private: System::Windows::Forms::Label^ lblStatus;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelIloscGosci;
	private: System::Windows::Forms::NumericUpDown^ numIloscGosci;
	private: System::Windows::Forms::ComboBox^ cmbTypDokumentu;
	private: System::Windows::Forms::TextBox^ txtNrDokumentu;
	private: System::Windows::Forms::ComboBox^ cmbPlatnosc;
	private: System::Windows::Forms::NumericUpDown^ numKwota;
	private: System::Windows::Forms::Button^ btnZapisz;
	private: System::Windows::Forms::Button^ btnZamelduj;
	private: System::Windows::Forms::Button^ btnWymelduj;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->panelTop = (gcnew System::Windows::Forms::Panel());
			   this->lblTytul = (gcnew System::Windows::Forms::Label());
			   this->groupInformacje = (gcnew System::Windows::Forms::GroupBox());
			   this->groupMeldunek = (gcnew System::Windows::Forms::GroupBox());
			   this->lblGosc = (gcnew System::Windows::Forms::Label());
			   this->lblPokoj = (gcnew System::Windows::Forms::Label());
			   this->lblStatus = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->labelIloscGosci = (gcnew System::Windows::Forms::Label());
			   this->numIloscGosci = (gcnew System::Windows::Forms::NumericUpDown());
			   this->cmbTypDokumentu = (gcnew System::Windows::Forms::ComboBox());
			   this->txtNrDokumentu = (gcnew System::Windows::Forms::TextBox());
			   this->cmbPlatnosc = (gcnew System::Windows::Forms::ComboBox());
			   this->numKwota = (gcnew System::Windows::Forms::NumericUpDown());
			   this->btnZapisz = (gcnew System::Windows::Forms::Button());
			   this->btnZamelduj = (gcnew System::Windows::Forms::Button());
			   this->btnWymelduj = (gcnew System::Windows::Forms::Button());

			   this->panelTop->SuspendLayout();
			   this->groupInformacje->SuspendLayout();
			   this->groupMeldunek->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numIloscGosci))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numKwota))->BeginInit();
			   this->SuspendLayout();

			   // panelTop
			   this->panelTop->BackColor = System::Drawing::Color::FromArgb(52, 73, 94); 
			   this->panelTop->Controls->Add(this->lblTytul);
			   this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
			   this->panelTop->Height = 70;

			   // lblTytul
			   this->lblTytul->AutoSize = true;
			   this->lblTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			   this->lblTytul->ForeColor = System::Drawing::Color::White;
			   this->lblTytul->Location = System::Drawing::Point(20, 18);
			   this->lblTytul->Text = L"Zarz¹dzanie Rezerwacj¹";

			   // groupInformacje
			   this->groupInformacje->Controls->Add(this->lblGosc);
			   this->groupInformacje->Controls->Add(this->lblPokoj);
			   this->groupInformacje->Controls->Add(this->lblStatus);
			   this->groupInformacje->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->groupInformacje->Location = System::Drawing::Point(25, 90);
			   this->groupInformacje->Size = System::Drawing::Size(430, 130);
			   this->groupInformacje->Text = L"Informacje ogólne";

			   // groupMeldunek
			   this->groupMeldunek->Controls->Add(this->labelIloscGosci);
			   this->groupMeldunek->Controls->Add(this->numIloscGosci);
			   this->groupMeldunek->Controls->Add(this->label1);
			   this->groupMeldunek->Controls->Add(this->cmbTypDokumentu);
			   this->groupMeldunek->Controls->Add(this->label2);
			   this->groupMeldunek->Controls->Add(this->txtNrDokumentu);
			   this->groupMeldunek->Controls->Add(this->label3);
			   this->groupMeldunek->Controls->Add(this->cmbPlatnosc);
			   this->groupMeldunek->Controls->Add(this->label4);
			   this->groupMeldunek->Controls->Add(this->numKwota);
			   this->groupMeldunek->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->groupMeldunek->Location = System::Drawing::Point(25, 240);
			   this->groupMeldunek->Size = System::Drawing::Size(430, 260);
			   this->groupMeldunek->Text = L"Dane meldunkowe i p³atnoœæ";

			   // Elementy w groupInformacje
			   this->lblGosc->AutoSize = true;
			   this->lblGosc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			   this->lblGosc->Location = System::Drawing::Point(20, 35);
			   this->lblGosc->Text = L"Goœæ: ";

			   this->lblPokoj->AutoSize = true;
			   this->lblPokoj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			   this->lblPokoj->Location = System::Drawing::Point(20, 65);
			   this->lblPokoj->Text = L"Pokój: ";

			   this->lblStatus->AutoSize = true;
			   this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			   this->lblStatus->Location = System::Drawing::Point(20, 95);
			   this->lblStatus->Text = L"Status: ";

			   // Elementy w groupMeldunek
			   // Iloœæ goœci
			   this->labelIloscGosci->AutoSize = true;
			   this->labelIloscGosci->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->labelIloscGosci->Location = System::Drawing::Point(20, 40);
			   this->labelIloscGosci->Text = L"Iloœæ osób:";
			   this->numIloscGosci->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->numIloscGosci->Location = System::Drawing::Point(170, 38);
			   this->numIloscGosci->Minimum = 1;
			   this->numIloscGosci->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 }); // maks 4 osoby
			   this->numIloscGosci->Value = 1;
			   this->numIloscGosci->Size = System::Drawing::Size(230, 27);

			   // Typ dokumentu
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->label1->Location = System::Drawing::Point(20, 85);
			   this->label1->Text = L"Typ dokumentu:";
			   this->cmbTypDokumentu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->cmbTypDokumentu->FormattingEnabled = true;
			   this->cmbTypDokumentu->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Dowód osobisty", L"Paszport" });
			   this->cmbTypDokumentu->Location = System::Drawing::Point(170, 82);
			   this->cmbTypDokumentu->Size = System::Drawing::Size(230, 28);

			   // Nr dokumentu
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->label2->Location = System::Drawing::Point(20, 130);
			   this->label2->Text = L"Nr dokumentu:";
			   this->txtNrDokumentu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->txtNrDokumentu->Location = System::Drawing::Point(170, 127);
			   this->txtNrDokumentu->Size = System::Drawing::Size(230, 27);

			   // Metoda p³atnoœci
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->label3->Location = System::Drawing::Point(20, 175);
			   this->label3->Text = L"Metoda p³atnoœci:";
			   this->cmbPlatnosc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->cmbPlatnosc->FormattingEnabled = true;
			   this->cmbPlatnosc->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Karta", L"Gotówka", L"Przelew" });
			   this->cmbPlatnosc->Location = System::Drawing::Point(170, 172);
			   this->cmbPlatnosc->Size = System::Drawing::Size(230, 28);

			   // Kwota
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->label4->Location = System::Drawing::Point(20, 220);
			   this->label4->Text = L"Kwota (PLN):";
			   this->numKwota->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			   this->numKwota->DecimalPlaces = 2;
			   this->numKwota->Location = System::Drawing::Point(170, 218);
			   this->numKwota->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			   this->numKwota->Size = System::Drawing::Size(230, 27);

			   // Przycisk Zapisz
			   this->btnZapisz->BackColor = System::Drawing::Color::FromArgb(189, 195, 199);
			   this->btnZapisz->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnZapisz->FlatAppearance->BorderSize = 0;
			   this->btnZapisz->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->btnZapisz->Location = System::Drawing::Point(25, 520);
			   this->btnZapisz->Size = System::Drawing::Size(130, 45);
			   this->btnZapisz->Text = L"Zapisz zmiany";
			   this->btnZapisz->UseVisualStyleBackColor = false;
			   this->btnZapisz->Click += gcnew System::EventHandler(this, &SzczegolyRezerwacjiForm::btnZapisz_Click);

			   // Przycisk Zamelduj
			   this->btnZamelduj->BackColor = System::Drawing::Color::FromArgb(46, 204, 113); 
			   this->btnZamelduj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnZamelduj->FlatAppearance->BorderSize = 0;
			   this->btnZamelduj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->btnZamelduj->ForeColor = System::Drawing::Color::White;
			   this->btnZamelduj->Location = System::Drawing::Point(175, 520);
			   this->btnZamelduj->Size = System::Drawing::Size(130, 45);
			   this->btnZamelduj->Text = L"Zamelduj";
			   this->btnZamelduj->UseVisualStyleBackColor = false;
			   this->btnZamelduj->Click += gcnew System::EventHandler(this, &SzczegolyRezerwacjiForm::btnZamelduj_Click);

			   // Przycisk Wymelduj
			   this->btnWymelduj->BackColor = System::Drawing::Color::FromArgb(231, 76, 60); 
			   this->btnWymelduj->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnWymelduj->FlatAppearance->BorderSize = 0;
			   this->btnWymelduj->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			   this->btnWymelduj->ForeColor = System::Drawing::Color::White;
			   this->btnWymelduj->Location = System::Drawing::Point(325, 520);
			   this->btnWymelduj->Size = System::Drawing::Size(130, 45);
			   this->btnWymelduj->Text = L"Wymelduj";
			   this->btnWymelduj->UseVisualStyleBackColor = false;
			   this->btnWymelduj->Click += gcnew System::EventHandler(this, &SzczegolyRezerwacjiForm::btnWymelduj_Click);

			   // SzczegolyRezerwacjiForm
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(480, 590);
			   this->Controls->Add(this->btnWymelduj);
			   this->Controls->Add(this->btnZamelduj);
			   this->Controls->Add(this->btnZapisz);
			   this->Controls->Add(this->groupMeldunek);
			   this->Controls->Add(this->groupInformacje);
			   this->Controls->Add(this->panelTop);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"SzczegolyRezerwacjiForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Szczegó³y rezerwacji";

			   this->panelTop->ResumeLayout(false);
			   this->panelTop->PerformLayout();
			   this->groupInformacje->ResumeLayout(false);
			   this->groupInformacje->PerformLayout();
			   this->groupMeldunek->ResumeLayout(false);
			   this->groupMeldunek->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numIloscGosci))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numKwota))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private:
		void WczytajDaneGoscia() {
			rezerwacja = RezerwacjaService::PobierzPoId(idRezerwacji);

			if (rezerwacja != nullptr) {
				lblGosc->Text = L"Goœæ: " + rezerwacja->Imie + L" " + rezerwacja->Nazwisko;
				String^ typPokoju = RezerwacjaService::PobierzTypDlaNumeruPokoju(rezerwacja->Pokoj);
				lblPokoj->Text = L"Pokój: " + rezerwacja->Pokoj.ToString() + " (" + typPokoju + ")";

				if (rezerwacja->StatusRezerwacji == L"Oczekujaca") {
					lblStatus->Text = L"Status: Oczekuj¹ca";
				}
				else {
					lblStatus->Text = L"Status: " + rezerwacja->StatusRezerwacji;
				}

				cmbTypDokumentu->Text = rezerwacja->TypDokumentu;
				txtNrDokumentu->Text = rezerwacja->NrDokumentu;
				cmbPlatnosc->Text = rezerwacja->MetodaPlatnosci;
				numKwota->Value = System::Decimal(rezerwacja->Kwota);
				numIloscGosci->Value = System::Decimal(rezerwacja->IloscGosci);

				// Logika przycisków
				if (rezerwacja->StatusRezerwacji == L"Oczekujaca") {
					btnZamelduj->Enabled = true;
					btnWymelduj->Enabled = false;
					btnZapisz->Enabled = true;
				}
				else if (rezerwacja->StatusRezerwacji == L"Zameldowany") {
					btnZamelduj->Enabled = false;
					btnWymelduj->Enabled = true;
					btnZapisz->Enabled = true;
				}
				else {
					btnZamelduj->Enabled = false;
					btnWymelduj->Enabled = false;
					btnZapisz->Enabled = false;
				}
			}
		}

		void PrzepiszDaneDoObiektu() {
			rezerwacja->TypDokumentu = cmbTypDokumentu->Text;
			rezerwacja->NrDokumentu = txtNrDokumentu->Text;
			rezerwacja->MetodaPlatnosci = cmbPlatnosc->Text;
			rezerwacja->Kwota = Convert::ToDouble(numKwota->Value);
			rezerwacja->IloscGosci = Convert::ToInt32(numIloscGosci->Value);
		}

		System::Void btnZapisz_Click(System::Object^ sender, System::EventArgs^ e) {
			PrzepiszDaneDoObiektu();
			RezerwacjaService::Aktualizuj(rezerwacja);
			MessageBox::Show(L"Dane zosta³y zaktualizowane w bazie danych.", L"Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

		System::Void btnZamelduj_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cmbTypDokumentu->Text == "" || txtNrDokumentu->Text == "") {
				MessageBox::Show(L"Aby zameldowaæ goœcia, musisz najpierw uzupe³niæ dane z dokumentu to¿samoœci!", L"Brak danych", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			PrzepiszDaneDoObiektu();
			rezerwacja->StatusRezerwacji = L"Zameldowany";
			RezerwacjaService::Aktualizuj(rezerwacja);

			MessageBox::Show(L"Goœæ zosta³ pomyœlnie zameldowany w pokoju!", L"Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

		System::Void btnWymelduj_Click(System::Object^ sender, System::EventArgs^ e) {
			rezerwacja->StatusRezerwacji = L"Wymeldowany";
			RezerwacjaService::Aktualizuj(rezerwacja);

			MessageBox::Show(L"Goœæ zosta³ pomyœlnie wymeldowany. Pokój zosta³ zwolniony.", L"Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}