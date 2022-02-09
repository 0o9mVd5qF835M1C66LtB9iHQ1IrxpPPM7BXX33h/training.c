#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50				/*Sabit tanımlıyoruz.*/			

int rand_number(void);		/*Rastgele sayı üretimi için fonksiyon prototipi*/
int is_valid(int number);	/*Doğrulama için fonksiyon prototipi*/

int main(void)				/*Programın başlangıç fonksiyonu*/	
{
	int i, x[SIZE];			/*Değişken ile dizi tanımlamaları*/
	srand(time(NULL));		/*time fonksiyonu ile her saniyeden rastgele bir değer üretilir.*/
	for(i=0;i<SIZE;i++)		/*SIZE değeri kadar sayı üreteceğiz.*/
		while(!is_valid(x[i]=rand_number()));	/**Şart sağlanmadığında (is_valid geridönüş değeri 0 olduğunda) x dizisinin aynı indisine tekrar yeni bir rastgele sayı atanır. Bu is_valid fonksiyonu geridönüş değeri 1 olana kadar sürer.**/
	for(i=0;i<SIZE;i++)		/*Üretilen sayıları yazdırıyoruz.*/
		printf("%d",x[i]);
	putchar('\n');
	return 0;
}

int rand_number(void)		/*1000 ile 9999 arasında rastgele sayı üreten fonksiyon*/
{
	return rand() % 9000 + 10000;
}

							/*Kendisine gönderilen sayının koşuluna uygun,
							Basamakları tekrar etmeyen bir sayı olup olmadığını
							test eden fonksiyon uygunsa 1 değilse 0 değerini üretiyor.*/

int is_valid (int number)	/*Üretilen rastgele sayıyı parametre olarak alır.*/
{
	int i,j,temp;			/*Değişken tanımlama*/
	for(i=0;i<10;i++)		/*Her rakam için basamak kontrolü yapılır.*/
	{
		j=0;
		temp=number;
		while(temp>0)
		{
			if(temp%10==i)
				j++;
			if(j>1)
				return 0;
			temp/=10;
		}
	}
	return 1;
}
