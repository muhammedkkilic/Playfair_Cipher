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
	/// Encryption_Form için özet
	/// </summary>
	public ref class Encryption_Form : public System::Windows::Forms::Form
	{
	public:
		Encryption_Form(void)
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
		~Encryption_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:







	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;










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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(783, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(186, 27);
			this->button2->TabIndex = 32;
			this->button2->Text = L"PLAYFAIR CIPHER ENCRYPTÝON";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Encryption_Form::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(639, 58);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(600, 400);
			this->pictureBox2->TabIndex = 31;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 400);
			this->pictureBox1->TabIndex = 30;
			this->pictureBox1->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(601, 22);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(159, 20);
			this->textBox2->TabIndex = 29;
			this->textBox2->Text = L"KURTLAR VADISI";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(472, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Mesajý  Giriniz  :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(362, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 27;
			this->button1->Text = L"RESÝM SEÇ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Encryption_Form::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(161, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 26;
			this->textBox1->Text = L"CIPHER";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Gizli  Anahtarý  Giriniz : ";
			// 
			// Encryption_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1253, 472);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Encryption_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Encryption_Form";
			this->Load += gcnew System::EventHandler(this, &Encryption_Form::Encryption_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
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
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
	{
		MessageBox::Show("Lütfen Güvenlik Anahtarýný Giriniz");
		return;
	}
	if (openFileDialog1->FileName == "")
	{
		MessageBox::Show("Lütfen Görüntü Seçiniz");
		return;
	}
	if (textBox2->Text == "")
	{
		MessageBox::Show("Lütfen Mesaj Giriniz");
		return;
	}
	String^ secret_key = secret_key_belirle(textBox1->Text);
	String^ mesaj = textBox2->Text;

	LPCTSTR input;
	CString str;
	int Width, Height;
	long Size;

	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;

	BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
	BYTE* renkli = ConvertBMPToRGBdizi(buffer, Width, Height);

	playfair_cipher_encoder(renkli, Width, Height, mesaj, secret_key);

	Bitmap^ surface2 = gcnew Bitmap(Width, Height, Drawing::Imaging::PixelFormat::Format24bppRgb);
	pictureBox2->Image = surface2;
	Color c;
	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			c = Color::FromArgb(renkli[(row * 3) * Width + (column * 3 + 2)], renkli[(row * 3) * Width + (column * 3 + 1)], renkli[(row * 3) * Width + (column * 3)]);
			surface2->SetPixel(column, row, c);
		}
	}
	String^ path = openFileDialog1->FileName;
	String^ adr =  openFileDialog1->SafeFileName;
	int pozisyon = path->IndexOf(adr);
	String^ path2 = path->Substring(0, pozisyon);
	std::string path3 = msclr::interop::marshal_as<std::string>(path2);
	std::ofstream anahtar_yaz(path3+"key.txt");
	for (int i = 0; i < secret_key->Length; i++)
	{
		anahtar_yaz << ascii_to_harf(Convert::ToInt32(secret_key[i])) << std::endl;
	}
	path2 = path2 + "output.bmp";
	pictureBox2->Image->Save(path2, Drawing::Imaging::ImageFormat::Bmp);
	MessageBox::Show("\n Þifreleme Ýþlemi Baþarýlý \n Anahtar Kaydedildi \n Þifreli Görsel Kaydedildi! ");
}


private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->CharacterCasing = CharacterCasing::Upper;
	textBox2->SelectionStart = textBox2->Text->Length;
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = textBox1->Text->ToUpper();
	textBox1->SelectionStart = textBox1->Text->Length;
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void Encryption_Form_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
