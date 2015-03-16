#include <iostream>
#include <cstdio>
using namespace std;

#include "ogrenci.h"
#include "ogrenci_dizisi.h"

Ogrenci_dizisi::Ogrenci_dizisi()//yapici fonksiyonumuzda ilk deger olarak ptrler NULL a ataniyor
{
    for (int i=0;i<1000;i++)
        bir_uye[i]=NULL;
}

Ogrenci *Ogrenci_dizisi::biruyeOku(int no) const
{
    return bir_uye[no-1];
}

ostream &operator<<(ostream & output,const Ogrenci_dizisi &sag)//cout asiri yuklemesi
{
    for (int i=0;i<1000;i++){
        if (sag.bir_uye[i]!=NULL)
        output<<*sag.bir_uye[i]<<endl;
    }

    return output;
}

void Ogrenci_dizisi::ekle(Ogrenci *yeni)//ekle fonksiyonu eklenecek dizi elemanina gerekli ogrencinin adresi ataniyor
{
    bir_uye[(yeni->ogrnoOku())-1]=yeni;
}

Ogrenci *Ogrenci_dizisi::cikar(Ogrenci *cikarilacak)//cikar fonksiyonu cikardigimiz ogrenci adresini geri donduruyor
{
    Ogrenci *gecici=cikarilacak;

    bir_uye[cikarilacak->ogrnoOku()-1]=NULL;

    return gecici;
}
