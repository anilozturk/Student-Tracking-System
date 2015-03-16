#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>

using std::istream;
using std::ostream;

class String{//karakter dizisi islemleri icin String class imiz
    friend ostream &operator<<(ostream &,const String &);
    friend istream &operator>>(istream &,String &);
private:
    int boyut;
    char *ptr;
public:
    String(int=0);//yapici fonksiyonumuz hem const hem normal olmak uzere asiri yuklendi
    String(const String &);

    int boyutOku()const;

    const String &operator=(const String &);
    bool operator==(const String &)const;
    bool operator<(const String &)const;
    bool operator>(const String &)const;
};

#endif // STRING_H_INCLUDED
