Belirli Aralıklarta Bir Kez Rastgele Değer Üreten Fonksiyon (Random.cpp) 

(https://csystem.org/kaynak-kod-arsivi?page=0%2C0%2C0%2C0%2C0%2C0%2C0%2C0%2C0%2C0%2C3)
Aşağıdaki Random sınıfı fonksiyon nesnelerinin kullanımına güzel bir örnek oluşturuyor. 
Random isimli sınıfın iki private elemanı üretilecek rastgele sayıların en düşük ve en yüksek değerlerini tutuyor.
Sınıfın kurucu fonksiyonu ile bu değerler dışarıdan alınıyor. Sınıfın diğer elemanı ise standart set sınıfından bir nesne. 
set içinde aynı değerden yalnızca bir tane tutulabilir değil mi? Sınıf için fonksiyon çağırma operatörü yükleniyor. 
Bu fonksiyon içinde standart rand fonksiyonu ile belirli aralıkta rastgele sayı üretiliyor ve bu sayı sete eklenmeye çalışılıyor. Ekleme başarısız olduğu sürece bu işlem yineleniyor. 
Ekleme işleminin başarısı için set sınıfının insert fonksiyonunun geri dönüş değerinden faydalanılıyor.
Eğer artık üretilecek başka bir değer kalmamışsa fonksiyon içinde logic_error sınıfı türünden bir hata nesnesi gönderiliyor.
