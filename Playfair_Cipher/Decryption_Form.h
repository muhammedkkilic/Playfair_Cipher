#pragma once
#include "atlstr.h"
#include <iomanip>
#include "imge_bmp.h"
#include <string>
#include <bitset>
#include <string>
#include "fonksiyonlar.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
namespace PlayfairCipher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Decryption_Form için özet
	/// </summary>
	public ref class Decryption_Form : public System::Windows::Forms::Form
	{
	public:
		Decryption_Form(void)
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
		~Decryption_Form()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;










	protected:

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(805, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Gelen Mesaj : ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(889, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 20);
			this->textBox1->TabIndex = 29;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(507, 8);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(191, 33);
			this->button3->TabIndex = 28;
			this->button3->Text = L"PLAYFAIR CIPHER DECRYPTÝON";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Decryption_Form::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(77, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 400);
			this->pictureBox1->TabIndex = 27;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(395, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 33);
			this->button2->TabIndex = 26;
			this->button2->Text = L"RESÝM SEÇ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Decryption_Form::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(211, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 33);
			this->button1->TabIndex = 25;
			this->button1->Text = L"SECRET KEY YÜKLE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Decryption_Form::button1_Click);
			// 
			// Decryption_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1253, 472);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Decryption_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Decryption_Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ dizi;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			LPCTSTR input;
			int Width, Height;
			long Size;
			CString str;
			str = openFileDialog2->FileName;
			input = (LPCTSTR)str;
			std::string adres = msclr::interop::marshal_as<std::string>(openFileDialog2->FileName);
			std::fstream secret_key_oku(adres);
			int i = 0;
			std::string yeni;
			while (i<25)
			{

				secret_key_oku >> yeni;
				String^ yeni_s = gcnew String(yeni.c_str());
				dizi = dizi + yeni_s;
				i = i + 1;
			}
			button1->Enabled = false;
			MessageBox::Show("Secret Key Yüklendi");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			LPCTSTR input;
			int Width, Height;
			long Size;
			CString str;
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			this->pictureBox1->ImageLocation = openFileDialog1->FileName;
		}
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	LPCTSTR input;
	CString str;
	int Width, Height;
	long Size;

	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;
	BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
	BYTE* renkli = ConvertBMPToRGBdizi(buffer, Width, Height);
	String^ sonuc = playfair_cipher_decoder(renkli, Width, Height, dizi);
	textBox1->Text = sonuc;
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
