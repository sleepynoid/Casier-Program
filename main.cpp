#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
struct goodsSale {
    string nama;
    int harga,stock,jumlah;
};
struct goodsCart {
    string nama;
    int harga,stock,jumlah;
};
struct goodsSale barang[10];
struct goodsCart keranjang[10];
int Index = 1;

int searchByName(string cariNama,goodsSale (&barang)[10]){
    int tempIndex = -1;
    for (int i = 0 ; i <= Index ; i++) {
        if (cariNama==barang[i].nama){
            tempIndex = i;
        }
    }
    return tempIndex;
}
void addGoods() {
    int tempIndex = Index++;
    getline(cin,barang[tempIndex].nama);
    cin >> barang[tempIndex].harga;
    cin >> barang[tempIndex].stock;
    Index++;
}
bool addsItem(string namaBarang,goodsSale (&barang)[10]) {
    int tmpIndex = searchByName(namaBarang,barang),tmpJumlah;
    int tmpJumlahMax = barang[tmpIndex].stock - barang[tmpIndex].jumlah;
    if (tmpIndex != -1 && tmpJumlahMax != 0) {
        do {
            printf("Masukan jumlah %s yang anda beli [%d] : ", barang[tmpIndex].nama.c_str(), barang[tmpIndex].stock);
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
void viewcart(goodsSale (&barang)[10]) {
    int tmpIndex[10],cart;
    for (int n=-1,i=0; i <= Index; i++) {
        if (barang[i].jumlah != 0) {
            n++;
            tmpIndex[n] = i;
        }
    }
}
int main() {
    barang[0] = {"mie sedaap", 3500, 20, 10};
    barang[1] = {"kecap", 2000, 15, 0};
    printf("Menu\n");
    printf("1. tambah barang ke keranjang\n");
    printf("2. hapus barang dari keranjang\n");
    printf("3. melihat isi keranjang\n");
    printf("4. tambah barang ke stock\n");
    printf("5. exit\n");
    int pilihan,tmp;
    string nama;
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
            break;
        case 4:
            break;
        case 5:
            break;
    }
}