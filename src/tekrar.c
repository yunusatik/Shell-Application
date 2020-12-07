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
	int i,count;
	count=strtoint(argv[1]); //sayiyi int'e ceviriyorum
	
	for(i=0; i<count; i++) //sayi kadar donup yazdiriyorum
	{
	   printf("→ %s\n",argv[0]);
	}	
    	return 0;
}
