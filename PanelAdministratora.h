#pragma once
#include "RezerwacjaService.h"
namespace AplikacjaHotelowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o PanelAministratora
	/// </summary>
	public ref class PanelAdministratora : public System::Windows::Forms::Form
	{
	public:
		PanelAdministratora(void)
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
		~PanelAdministratora()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbDzial;
	private: System::Windows::Forms::TextBox^ txtWiadomosc;
	private: System::Windows::Forms::Button^ btnDodajWiadomosc;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbDzial = (gcnew System::Windows::Forms::ComboBox());
			this->txtWiadomosc = (gcnew System::Windows::Forms::TextBox());
			this->btnDodajWiadomosc = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(267, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(489, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Panel Administratora";
			// 
			// cmbDzial
			// 
			this->cmbDzial->FormattingEnabled = true;
			this->cmbDzial->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Recepcja", L"Housekeeping", L"Manager", L"Serwis" });
			this->cmbDzial->Location = System::Drawing::Point(193, 150);
			this->cmbDzial->Name = L"cmbDzial";
			this->cmbDzial->Size = System::Drawing::Size(121, 33);
			this->cmbDzial->TabIndex = 1;
			// 
			// txtWiadomosc
			// 
			this->txtWiadomosc->Location = System::Drawing::Point(193, 237);
			this->txtWiadomosc->Multiline = true;
			this->txtWiadomosc->Name = L"txtWiadomosc";
			this->txtWiadomosc->Size = System::Drawing::Size(605, 407);
			this->txtWiadomosc->TabIndex = 2;
			// 
			// btnDodajWiadomosc
			// 
			this->btnDodajWiadomosc->Location = System::Drawing::Point(348, 678);
			this->btnDodajWiadomosc->Name = L"btnDodajWiadomosc";
			this->btnDodajWiadomosc->Size = System::Drawing::Size(280, 52);
			this->btnDodajWiadomosc->TabIndex = 3;
			this->btnDodajWiadomosc->Text = L"Dodaj wiadomoœæ";
			this->btnDodajWiadomosc->UseVisualStyleBackColor = true;
			this->btnDodajWiadomosc->Click += gcnew System::EventHandler(this, &PanelAdministratora::btnDodajWiadomosc_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(188, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Dzia³:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(193, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(190, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Treœæ wiadomoœci:";
			// 
			// PanelAdministratora
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 864);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnDodajWiadomosc);
			this->Controls->Add(this->txtWiadomosc);
			this->Controls->Add(this->cmbDzial);
			this->Controls->Add(this->label1);
			this->Name = L"PanelAdministratora";
			this->Text = L"PanelAdministratora";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
private: System::Void btnDodajWiadomosc_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(
		txtWiadomosc->Text))
	{
		MessageBox::Show(
			"Wpisz wiadomoœæ");

		return;
	}

	RezerwacjaService::DodajWiadomosc(
		cmbDzial->Text,
		txtWiadomosc->Text);

	MessageBox::Show(
		"Dodano wiadomoœæ");

	txtWiadomosc->Clear();
}
};
}
