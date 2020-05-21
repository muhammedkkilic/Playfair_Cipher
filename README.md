C++ ile yaptığım bu projede bir görsel üzerinde Playfair Cipher veri şifreleme işlemi yapıldı.
Anahtar olarak girilen değer matrise yerleştirilir.Geriye kalan harfler random atanır.  

![encryption-keysquare](https://user-images.githubusercontent.com/33607770/82567971-ce763e00-9b86-11ea-9d33-d2e2f3b477b6.png)  

PlainText: "instruments"   
After Split: 'in' 'st' 'ru' 'me' 'nt' 'sz'  
Diagraph: "me"  
Encrypted Text: cl  
Encryption:  
  m -> c  
  e -> l  


![encryption-of-me](https://user-images.githubusercontent.com/33607770/82568600-beab2980-9b87-11ea-8d86-8072b36ac152.png)  
Diagraph: "st"  
Encrypted Text: tl  
Encryption:   
  s -> t  
  t -> l  


![encryption-of-st](https://user-images.githubusercontent.com/33607770/82569686-404f8700-9b89-11ea-8677-37a5b85c605d.png)  

Diagraph: "nt"  
Encrypted Text: rq  
Encryption:   
  n -> r  
  t -> q  

![encryption-of-nt](https://user-images.githubusercontent.com/33607770/82568791-0336c500-9b88-11ea-8370-6dc7b05c287b.png)  

Programın Ekran Görüntüsü  

Şifreleme  

![encryption](https://user-images.githubusercontent.com/33607770/82569263-aab3f780-9b88-11ea-8b7f-47c3e70f7f83.JPG) 

Deşifreleme  

![decryption](https://user-images.githubusercontent.com/33607770/82569477-f8c8fb00-9b88-11ea-8b22-3af3ad853e2e.JPG)  

