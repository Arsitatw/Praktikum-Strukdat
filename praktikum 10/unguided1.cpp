#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void tampilGraph(string simpul[], int busur[][7], int ukuran) {
    for (int baris = 0; baris < ukuran; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < ukuran; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main() {
    int ukuran = 7;
    string simpul[ukuran];
    int busur[ukuran][7] = {0};

    // Input untuk nama kota
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nama untuk kota " << i + 1 << ": ";
        cin >> simpul[i];
    }

    // Input untuk busur
    char pilihan;
    do {
        int dari, ke, bobot;
        cout << "Masukkan indeks kota asal (1-" << ukuran << "): ";
        cin >> dari;
        cout << "Masukkan indeks kota tujuan (1-" << ukuran << "): ";
        cin >> ke;
        cout << "Masukkan bobot busur: ";
        cin >> bobot;
        busur[dari - 1][ke - 1] = bobot;

        cout << "Apakah Anda ingin memasukkan busur lain? (y/t): ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    tampilGraph(simpul, busur, ukuran);

    return 0;
}
