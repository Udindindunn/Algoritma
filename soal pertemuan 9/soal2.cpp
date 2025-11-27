#include <iostream>

using std::cout;
using std::endl;

const int MAX_SIZE = 10;

struct Queue {
    char data[MAX_SIZE]; 
    int front; 
    int rear;  
};

bool is_empty(const Queue& q) {
    return (q.front == -1);
}

bool is_full(const Queue& q) {
    return ((q.front == (q.rear + 1) % MAX_SIZE));
}


void insert(Queue& q, char x) {
    if (is_full(q)) {
        cout << "Queue penuh! Tidak bisa insert '" << x << "'.\n";
        return;
    }

    if (is_empty(q)) {

        q.front = q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % MAX_SIZE;
    }

    q.data[q.rear] = x;
}

char remove(Queue& q) {
    if (is_empty(q)) {
        cout << "Queue kosong! Tidak ada yang di-remove.\n";
        return '\0';
    }

    char removed = q.data[q.front];

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % MAX_SIZE;
    }

    return removed;
}

void display(const Queue& q) {
    if (is_empty(q)) {
        cout << "Isi Queue: (kosong)\n";
        return;
    }

    cout << "Isi Queue: ";
    int i = q.front;
    while (true) {
        cout << q.data[i] << " ";
        if (i == q.rear) break;
        i = (i + 1) % MAX_SIZE; 
    }
    cout << endl;
}


int main() {

    Queue q;
    q.front = q.rear = -1;

    insert(q, 'A');
    insert(q, 'R');
    insert(q, 'I');
    insert(q, 'F');

    cout << "--- Operasi Queue ---\n";
    cout << "Setelah insert A, R, I, F:\n";
    display(q);

    cout << "\nMelakukan Dequeue (Remove):\n";
    char removed1 = remove(q);
    if (removed1 != '\0') {
        cout << "Remove 1: '" << removed1 << "' dihapus.\n";
    }

    char removed2 = remove(q);
    if (removed2 != '\0') {
        cout << "Remove 2: '" << removed2 << "' dihapus.\n";
    }

    cout << "\nSetelah remove 2 elemen:\n";
    display(q);
    
    for (int i = 0; i < 6; ++i) {
        insert(q, (char)('0' + i));
    }
    cout << "\nSetelah insert 6 elemen lagi:\n";
    display(q);
    
    insert(q, 'Z');

    return 0;
}