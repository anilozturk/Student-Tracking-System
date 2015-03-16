#include <iostream>
#include <iomanip>

using namespace std;

#include "bilgisayar.h"
#include "string.h"

Bilgisayar::Bilgisayar(String arg_seri,String arg_marka,String arg_model)//yapici fonksiyonumuz
{
    seri_no=arg_seri;
    marka=arg_marka;
    model=arg_model;
}

String Bilgisayar::serinoOku() const {return seri_no;}

String Bilgisayar::markaOku() const {return marka;}

String Bilgisayar::modelOku() const {return model;}

void Bilgisayar::serinoAyarla(String arg_serino)
{
    seri_no=arg_serino;
}

void Bilgisayar::markaAyarla(String arg_marka)
{
    marka=arg_marka;
}

void Bilgisayar::modelAyarla(String arg_model)
{
    model=arg_model;
}

ostream &operator<<(ostream & output,const Bilgisayar &sag)//cout asiri yuklemesi
{
    output<<sag.seri_no<<setw(12)<<sag.marka<<setw(6)<<sag.model;

    return output;
}

istream &operator>>(istream & input,Bilgisayar &sag)//cin asiri yuklemesi
{
    input>>sag.seri_no>>sag.marka>>sag.model;

    return input;
}
