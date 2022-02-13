#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_OF_WORDS 20									/*Oluşturulacak kelime sayısı*/
#define MIN_LEN 9										/*Kelimenin minimum uzunluğu*/
#define MAX_LEN 15										/*Kelimenin maksimum uzunluğu*/
#define MAX_VOWEL 2										/*Belirtilen sayısda sesli harf yanyana gelemez.*/
#define MAX_CONS 3										/*Belirtilen sayısa sessiz harf yanyana gelemez.*/

int is_vowel(int x);									/*Sesli harf tespit eden fonksiyonun prototipi*/
int main()												/*Main fonksiyonu bildirimi*/
{
    int i, l, ch, vowelcounter, conscounter, counter;	/*Değişkenlerin tanımlanması*/
    vowelcounter=0;										/*Değişkenlere varsayılan değerin atanması*/
 	conscounter=0;										/*Değişkenlere varsayılan değerin atanması*/
    for(i=0; i<NO_OF_WORDS; i++)						/*Oluşturulacak sayı kadar döngü iteratifi oluşturulması*/	
    {
        counter=0;										/*karakter sayıcısına varsayılan değer atanması*/
        l=rand()%(MAX_LEN-MIN_LEN+1)+MIN_LEN;			/*Oluşturuan her kelime için uzunluğun belirlenmesi*/
        while(counter<l)
        {
            ch=((rand()%26)+65);						/*Karkaterin rastgele oluşturulması*/
            if (is_vowel(ch))							/*Oluşturulan karakterin sesli harf olup olmadığının tespiti*/
            {
                vowelcounter++;							/*Eğer sesli harf ise sesli harf sayıcısının arttırılması*/
                if (vowelcounter<MAX_VOWEL)				/*Eğer sesli harf olması gereken sınırın altında ise sesli harfin karakter olarak ekrana yazılması*/
                {
                    printf("%c",ch);					/*Sesli harfin karakterinin ekrana yazılması*/
                    counter++;							/*Karakter sayacının arttırılması*/
                }
                conscounter=0;							/*Sessiz harf sayıcısının sıfırlanması*/
            }
            else										/*Oluşturulan karakter sesssiz harf ise*/
            {
                conscounter++;							/*Sessiz harf sayıcısının arttırılması*/
                if (conscounter<MAX_CONS)				/*Sessiz harf, sessiz harf sınırının altında ise*/
                {
                    printf("%c",ch);					/*Sessiz harfin karakterinin ekrana yazılması*/
                    counter++;							/*Karakter sayacının arttırılması*/
                }
                vowelcounter=0;							/*Sessiz harf sayacının sıfırlanması*/
            }
        }
        putchar('\n');
    }
	getch();
    return 0;
}
int is_vowel(int x)										/*Sesli harflerin tespit edilmesini sağlayan fonksiyon*/
{
    return (x=='X'||x=='E'||x=='I'||x=='O'||x=='U');
}