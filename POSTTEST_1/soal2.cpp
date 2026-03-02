#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    // Input data
    cout << "=== Input Data Mahasiswa ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "NIM  : ";
        getline(cin, mhs[i].nim);

        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    // Mencari IPK tertinggi
    int indeksTertinggi = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[indeksTertinggi].ipk) {
            indeksTertinggi = i;
        }
    }

    // Menampilkan hasil
    cout << "\n=== Mahasiswa dengan IPK Tertinggi ===" << endl;
    cout << "Nama : " << mhs[indeksTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksTertinggi].ipk << endl;

    return 0;
}