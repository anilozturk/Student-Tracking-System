#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

#include "string.h"

String::String(int diziBoyu)
{
    boyut=diziBoyu;
    ptr=new char[boyut];//yapici fonksiyonumuz kullanicinin girdigi boyuta gore hafizada yer ayiriyor

    for (int i=0;i<boyut;i++)
        ptr[i]=NULL;
}

String::String(const String &kopya):boyut(kopya.boyut)//const yapici fonksiyonumuz
{
    ptr=new char[boyut];

    for (int i=0;i<boyut;i++)
        ptr[i]=kopya.ptr[i];
}

int String::boyutOku() const{return boyut;}

const String &String::operator=(const String &sag)//atama operatorumuz asiri yukleniyor
{
    if (&sag!=this){//atamanin sagindaki karakter boyutu atanacak yerdekinden buyukse atanacak yer tekrar duzenleniyor
        if (boyut!=sag.boyut){
            delete []ptr;
            boyut=sag.boyut;
            ptr=new char[boyut];
        }

        for (int i=0;i<boyut;i++)
            ptr[i]=sag.ptr[i];
    }

    return *this;
}

bool String::operator==(const String &sag) const
{
    if ((strcmp(ptr,sag.ptr))==0)
        return true;
    else
        return false;
}

bool String::operator<(const String &sag) const
{
    if ((strcmp(ptr,sag.ptr))<0)
        return true;
    else
        return false;
}

bool String::operator>(const String &sag) const
{
    if ((strcmp(ptr,sag.ptr))>0)
        return true;
    else
        return false;
}

ostream &operator<<(ostream & output,const String &cumle)//cout asiri yuklemesi
{
    for (int i=0;i<cumle.boyut;i++){
        if (cumle.ptr[i]=='\0')
            break;
        output<<cumle.ptr[i];
    }

    return output;
}

istream &operator>>(istream & input,String &cumle)//cin asiri yuklemesi
{
    gets(cumle.ptr);

    for (int i=0;i<cumle.boyut;i++)
        cumle.ptr[i]=tolower(cumle.ptr[i]);

    return input;
}
