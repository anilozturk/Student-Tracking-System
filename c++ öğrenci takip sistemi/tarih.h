#ifndef TARIH_H_INCLUDED
#define TARIH_H_INCLUDED

class Tarih{//tarihle ilgili islemler icin tarih class i tanimlamasi
    friend ostream &operator<<(ostream &,const Tarih &);
    friend istream &operator>>(istream &,Tarih &);
private:
    int gun;
    int ay;
    int yil;
public:
    Tarih(int=0,int=0,int=0);

    int gunOku() const;
    int ayOku() const;
    int yilOku() const;

    void gunAyarla(int);
    void ayAyarla(int);
    void yilAyarla(int);

    bool operator==(const Tarih &)const;
    bool operator<(const Tarih &)const;
    bool operator>(const int) const;
    bool operator>(const Tarih &)const;
};

#endif // TARIH_H_INCLUDED
