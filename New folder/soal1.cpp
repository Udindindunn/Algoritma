#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int *arr;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }
        arr[++top] = data;
        cout << "Data " << data << " berhasil ditambahkan.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Data " << arr[top--] << " dihapus.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Elemen teratas: " << arr[top] << endl;
    }

    void size() {
        cout << "Jumlah elemen: " << (top + 1) << endl;
    }
};

int main() {
    int cap;
    cout << "Masukkan kapasitas stack: ";
    cin >> cap;

    Stack st(cap);
    int choice, value;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Size\n6. Exit\nPilih: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan data: ";
            cin >> value;
            st.push(value);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            cout << (st.isEmpty() ? "Stack kosong\n" : "Stack tidak kosong\n");
            break;
        case 5:
            st.size();
            break;
        }
    } while (choice != 6);

    return 0;
}