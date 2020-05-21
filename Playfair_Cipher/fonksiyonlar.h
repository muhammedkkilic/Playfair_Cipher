#pragma once

using namespace System;

int binary_to_ascii(String^ gelen);
char ascii_to_harf(int gelen);
String^ mesaj_padding(String^ mesaj);
void playfair_cipher_encoder(Byte* renkli, int Width, int Height, String^ mesaj, String^ dizi);
String^ playfair_cipher_decoder(Byte* renkli, int Width, int Height, String^ dizi);
String^ secret_key_belirle(String^ key);