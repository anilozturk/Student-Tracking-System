#include <iostream>
#include <iomanip>

using namespace std;

#include "ogrenci.h"
#include "string.h"
#include "tarih.h"
#include "bilgisayar.h"

Ogrenci::Ogrenci(int arg_ogrno,String arg_ad,String arg_soyad,Tarih arg_dogum,Tarih arg_kayit,Bilgisayar &arg_laptop,int arg_sinif,float arg_ort):
ogr_no(arg_ogrno),ad(arg_ad),soyad(arg_soyad),dogum(arg_dogum),kayit(arg_kayit),laptop(arg_laptop)
{//yapici fonksiyonumuz
    sinif=arg_sinif;
    not_ort=arg_ort;
}

int Ogrenci::ogrnoOku() const {return ogr_no;}

String Ogrenci::adoku() const {return ad;}

String Ogrenci::soyadOku() const {return soyad;}

Tarih Ogrenci::dogumOku() const {return dogum;}

Tarih Ogrenci::kayitOku() const {return kayit;}

Bilgisayar Ogrenci::laptopOku() const {return laptop;}

int Ogrenci::sinifOku() const {return sinif;}

float Ogrenci::notortOku() const {return not_ort;}

void Ogrenci::sinifAyarla(int arg_sinif)
{
    sinif=arg_sinif;
}

void Ogrenci::notortAyarla(float arg_not)
{
    not_ort=arg_not;
}

ostream &operator<<(ostream & output,const Ogrenci &sag)//cout asiri yuklemesi
{
    output<<sag.ogr_no<<setw(7)
          <<sag.ad<<setw(6)
          <<sag.soyad<<setw(9)
          <<sag.sinif<<setw(7)
          <<sag.not_ort<<setw(10)
          <<sag.dogum<<setw(5)
          <<sag.kayit;

    return output;
}
