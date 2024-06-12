# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Table</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
### Rekursif
Rekursi adalah teknik dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah. 
Dalam pemrograman, fungsi rekursif terdiri dari dua bagian: basis kasus (base case) dan langkah rekursif. 
Basis kasus adalah kondisi di mana rekursi dihentikan dan nilai dikembalikan, sedangkan langkah rekursif adalah bagian di mana fungsi memanggil dirinya sendiri dengan input yang lebih sederhana. 
Fungsi rekursif harus dirancang sedemikian rupa sehingga kondisi basis dapat tercapai setelah beberapa pemanggilan rekursif. Rekursi dapat digunakan untuk menyelesaikan berbagai macam masalah, seperti penghitungan faktorial, pencarian pola dalam string, dan eksplorasi struktur data seperti pohon.
### Hash Table
Hash tabel adalah struktur data yang digunakan untuk menyimpan data dalam bentuk array, di mana data disimpan di lokasi yang ditentukan berdasarkan fungsi hash. 
Fungsi hash mengonversi kunci (key) menjadi indeks array, yang kemudian digunakan untuk menempatkan atau mencari data. Untuk meminimalkan konflik (collision), yaitu saat dua kunci menghasilkan indeks yang sama, teknik seperti chaining (menggunakan linked list untuk menangani konflik) atau open addressing (mencari lokasi yang kosong di sekitar indeks yang dihasilkan) dapat digunakan. Hash table efisien dalam pencarian, penambahan, dan penghapusan data dengan kompleksitas waktu rata-rata O(1), tetapi dapat membutuhkan lebih banyak memori daripada struktur data lainnya karena ukuran tetap arraynya. 
Hash table digunakan dalam berbagai aplikasi seperti database, pengindeksan, dan pengelompokan data.

## Guided
### 1. Rekursif
```C++
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return; 
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    int number = 5; 

    cout << "Rekursif Langsung: ";
    countdown(number);
    cout << endl;

    return 0;
}
```
### 2. Rekuesif Tidak Langsung
```C++
#include <iostream>
using namespace std;
void functionB(int n);
void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); 
    }
}
void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); 
    }
}
int main() {
    int num = 5;
    cout << "rekursif tidak langsung: ";
    functionA(num);
    return 0;
}
```
### 3. Hash Table
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;


string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};


class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE; 
}

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    void remove(string name) {
        int hash_val = hashFunc(name);
        
        for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
return "";
}

void print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
            for (auto pair : table[i]) {
            if(pair != nullptr){
                cout << "[" << pair->name << ", " << pair->phone_number << "]";
            }
        }
        cout << endl;
    }
    }   
};
int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "nomor Hp Mistah : " <<
employee_map.searchByName("Mistah") << endl;
cout << "nomor Hp Pastah : " <<
employee_map.searchByName("Pastah") << endl;
employee_map.remove("Mistah");

cout << "nomor Hp Mistah setelah dihapus : " <<
employee_map.searchByName("Mistah") << endl << endl;
cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```
## Unguided
### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif! Contoh Output: masukan bilangan bulat positif 5 faktorial dari bilangan 5 adalah 120.
```C++
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;
    cout << "masukkan bilangan bulat positif: ";
    cin >> number;
    if (number < 0) {
        cout << "masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "faktorial dari bilangan " << number << " adalah " << result << endl;
    }

    return 0;
}
```
#### Output
![Screenshot 202024-06-12 20232854](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%209/Screenshot%202024-06-12%20232854.png)
#### Penjelasan 
Kode di atas adalah program C++ yang menghitung nilai faktorial dari sebuah bilangan bulat positif yang diinput oleh pengguna. Program dimulai dengan mengimpor pustaka iostream dan menggunakan namespace std agar bisa menggunakan objek-objek seperti cout dan cin tanpa perlu menulis std:: di depannya. 
Fungsi factorial didefinisikan untuk menghitung faktorial secara rekursif, di mana jika nilai n adalah 0 atau 1, fungsi akan mengembalikan 1 (basis rekursi). Jika tidak, fungsi akan mengembalikan hasil perkalian n dengan pemanggilan fungsi factorial dengan argumen n-1. Fungsi main dimulai dengan mendeklarasikan variabel number untuk menyimpan input pengguna. 
Pengguna diminta untuk memasukkan bilangan bulat positif, dan nilai tersebut dibaca menggunakan cin. Jika pengguna memasukkan bilangan negatif, program akan meminta pengguna untuk memasukkan bilangan bulat positif. Jika bilangan yang dimasukkan adalah bilangan bulat positif, program akan menghitung faktorial menggunakan fungsi factorial dan menyimpan hasilnya dalam variabel result. 
Akhirnya, program akan mencetak hasil faktorial dari bilangan yang dimasukkan. Program ini ditutup dengan mengembalikan nilai 0 dari fungsi main, menandakan bahwa program telah berhasil dijalankan tanpa kesalahan.

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!
```C++
#include <iostream>
using namespace std;

int factorialHelper(int n, int accumulator);

int factorial(int n) {
    return factorialHelper(n, 1);
}

int factorialHelper(int n, int accumulator) {
    if (n == 0 || n == 1) {
        return accumulator;
    } else {
        return factorial(n - 1) * n;
    }
}

int main() {
    int number;
    cout << "masukkan bilangan bulat positif: ";
    cin >> number;
    if (number < 0) {
        cout << "masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "faktorial dari bilangan " << number << " adalah " << result << endl;
    }

    return 0;
}
```

#### Output
![Screenshot 202024-06-12 20232945](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%209/Screenshot%202024-06-12%20232945.png)
#### Penjelasan
Kode di atas adalah program C++ yang menghitung nilai faktorial dari sebuah bilangan bulat positif menggunakan rekursi tidak langsung (indirect recursion). Program ini dimulai dengan mengimpor pustaka iostream dan menggunakan namespace std untuk memudahkan penggunaan objek-objek seperti cout dan cin. 
Fungsi factorial memanggil fungsi pembantu factorialHelper dengan argumen awal n dan 1 sebagai accumulator. Fungsi factorialHelper bertanggung jawab untuk menghitung faktorial dengan menggunakan rekursi. Jika nilai n adalah 0 atau 1, fungsi mengembalikan nilai accumulator, yang berarti proses rekursi berhenti. 
Jika tidak, fungsi mengembalikan hasil perkalian n dengan panggilan rekursif ke factorial dengan argumen n-1, yang melibatkan pemanggilan kembali factorialHelper. Dalam fungsi main, program meminta pengguna untuk memasukkan bilangan bulat positif dan membaca input tersebut menggunakan cin. 
Jika pengguna memasukkan bilangan negatif, program akan meminta pengguna untuk memasukkan bilangan bulat positif. Jika bilangan yang dimasukkan adalah positif, program akan menghitung faktorial menggunakan fungsi factorial dan menyimpan hasilnya dalam variabel result. 
Akhirnya, program mencetak hasil faktorial dari bilangan yang dimasukkan dan menutup program dengan mengembalikan nilai 0, menandakan eksekusi yang sukses.

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
##### a. Setiap mahasiswa memiliki NIM dan nilai.
##### b. Program memiliki tampilan pilihan menu berisi poin C.
##### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).
```C++
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
```
#### Output
![Screenshot 202024-06-12 20233159](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%209/Screenshot%202024-06-12%20233159.png)
![Screenshot 202024-06-12 20233234](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%209/Screenshot%202024-06-12%20233234.png)
#### Penjelasan
Kode di atas adalah program C++ yang mengimplementasikan hash table untuk menyimpan data mahasiswa berdasarkan NIM dan nilai mereka. Kelas Mahasiswa mendefinisikan struktur data mahasiswa dengan atribut NIM dan nilai. 
Kelas HashTable menggunakan array dari vector untuk menyimpan objek Mahasiswa dan menangani collision dengan teknik chaining. Fungsi hashFunction digunakan untuk menghitung indeks hash dari NIM menggunakan algoritma sederhana berbasis nilai ASCII karakter. 
Fungsi-fungsi publik tambahData, hapusData, cariBerdasarkanNIM, dan cariBerdasarkanRentangNilai memungkinkan penambahan, penghapusan, dan pencarian data dalam hash table. Dalam fungsi main, pengguna diberikan menu untuk memilih operasi yang ingin dilakukan, seperti menambahkan data baru, menghapus data, mencari data berdasarkan NIM, atau mencari data berdasarkan rentang nilai. 
Input pengguna diproses dalam loop do-while hingga pengguna memilih untuk keluar dari program. Program ini dirancang untuk mendemonstrasikan penggunaan dasar dari hash table dalam menyimpan dan mengelola data secara efisien.







