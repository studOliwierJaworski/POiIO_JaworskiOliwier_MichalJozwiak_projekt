#pragma once
#include "TworzenieRezerwacjiForm.h"

namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			// konfiguracja kolumn wiadomoœci
			this->dgvWiadomosci->ColumnCount = 3;
			this->dgvWiadomosci->Columns[0]->Name = L"Data";
			this->dgvWiadomosci->Columns[0]->Width = 80;
			this->dgvWiadomosci->Columns[1]->Name = L"Dzia³";
			this->dgvWiadomosci->Columns[1]->Width = 110;
			this->dgvWiadomosci->Columns[2]->Name = L"Treœæ";
			this->dgvWiadomosci->Columns[2]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			// konfiguracja kolumn budzeñ
			this->dgvBudzenia->ColumnCount = 3;
			this->dgvBudzenia->Columns[0]->Name = L"Pokój";
			this->dgvBudzenia->Columns[0]->Width = 70;
			this->dgvBudzenia->Columns[1]->Name = L"Godzina";
			this->dgvBudzenia->Columns[1]->Width = 90;
			this->dgvBudzenia->Columns[2]->Name = L"Status";
			this->dgvBudzenia->Columns[2]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: 
		   System::Windows::Forms::PictureBox^ pictureBox2;
		   System::Windows::Forms::Button^ btnRezerwacje;
		   System::ComponentModel::Container^ components;
		   System::Windows::Forms::PictureBox^ pictureBox1;
		   System::Windows::Forms::Button^ btnZameldowania;
		   System::Windows::Forms::Button^ btnWymeldowania;
		   System::Windows::Forms::PictureBox^ pictureBox3;
	       System::Windows::Forms::PictureBox^ pictureBox4;
		   System::Windows::Forms::Button^ btnCzystosc;

		   System::Windows::Forms::Panel^ panelDashboard;
		   System::Windows::Forms::Label^ lblDashboardTytul;

		   System::Windows::Forms::Label^ lblWiadomosciTytul;
		   System::Windows::Forms::DataGridView^ dgvWiadomosci;

		   System::Windows::Forms::Label^ lblBudzeniaTytul;
		   System::Windows::Forms::DataGridView^ dgvBudzenia;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->btnZameldowania = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnWymeldowania = (gcnew System::Windows::Forms::Button());
			this->btnCzystosc = (gcnew System::Windows::Forms::Button());
			this->btnRezerwacje = (gcnew System::Windows::Forms::Button());
			this->panelDashboard = (gcnew System::Windows::Forms::Panel());
			this->lblDashboardTytul = (gcnew System::Windows::Forms::Label());
			this->lblWiadomosciTytul = (gcnew System::Windows::Forms::Label());
			this->dgvWiadomosci = (gcnew System::Windows::Forms::DataGridView());
			this->lblBudzeniaTytul = (gcnew System::Windows::Forms::Label());
			this->dgvBudzenia = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWiadomosci))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudzenia))->BeginInit();
			this->SuspendLayout();
			// 
			// btnZameldowania
			// 
			this->btnZameldowania->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnZameldowania->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnZameldowania->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnZameldowania->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZameldowania->ForeColor = System::Drawing::Color::White;
			this->btnZameldowania->Location = System::Drawing::Point(12, 272);
			this->btnZameldowania->Name = L"btnZameldowania";
			this->btnZameldowania->Size = System::Drawing::Size(340, 57);
			this->btnZameldowania->TabIndex = 0;
			this->btnZameldowania->Text = L"Zameldowania";
			this->btnZameldowania->UseVisualStyleBackColor = false;
			this->btnZameldowania->Click += gcnew System::EventHandler(this, &Home::btnZameldowania_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(340, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btnWymeldowania
			// 
			this->btnWymeldowania->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnWymeldowania->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnWymeldowania->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnWymeldowania->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnWymeldowania->ForeColor = System::Drawing::Color::White;
			this->btnWymeldowania->Location = System::Drawing::Point(395, 272);
			this->btnWymeldowania->Name = L"btnWymeldowania";
			this->btnWymeldowania->Size = System::Drawing::Size(340, 57);
			this->btnWymeldowania->TabIndex = 2;
			this->btnWymeldowania->Text = L"Wymeldowania";
			this->btnWymeldowania->UseVisualStyleBackColor = false;
			this->btnWymeldowania->Click += gcnew System::EventHandler(this, &Home::btnWymeldowania_Click);

			// 
			// btnCzystosc
			// 
			this->btnCzystosc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnCzystosc->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCzystosc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCzystosc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnCzystosc->ForeColor = System::Drawing::Color::White;
			this->btnCzystosc->Location = System::Drawing::Point(12, 623);
			this->btnCzystosc->Name = L"btnCzystosc";
			this->btnCzystosc->Size = System::Drawing::Size(340, 57);
			this->btnCzystosc->TabIndex = 4;
			this->btnCzystosc->Text = L"Stan czystoœci pokoi";
			this->btnCzystosc->UseVisualStyleBackColor = false;
			this->btnCzystosc->Click += gcnew System::EventHandler(this, &Home::btnCzystosc_Click);
			// 
			// btnRezerwacje
			// 
			this->btnRezerwacje->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnRezerwacje->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRezerwacje->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRezerwacje->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRezerwacje->ForeColor = System::Drawing::Color::White;
			this->btnRezerwacje->Location = System::Drawing::Point(395, 623);
			this->btnRezerwacje->Name = L"btnRezerwacje";
			this->btnRezerwacje->Size = System::Drawing::Size(340, 57);
			this->btnRezerwacje->TabIndex = 5;
			this->btnRezerwacje->Text = L"Rezerwacje";
			this->btnRezerwacje->UseVisualStyleBackColor = false;
			this->btnRezerwacje->Click += gcnew System::EventHandler(this, &Home::btnRezerwacje_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(395, 39);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(340, 200);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 422);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(340, 200);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(395, 422);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(340, 200);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;

			//
			// panelDashboard
			//
			this->panelDashboard->Location = System::Drawing::Point(750, 12);
			this->panelDashboard->Name = L"panelDashboard";
			this->panelDashboard->Size = System::Drawing::Size(400, 300);
			this->panelDashboard->BackColor = System::Drawing::Color::FromArgb(52, 73, 94);
			this->panelDashboard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			//
			// lblDashboardTytul
			//
			this->lblDashboardTytul->Location = System::Drawing::Point(0, 8);
			this->lblDashboardTytul->Size = System::Drawing::Size(400 - 2, 36);
			this->lblDashboardTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblDashboardTytul->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblDashboardTytul->ForeColor = System::Drawing::Color::White;
			this->lblDashboardTytul->Text = L"Panel informacyjny";
			this->panelDashboard->Controls->Add(this->lblDashboardTytul);






			//
			// lblWiadomosciTytul
			//
			this->lblWiadomosciTytul->Location = System::Drawing::Point(750, 322);
			this->lblWiadomosciTytul->Size = System::Drawing::Size(750, 22);
			this->lblWiadomosciTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblWiadomosciTytul->Text = L"Wiadomoœci hotelu";

			//
			// dgvWiadomosci
			//
			this->dgvWiadomosci->Location = System::Drawing::Point(750, 348);
			this->dgvWiadomosci->Size = System::Drawing::Size(400, 180);
			this->dgvWiadomosci->Name = L"dgvWiadomosci";
			this->dgvWiadomosci->AllowUserToAddRows = false;
			this->dgvWiadomosci->AllowUserToDeleteRows = false;
			this->dgvWiadomosci->ReadOnly = true;
			this->dgvWiadomosci->RowHeadersVisible = false;
			this->dgvWiadomosci->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvWiadomosci->BackgroundColor = System::Drawing::Color::White;


			//
			// lblBudzeniaTytul
			//
			this->lblBudzeniaTytul->Location = System::Drawing::Point(750, 538);
			this->lblBudzeniaTytul->Size = System::Drawing::Size(400, 22);
			this->lblBudzeniaTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblBudzeniaTytul->Text = L"Lista budzeñ";

			//
			// dgvBudzenia
			//
			this->dgvBudzenia->Location = System::Drawing::Point(750, 564);
			this->dgvBudzenia->Size = System::Drawing::Size(400, 159);
			this->dgvBudzenia->Name = L"dgvBudzenia";
			this->dgvBudzenia->AllowUserToAddRows = false;
			this->dgvBudzenia->AllowUserToDeleteRows = false;
			this->dgvBudzenia->ReadOnly = true;
			this->dgvBudzenia->RowHeadersVisible = false;
			this->dgvBudzenia->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvBudzenia->BackgroundColor = System::Drawing::Color::White;

			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1193, 735);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnZameldowania);
			this->Controls->Add(this->btnWymeldowania);
			this->Controls->Add(this->btnCzystosc);
			this->Controls->Add(this->btnRezerwacje);
			this->Controls->Add(this->panelDashboard);
			this->Controls->Add(this->lblWiadomosciTytul);
			this->Controls->Add(this->dgvWiadomosci);
			this->Controls->Add(this->lblBudzeniaTytul);
			this->Controls->Add(this->dgvBudzenia);
			this->Name = L"Home";
			this->Text = L"Strona g³ówna";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWiadomosci))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudzenia))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void btnZameldowania_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(L"Modu³ zameldowañ - w przygotowaniu.", L"Zameldowania", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		
		System::Void btnWymeldowania_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(L"Modu³ wymeldowañ - w przygotowaniu.", L"Wymeldowania", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		System::Void btnCzystosc_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(L"Stan czystoœci pokoi - w przygotowaniu.",L"Czystoœæ pokoi", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		System::Void btnRezerwacje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			TworzenieRezerwacjiForm^ form = gcnew TworzenieRezerwacjiForm();
			form->ShowDialog();
		}


};
}
