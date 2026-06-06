#pragma once
#include "TworzenieRezerwacjiForm.h"
#include "RezerwacjaService.h"
#include "ZameldowaniaListaForm.h"
#include "WymeldowaniaListaForm.h"
#include "PobudkaService.h"
#include "PanelPokojuForm.h"
#include "StanCzystosciForm.h"
#include "ListaPokoiForm.h"
#include "DashboardService.h"
#include "PanelAdministratora.h"
using namespace Microsoft::VisualBasic;
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

		void OdswiezListePobudek()
		{
			dgvBudzenia->Rows->Clear();

			List<Pobudka^>^ lista =
				PobudkaService::PobierzWszystkie();

			for each (Pobudka ^ p in lista)
			{
				array<String^>^ row =
				{
					p->Pokoj.ToString(),
					p->Godzina,
					"Aktywna"
				};

				dgvBudzenia->Rows->Add(row);
			}
		}
		void OdswiezWiadomosci()
		{
			dgvWiadomosci->AutoGenerateColumns = true;

			dgvWiadomosci->DataSource =
				RezerwacjaService::PobierzWiadomosci();

			dgvWiadomosci->Columns["Dzial"]->HeaderText =
				"Dzia³";

			dgvWiadomosci->Columns["Tresc"]->HeaderText =
				"Treœæ";

			dgvWiadomosci->AutoSizeColumnsMode =
				DataGridViewAutoSizeColumnsMode::Fill;

			dgvWiadomosci->ReadOnly = true;

			dgvWiadomosci->AllowUserToAddRows =
				false;

			dgvWiadomosci->DefaultCellStyle->SelectionBackColor =
				dgvWiadomosci->DefaultCellStyle->BackColor;

			dgvWiadomosci->DefaultCellStyle->SelectionForeColor =
				dgvWiadomosci->DefaultCellStyle->ForeColor;

			dgvWiadomosci->ClearSelection();
			

		}
	public:
		Home(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			
			this->KeyPreview = true;
			
			// baza danych SQLite
			AplikacjaHotelowa::RezerwacjaService::InitializeBase();
			PobudkaService::InitializeBase();

			// konfiguracja kolumn wiadomoœci
			//this->dgvWiadomosci->ColumnCount = 3;
			//this->dgvWiadomosci->Columns[0]->Name = L"Data";
			//this->dgvWiadomosci->Columns[0]->Width = 80;
			//this->dgvWiadomosci->Columns[1]->Name = L"Dzia³";
			//this->dgvWiadomosci->Columns[1]->Width = 110;
			//this->dgvWiadomosci->Columns[2]->Name = L"Treœæ";
			//this->dgvWiadomosci->Columns[2]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			// konfiguracja kolumn budzeñ
			this->dgvBudzenia->ColumnCount = 3;
			this->dgvBudzenia->Columns[0]->Name = L"Pokój";
			this->dgvBudzenia->Columns[0]->Width = 70;
			this->dgvBudzenia->Columns[1]->Name = L"Godzina";
			this->dgvBudzenia->Columns[1]->Width = 90;
			this->dgvBudzenia->Columns[2]->Name = L"Status";
			this->dgvBudzenia->Columns[2]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

			OdswiezListePobudek();
			this->dateTimePicker1->ValueChanged +=
				gcnew System::EventHandler(
					this,
					&Home::dateTimePicker1_ValueChanged);
			OdswiezDashboard();
			OdswiezWiadomosci();

			
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
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ menuU¿ytkownikaToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ pobytToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ listaPokoiToolStripMenuItem;
	private: System::Windows::Forms::Label^ lblZameldowania;
		   System::Windows::Forms::Label^ lblWymeldowania;
		   System::Windows::Forms::Label^ lblGoscie;
		   System::Windows::Forms::Label^ lblWolnePokoje;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
private: System::Windows::Forms::ToolStripMenuItem^ administratorToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ wiadomoœciToolStripMenuItem;

		   System::Windows::Forms::ToolStripMenuItem^ panelPokojuToolStripMenuItem;


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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblZameldowania = (gcnew System::Windows::Forms::Label());
			this->lblDashboardTytul = (gcnew System::Windows::Forms::Label());
			this->lblWymeldowania = (gcnew System::Windows::Forms::Label());
			this->lblGoscie = (gcnew System::Windows::Forms::Label());
			this->lblWolnePokoje = (gcnew System::Windows::Forms::Label());
			this->lblWiadomosciTytul = (gcnew System::Windows::Forms::Label());
			this->dgvWiadomosci = (gcnew System::Windows::Forms::DataGridView());
			this->lblBudzeniaTytul = (gcnew System::Windows::Forms::Label());
			this->dgvBudzenia = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuU¿ytkownikaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pobytToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelPokojuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaPokoiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wiadomoœciToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panelDashboard->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWiadomosci))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudzenia))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->menuStrip1->SuspendLayout();
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
			// panelDashboard
			// 
			this->panelDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panelDashboard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDashboard->Controls->Add(this->dateTimePicker1);
			this->panelDashboard->Controls->Add(this->lblZameldowania);
			this->panelDashboard->Controls->Add(this->lblDashboardTytul);
			this->panelDashboard->Controls->Add(this->lblWymeldowania);
			this->panelDashboard->Controls->Add(this->lblGoscie);
			this->panelDashboard->Controls->Add(this->lblWolnePokoje);
			this->panelDashboard->Location = System::Drawing::Point(750, 12);
			this->panelDashboard->Name = L"panelDashboard";
			this->panelDashboard->Size = System::Drawing::Size(400, 300);
			this->panelDashboard->TabIndex = 8;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(100, 45);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(198, 25);
			this->dateTimePicker1->TabIndex = 4;
			// 
			// lblZameldowania
			// 
			this->lblZameldowania->AutoSize = true;
			this->lblZameldowania->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblZameldowania->ForeColor = System::Drawing::Color::White;
			this->lblZameldowania->Location = System::Drawing::Point(15, 81);
			this->lblZameldowania->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblZameldowania->Name = L"lblZameldowania";
			this->lblZameldowania->Size = System::Drawing::Size(141, 21);
			this->lblZameldowania->TabIndex = 0;
			this->lblZameldowania->Text = L"Zameldowania: 0";
			// 
			// lblDashboardTytul
			// 
			this->lblDashboardTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblDashboardTytul->ForeColor = System::Drawing::Color::White;
			this->lblDashboardTytul->Location = System::Drawing::Point(0, 8);
			this->lblDashboardTytul->Name = L"lblDashboardTytul";
			this->lblDashboardTytul->Size = System::Drawing::Size(400, 36);
			this->lblDashboardTytul->TabIndex = 0;
			this->lblDashboardTytul->Text = L"Panel informacyjny";
			this->lblDashboardTytul->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblWymeldowania
			// 
			this->lblWymeldowania->AutoSize = true;
			this->lblWymeldowania->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblWymeldowania->ForeColor = System::Drawing::Color::White;
			this->lblWymeldowania->Location = System::Drawing::Point(15, 135);
			this->lblWymeldowania->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblWymeldowania->Name = L"lblWymeldowania";
			this->lblWymeldowania->Size = System::Drawing::Size(147, 21);
			this->lblWymeldowania->TabIndex = 1;
			this->lblWymeldowania->Text = L"Wymeldowania: 0";
			// 
			// lblGoscie
			// 
			this->lblGoscie->AutoSize = true;
			this->lblGoscie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblGoscie->ForeColor = System::Drawing::Color::White;
			this->lblGoscie->Location = System::Drawing::Point(15, 186);
			this->lblGoscie->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblGoscie->Name = L"lblGoscie";
			this->lblGoscie->Size = System::Drawing::Size(77, 21);
			this->lblGoscie->TabIndex = 2;
			this->lblGoscie->Text = L"Goœcie: 0";
			// 
			// lblWolnePokoje
			// 
			this->lblWolnePokoje->AutoSize = true;
			this->lblWolnePokoje->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblWolnePokoje->ForeColor = System::Drawing::Color::White;
			this->lblWolnePokoje->Location = System::Drawing::Point(15, 240);
			this->lblWolnePokoje->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblWolnePokoje->Name = L"lblWolnePokoje";
			this->lblWolnePokoje->Size = System::Drawing::Size(134, 21);
			this->lblWolnePokoje->TabIndex = 3;
			this->lblWolnePokoje->Text = L"Wolne pokoje: 0";
			// 
			// lblWiadomosciTytul
			// 
			this->lblWiadomosciTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblWiadomosciTytul->Location = System::Drawing::Point(750, 322);
			this->lblWiadomosciTytul->Name = L"lblWiadomosciTytul";
			this->lblWiadomosciTytul->Size = System::Drawing::Size(750, 22);
			this->lblWiadomosciTytul->TabIndex = 9;
			this->lblWiadomosciTytul->Text = L"Wiadomoœci hotelu";
			// 
			// dgvWiadomosci
			// 
			this->dgvWiadomosci->AllowUserToAddRows = false;
			this->dgvWiadomosci->AllowUserToDeleteRows = false;
			this->dgvWiadomosci->BackgroundColor = System::Drawing::Color::White;
			this->dgvWiadomosci->ColumnHeadersHeight = 46;
			this->dgvWiadomosci->Location = System::Drawing::Point(750, 348);
			this->dgvWiadomosci->Name = L"dgvWiadomosci";
			this->dgvWiadomosci->ReadOnly = true;
			this->dgvWiadomosci->RowHeadersVisible = false;
			this->dgvWiadomosci->RowHeadersWidth = 82;
			this->dgvWiadomosci->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvWiadomosci->Size = System::Drawing::Size(400, 180);
			this->dgvWiadomosci->TabIndex = 10;
			// 
			// lblBudzeniaTytul
			// 
			this->lblBudzeniaTytul->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblBudzeniaTytul->Location = System::Drawing::Point(750, 538);
			this->lblBudzeniaTytul->Name = L"lblBudzeniaTytul";
			this->lblBudzeniaTytul->Size = System::Drawing::Size(400, 22);
			this->lblBudzeniaTytul->TabIndex = 11;
			this->lblBudzeniaTytul->Text = L"Lista budzeñ";
			// 
			// dgvBudzenia
			// 
			this->dgvBudzenia->AllowUserToAddRows = false;
			this->dgvBudzenia->AllowUserToDeleteRows = false;
			this->dgvBudzenia->BackgroundColor = System::Drawing::Color::White;
			this->dgvBudzenia->ColumnHeadersHeight = 46;
			this->dgvBudzenia->Location = System::Drawing::Point(750, 564);
			this->dgvBudzenia->Name = L"dgvBudzenia";
			this->dgvBudzenia->ReadOnly = true;
			this->dgvBudzenia->RowHeadersVisible = false;
			this->dgvBudzenia->RowHeadersWidth = 82;
			this->dgvBudzenia->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvBudzenia->Size = System::Drawing::Size(400, 159);
			this->dgvBudzenia->TabIndex = 12;
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
			this->pictureBox3->Location = System::Drawing::Point(12, 404);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(340, 200);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			//this->pictureBox3->Click += gcnew System::EventHandler(this, &Home::pictureBox3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(395, 404);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(340, 200);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuU¿ytkownikaToolStripMenuItem,
					this->administratorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(3, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1193, 24);
			this->menuStrip1->TabIndex = 13;
			// 
			// menuU¿ytkownikaToolStripMenuItem
			// 
			this->menuU¿ytkownikaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->pobytToolStripMenuItem,
					this->listaPokoiToolStripMenuItem
			});
			this->menuU¿ytkownikaToolStripMenuItem->Name = L"menuU¿ytkownikaToolStripMenuItem";
			this->menuU¿ytkownikaToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->menuU¿ytkownikaToolStripMenuItem->Text = L"Menu u¿ytkownika";
			// 
			// pobytToolStripMenuItem
			// 
			this->pobytToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->panelPokojuToolStripMenuItem });
			this->pobytToolStripMenuItem->Name = L"pobytToolStripMenuItem";
			this->pobytToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->pobytToolStripMenuItem->Text = L"Pobyt";
			// 
			// panelPokojuToolStripMenuItem
			// 
			this->panelPokojuToolStripMenuItem->Name = L"panelPokojuToolStripMenuItem";
			this->panelPokojuToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->panelPokojuToolStripMenuItem->Text = L"Panel pokoju";
			this->panelPokojuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Home::panelPokojuToolStripMenuItem_Click);
			// 
			// listaPokoiToolStripMenuItem
			// 
			this->listaPokoiToolStripMenuItem->Name = L"listaPokoiToolStripMenuItem";
			this->listaPokoiToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->listaPokoiToolStripMenuItem->Text = L"Lista pokoi";
			this->listaPokoiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Home::listaPokoiToolStripMenuItem_Click);
			// 
			// administratorToolStripMenuItem
			// 
			this->administratorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->wiadomoœciToolStripMenuItem });
			this->administratorToolStripMenuItem->Name = L"administratorToolStripMenuItem";
			this->administratorToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->administratorToolStripMenuItem->Text = L"Administrator";
			// 
			// wiadomoœciToolStripMenuItem
			// 
			this->wiadomoœciToolStripMenuItem->Name = L"wiadomoœciToolStripMenuItem";
			this->wiadomoœciToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->wiadomoœciToolStripMenuItem->Text = L"Dodaj wiadomoœæ";
			this->wiadomoœciToolStripMenuItem->Click += gcnew System::EventHandler(this, &Home::wiadomoœciToolStripMenuItem_Click);
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
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Home";
			this->Text = L"Strona g³ówna";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Home::Home_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panelDashboard->ResumeLayout(false);
			this->panelDashboard->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWiadomosci))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBudzenia))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void OdswiezDashboard()
		{
			DashboardStats^ stats =
				DashboardService::PobierzStatystyki(dateTimePicker1->Value);

			lblZameldowania->Text =
				L"Zameldowania dzisiaj: " +
				stats->liczbaZameldowan;

			lblWymeldowania->Text =
				L"Wymeldowania dzisiaj: " +
				stats->liczbaWymeldowan;

			lblGoscie->Text =
				L"Aktualni goœcie: " +
				stats->liczbaGosci;

			lblWolnePokoje->Text =
				L"Wolne pokoje: " +
				stats->liczbaWolnychPokoi;
		}
	private:
		System::Void btnZameldowania_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ZameldowaniaListaForm^ listaForm = gcnew ZameldowaniaListaForm();
			listaForm->ShowDialog();
			OdswiezDashboard();
		}

		System::Void btnWymeldowania_Click(System::Object^ sender, System::EventArgs^ e)
		{
			WymeldowaniaListaForm^ wymeldowaniaForm = gcnew WymeldowaniaListaForm();
			wymeldowaniaForm->ShowDialog();
			OdswiezDashboard();
		}

		System::Void btnCzystosc_Click(System::Object^ sender, System::EventArgs^ e)
		{
			StanCzystosciForm^ form = gcnew StanCzystosciForm();
			form->ShowDialog();
		}

		System::Void btnRezerwacje_Click(System::Object^ sender, System::EventArgs^ e)
		{
			TworzenieRezerwacjiForm^ form = gcnew TworzenieRezerwacjiForm();
			form->ShowDialog();
		}
	private: System::Void panelPokojuToolStripMenuItem_Click(
		System::Object^ sender,
		System::EventArgs^ e)

	{
		PanelPokojuForm^ form =
			gcnew PanelPokojuForm(1);

		form->ShowDialog();

		OdswiezListePobudek();
		OdswiezDashboard();
		
	}

	private: System::Void listaPokoiToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		ListaPokoiForm^ form = gcnew ListaPokoiForm();
		form->ShowDialog();
		OdswiezDashboard();
	}
		   private:
			   System::Void dateTimePicker1_ValueChanged(
				   System::Object^ sender,
				   System::EventArgs^ e)
			   {
				   OdswiezDashboard();
				   this->ActiveControl = nullptr;
			   }

private: System::Void wiadomoœciToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	PanelAdministratora^ panel =
		gcnew PanelAdministratora();

	panel->ShowDialog();
	OdswiezDashboard();
	OdswiezWiadomosci();
}

private: System::Void Home_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	// Wciœniêcie R - otwieramy tworzenie rezerwacji
	if (e->KeyCode == Keys::R) {
		btnRezerwacje_Click(sender, e);
	}
	// Z - otwieramy zameldowania
	else if (e->KeyCode == Keys::Z) {
		btnZameldowania_Click(sender, e);
	}
	// W - otwiera wymeldowania
	else if (e->KeyCode == Keys::W) {
		btnWymeldowania_Click(sender, e);
	}
	// C - otwieramy stan czystoœci
	else if (e->KeyCode == Keys::C) {
		btnCzystosc_Click(sender, e);
	}
	// P - lista pokoi
	else if (e->KeyCode == Keys::P) {
		listaPokoiToolStripMenuItem_Click(sender, e);
	}
	// A - panel administratora (wiadomoœci hotelowe)
	else if (e->KeyCode == Keys::A) {
		wiadomoœciToolStripMenuItem_Click(sender, e);
	}
}
};
}
