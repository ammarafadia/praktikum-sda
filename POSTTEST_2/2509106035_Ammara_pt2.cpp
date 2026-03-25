#include <iostream>
#include <iomanip>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

const int MAX = 100;

void tampilData(Hewan* arr, int n) {
    cout << "\n=== DATA HEWAN PAWCARE ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ID     : " << (arr + i)->id << endl;
        cout << "Nama   : " << (arr + i)->nama << endl;
        cout << "Jenis  : " << (arr + i)->jenis << endl;
        cout << "Harga  : " << (arr + i)->harga << endl;
        cout << "------------------------\n";
    }
}

void tambahData(Hewan* arr, int &n) {
    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> (arr + n)->id;
    cout << "Nama   : "; cin >> (arr + n)->nama;
    cout << "Jenis  : "; cin >> (arr + n)->jenis;
    cout << "Harga  : "; cin >> (arr + n)->harga;
    n++;
}

void swapPointer(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void linearSearch(Hewan* arr, int n, string key) {
    bool ditemukan = false;
    cout << "\nProses Linear Search:\n";

    for (int i = 0; i < n; i++) {
        cout << "Iterasi ke-" << i+1 << " cek: " << (arr+i)->nama << endl;

        if ((arr + i)->nama == key) {
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << (arr+i)->id << endl;
            cout << "Nama  : " << (arr+i)->nama << endl;
            cout << "Jenis : " << (arr+i)->jenis << endl;
            cout << "Harga : " << (arr+i)->harga << endl;

            swapPointer(arr, arr + i);
            cout << "Data ditukar ke posisi awal.\n";

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}

void fibonacciSearch(Hewan* arr, int n, int key) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    cout << "\nProses Fibonacci Search:\n";

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        cout << "Cek index " << i << " ID: " << (arr+i)->id << endl;

        if ((arr + i)->id < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if ((arr + i)->id > key) {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            cout << "\nData ditemukan!\n";
            cout << "Nama: " << (arr+i)->nama << endl;

            swapPointer(arr, arr + i); // swap pointer
            cout << "Data ditukar ke posisi awal.\n";
            return;
        }
    }

    if (fibMMm1 && (arr + offset + 1)->id == key) {
        cout << "\nData ditemukan!\n";
        cout << "Nama: " << (arr + offset + 1)->nama << endl;

        swapPointer(arr, arr + offset + 1);
        cout << "Data ditukar ke posisi awal.\n";
    }
    else {
        cout << "Data tidak ditemukan.\n";
    }
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                swapPointer(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama.\n";
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;

        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+minIdx)->harga) {
                minIdx = j;
            }
        }

        swapPointer(arr + i, arr + minIdx);
    }
    cout << "Data berhasil diurutkan berdasarkan harga.\n";
}

int main() {
    Hewan data[MAX];
    int n = 0;
    int pilihan;

    do {
        cout << "\n=== PAWCARE PETSHOP MENU ===\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampil Data\n";
        cout << "3. Nama\n";
        cout << "4. ID\n";
        cout << "5. Nama A-Z\n";
        cout << "6. Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(data, n);
                break;
            case 2:
                tampilData(data, n);
                break;
            case 3: {
                string nama;
                cout << "Masukkan nama: ";
                cin >> nama;
                linearSearch(data, n, nama);
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID: ";
                cin >> id;
                fibonacciSearch(data, n, id);
                break;
            }
            case 5:
                bubbleSort(data, n);
                break;
            case 6:
                selectionSort(data, n);
                break;
        }

    } while (pilihan != 0);

    return 0;
}

// Pada Fibonacci Search, pencarian dilakukan dengan cara membagi data menggunakan pola bilangan Fibonacci, sehingga tidak dicek satu per satu seperti Linear Search.

// Setiap iterasi:
// Program menentukan posisi tertentu berdasarkan perhitungan Fibonacci.
// Kemudian membandingkan ID hewan pada posisi tersebut dengan ID yang dicari.
// Jika nilai lebih kecil dari key, pencarian digeser ke bagian kanan.
// Jika nilai lebih besar, pencarian digeser ke bagian kiri.
// Proses ini terus dilakukan dengan memperkecil jangkauan pencarian.

// Jika data ditemukan:
// Program menampilkan data yang dicari.
// Lalu data tersebut ditukar ke posisi awal menggunakan pointer.

// Jika tidak ditemukan:
// Program akan menampilkan bahwa data tidak ditemukan setelah proses pencarian selesai.