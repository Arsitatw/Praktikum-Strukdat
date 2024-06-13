# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
Graf dan Tree adalah dua struktur data fundamental dalam ilmu komputer yang digunakan untuk merepresentasikan hubungan antara objek. Graf terdiri dari himpunan simpul (nodes atau vertices) dan himpunan sisi (edges) yang menghubungkan pasangan simpul. Graf dapat bersifat berarah (directed) atau tak berarah (undirected), bergantung pada arah hubungan antara simpul-simpulnya. Tree adalah subtipe khusus dari graf yang tidak mengandung siklus, sehingga selalu memiliki satu jalur unik antara dua simpul manapun. Sebagai graf terhubung tanpa siklus, Tree sering digunakan dalam berbagai aplikasi seperti struktur data hierarkis, algoritma pencarian, dan sistem file. Graf dan Tree memiliki beberapa properti penting seperti kedalaman (depth), tingkat (level), dan tinggi (height) yang membantu dalam analisis dan implementasi algoritma. Selain itu, beberapa algoritma terkenal seperti Depth-First Search (DFS) dan Breadth-First Search (BFS) sering digunakan untuk eksplorasi graf dan pohon. Memahami graf dan Tree serta algoritma terkait adalah dasar yang penting bagi pengembangan perangkat lunak yang efisien dan optimisasi berbagai masalah komputasi.

## Guided
### 1. Single linked list
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {
    "ciamis",
    "bandung",
    "bekasi",
    "tasikmalaya",
    "cianjur",
    "purwokerto",
    "yogyakarta"
};

int busur[7][7] = {   
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
### 2. Guided
```C++
#include <iostream>
using namespace std;

// definisi dulu
struct pohon {
    pohon*kanan;
    char data;
    pohon*kiri;
};
//deklarasi variable global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

//fungsi
void inisialisasi(){
    root = NULL;
}

//fungsi membuat simpul baru
void simpulBaru(char dataMasukan){
    simpul = new pohon;
    simpul->data = dataMasukan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

//fungsi untuk membuat simpul akar
void simpulAkar(){
    if (root == NULL){
        char dataAnda;
        cout << "silahkan masukan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// fungsi menambah simpul
void tambahSimpul(){
    if (root !=NULL){
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256){
            cout << "masukan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0){
                cout << "masukan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0'){
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}
// fungsi untuk membaca pohon
void bacaPohon(){
    if(root != NULL){
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i]!=NULL){
            saatIni = alamat[i];
            cout << saatIni->data <<" ";
            pencacah++;
            if (pencacah == n) {
                cout<< endl;
                pencacah = 0;
                n = n* 2;
            }
            i++;
        }
    }
}
//fungsi utama
int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
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
```
#### Output
![Screenshot 202024-06-13 20164201](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%2010/Screenshot%202024-06-13%20164201.png)
#### Penjelasan 
Program ini menggunakan array dua dimensi untuk merepresentasikan matriks ketetanggaan (adjacency matrix) yang menyimpan bobot busur antara simpul-simpul graf. Fungsi tampilGraph digunakan untuk menampilkan graf dalam format teks, di mana setiap simpul ditampilkan bersama dengan semua simpul yang terhubung dengannya beserta bobot masing-masing busur. Pada fungsi main, program meminta input dari pengguna untuk mengisi nama-nama simpul dan kemudian menambahkan busur antara simpul dengan bobot yang ditentukan oleh pengguna. Pengguna dapat memasukkan beberapa busur melalui loop do-while yang terus meminta input hingga pengguna memutuskan untuk berhenti dengan memasukkan karakter 't'. Setelah semua data dimasukkan, fungsi tampilGraph dipanggil untuk menampilkan graf yang telah dibuat di layar. Program ini menggambarkan penggunaan dasar array dan loop untuk mengelola dan menampilkan struktur graf berbasis teks.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data untuk root: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;
        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri (0 untuk berhenti): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan (0 untuk berhenti): ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

// Fungsi traversal pre-order
void preOrder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

// Fungsi traversal in-order
void inOrder(pohon* node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}

// Fungsi traversal post-order
void postOrder(pohon* node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}

// Fungsi utama
int main() {
    int pilihan;
    inisialisasi();

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Buat Root" << endl;
        cout << "2. Tambah Simpul" << endl;
        cout << "3. Tampilkan Pre-order" << endl;
        cout << "4. Tampilkan In-order" << endl;
        cout << "5. Tampilkan Post-order" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                simpulAkar();
                break;
            case 2:
                tambahSimpul();
                break;
            case 3:
                cout << "Traversal Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Traversal In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Traversal Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
```
#### Output
![Screenshot 202024-06-13 20164013](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%2010/Screenshot%202024-06-13%20164013.png)
![Screenshot 202024-06-13 20164022](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%2010/Screenshot%202024-06-13%20164022.png)
#### Penjelasan
Pertama, struktur Tree didefinisikan dengan tiga anggota: dua pointer untuk menghubungkan ke anak kiri dan kanan, serta satu karakter untuk menyimpan data. Variabel global seperti root, simpul, saatIni, dan array alamat digunakan untuk mengelola simpul-simpul dalam pohon. Fungsi inisialisasi mengatur root menjadi NULL untuk memulai Tree kosong, sementara simpulBaru membuat simpul baru dengan data yang diberikan. Fungsi simpulAkar memungkinkan pengguna untuk menambahkan simpul akar jika belum ada, sedangkan tambahSimpul menambahkan simpul baru ke Tree berdasarkan input pengguna, baik di sisi kiri maupun kanan. Fungsi preOrder, inOrder, dan postOrder masing-masing melakukan traversal pohon dengan metode pre-order, in-order, dan post-order untuk menampilkan data dari Tree. Fungsi utama (main) menyediakan menu interaktif bagi pengguna untuk membuat simpul akar, menambah simpul, serta menampilkan hasil traversal pohon dalam berbagai urutan, hingga pengguna memilih untuk keluar dari program.
