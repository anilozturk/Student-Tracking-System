#ifndef BILGISAYAR_H_INCLUDED
#define BILGISAYAR_H_INCLUDED

#include "string.h"

class Bilgisayar{//bilgisayar islemleri icin Bilgisayar class imiz
    friend ostream &operator<<(ostream &,const Bilgisayar &);
    friend istream &operator>>(istream &,Bilgisayar &);
private:
    String seri_no;
    String marka;
    String model;
public:
    Bilgisayar(String='\0',String='\0',String='\0');

    String serinoOku() const;
    String markaOku() const;
    String modelOku() const;

    void serinoAyarla(String );
    void markaAyarla(String );
    void modelAyarla(String );
};

#endif // BILGISAYAR_H_INCLUDED
