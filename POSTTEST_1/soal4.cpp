#include <iostream>

using namespace std;

void swapDuaBilangan(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    cout << "=== Program Menukar Dua Bilangan (Pointer) ===" << endl;
    
    cout << "Masukkan nilai pertama (x): ";
    cin >> x;
    cout << "Masukkan nilai kedua   (y): ";
    cin >> y;

    cout << "\n[Sebelum Pertukaran]" << endl;
    cout << "Nilai x: " << x << " (Alamat: " << &x << ")" << endl;
    cout << "Nilai y: " << y << " (Alamat: " << &y << ")" << endl;

    swapDuaBilangan(&x, &y);

    cout << "\n[Sesudah Pertukaran]" << endl;
    cout << "Nilai x: " << x << " (Alamat: " << &x << ")" << endl;
    cout << "Nilai y: " << y << " (Alamat: " << &y << ")" << endl;

    return 0;
}