#pragma once
#include "Encryption_Form.h"
#include "Decryption_Form.h"
#include <cstddef>
namespace PlayfairCipher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ playfairEncryptionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ encryptionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ decryptionToolStripMenuItem;

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->playfairEncryptionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->encryptionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decryptionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->playfairEncryptionToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1275, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// playfairEncryptionToolStripMenuItem
			// 
			this->playfairEncryptionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->encryptionToolStripMenuItem,
					this->decryptionToolStripMenuItem
			});
			this->playfairEncryptionToolStripMenuItem->Name = L"playfairEncryptionToolStripMenuItem";
			this->playfairEncryptionToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->playfairEncryptionToolStripMenuItem->Text = L"Playfair";
			// 
			// encryptionToolStripMenuItem
			// 
			this->encryptionToolStripMenuItem->Name = L"encryptionToolStripMenuItem";
			this->encryptionToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->encryptionToolStripMenuItem->Text = L"Encryption";
			this->encryptionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::encryptionToolStripMenuItem_Click);
			// 
			// decryptionToolStripMenuItem
			// 
			this->decryptionToolStripMenuItem->Name = L"decryptionToolStripMenuItem";
			this->decryptionToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->decryptionToolStripMenuItem->Text = L"Decryption";
			this->decryptionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::decryptionToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1275, 472);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void encryptionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (Application::OpenForms["Decryption_Form"])
		{
			Application::OpenForms["Decryption_Form"]->Close();
		}
		if (!Application::OpenForms["Encryption_Form"])
		{
			Encryption_Form^ encryption_form = gcnew Encryption_Form();
			encryption_form->MdiParent = this;
			encryption_form->Left = 0;
			encryption_form->Top = 0;
			Drawing::Rectangle^ recNew = gcnew Drawing::Rectangle();
			recNew = this->ClientRectangle;
			recNew->Height -= 30;
			recNew->Width -= 5;
			encryption_form->Size = recNew->Size;
			encryption_form->Show();
		}

	}
	private: System::Void decryptionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (Application::OpenForms["Encryption_Form"])
		{
			Application::OpenForms["Encryption_Form"]->Close();
		}
		if (!Application::OpenForms["Decryption_Form"])
		{
			Decryption_Form^ decryption_form = gcnew Decryption_Form();
			decryption_form->MdiParent = this;
			decryption_form->Left = 0;
			decryption_form->Top = 0;
			Drawing::Rectangle^ recNew = gcnew Drawing::Rectangle();
			recNew = this->ClientRectangle;
			recNew->Height -= 30;
			recNew->Width -= 5;
			decryption_form->Size = recNew->Size;
			decryption_form->Show();
		}
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	if (Application::OpenForms["Decryption_Form"])
	{
		Application::OpenForms["Decryption_Form"]->Close();
	}
	if (!Application::OpenForms["Encryption_Form"])
	{
		Encryption_Form^ encryption_form = gcnew Encryption_Form();
		encryption_form->MdiParent = this;
		encryption_form->Left = 0;
		encryption_form->Top = 0;
		Drawing::Rectangle^ recNew = gcnew Drawing::Rectangle();
		recNew = this->ClientRectangle;
		recNew->Height -= 30;
		recNew->Width -= 5;
		encryption_form->Size = recNew->Size;
		encryption_form->Show();
	}
}
};
}
