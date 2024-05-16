#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahDepan(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusDepan() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool perbarui(string namaProdukLama, string namaProdukBaru, int hargaBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == namaProdukLama) {
                current->namaProduk = namaProdukBaru;
                current->harga = hargaBaru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void hapusSemua() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void tampilkan() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->namaProduk << "\t" << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }

    void tambahDiUrutan(string namaProduk, int harga, int posisi) {
        if (posisi == 0) {
            tambahDepan(namaProduk, harga);
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        Node* current = head;
        for (int i = 0; i < posisi - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            newNode->next = nullptr;
            newNode->prev = tail;
            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }

    void hapusDiUrutan(int posisi) {
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        for (int i = 0; i < posisi && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }
};

int main() {
    DoublyLinkedList list;

    // Menambahkan data awal
    list.tambahDepan("Hanasui", 30000);
    list.tambahDepan("Wardah", 50000);
    list.tambahDepan("Skintific", 100000);
    list.tambahDepan("Somethinc", 150000);
    list.tambahDepan("Originote", 60000);

    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.tambahDepan(namaProduk, harga);
                break;
            }
            case 2: {
                list.hapusDepan();
                break;
            }
            case 3: {
                string namaProdukLama, namaProdukBaru;
                int hargaBaru;
                cout << "Masukkan nama produk lama: ";
                cin >> namaProdukLama;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProdukBaru;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;
                bool diperbarui = list.perbarui(namaProdukLama, namaProdukBaru, hargaBaru);
                if (!diperbarui) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk;
                int harga, posisi;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.tambahDiUrutan(namaProduk, harga, posisi);
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.hapusDiUrutan(posisi);
                break;
            }
            case 6: {
                list.hapusSemua();
                break;
            }
            case 7: {
                list.tampilkan();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }

    return 0;
}
