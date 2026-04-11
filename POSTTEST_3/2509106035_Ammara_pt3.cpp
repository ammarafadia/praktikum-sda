#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

const int MAX = 100;

void tampilData(Hewan* arr, int n) {
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr+i)->id << " | "
             << (arr+i)->nama << " | "
             << (arr+i)->jenis << " | "
             << (arr+i)->harga << endl;
    }
}

void tambahData(Hewan* arr, int &n) {
    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> (arr+n)->id;
    cout << "Nama   : "; cin >> (arr+n)->nama;
    cout << "Jenis  : "; cin >> (arr+n)->jenis;
    cout << "Harga  : "; cin >> (arr+n)->harga;
    n++;
}

void swapPointer(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

struct Queue {
    Hewan data[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

bool isFullQueue(Queue q) {
    return q.rear == MAX-1;
}

bool isEmptyQueue(Queue q) {
    return q.rear < q.front;
}

void enqueue(Queue &q, Hewan h) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh (Overflow)\n";
        return;
    }
    q.rear++;
    *(q.data + q.rear) = h;
    cout << "Hewan masuk antrian\n";
}

void dequeue(Queue &q, Hewan &h) {
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong (Underflow)\n";
        return;
    }

    h = *(q.data + q.front);
    cout << "Memanggil: " << h.nama << " (ID: " << h.id << ")\n";

    for (int i = q.front; i < q.rear; i++) {
        *(q.data + i) = *(q.data + i + 1);
    }

    q.rear--;
}

void tampilQueue(Queue *q) {
    if (isEmptyQueue(*q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = q->front; i <= q->rear; i++) {
        cout << (q->data + i)->id << " - "
             << (q->data + i)->nama << endl;
    }
}

struct Stack {
    Hewan data[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isFullStack(Stack s) {
    return s.top == MAX-1;
}

bool isEmptyStack(Stack s) {
    return s.top == -1;
}

void push(Stack &s, Hewan h) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh (Overflow)\n";
        return;
    }
    s.top++;
    *(s.data + s.top) = h;
    cout << "Masuk riwayat\n";
}

void pop(Stack &s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong (Underflow)\n";
        return;
    }
    cout << "Menghapus riwayat: "
         << (s.data + s.top)->nama << endl;
    s.top--;
}

void tampilStack(Stack *s) {
    if (isEmptyStack(*s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = s->top; i >= 0; i--) {
        cout << (s->data + i)->id << " - "
             << (s->data + i)->nama << endl;
    }
}

void peek(Queue q, Stack s) {
    cout << "\n=== PEEK ===\n";

    if (!isEmptyQueue(q)) {
        cout << "Antrian depan: "
             << (q.data + q.front)->nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack(s)) {
        cout << "Riwayat terakhir: "
             << (s.data + s.top)->nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

int main() {
    Hewan data[MAX];
    int n = 0;

    Queue q;
    Stack s;

    initQueue(q);
    initStack(s);

    int pilihan;

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampil Data\n";
        cout << "3. Masuk Antrian\n";
        cout << "4. Panggil Pasien\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Hapus Riwayat (Pop)\n";
        cout << "8. Peek\n";
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
                int idx;
                cout << "Masukkan index hewan: ";
                cin >> idx;

                if (idx >= 0 && idx < n) {
                    enqueue(q, *(data + idx));
                } else {
                    cout << "Index tidak valid!\n";
                }
                break;
            }

            case 4: {
                Hewan h;
                dequeue(q, h);
                if (h.id != 0) {
                    push(s, h);
                }
                break;
            }

            case 5:
                tampilQueue(&q);
                break;

            case 6:
                tampilStack(&s);
                break;

            case 7:
                pop(s);
                break;

            case 8:
                peek(q, s);
                break;
        }

    } while (pilihan != 0);

    return 0;
}