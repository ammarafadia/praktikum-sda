#include <iostream>
using namespace std;

// Pseudocode:
// procedure FindMin(A : array of n elements)
//   min ← A[0]
//   for i ← 1 to n - 1 do
//     if A[i] < min then
//       min ← A[i]
//     end if
//   end for
//   return min
// end procedure

int FindMin(const int A[], int n, int &minIndex) {
    int mn = A[0];
    minIndex = 0;

    for (int i = 1; i <= n - 1; i++) {
        if (A[i] < mn) {
            mn = A[i];
            minIndex = i;
        }
    }
    return mn;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int idxMin = -1;
    int minVal = FindMin(A, n, idxMin);

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << A[i] << (i < n-1 ? " " : "\n");

    cout << "Nilai minimum = " << minVal << "\n";
    cout << "Indeks minimum = " << idxMin << "\n";

    return 0;
}

// ========================================================
// Analisis kompleksitas (tabel pseudocode + cost)
// ========================================================
// Kita hitung biaya dengan konstanta per operasi:

// (1) min = A[0]                       -> biaya c1, dieksekusi 1 kali
// (2) i = 1                            -> biaya c2, dieksekusi 1 kali
// (3) cek kondisi loop (i <= n-1)       -> biaya c3, dieksekusi n kali
//     (untuk i=1..n-1 berhasil, lalu 1 kali gagal saat keluar)
// (4) if (A[i] < min)                  -> biaya c4, dieksekusi (n-1) kali
// (5) min = A[i] (hanya jika true)      -> biaya c5, tergantung kasus
// (6) i++                               -> biaya c6, dieksekusi (n-1) kali
// (7) return min                        -> biaya c7, dieksekusi 1 kali

// Jumlah eksekusi baris (5):
// - Best case: kondisi if selalu FALSE (array sudah non-decreasing),
//   jadi baris (5) dieksekusi 0 kali.
// - Worst case: kondisi if selalu TRUE (array strictly decreasing),
//   jadi baris (5) dieksekusi (n-1) kali.

// Maka:
// Tmin(n) = c1 + c2 + (n)c3 + (n-1)c4 + 0*c5 + (n-1)c6 + c7
//         = (c3 + c4 + c6)n + (c1 + c2 + c7 - c4 - c6)

// Tmax(n) = c1 + c2 + (n)c3 + (n-1)c4 + (n-1)c5 + (n-1)c6 + c7
//         = (c3 + c4 + c5 + c6)n + (c1 + c2 + c7 - c4 - c5 - c6)

// Kesimpulan:
// - Best case  : O(n)  (bahkan Θ(n))
// - Worst case : O(n)  (bahkan Θ(n))
// ========================================================