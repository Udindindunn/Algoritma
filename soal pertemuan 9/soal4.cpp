#include <iostream>
using namespace std;

struct Pelanggan {
    int nomor;
    int lamaPelayanan;
    Pelanggan* next;
};

Pelanggan* front = NULL;
Pelanggan* rear = NULL;

bool isEmpty() {
    return (front == NULL);
}

void enqueue(int nomor, int lama) {
    Pelanggan* baru = new Pelanggan;
    baru->nomor = nomor;
    baru->lamaPelayanan = lama;
    baru->next = NULL;

    if (isEmpty()) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Pelanggan nomor " << nomor 
         << " ditambahkan (lama pelayanan: " << lama << " detik)\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Tidak ada pelanggan yang menunggu.\n";
        return;
    }

    Pelanggan* hapus = front;
    cout << "Melayani pelanggan nomor " << hapus->nomor
         << " (lama pelayanan: " << hapus->lamaPelayanan << " detik)\n";

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete hapus;
}

void tampilkanAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Pelanggan yang sedang menunggu:\n";
    Pelanggan* temp = front;
    while (temp != NULL) {
        cout << "- Nomor " << temp->nomor
             << " (lama pelayanan: " << temp->lamaPelayanan << " detik)\n";
        temp = temp->next;
    }
}

int jumlahAntrian() {
    int count = 0;
    Pelanggan* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int pilihan, nomor = 1;

    while (true) {
        cout << "\n=== SIMULASI ANTRIAN KASIR ===\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Layani pelanggan\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Tampilkan jumlah pelanggan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int lama;
            cout << "Masukkan lama pelayanan (detik): ";
            cin >> lama;
            enqueue(nomor++, lama);
        }
        else if (pilihan == 2) {
            dequeue();
        }
        else if (pilihan == 3) {
            tampilkanAntrian();
        }
        else if (pilihan == 4) {
            cout << "Jumlah pelanggan dalam antrian: "
                 << jumlahAntrian() << endl;
        }
        else if (pilihan == 5) {
            cout << "Program selesai.\n";
            break;
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
