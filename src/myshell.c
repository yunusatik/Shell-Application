#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
  
#define MAXCOM 1000 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported   
#define clear() printf("\033[H\033[J") 
  
void giris_Ekrani() //Programa Giriş Yapılırken Giriş Ekranı
{ 
	clear(); // ilk önce ekranı temizliyorum
	 
 	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t↑→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→");
	printf("→→→↓\n\t\t\t↑ MY SHELL Programına Geçiş Yapılıyor↓"); 
	printf("\n\t\t\t↑←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←↓");    	
	printf("\n\n\t\t             Coded From ♥ Yunus Emre Atik♥\n"); 

	sleep(2);    
	clear(); 

	printf("\t\t\t\tPROGRAMIMA HOŞGELDİNİZ\n\t\t      Programda bulunan komutları öğrenmek için"); 
	printf("\n\t\t\t\t        'bilgi' \n\t\t\t    komunutunu çalıştırabilirsiniz ");
	printf("\n");
	sleep(2);
	clear();

	printf("\t\t\t\t**************************\n");
	printf("\t\t\t\t***** 😎️  MYSHELL 😎️ *****\n");
	printf("\t\t\t\t**************************");
} 

void openHelp() // Programımda ki tüm komutların açıklamasının verildiği kısım
{ 
	puts("\n\n\t\t\t\t***** 😎️  MYSHELL 😎️ *****  "
	"\n'exit' : Programdan Çıkış Yapmanızı Sağlar"
	"\n    → Kullanılışı →  exit"
	"\n\n'tekrar' : Yanına yazdığınız stringi verdiğiniz sayı kadar ekrana basar"
	"\n    → Kullanılışı →  tekrar fatih 3"
	"\n\n'islem' : Yanına yazdığınız komut ile verdiğiniz sayıları toplar veya çıkarır"
	"\n    → Kullanılışı →  islem topla 4 5 , islem cikar 4 2"
	"\n\n'bilgi' : Program hakkında bilgi almanızı sağlar"
	"\n    → Kullanılışı →  bilgi"
	"\n\n'clear' : Terminali Temizler"
	"\n    → Kullanılışı →  clear"
	"\n\n'cat' : Yanına Yazdığınız Dosyanın İçeriğini Bastırır"
	"\n    → Kullanılışı →  cat dosya_adi"
	"\n\t\t\t\t***** 😎️  MYSHELL 😎️ *****  "); 
} 

int kontroller(char* ilk_girdi) //Girdimizin tüm kontrollerinin yapıldığı fonksiyon.
{
	int komut_Sayisi=6;
	int first_kontrol=0;
	
	char *mevcut_Komutlarr[komut_Sayisi]; // Komutlarımı tanımlıyorum
	      mevcut_Komutlarr[0] = "exit"; 
	      mevcut_Komutlarr[1] = "tekrar"; 
	      mevcut_Komutlarr[2] = "islem"; 
	      mevcut_Komutlarr[3] = "bilgi";
	      mevcut_Komutlarr[4] = "clear";
	      mevcut_Komutlarr[5] = "cat";
	
	char *girdi[100];	//Girdimizi geçici girdi dizimize alıyorum
	char *tekrar_girdi[2]; // tekrar komutunun yanında ki stirng ve sayıyı atıyorum
	
	char *cat_girdi[2];	//cat komutunun yanında ki dosya adını atıyorum
	      cat_girdi[0]="/bin/cat";
	      cat_girdi[2]=NULL;
	      
	char *islem_girdi[2];	// islem komutunun yanında ki 2 sayıyı atıyorum
	      islem_girdi[1]="bos";
	      islem_girdi[2]="bos";
	
	char *cizgi[1];  	// Birden fazla komut girilirse arada ki kontrol 
	      cizgi[0]="|";
		
	char* words = strtok(ilk_girdi, " "); // words dizime girdimin ilk kelimesini atıyorum
	int a;
	int sinir=30;
	for(a=0;a<sinir;a++)	 //Girdi sınırına kadar tüm kelimeleri words'e atıyorum
	{
	   girdi[a]=words;
	   words=strtok(NULL," "); // Atadıktan sonra bir sonraki kelimeye geçiyorum.
	}
	
	int frk1,frk2,frk3;
	int exec1,exec2,exec3;
	int i;
	int c=0;
	
	while(girdi[c]!=NULL)  // Girdim NULL gelene kadar dönüyorum.
	{  
	   for (i = 0; i < komut_Sayisi; i++) 
	   { 	
		first_kontrol=0;
		if (strcmp(girdi[c], mevcut_Komutlarr[i]) == 0) //komut kontrol
		{ 
		    first_kontrol=1;
		    break; 
		}
		if(strcmp(girdi[c], cizgi[0]) == 0){ // Cizgi Kontrol
		    first_kontrol=2;
		    c++;
		    break;	
		} 					
	   }
				
	   if(first_kontrol==0) //Komutumuz hatalıysa
	   {  
		printf("*HATA*: '%s' Komutu Bulunamamıştır!\n",girdi[c]);
		c++;
	   }
	   else if(first_kontrol==1) //Bir komutumuz eşleştiyse
	   { 
	       first_kontrol=0;
	       if(i==5)
	       {
	          printf("\n\n***************\t 'cat → %s' SON\t*************** ",girdi[c+1]);
	       }
	       switch(i) //Komut seçme için switch-case
	       {  
		  case 0: //exit ise
			  printf("\n\t\t🖐️ 🖐️ 🖐️  Görüşmek Üzere 🖐️ 🖐️ 🖐️ \n"); 
			  exit(0);
			
		  case 1: //tekrar ise
			  tekrar_girdi[0]=girdi[c+1]; //tekrar stringi
			  tekrar_girdi[1]=girdi[c+2]; //tekrar sayisi
			  c=c+3;
							
		      	  frk1= fork();	//tekrar forku
		      	  if(frk1==0)
		      	  {		      	  
			     printf("\nKomut Çalıştırıldı : tekrar");
			     printf("→  %s →  %s \n",tekrar_girdi[0],tekrar_girdi[1]); 
			     exec1 = execve("tekrar",tekrar_girdi,NULL);
			     perror("exec2: execve failed\n");
		      	  } 
		      	  else
		      	  {
		      	     wait(&exec1);			      	  
		      	     if(tekrar_girdi[0]==NULL || tekrar_girdi[1]==NULL ) // Komut eksik ise
		      	     {
				 printf("*HATA*: 'tekrar' 'dan sonra lütfen yazı ve sayı giriniz.\n");
			     }
		      	  }  
		      	  break;
		      	
		  case 2: //islem ise
			  islem_girdi[0]=girdi[c+1]; //islem adi
			  islem_girdi[1]=girdi[c+2]; //1.sayi
			  islem_girdi[2]=girdi[c+3]; //2.sayi
			  c=c+4;
				
		      	  frk2= fork(); //islem forku
		      	  if(frk2==0)
		      	  {		      	  
			    printf("\nKomut Çalıştırıldı : islem ");
			    printf("→  %s →  %s  →  %s \n",islem_girdi[0],islem_girdi[1],islem_girdi[2]); 
			    exec2 = execve("islem",islem_girdi,NULL);				  
		      	  }
		      	  else
		      	  {
			    wait(&exec2);
			    if(islem_girdi[1]==NULL || islem_girdi[2]==NULL) // Komut eksik ise
			    {
			       printf("*HATA*: '%s' 'dan sonra lütfen iki değer giriniz.\n",islem_girdi[0]);
			    }
		      	  }
			  break; 
			
		  case 3: // bilgi ise
			  printf("\nKomut Çalıştırıldı : bilgi ");
			  openHelp(); // bilgi fonksiyonunu çağırıyorum
			  c=c+1; 
			  break;
			
		  case 4: // clear ise
			  clear();  // clear fonksiyonunu çağırıyorum
			  c=c+1; 
			  break;
			
		  case 5: //cat ise
			  cat_girdi[1]=girdi[c+1];
					
			  c=c+2;
			  frk3= fork(); //cat için fork yapıyorum
		      	  if(frk3==0)
		      	  {
			    exec3 = execve("/bin/cat",cat_girdi,NULL);				  
		      	  }
		      	  else
		      	  {		      	  	
		      	    wait(&exec3);
		      	  }		
			  break;
	       }	
	   }
	}
  return 0;
}
int main() 
{ 
	giris_Ekrani(); //giris ekranimi cagiriyorum ilk once
	int first_kontrol=0;
	
	while (1) 
	{          
	  char* girdi;
	  girdi = readline("\nmyshell>>"); //girdi mi alıyorum

	  if (strlen(girdi) != 0)  //bos olup olmadigini kontrol ediyorum
	  { 
	    add_history(girdi);
	    kontroller(girdi);
	  }
	  else	// bos ise komut girmesini istiyorum
	  {
	    printf("Lütfen Komut Giriniz.");
	  }
	} 
  return 0; 
} 

