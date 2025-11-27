#include <iostream>
using namespace std;

#define MAX 5 

char Q[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}
bool isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(char x) {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    Q[rear] = x;
}

char dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return '\0';
    }

    char data = Q[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return data;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Isi Queue: ";
    int i = front;
    while (true) {
        cout << Q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {

    cout << "=== Mengisi queue hingga penuh ===\n";
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');
    enqueue('E');

    display();
    cout << "Front: " << front << ", Rear: " << rear << endl << endl;

    cout << "=== Menghapus 3 elemen ===\n";
    dequeue();
    dequeue();
    dequeue();

    display();
    cout << "Front: " << front << ", Rear: " << rear << endl << endl;

    cout << "=== Menambah 2 elemen baru ===\n";
    enqueue('X');
    enqueue('Y');

    display();
    cout << "Front: " << front << ", Rear: " << rear << endl;

    return 0;
}
