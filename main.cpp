/*
    by bihsantaha
    !!! Tested in macOS. Not tested in Windows
*/



#include "pixelpet.h"

//---------------------------------------------------------
//değere göre renk
string renkSec(int deger) {
    if (deger >= 70) return R_YESIL; // İyi durum
    if (deger >= 30) return R_SARI;  // Orta durum
    return R_KIRMIZI;                // Kötü durum
}
//---------------------------------------------------------
//fonk
void yavasYaz(const string& metin, int beklemeSuresi) {
    for (char karakter : metin) {
        cout << karakter << flush;
        this_thread::sleep_for(chrono::milliseconds(beklemeSuresi));
    }
}
//---------------------------------------------------------
//system cleardan daha az hata problemi olduğunu düşündüğüm için
void ekraniTemizle(int satirSayisi = 50) {
    for (int i = 1; i < satirSayisi; ++i) {
        cout << "\n";
    }
}
//---------------------------------------------------------
void oyunuKaydet(const Hayvan &h) {
    ofstream dosya("pixelpet_data.txt");
    if (dosya.is_open()) {
        dosya << h.isim << endl;
        dosya << h.aclik_level << endl;
        dosya << h.mutluluk_level << endl;
        dosya << h.enerji_level << endl;
        dosya.close();
    }
}
//---------------------------------------------------------
bool oyunuYukle(Hayvan &h) {
    ifstream dosya("pixelpet_data.txt");
    if (dosya.is_open()) {
        dosya >> h.isim >> h.aclik_level >> h.mutluluk_level >> h.enerji_level;
        dosya.close();
        return true;
    }
    return false;
}
//---------------------------------------------------------
void menuGoster() {
    cout << "\n\n" << R_MAVI << "<<------------Komutlar------------>>" << R_RESET << "\n";
    cout << "1. Besle \n";
    cout << "2. Oyna \n";
    cout << "3. Uyut \n";
    cout << "4. Kaydet \n";
    cout << "5. Cikis \n";
    cout << "\nSeciminiz: ";
}
//---------------------------------------------------------
void oyunCiz() {
    cout << "\n";
    cout << "         .---. " << endl;
    cout << "       .' / \\ `." << endl;
    cout << "      |---|o|---|" << endl;
    cout << "       `. \\ / .'" << endl;
    cout << "         `---'          " << endl;
}
//---------------------------------------------------------
void oyna(Hayvan &h){
    if (h.mutluluk_level >= 100){
        yavasYaz(h.isim + " zaten mutlu! oynamayi dusunmuyor.", 20);
    } else {
        h.mutluluk_level += 20;
        h.enerji_level -= 10;
        h.aclik_level -= 20;
        if (h.mutluluk_level > 100) h.mutluluk_level = 100;
        cout<<"\n";
        yavasYaz(h.isim + " oyununu oynadi. \n(Mutluluk +20)\n(Enerji -10)\n(Aclik -20)", 20);
    }
}
//---------------------------------------------------------
void yemekCiz() {
    cout << "\n";
    cout << "        .:'" << endl;
    cout << "      __ :'__" << endl;
    cout << "   .'`  `-'  ``." << endl;
    cout << "   :           :" << endl;
    cout << "   :           :" << endl;
    cout << "    :         : " << endl;
    cout << "     `.__.__.'          " << endl;
}
//---------------------------------------------------------
void besle(Hayvan &h) {
    if (h.aclik_level >= 100) {
        yavasYaz(h.isim + " zaten tok! Yemegi reddetti.", 20);
    } else {
        h.aclik_level += 20;
        if(h.aclik_level > 100) h.aclik_level = 100;

        cout<<"\n";
        yavasYaz(h.isim + " mamasini yedi. \n(Aclik +20)", 20);
    }
}
//---------------------------------------------------------
void uykuCiz() {
    cout << "\n";
    cout << "         z" << endl;
    cout << "       Z" << endl;
    cout << "      |==| " << endl;
    cout << "      |  |____________" << endl;
    cout << "      |  |############|" << endl;
    cout << "      |__|############|" << endl;
    cout << "       ||          ||          " << endl; 
}
//---------------------------------------------------------
void uyu(Hayvan &h){
    if (h.enerji_level >= 100) {
        yavasYaz(h.isim + " uyumak istemiyor! enerji duzeyi full duzeyde", 20);
    } else {
        h.enerji_level += 30;
        h.aclik_level -= 5;
        h.mutluluk_level -= 3;
        if (h.enerji_level > 100 ) h.enerji_level = 100;

        cout<<"\n";
        yavasYaz(h.isim + " uyudu! \n(Enerji +20)\n(Aclik -5)\n(Mutluluk -3)", 20);
    }
}
//---------------------------------------------------------
void turDondu(Hayvan &h) {
    h.aclik_level -= (rand() % 8 + 2);
    h.enerji_level -= (rand() % 8 + 2);
    h.mutluluk_level -= (rand() % 8 + 2);

    if(h.aclik_level < 0) h.aclik_level = 0;
    if(h.enerji_level < 0) h.enerji_level = 0;
    if(h.mutluluk_level < 0) h.mutluluk_level = 0;
}
//---------------------------------------------------------
void hayvanDurumuCiz(const Hayvan &h) {
    cout << "\n";
    if (h.aclik_level < 30) {
        cout << R_KIRMIZI << "      ( O_____O )  < ( Karnim gurulduyor! )" << R_RESET << endl;
        cout << R_KIRMIZI << "      (  vvvvv  ) " << R_RESET << endl;
    } else if (h.enerji_level < 20) {
        cout << "      ( -_____- )  < ( Cok uykum var... )" << endl;
        cout << "      (         ) " << endl;
    } else if (h.mutluluk_level < 30) {
        cout << "      ( ;_____; )  < ( Canim sikkin... )" << endl;
        cout << "      (  ^___^  ) " << endl;
    } else {
        cout << R_YESIL << "      ( ^_____^ )  < ( Yasasin! )" << R_RESET << endl;
        cout << R_YESIL << "      (  vvvvv  ) " << R_RESET << endl;
    }
    cout << "      (_________)" << endl;
    cout << "       /       \\  " << endl;
    cout << "      /         \\ " << endl << endl;
}


//---------------------------------------------------------
int main() {
    char kayitSecimi;
    Hayvan hayvanVerilerim;
    srand(static_cast<unsigned int>(time(0))); 

    yavasYaz("\n\n**************************************\n", 15);
    yavasYaz("******** " + R_YESIL + " Oyun Yukleniyor" + R_RESET + "   **********\n", 15);
    yavasYaz("**************************************\n", 15);
    yavasYaz("\nPiksel Varlik Oyununa Hosgeldiniz!\n\n", 30);
    yavasYaz("Onceki kayittan devam etmek istermisiniz? ('e'/'E') ", 30);
    cout<<"\nistemiyorsanız başka harfe basıp devam ediniz"<<endl;
    cin >> kayitSecimi;

    bool yuklemeBasarili = false;
    
    //oyun yukleme kontrolu
    if (kayitSecimi == 'e' || kayitSecimi == 'E') {
        if (oyunuYukle(hayvanVerilerim)) {
            yavasYaz("\n" + R_YESIL + "Kayit bulundu! " + hayvanVerilerim.isim + " geri dondu!" + R_RESET, 30);
            yuklemeBasarili = true;
        } else {
            yavasYaz("\n" + R_KIRMIZI + "Kayit dosyasi bulunamadi! Yeni oyun baslatiliyor..." + R_RESET, 30);
        }
    }
    
    //yeni oyun
    if (!yuklemeBasarili) {
        yavasYaz("\nDostunuza bir ad verin: ", 25);
        cin >> hayvanVerilerim.isim;

        hayvanVerilerim.aclik_level = rand() % 41 + 20;
        hayvanVerilerim.enerji_level = rand() % 21 + 70;
        hayvanVerilerim.mutluluk_level = rand() % 51 + 20;

        yavasYaz("\n\nBaslangic Değerleri Hazirlandi\n", 30);
        yavasYaz(hayvanVerilerim.isim + " canlısının başlangıç değerleri:\n", 35);
        yavasYaz("Enerji: " + to_string(hayvanVerilerim.enerji_level) + "\n", 35);
        yavasYaz("Mutluluk: " + to_string(hayvanVerilerim.mutluluk_level) + "\n", 35);
        yavasYaz("Açlık: " + to_string(hayvanVerilerim.aclik_level) + "\n", 35);
    }

    yavasYaz("\nMenuye yonlendiriliyorsunuz...", 50);
    this_thread::sleep_for(chrono::seconds(1));

    int secim = 0;
    bool oyunDevam = true;

    while (oyunDevam) {
        ekraniTemizle();
        
        //olup olmedıgının kontrolu
        if (hayvanVerilerim.aclik_level <= 0 || hayvanVerilerim.mutluluk_level <= 0 || hayvanVerilerim.enerji_level <= 0) {
            cout << "\n\n" << R_KIRMIZI << "=================================" << endl;
            cout << "OYUN BITTI! " << hayvanVerilerim.isim << " aramizdan ayrildi..." << endl;
            cout << "=================================" << R_RESET << endl;
            break; 
        }

        cout << R_MAVI << "<<≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈>>" << R_RESET << endl;
        cout << "         " << hayvanVerilerim.isim << "  Adli Piksel Varligin" << endl;
        cout << R_MAVI << "<<≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈>>" << R_RESET << endl;
        
        hayvanDurumuCiz(hayvanVerilerim);
        cout << "Aclik   : " << renkSec(hayvanVerilerim.aclik_level) 
             << hayvanVerilerim.aclik_level << "/100" << R_RESET << endl;

        cout << "Mutluluk: " << renkSec(hayvanVerilerim.mutluluk_level) 
             << hayvanVerilerim.mutluluk_level << "/100" << R_RESET << endl;

        cout << "Enerji  : " << renkSec(hayvanVerilerim.enerji_level) 
             << hayvanVerilerim.enerji_level << "/100" << R_RESET << endl;
        
        menuGoster();
        
        while (!(cin >> secim)) {
            cout << "\n" << R_KIRMIZI << "Hatali giris! Lutfen sadece sayi giriniz." << R_RESET << "\n";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Seciminiz: ";
        }

        switch (secim) {
            case 1:
                yemekCiz();
                yavasYaz("\nYem veriliyor...", 80);
                besle(hayvanVerilerim);
                yavasYaz("\nekran yenileniyor 3 2 1", 150);
                break;
            case 2:
                oyunCiz();
                yavasYaz("\nOyun oynaniyor...", 80);
                oyna(hayvanVerilerim);
                yavasYaz("\nekran yenileniyor 3 2 1", 150);
                break;
            case 3:
                uykuCiz();
                yavasYaz("\nUyutuluyor...", 80);
                uyu(hayvanVerilerim);
                yavasYaz("\nekran yenileniyor 3 2 1", 150);
                break;
            case 4:
                oyunuKaydet(hayvanVerilerim);
                yavasYaz("\n" + R_YESIL + "Oyun kaydedildi!" + R_RESET, 30);
                yavasYaz("\n~~~~~~.*", 300);
                break;
            case 5:
                yavasYaz("\nGorusmek uzere!", 50);
                yavasYaz("\n~~~~~~.*", 300);
                oyunDevam = false; 
                break;
            default:
                cout << "\nGecersiz secim! Tekrar deneyin.\n";
        }
        
        if (oyunDevam && secim != 4 && secim != 5) {
            turDondu(hayvanVerilerim);
            this_thread::sleep_for(chrono::milliseconds(400));
        }
    }
    
    return 0;
}