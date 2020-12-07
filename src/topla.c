#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strtoint( char* charnums) //hocanin fonksiyonu
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {
	
    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
    }
    else
    {
        number=-1;
        printf("\n*HATA*: '%s' sayı olmak zorundadır.\n",charnums);
        break;
    }
 }
 return number;
}
int main(int argc, char *argv[])
{   
	int hata=0;	
	int sayi1=strtoint(argv[0]); //ilk sayiyi int'e ceviriyorum
	int sayi2=strtoint(argv[1]); //ikinci sayiyi int'e ceviriyorum
	
	if(sayi1!=1999 && sayi2!=1999)//kontrol ardindan islemimi yapiyorum
	{  	
	   int sonuc=sayi1+sayi2;
	   printf("%d + %d = %d\n",sayi1,sayi2,sonuc);
	}	
    	return 0;
}
