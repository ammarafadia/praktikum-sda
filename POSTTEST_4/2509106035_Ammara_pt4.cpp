#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

const int MAX = 100;

// ================= ARRAY VERSION (ASLI) =================

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

// ================= QUEUE ARRAY =================

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
    cout << "Memanggil: " << h.nama << endl;

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

// ================= STACK ARRAY =================

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
        cout << "Riwayat penuh\n";
        return;
    }
    s.top++;
    *(s.data + s.top) = h;
}

void pop(Stack &s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }
    cout << "Menghapus: " << (s.data + s.top)->nama << endl;
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

// ================= LINKED LIST =================

struct Node {
    Hewan data;
    Node* next;
};

// ================= QUEUE LINKED LIST =================

struct QueueLL {
    Node* front;
    Node* rear;
};

void initQueueLL(QueueLL &q) {
    q.front = q.rear = NULL;
}

bool isEmptyQueueLL(QueueLL q) {
    return q.front == NULL;
}

void enqueueLL(QueueLL &q, Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = NULL;

    if (isEmptyQueueLL(q)) {
        q.front = q.rear = baru;
    } else {
        q.rear->next = baru;
        q.rear = baru;
    }

    cout << "Enqueue (LL) berhasil\n";
}

void dequeueLL(QueueLL &q, Hewan &h) {
    if (isEmptyQueueLL(q)) {
        cout << "Antrian kosong (Underflow)\n";
        return;
    }

    Node* hapus = q.front;
    h = hapus->data;

    cout << "Dequeue (LL): " << h.nama << endl;

    q.front = q.front->next;
    if (q.front == NULL) q.rear = NULL;

    delete hapus;
}

void tampilQueueLL(QueueLL *q) {
    if (isEmptyQueueLL(*q)) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* temp = q->front;
    cout << "\n=== ANTRIAN (LL) ===\n";

    while (temp != NULL) {
        cout << temp->data.id << " - " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// ================= STACK LINKED LIST =================

struct StackLL {
    Node* top;
};

void initStackLL(StackLL &s) {
    s.top = NULL;
}

bool isEmptyStackLL(StackLL s) {
    return s.top == NULL;
}

void pushLL(StackLL &s, Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = s.top;
    s.top = baru;

    cout << "Push (LL) berhasil\n";
}

void popLL(StackLL &s) {
    if (isEmptyStackLL(s)) {
        cout << "Riwayat kosong (Underflow)\n";
        return;
    }

    Node* hapus = s.top;
    cout << "Pop (LL): " << hapus->data.nama << endl;

    s.top = s.top->next;
    delete hapus;
}

void tampilStackLL(StackLL *s) {
    if (isEmptyStackLL(*s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* temp = s->top;
    cout << "\n=== RIWAYAT (LL) ===\n";

    while (temp != NULL) {
        cout << temp->data.id << " - " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// ================= PEEK =================

void peekLL(QueueLL q, StackLL s) {
    cout << "\n=== PEEK (LL) ===\n";

    if (!isEmptyQueueLL(q))
        cout << "Depan: " << q.front->data.nama << endl;
    else
        cout << "Antrian kosong\n";

    if (!isEmptyStackLL(s))
        cout << "Top: " << s.top->data.nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// ================= MAIN =================

int main() {
    Hewan data[MAX];
    int n = 0;

    Queue q;
    Stack s;
    QueueLL qll;
    StackLL sll;

    initQueue(q);
    initStack(s);
    initQueueLL(qll);
    initStackLL(sll);

    int pilihan;

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Enqueue (LL)\n";
        cout << "4. Dequeue (LL)\n";
        cout << "5. Tampil Antrian (LL)\n";
        cout << "6. Push (LL)\n";
        cout << "7. Pop (LL)\n";
        cout << "8. Tampil Riwayat (LL)\n";
        cout << "9. Peek (LL)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(data, n); break;
            case 2: tampilData(data, n); break;

            case 3: {
                int idx; cin >> idx;
                if (idx >= 0 && idx < n)
                    enqueueLL(qll, *(data + idx));
                break;
            }

            case 4: {
                Hewan h;
                dequeueLL(qll, h);
                if (h.id != 0)
                    pushLL(sll, h);
                break;
            }

            case 5: tampilQueueLL(&qll); break;

            case 6: {
                int idx; cin >> idx;
                if (idx >= 0 && idx < n)
                    pushLL(sll, *(data + idx));
                break;
            }

            case 7: popLL(sll); break;
            case 8: tampilStackLL(&sll); break;
            case 9: peekLL(qll, sll); break;

        }

    } while (pilihan != 0);

    return 0;
}