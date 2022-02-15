#include<stdio.h>					
#include<stdlib.h>

int isPowTwo (int);						/*Fonksiyon prototipinin yazılması*/
void main()								    /*Main fonksiyonunun bildirilmesi*/
{
unsigned int x;							  /*Değişken tanımlamalarının yapılması*/
int result;
printf("Please, write a number\n");
scanf_s("%d",&x);						  /*Kullanıcıdan unsigned integer türünde bir sayının alınması*/
result=isPowTwo(x);						/*Kullanıcıdan alınan sayının ikinin kuvveti olup olmadığının bulunması*/
if(result==1)
printf("%d.True",x);					/*Eğer sonuç kuvveti ise ekrana true kelimesinin yazılması*/
else
printf("%d.False",x);					/*Eğer sonuç kuuvveti değil ise false kelimesinin yazılması*/
getch();
}
int isPowTwo(int j)						/*Fonksiyonun tanımlanması. Fonksiyonun nasıl çalıştığını anlamayı sizlere bırakıyorum. E-posta ile anlamadığınız yerleri sorabilirsiniz.*/
{
	if((j%2)==1)
		return 0;
	if((j%2)==0)
		return 1;
	else
	{
		return isPowTwo(j/2);
	}
}
