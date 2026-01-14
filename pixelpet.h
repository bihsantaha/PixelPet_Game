#ifndef PIXELPET_H
#define PIXELPET_H

#include <iostream> // input-output işlemleri için
#include <string> // hayvan ismi için
#include <cstdlib> // rastgele değerler için
#include <ctime> // zaman için
#include <thread> // bekleme işlemi için
#include <chrono> // zaman kavramı için
#include <fstream>  //Kullancı oyununu kaydetmek içim

using namespace std;

//---------------------------------------------------------
//renk kodları
const string R_KIRMIZI = "\033[31m";
const string R_YESIL   = "\033[32m";
const string R_SARI    = "\033[33m";
const string R_MAVI    = "\033[34m"; 
const string R_RESET   = "\033[0m";

//---------------------------------------------------------
// Hayvanın değişkenlerini struct içinde aldım
struct Hayvan {
    string isim;
    int aclik_level;
    int mutluluk_level;
    int enerji_level;
};

//---------------------------------------------------------
string renkSec(int deger);
void yavasYaz(const string& metin, int beklemeSuresi); // Yavaş yazdırma fonksiyonu
void oyunuKaydet(const Hayvan &h); //kaydetme ve yükleme
bool oyunuYukle(Hayvan &h);
void menuGoster(); // oyunun ekranının fonksiyonu
void oyunCiz();
void oyna(Hayvan &h);
void yemekCiz();
void besle(Hayvan &h);
void uykuCiz();
void uyu(Hayvan &h);
void turDondu(Hayvan &h);
void hayvanDurumuCiz(const Hayvan &h);

#endif