using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
#include <math.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

String^ secret_key_belirle(String^ key)
{
	String^ alfabe = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	String^ secret_key;
	int adet;
	for (int a = 0; a < key->Length; a++)
	{
		secret_key = secret_key + key[a];
		for (int b = 0; b < alfabe->Length; b++)
		{
			if (key[a] == alfabe[b])
			{
				alfabe = alfabe->Remove(b,1);
			}
		}
		adet = adet + 1;
	}
	int random;
	while(alfabe->Length > 0)
	{
		srand(time(0));
		random = rand() % alfabe->Length;
		secret_key = secret_key + alfabe[random];
		alfabe = alfabe->Remove(random, 1);
		adet = adet + 1;
	}
	return secret_key;
}

int binary_to_ascii(String^ gelen)
{
	int sonuc = 0;
	for (int a = 0; a < 8; a++)
	{
		sonuc = sonuc + ((Convert::ToChar(gelen[a]) - 48) *pow(2,8-1-a));
	}
	return sonuc;
}
char ascii_to_harf(int gelen)
{
	char karakter = (char)gelen;
	return karakter;
}

String^ mesaj_padding(String^ mesaj)
{
	int mesaj_uzunluk = mesaj->Length;
	String^ modify_mesaj;
	char karakter = mesaj[0];
	for (int i = 0; i < mesaj_uzunluk; i++)
	{
		if (mesaj[i] != ' ')
		{
			if (i != 0 && karakter == mesaj[i])
			{
				modify_mesaj = modify_mesaj + "X";
			}
			karakter = mesaj[i];
			modify_mesaj = modify_mesaj + mesaj[i];
		}
	}
	int modify_mesaj_uzunluk = modify_mesaj->Length;
	if (modify_mesaj_uzunluk % 2 == 1)
	{
		modify_mesaj = modify_mesaj + "X";
	}
	return modify_mesaj;
}

void playfair_cipher_encoder(Byte* renkli,int Width,int Height,String^ mesaj,String^ dizi)
{
	mesaj = mesaj_padding(mesaj);
	int modify_mesaj_uzunluk = mesaj->Length;
	String^ islenecek;
	int ascii;

	int sayac = 0;
	sayac = (Height / 5) * Width + (Width / 20);
	for (int i = 0; i < modify_mesaj_uzunluk; i = i + 2)
	{
		int index1[2]{};
		int index2[2]{};
		for (int a = 0; a < 5; a++)
		{
			for (int b = 0; b < 5; b++)
			{
				if (mesaj[i] == dizi[a * 5 + b] || mesaj[i + 1] == dizi[a * 5 + b])
				{
					if (mesaj[i] == dizi[a * 5 + b])
					{
						index1[0] = a;
						index1[1] = b;
					}
					else
					{
						index2[0] = a;
						index2[1] = b;
					}
				}
			}
		}
		char alinan_ilk;
		char alinan_iki;
		if (index1[0] == index2[0])
		{
			alinan_ilk = dizi[index1[0] * 5 + ((index1[1] + 1) % 5)];
			alinan_iki = dizi[index2[0] * 5 + ((index2[1] + 1) % 5)];
		}
		else if (index1[1] == index2[1])
		{
			alinan_ilk = dizi[((index1[0] + 1) % 5) * 5 + index1[1]];
			alinan_iki = dizi[((index2[0] + 1) % 5) * 5 + index2[1]];
		}
		else
		{
			alinan_iki = dizi[index2[0] * 5 + index1[1]];
			alinan_ilk = dizi[index1[0] * 5 + index2[1]];
		}
		String^ alinan_ilk_bit = Convert::ToString(alinan_ilk, 2)->PadLeft(8, '0');
		String^ alinan_iki_bit = Convert::ToString(alinan_iki, 2)->PadLeft(8, '0');
		for (int d = 0; d < 8; d++)
		{
			String^ resim_ilk_bit = Convert::ToString(renkli[sayac * 3 + 1], 2)->PadLeft(8, '0');
			resim_ilk_bit = resim_ilk_bit->Remove(7);
			resim_ilk_bit = resim_ilk_bit + alinan_ilk_bit[d];
			renkli[sayac * 3 + 1] = binary_to_ascii(resim_ilk_bit);

			String^ resim_iki_bit = Convert::ToString(renkli[(sayac + 1) * 3 + 1], 2)->PadLeft(8, '0');
			resim_iki_bit = resim_iki_bit->Remove(7);
			resim_iki_bit = resim_iki_bit + alinan_iki_bit[d];
			renkli[(sayac + 1) * 3 + 1] = binary_to_ascii(resim_iki_bit);
			sayac = sayac + 2;
		}
	}
	for (int d = 0; d < 8; d++)
	{
		String^ resim_ilk_bit = Convert::ToString(renkli[sayac * 3 + 1], 2)->PadLeft(8, '0');
		resim_ilk_bit = resim_ilk_bit->Remove(7);
		resim_ilk_bit = resim_ilk_bit + 0;
		renkli[sayac * 3 + 1] = binary_to_ascii(resim_ilk_bit);

		String^ resim_iki_bit = Convert::ToString(renkli[(sayac + 1) * 3 + 1], 2)->PadLeft(8, '0');
		resim_iki_bit = resim_iki_bit->Remove(7);
		resim_iki_bit = resim_iki_bit + 0;
		renkli[(sayac + 1) * 3 + 1] = binary_to_ascii(resim_iki_bit);
		
		sayac = sayac + 2;
	}
}
String^ playfair_cipher_decoder(Byte* renkli, int Width, int Height, String^ dizi)
{
	String^ sonuc;
	string sonucs;
	String^ resim_ilk_bit;
	String^ resim_iki_bit;
	String^ ilk_harf;
	String^ ikinci_harf;
	String^ ara_sonuc;

	char ilk_harrff,alinan_ilk;
	char ikinci_harrff,alinan_iki;

	int baslangic = (Height / 5) * Width + (Width / 20);
	for (int a = baslangic; a < Width * Height; a = a + 16)
	{
		ilk_harf = "";
		ikinci_harf = "";
		for (int b = 0; b < 8; b++)
		{
			resim_ilk_bit = Convert::ToString(renkli[(a + b * 2) * 3 + 1], 2)->PadLeft(8, '0');
			resim_iki_bit = Convert::ToString(renkli[((a + b * 2) + 1) * 3 + 1], 2)->PadLeft(8, '0');
			ilk_harf = ilk_harf + resim_ilk_bit[7];
			ikinci_harf = ikinci_harf + resim_iki_bit[7];
		}
		ilk_harrff = ascii_to_harf(binary_to_ascii(ilk_harf));
		ikinci_harrff = ascii_to_harf(binary_to_ascii(ikinci_harf));
		if (binary_to_ascii(ilk_harf) == 0 && binary_to_ascii(ikinci_harf) == 0)
		{
			break;
		}
		int index1[2]{};
		int index2[2]{};
		for (int a = 0; a < 5; a++)
		{
			for (int b = 0; b < 5; b++)
			{
				if (ilk_harrff == dizi[a * 5 + b] || ikinci_harrff == dizi[a * 5 + b])
				{
					if (ilk_harrff == dizi[a * 5 + b])
					{
						index1[0] = a;
						index1[1] = b;
					}
					else
					{
						index2[0] = a;
						index2[1] = b;
					}
				}
			}
		}
		if (index1[0] == index2[0])
		{
			alinan_ilk = dizi[index1[0] * 5 + ((index1[1] - 1 + 5) % 5)];
			alinan_iki = dizi[index2[0] * 5 + ((index2[1] - 1 + 5) % 5)];
		}
		else if (index1[1] == index2[1])
		{
			alinan_ilk = dizi[((index1[0] - 1 + 5) % 5) * 5 + index1[1]];
			alinan_iki = dizi[((index2[0] - 1 + 5) % 5) * 5 + index2[1]];
		}
		else
		{
			alinan_iki = dizi[index2[0] * 5 + index1[1]];
			alinan_ilk = dizi[index1[0] * 5 + index2[1]];
		}
		sonucs = sonucs + alinan_ilk + alinan_iki;
		ara_sonuc = gcnew String(sonucs.c_str());
		sonuc = ara_sonuc;
	}
	return sonuc;
}