#include <iostream>
#include <iterator>
#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
struct goodsSale {
    string nama;
    int harga,stock,jumlah;
};
struct goodsSale barang[10];
struct goodsSale history[10];
int Index = 1,IndexHistory = -1;

int searchByName(string cariNama,goodsSale (&barang)[10]){
    int tempIndex = -1;
    for (int i = 0 ; i <= Index ; i++) {
        if (cariNama==barang[i].nama){
            tempIndex = i;
        }
    }
    return tempIndex;
}
bool addsItem(string namaBarang,goodsSale (&barang)[10]) {
    int tmpIndex = searchByName(namaBarang,barang),tmpJumlah;
    int tmpJumlahMax = barang[tmpIndex].stock - barang[tmpIndex].jumlah;
    if (tmpIndex != -1 && tmpJumlahMax != 0) {
        do {
            printf("Masukan jumlah %s yang anda beli [%d] : ", barang[tmpIndex].nama.c_str(), tmpJumlahMax);
            cin >> tmpJumlah;
            if (tmpJumlah > tmpJumlahMax) printf("Maaf Jumlah Pembelian Melebihi Stock\n");
            else if (tmpJumlah < 0) printf("Masukan Jumlah dengan Benar\n");
        } while (tmpJumlah > tmpJumlahMax || tmpJumlah < 0) ;
        barang[tmpIndex].jumlah = tmpJumlah;
        return true;
    }
    else printf("maaf barang tidak tersedia\n");
    return false;
}
void removeItem(string namaBarang,goodsSale (&barang)[10]) {
    int tmpIndex = searchByName(namaBarang, barang),tmpJumlah;
    int tmpJumlahMax = barang[tmpIndex].jumlah;
    if (tmpIndex != -1 && tmpJumlahMax != 0) {
        do {
            printf("Masukan jumlah %s yang anda hapus [%d] : ",barang[tmpIndex].nama.c_str(),barang[tmpIndex].jumlah);
            cin >> tmpJumlah;
        } while (tmpJumlah > tmpJumlahMax || tmpJumlah < 0);
        barang[tmpIndex].jumlah -= tmpJumlah;
    }
}
void viewCart(goodsSale (&barang)[10]) {
    printf("|Nama Barang|\tHarga barang|\tStok Barang|DiKeranjang\n");
    for (int i = 0; i <= Index; i++) {
        printf("%s\t %d    \t %d\t\t %d\t\n", barang[i].nama.c_str(), barang[i].harga, barang[i].stock, barang[i].jumlah);
    }
    printf("================================================\n");
}
void viewBarang(goodsSale (&barang)[10]) {
    printf("|Nama Barang|\tHarga barang|\tStok Barang|\n");
    for (int i = 0; i <= Index; i++) {
        printf("%s\t %d\t\t %d\t\n", barang[i].nama.c_str(), barang[i].harga, barang[i].stock);
    }
    printf("--------------------------------------------\n");
}
void addGoods(string namaBarang, int harga, int stock, struct goodsSale (&barang)[10]) {
    int tempIndex = ++Index;
    barang[tempIndex].nama = namaBarang;
    barang[tempIndex].harga = harga;
    barang[tempIndex].stock = stock;
}
void addsHistory(goodsSale (&barang)[10],goodsSale (&history)[10]) {
    int tmpIndex[10],find = -1;
    for (int i=0; i <= Index; i++) {
        if (barang[i].jumlah != 0) {
            tmpIndex[++find] = i;
        }
    }
    for (int i=0; i <= find; i++) {
        history[++IndexHistory].nama = barang[tmpIndex[i]].nama;
        history[IndexHistory].harga = barang[tmpIndex[i]].harga;
        history[IndexHistory].stock = barang[tmpIndex[i]].stock;
        history[IndexHistory].jumlah = barang[tmpIndex[i]].jumlah;
    }
}
void checkout(goodsSale (&barang)[10]) {
    int tmpIndex[10],find = -1;
    for (int i=0; i <= Index; i++) {
        if (barang[i].jumlah != 0) {
            tmpIndex[++find] = i;
        }
    }
    int total = 0,tunai = 0;
    for (int i=0; i <= find; i++) {
        printf("barang 1=%d barang 2=%d",barang[tmpIndex[find]].harga, barang[tmpIndex[find]].jumlah);
        total += barang[tmpIndex[find]].harga * barang[tmpIndex[find]].jumlah;
    }
    cout << total;
    while (tunai < total) {
        printf("masukan tunai : ");
        cin >> tunai;
        if (tunai < total) printf("tunai kurang");
    }
}
void _menu() {
    barang[0] = {"mie sedaap", 3500, 20, 10};
    barang[1] = {"kecap manis", 2000, 15, 0};
    viewBarang(barang);
    printf("Menu\n");
    printf("mie sedaap kecap\n");
    printf("1. tambah barang ke keranjang\n");
    printf("2. hapus barang dari keranjang\n");
    printf("3. melihat isi keranjang\n");
    printf("4. tambah barang ke stock\n");
    printf("5. checkout\n");
    printf("6. exit\n");
    printf("[1-6] ==> ");
}

int main() {
    int pilihan,tmp;
    string nama;
    bool exit = false,first = false;
    do {
        _menu();
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                printf("Masukan Nama Barang : ");
                getline(cin,nama);
                addsItem(nama, barang);
                break;
            case 2:
                getline(cin,nama);
                removeItem(nama, barang);
                break;
            case 3:
                viewCart(barang);
                break;
            case 4:
                printf("Masukan Nama Barang : ");
                getline(cin,nama);
                int harga,stock;
                printf("Masukan Harga barang : ");
                cin >> harga;
                printf("Masukan Stok Barang : ");
                cin >> stock;
                addGoods(nama, harga, stock, barang);
                break;
            case 5:
                addsHistory(barang,history);
                viewCart(history);
                checkout(barang);
                break;
    }
    sleep_for(3s);
    }while (exit == false);
}
