#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "tarih.h"

Tarih::Tarih(int gun_no,int ay_no,int yil_no)//yapici fonksiyonumuz
{
    gun=gun_no;
    ay=ay_no;
    yil=yil_no;
}

int Tarih::gunOku() const {return gun;}

int Tarih::ayOku() const {return ay;}

int Tarih::yilOku() const {return yil;}

void Tarih::gunAyarla(int arg_gun)
{
    gun=arg_gun;
}

void Tarih::ayAyarla(int arg_ay)
{
    ay=arg_ay;
}

void Tarih::yilAyarla(int arg_yil)
{
    yil=arg_yil;
}

bool Tarih::operator==(const Tarih &sag) const
{
    if (yil==sag.yil){
        if (ay==sag.ay){
            if (gun==sag.gun)
                return true;
        }
    }

    return false;
}

bool Tarih::operator<(const Tarih &sag) const
{
    if (yil>sag.yil)
        return true;
    else if (yil==sag.yil && ay>sag.ay)
        return true;
    else if (yil==sag.yil && ay==sag.ay && gun>sag.gun)
        return true;

    return false;
}

bool Tarih::operator>(const Tarih &sag) const
{
    if (yil<sag.yil)
        return true;
    else if (yil==sag.yil && ay<sag.ay)
        return true;
    else if (yil==sag.yil && ay==sag.ay && gun<sag.gun)
        return true;

    return false;
}

bool Tarih::operator>(const int arg_yil) const
{
    if (yil>arg_yil)
        return true;
    else
        return false;
}

ostream &operator<<(ostream & output,const Tarih &sag)//cout asiri yuklemesi
{
    output<<sag.gun<<"."<<sag.ay<<"."<<sag.yil;

    return output;
}

istream &operator>>(istream & input,Tarih &sag)//cin asiri yuklemesi
{
    input>>sag.gun>>sag.ay>>sag.yil;

    return input;
}
