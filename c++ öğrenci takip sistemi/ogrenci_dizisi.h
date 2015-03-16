#ifndef OGRENCI_DIZISI_H_INCLUDED
#define OGRENCI_DIZISI_H_INCLUDED

#include "ogrenci.h"

class Ogrenci_dizisi{//ogrencilerin eklendigi pointer listemiz
    friend ostream &operator<<(ostream &,const Ogrenci_dizisi &);
private:
    Ogrenci *bir_uye[1000];
public:
    Ogrenci_dizisi();

    Ogrenci *biruyeOku(int) const;

    void ekle(Ogrenci *);
    Ogrenci *cikar(Ogrenci *);
};

#endif // OGRENCI_DIZISI_H_INCLUDED
