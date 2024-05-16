#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    // Komponen/member
    string nama;
    int usia;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Node di Depan
void insertDepan(string nama, int usia) {
    // Buat Node baru
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di Belakang
void insertBelakang(string nama, int usia) {
    // Buat Node baru
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah Node di Tengah
void insertTengah(string nama, int usia, int posisi) {
    if (posisi < 1) {
        cout << "Posisi harus lebih dari 0" << endl;
        return;
    }
    if (posisi == 1) {
        insertDepan(nama, usia);
        return;
    }

    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;

    Node* bantu = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (bantu == NULL) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    baru->next = bantu->next;
    bantu->next = baru;
}

// Hapus Node dengan nama tertentu
void hapusData(string nama) {
    Node* hapus = NULL;
    Node* bantu = head;

    if (isEmpty()) {
        cout << "List kosong" << endl;
        return;
    }

    if (head->nama == nama) {
        hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    while (bantu->next != NULL && bantu->next->nama != nama) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;
}

// Ubah data berdasarkan nama
void ubahData(string nama, string namaBaru, int usiaBaru) {
    Node* bantu = head;
    while (bantu != NULL) {
        if (bantu->nama == nama) {
            bantu->nama = namaBaru;
            bantu->usia = usiaBaru;
            return;
        }
        bantu = bantu->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

// Menampilkan seluruh data
void tampilkanList() {
    Node* bantu = head;
    while (bantu != NULL) {
        cout << bantu->nama << "\t" << bantu->usia << endl;
        bantu = bantu->next;
    }
}

int main() {
    init();

    // Memasukkan data awal
    insertDepan("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertTengah("Akechi", 20, 4); // Memasukkan Akechi setelah Michael
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    // Hapus data Akechi
    hapusData("Akechi");

    // Tambahkan data berikut di antara John dan Jane
    insertTengah("Futaba", 18, 2);

    // Tambahkan data berikut di awal
    insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    ubahData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Seluruh Data:" << endl;
    tampilkanList();

    return 0;
}



