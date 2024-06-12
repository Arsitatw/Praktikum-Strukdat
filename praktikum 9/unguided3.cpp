#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mahasiswa {
public:
    string NIM;
    int nilai;

    Mahasiswa(string nim, int nilai) : NIM(nim), nilai(nilai) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<Mahasiswa> table[TABLE_SIZE];

    int hashFunction(string nim) {
        int hash = 0;
        for (char c : nim) {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }

public:
    void tambahData(string nim, int nilai) {
        int index = hashFunction(nim);
        for (auto &mhs : table[index]) {
            if (mhs.NIM == nim) {
                cout << "NIM sudah ada dalam tabel." << endl;
                return;
            }
        }
        table[index].emplace_back(nim, nilai);
        cout << "data berhasil ditambahkan." << endl;
    }

    void hapusData(string nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == nim) {
                table[index].erase(it);
                cout << "data berhasil dihapus." << endl;
                return;
            }
        }
        cout << "NIM tidak ditemukan." << endl;
    }

    void cariBerdasarkanNIM(string nim) {
        int index = hashFunction(nim);
        for (auto &mhs : table[index]) {
            if (mhs.NIM == nim) {
                cout << "NIM: " << mhs.NIM << ", Nilai: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "NIM tidak ditemukan." << endl;
    }

    void cariBerdasarkanRentangNilai(int nilai_min, int nilai_max) {
        bool ditemukan = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto &mhs : table[i]) {
                if (mhs.nilai >= nilai_min && mhs.nilai <= nilai_max) {
                    cout << "NIM: " << mhs.NIM << ", Nilai: " << mhs.nilai << endl;
                    ditemukan = true;
                }
            }
        }
        if (!ditemukan) {
            cout << "tidak ada mahasiswa dengan nilai dalam rentang " << nilai_min << " - " << nilai_max << "." << endl;
        }
    }
};

void tampilkanMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah data baru" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Cari data berdasarkan NIM" << endl;
    cout << "4. Cari data berdasarkan rentang nilai (80 - 90)" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main() {
    HashTable ht;
    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                string nim;
                int nilai;
                cout << "masukkan NIM: ";
                cin >> nim;
                cout << "masukkan nilai: ";
                cin >> nilai;
                ht.tambahData(nim, nilai);
                break;
            }
            case 2: {
                string nim;
                cout << "masukkan NIM: ";
                cin >> nim;
                ht.hapusData(nim);
                break;
            }
            case 3: {
                string nim;
                cout << "masukkan NIM: ";
                cin >> nim;
                ht.cariBerdasarkanNIM(nim);
                break;
            }
            case 4: {
                ht.cariBerdasarkanRentangNilai(80, 90);
                break;
            }
            case 5:
                cout << "keluar dari program." << endl;
                break;
            default:
                cout << "pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}
