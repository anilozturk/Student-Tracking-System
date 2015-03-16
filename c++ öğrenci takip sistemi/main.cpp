#include <iostream>
#include <cstdio>

#include "string.h"
#include "tarih.h"
#include "bilgisayar.h"
#include "ogrenci.h"
#include "ogrenci_dizisi.h"

using namespace std;

int menu_goster();

int main()
{
    int secim,ogr_no,sinif,ogr_say,yil;
    float puan_ort;
    String ad(16),soyad(21),seri(13),marka(11),model(11);
    Bilgisayar pc(seri,marka,model);
    Tarih d_tarihi,k_tarihi;
    Ogrenci_dizisi liste;
    Ogrenci *bir_ogrenci,*gecici;

    do{
        secim=menu_goster();
        switch(secim){
            case 1:
                cout<<"Eklemek istediginiz ogrenci numarasini giriniz:"<<endl;
                cin>>ogr_no;
                bir_ogrenci=liste.biruyeOku(ogr_no);//kullanicidan alinan ogr no ya ait kayit olup olmadigi kontrol ediliyor
                if (bir_ogrenci==NULL){
                    cout<<"Ogrencinin adini girin:"<<endl;
                    fflush(stdin);
                    cin>>ad;
                    cout<<"Ogrencinin soyadini girin:"<<endl;
                    fflush(stdin);
                    cin>>soyad;
                    cout<<"Ogrencinin dogum tarihini girin:"<<endl;
                    cin>>d_tarihi;
                    cout<<"Ogrencinin kayit tarihini girin:"<<endl;
                    cin>>k_tarihi;
                    cout<<"Ogrenciye verilecek laptopla ilgili bilgiler:"<<endl;
                    fflush(stdin);
                    cin>>pc;
                    bir_ogrenci=new Ogrenci(ogr_no,ad,soyad,d_tarihi,k_tarihi,pc,1,0);//Ogrenci class inda bir ogrenci yaratiliyor
                    liste.ekle(bir_ogrenci);//eklenecek ptr listesine ogrencinin adresi gonderiliyor
                    cout<<"Ogrenci eklendi."<<endl;
                }
                else
                    cout<<"Girdiginiz numaraya ait bir kayit zaten var!"<<endl;
                break;
            case 2:
                cout<<"Eklemek istediginiz ogrenci numarasini giriniz:"<<endl;
                cin>>ogr_no;
                if (!liste.biruyeOku(ogr_no)){
                    cout<<"Ogrencinin adini girin:"<<endl;
                    fflush(stdin);
                    cin>>ad;
                    cout<<"Ogrencinin soyadini girin:"<<endl;
                    fflush(stdin);
                    cin>>soyad;
                    cout<<"Ogrencinin dogum tarihini girin:"<<endl;
                    cin>>d_tarihi;
                    cout<<"Ogrencinin kayit tarihini girin:"<<endl;
                    cin>>k_tarihi;
                    cout<<"Ogrencinin sinifini girin:"<<endl;
                    cin>>sinif;
                    cout<<"Ogrencinin not ortalamasini girin:"<<endl;
                    cin>>puan_ort;
                    cout<<"Ogrenciye verilecek laptopla ilgili bilgiler:"<<endl;
                    fflush(stdin);
                    cin>>pc;
                    bir_ogrenci=new Ogrenci(ogr_no,ad,soyad,d_tarihi,k_tarihi,pc,sinif,puan_ort);
                    liste.ekle(bir_ogrenci);
                    cout<<"Ogrenci eklendi."<<endl;
                }
                else
                    cout<<"Girdiginiz numaraya ait bir kayit zaten var!"<<endl;
                break;
            case 3:
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        cout<<"\n"<<bir_ogrenci->ogrnoOku()<<" numarali ogrenci:"<<endl;
                        cout<<"Ogrencinin yeni sinifini girin:"<<endl;
                        cin>>sinif;
                        bir_ogrenci->sinifAyarla(sinif);//yeni sinifi ayarlaniyor
                        cout<<"Ogrencinin yeni not ortalamasini girin:"<<endl;
                        cin>>puan_ort;
                        bir_ogrenci->notortAyarla(puan_ort);//yeni not ortu ayarlaniyor
                        liste.ekle(bir_ogrenci);//guncellenmis ogrenci ptr listesine eklenmek uzere gonderiliyor
                    }
                }
                break;
            case 4:
                cout<<"Kaydini silmek istediginiz ogrenci numarasini girin:"<<endl;
                cin>>ogr_no;
                bir_ogrenci=liste.biruyeOku(ogr_no);
                if (bir_ogrenci!=NULL){
                    gecici=liste.cikar(bir_ogrenci);//silinecek olan ogrenci kaydi ptr listesinden cikarilip donduruluyor
                    delete gecici;//ve burada hafizaya serbest birakiliyor
                    cout<<"Ogrenci basariyla silinmistir."<<endl;
                }
                else
                    cout<<"Girdiginiz numaraya ait bir kayit bulunmamaktadir!"<<endl;
                break;
            case 5:
                cout<<"Goruntulemek istediginiz ogrenci numarasini girin:"<<endl;
                cin>>ogr_no;
                bir_ogrenci=liste.biruyeOku(ogr_no);
                if (bir_ogrenci!=NULL){
                    cout<<"Ogr No  Ad       Soyad         Sinif  Not Ort  Dog Tar     Kay Tar"<<endl;
                    cout<<"------  --       -----         -----  -------  -------     -------"<<endl;
                    cout<<*bir_ogrenci<<endl;//asiri yuklenmis ogrenci ekrana yazdiriliyor
                    cout<<"\nTasinabilir Bilgisayar:"<<endl;
                    cout<<"Seri Numarasi   Marka       Model"<<endl;
                    cout<<"-------------   -----       -----"<<endl;
                    cout<<bir_ogrenci->laptopOku()<<endl;//asiri yuklenmis bilgisayar ekrana yazdiriliyor
                }
                else
                    cout<<"Girdiginiz numaraya ait bir kayit bulunmamaktadir!"<<endl;
                break;
            case 6:
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                cout<<liste<<endl;//asiri yuklenmis ptr listesi ekrana yazdiriliyor
                break;
            case 7:
                ogr_say=0;
                cout<<"Goruntulemek istediginiz sinif numarasini girin:"<<endl;
                cin>>sinif;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if (bir_ogrenci->sinifOku()==sinif){//ptr listesinden gelen ogrencilerin kullanicidan alinan sinifta olup olmadigi kontrol ediliyor
                            cout<<*bir_ogrenci<<endl;
                            ogr_say++;
                        }
                    }
                }
                cout<<"\nSinifin ogrenci sayisi:"<<ogr_say<<endl;
                break;
            case 8:
                cout<<"Goruntulemek istediginiz ogrenciler icin bir ad girin:"<<endl;
                fflush(stdin);
                cin>>ad;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if (bir_ogrenci->adoku()==ad)//ptr listesinden gelen ogrencilerin kullanicidan alinan adla ayni olup olmadigi kontrol ediliyor
                            cout<<*bir_ogrenci<<endl;
                    }
                }
                break;
            case 9:
                cout<<"Goruntulemek istediginiz ogrenciler icin bir dogum tarihi girin:"<<endl;
                cin>>d_tarihi;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if (bir_ogrenci->dogumOku()>d_tarihi)//asiri yuklenmis karsilastirma operatoru sayesinde kontrol yapiliyor
                            cout<<*bir_ogrenci<<endl;
                    }
                }
                break;
            case 10:
                cout<<"Goruntulemek istediginiz ogrenciler icin bir kayit yili girin:"<<endl;
                cin>>yil;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if (bir_ogrenci->kayitOku()>yil)//asiri yuklenmis karsilastirma operatoru sayesinde kontrol yapiliyor
                            cout<<*bir_ogrenci<<endl;
                    }
                }
                break;
            case 11:
                cout<<"Goruntulemek istediginiz ogrenciye ait pc nin seri numarasini girin:"<<endl;
                fflush(stdin);
                cin>>seri;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if (((bir_ogrenci->laptopOku()).serinoOku())==seri){
                            cout<<*bir_ogrenci<<endl;
                            break;
                        }
                    }
                }
                break;
            case 12:
                cout<<"Goruntulemek istediginiz ogrencilere ait pc nin markasini girin:"<<endl;
                fflush(stdin);
                cin>>marka;
                cout<<"Goruntulemek istediginiz ogrencilere ait pc nin modelini girin:"<<endl;
                fflush(stdin);
                cin>>model;
                cout<<"Ogr No   Ad          Soyad      Sinif   Not Ort     Dogum Tar     Kayit Tar"<<endl;
                cout<<"------   --          -----      -----   -------     ---------     ---------"<<endl;
                for (int i=0;i<1000;i++){
                    bir_ogrenci=liste.biruyeOku(i+1);
                    if (bir_ogrenci!=NULL){
                        if ((((bir_ogrenci->laptopOku()).markaOku())==marka) && (((bir_ogrenci->laptopOku()).modelOku())==model))
                            cout<<*bir_ogrenci<<endl;//hem marka hem model kontrolu yapiliyor ust satirda
                    }
                }
                break;
        }
    }while (secim!=13);

    return 0;
}

int menu_goster()
{
    int secim;

    cout<<"\n1.Yeni kazanan bir ogrencinin okula kaydedilmesi:\n"
        <<"2.Yatay gecisle gelen bir ogrencinin okula kaydedilmesi:\n"
        <<"3.Yil sonunda tum ogrencilerin siniflarinin ve not ort larinin guncellenmesi:\n"
        <<"4.Bir ogrencinin okuldan kaydinin silinmesi:\n"
        <<"5.Bir ogrencinin bilgilerinin goruntulenmesi:\n"
        <<"6.Okula kayitli tum ogrencilerin goruntulenmesi:\n"
        <<"7.Bir sinifta okuyan ogrencilerin listelenmesi:\n"
        <<"8.Belirli bir ada sahip ogrencilerin listelenmsi:\n"
        <<"9.Belirli bir tarihten once dogan ogrencilerin listelenmesi:\n"
        <<"10.Belirli bir yildan sonra bolume kaydedilmis ogrencilerin listelenmesi:\n"
        <<"11.Bir tasinabilir bilgisayarin verilmis oldugu ogrencinin goruntulenmesi:\n"
        <<"12.Belirli bir marka ve model bilgisayarin verilmis oldugu ogrencilerin listelenmesi:"<<endl;
    cin>>secim;

    return secim;
}
