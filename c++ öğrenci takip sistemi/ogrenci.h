#ifndef OGRENCI_H_INCLUDED
#define OGRENCI_H_INCLUDED

#include "string.h"
#include "tarih.h"
#include "bilgisayar.h"

class Ogrenci{
    friend ostream &operator<<(ostream &,const Ogrenci &);
private:
    const int ogr_no;//degismeyecegi ongorulen veri uyeleri const tanimlandi
    const String ad;
    const String soyad;
    const Tarih dogum;
    const Tarih kayit;
    const Bilgisayar laptop;
    int sinif;
    float not_ort;
public:
    Ogrenci(int,String,String,Tarih,Tarih,Bilgisayar &,int,float);

    int ogrnoOku() const;
    String adoku() const;
    String soyadOku() const;
    Tarih dogumOku() const;
    Tarih kayitOku() const;
    Bilgisayar laptopOku() const;
    int sinifOku() const;
    float notortOku() const;

    void sinifAyarla(int);
    void notortAyarla(float);
};

#endif // OGRENCI_H_INCLUDED
