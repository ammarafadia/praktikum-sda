#include <iostream>

using namespace std;

// Fungsi untuk membalikkan array menggunakan pointer logic
void reverseArray(int* arr, int n) {
    int* start = arr; 
    int* end = arr + (n - 1); 
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

void tampilkanArray(int* arr, int n) {
    cout << "----------------------------------------------------" << endl;
    cout << "Indeks\tIsi\tAlamat Memori (Pointer)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << *(arr + i) << "\t" << (arr + i) << endl;
    }
    cout << "----------------------------------------------------" << endl;
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "=== ARRAY SEBELUM DIBALIK ===" << endl;
    tampilkanArray(prima, n);

    reverseArray(prima, n);

    cout << "\n=== ARRAY SESUDAH DIBALIK (REVERSED) ===" << endl;
    tampilkanArray(prima, n);

    return 0;
}