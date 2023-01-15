#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    char U_barang_nama[10][20];
    int U_barang_jumlah[10];
    int loop = 1, nloop;
    while (loop <= 10) {
        printf("###Menu###\n");
        printf("1. sabun\tRp.3000\n2. odol \tRp.8000\n3. rinso\tRp.5000\n");
        printf("Masukan Nama Barang : ");
        scanf("%s",&U_barang_nama[loop][0]);
        printf("Jumlah barang : ");
        scanf("%d",&U_barang_jumlah[loop]);
        // printf("#%d Nama barang %s, jumlah %d\n",loop,U_barang_nama[loop],U_barang_jumlah[loop]); //debug
        printf("Apakah Anda ingin Beli yang lain(y/n)? ");
        char respon = ' ';
        cin >> respon;
        if (respon == 'y' || respon == 'Y') {
            loop++;
        }
        else if (respon == 'n' || respon == 'N') {
            nloop = loop;
            loop=11;
        }
    }
    char F_barang_tersedia[4][20] = {
        "NULL",
        "sabun",
        "odol",
        "rinso"
    };
    int barang_harga[10] = {
        0,
        3000,
        8000,
        5000
    };
    char F_barang_nama[10][20];
    int F_barang_jumlah[10];
    int count = 0;
    // khusus filter nama barang
    char F_barang_nama_salah[10][20];
    int ncount=0;
    int count_salah=0;
    for (int i=1; i <= nloop; i++) {
        for (int l=1; l <= 4; l++) {
            if ((strcmp(F_barang_tersedia[l],U_barang_nama[i])) == 0) {
                count++;
                strcpy(F_barang_nama[count],U_barang_nama[i]);
                F_barang_jumlah[count] = U_barang_jumlah[i];
                // printf("benar ke-%d, U_barang %s, jumlah %d\n",count,U_barang_nama[i],U_barang_jumlah[i]);
                // printf("SESUDAH benar ke-%d, F_barang %s, jumlah %d\n",count++,F_barang_nama[i],F_barang_jumlah[i]);
            }
            else {
                ncount++;
                if ((ncount%3) == 0) {
                    count_salah++;
                    strcpy(F_barang_nama_salah[count_salah],U_barang_nama[i]);
                    //printf("barang_salah #%d%s, U_barang %d%s\n",count_salah,F_barang_nama_salah[count_salah],i,U_barang_nama[i]);
                }
            }
        }
    }
    for (int i=1; i<= count_salah; i++) {
        printf("Maaf barang %s tidak tersedia\n",F_barang_nama_salah[i]);
    }
    cout << endl;
    // printf("barang yang benar ada = %d\n",count);
    // kondisi pengujian semua disini
    int F_barang_harga[10];
    for (int i=1,n=1; i <= count; i++) {
        if ((strcmp(F_barang_tersedia[1],F_barang_nama[i])) == 0) {
            F_barang_harga[n]=barang_harga[1];
            // printf("#%d F_barang %s, jumlah %d, harga %d\n",n++,F_barang_nama[i],F_barang_jumlah[i],F_barang_harga[n]);
            n++;
        }
        else if ((strcmp(F_barang_tersedia[2],F_barang_nama[i])) == 0) {
            F_barang_harga[n]=barang_harga[2];
            // printf("#%d F_barang %s, jumlah %d, harga %d\n",n++,F_barang_nama[i],F_barang_jumlah[i],F_barang_harga[n]);
            n++;
        }
        else if ((strcmp(F_barang_tersedia[3],F_barang_nama[i])) == 0) {
            F_barang_harga[n]=barang_harga[3];
            n++;
            // printf("#%d F_barang %s, jumlah %d, harga %d\n",n++,F_barang_nama[i],F_barang_jumlah[i],F_barang_harga[n]);
        }
    }
    printf("STRUK\n");
    printf("==================================\n");
    for (int i=1; i <= count; i++) {
        printf("Nama Barang : %s\n",F_barang_nama[i]);
        printf("Harga : %d\n",F_barang_harga[i]);
        printf("Jumlah : %d\n", F_barang_jumlah[i]);
    }
    int sum = 0;
    for (int i=1; i <= count; i++) {
        // printf("jumlah %d, harga %d\n",F_barang_jumlah[i],F_barang_harga[i]);
        sum+=F_barang_jumlah[i]*F_barang_harga[i];
    }
    printf("Total bayar : %d\n",sum);
    int tunai;
    while (tunai < sum) {
        printf("Bayar : ");
        scanf("%d",&tunai);
        if (tunai >= sum) {
            // printf("sum %d, tunai %d\n",sum,tunai);
            int tmp = tunai-sum;
            printf("Kembali : %d",tmp);
        }
        else {
            cout<<"Maaf Uang Tunai Anda Kurang\n";
        }
    }
}