#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stddef.h>
#include<string.h>

/*
hasta takip sistemi
hasta no,ad,yas,ve hastalık bilgisin tutunuz struck ile
dossya icinde hasta bilgilerini tutunuz
hasta kaydı sil
hasta kaydı düzenle
dosyadan hastaları listele
*/
struct hasta
 {
    int no;
    char ad[20];
    int yas;
    char hastalik[20];
};



 struct hasta  bosHasta= {0 ,"",0,""};
 struct hasta kisi;
 
FILE *ptr;

void listeleolustur()
{
    if((ptr=fopen("hastakayit.dat","w")) !=NULL)
{
    int i;
    for(i=0;i<100;i++)
     fwrite(&bosHasta,sizeof(struct hasta),1,ptr);
     printf("100  hasta kaydi icin gerekli yerler ayrıldı \n");
}
fclose(ptr);
}

void ekle()
{   
    int hastaID;
    if((ptr=fopen("hastakayit.dat","r+")) !=NULL)
{
    printf("hasta no giriniz: ");
    scanf("%d",&hastaID);
    fseek(ptr,(hastaID-1)*sizeof(struct hasta), SEEK_SET ) ;
    fread(&kisi,sizeof(struct hasta),1,ptr);
    if(kisi.no!=0)
    printf("%d numarasında hasta mevcut \n",hastaID);
    else if(hastaID>100 || hastaID<1)
    printf("hasta numarasi olarak 1-100 arasi giriniz \n");
    else
    {
    
        printf("hasta adi giriniz: ");
        scanf("%s",kisi.ad);
        printf("hasta yas giriniz: ");
        scanf("%d",&kisi.yas);
        printf("hasta hastalik giriniz: ");
        scanf("%s",kisi.hastalik);
        kisi.no=hastaID;
        fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&kisi,sizeof(struct hasta),1,ptr);
        printf("hasta kaydi basarili \n");
    }
}
fclose(ptr);
}


void sil()
{   
    int hastaID;
    if((ptr=fopen("hastakayit.dat","r+")) !=NULL)
{
    printf(" silinecek hasta no giriniz: ");
    scanf("%d",&hastaID);
    fseek(ptr,(hastaID-1)*sizeof(struct hasta), SEEK_SET ) ;
    fread(&kisi,sizeof(struct hasta),1,ptr);
    if(kisi.no==0)
    printf("%d numarasında kayıtlı hasta mevcut değildir \n",hastaID);
    else
    {
        fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&bosHasta,sizeof(struct hasta),1,ptr);
        printf("hasta kaydi basarili \n");
    }
}
fclose(ptr);
}


void guncelle()
{   
    int hastaID;
    if((ptr=fopen("hastakayit.dat","r+")) !=NULL)
{
    printf(" guncellenecek hasta no giriniz: ");
    scanf("%d",&hastaID);
    fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
    fread(&kisi,sizeof(struct hasta),1,ptr);
    if(kisi.no==0)
    printf("%d numarasında kayıtlı hasta mevcut değildir \n",hastaID);
    else
    {
        fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&bosHasta,sizeof(struct hasta),1,ptr);
        printf("%d numaralı hasta bilgiler: \n");
        printf("hasta adi giriniz: ");
        scanf("%s",kisi.ad);
        printf("hasta yas giriniz: ");
        scanf("%d",&kisi.yas);
        printf("hasta hastalik giriniz: ");
        scanf("%s",kisi.hastalik);
        

        printf("ad/yas/hastalık: %s/%d/%s \n",kisi.ad,&kisi.yas,kisi.hastalik);
         kisi.no=hastaID;
        fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&kisi,sizeof(struct hasta),1,ptr);
        printf("hasta kaydi basarili sekilde güncellendi \n");
    }
}
fclose(ptr);
}



void hastara()
{   
    int hastaID;
    if((ptr=fopen("hastakayit.dat","r+")) !=NULL)
{
    printf(" aradiginiz hastanin numarasi: ");
    scanf("%d",&hastaID);
    fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
    fread(&kisi,sizeof(struct hasta),1,ptr);
    if(kisi.no==0)
    printf("%d numarasında kayıtlı hasta mevcut değildir \n",hastaID);
    else
    {
        fseek(ptr,(hastaID-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&bosHasta,sizeof(struct hasta),1,ptr);
        printf("%d numaralı hasta bilgiler: \n");
        printf("hasta adi giriniz: ");
        scanf("%s",kisi.ad);
        printf("hasta yas giriniz: ");
        scanf("%d",&kisi.yas);
        printf("hasta hastalik giriniz: ");
        scanf("%s",kisi.hastalik);
        
    }
}
fclose(ptr);
}


void yazdir()
{   
    system("cls");
    int hastaID;
    if((ptr=fopen("hastakayit.dat","r+")) !=NULL)
{
    printf(" NUMARASİ\nAD\tYAS\tHASTALİK\n: ");
    while (!feof(ptr))
    {
        fread(&kisi,sizeof(struct hasta),1,ptr);
        if(kisi.no!=0)
        printf("%d\t%s\t%d\t%s\n",kisi.no,kisi.ad,kisi.yas,kisi.hastalik);

        
    }
}
fclose(ptr);
}


int main ()
{
int secim;
secim=-1;

while(secim!=0)
{

printf("\n1-ekle \n");
printf("2-sil \n");
printf("3-guncelle \n");
printf("4-hastara \n");
printf("5-yazdir \n");
printf("6-listeleolustur \n");
printf("7-çikis \n ");
printf("seciminiz: ");
scanf("%d",&secim);

switch (secim)
{
case 1:
ekle();
break;
case 2:
sil();
break;
case 3:
guncelle();
break;
case 4:
hastara();
break;
case 5:
yazdir();
break;
case 6:
listeleolustur();
break;
case 7:
çikis();
break;
default:
printf("yanlis secim \n");

}
}

 return 0;
}