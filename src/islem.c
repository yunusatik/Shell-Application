#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

int main(int argc, char *argv[])
{   
	int frk1,exec1;      
	
	char *topla[1];  //topla kontrol
	      topla[0]="topla";
	      
	char *cikar[1];  //cikar kontrol
	      cikar[0]="cikar";
	      	
	char *komut[1];  //komut kontrol
	      komut[0]=argv[0];
	      
	char *sayilar[1]; //Gonderecegim dizi
	      sayilar[0]=argv[1];
	      sayilar[1]=argv[2];
	   
	
	if (strcmp(komut[0],topla[0]) == 0) //topla Compare yapiyorum
	{ 
	    exec1 = execve("topla",sayilar,NULL);
	}
		
	else if(strcmp(komut[0], cikar[0]) == 0) //cikar Compare yapiyorum
	{
	    exec1 = execve("cikar",sayilar,NULL);
	}
	
	else	// hata varsa cikti aliyorum
	{
	    wait(&exec1);
	    printf("*HATA*: '%s' bir komut değildir. (topla veya cikar)\n\n",argv[0]);
	}
	
    	return 0;
}
