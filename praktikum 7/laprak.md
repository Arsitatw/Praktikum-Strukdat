# <h1 align="center">Laporan Praktikum Modul Stack and Queue</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
### Stack
Stack adalah struktur data yang mengikuti prinsip Last In, First Out (LIFO), di mana elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan. Operasi-operasi dasar pada stack meliputi push (untuk menambahkan elemen ke dalam stack) dan pop (untuk menghapus elemen dari stack). 
Stack sering digunakan dalam implementasi pemanggilan fungsi (function call), pengecekan tanda kurung (parentheses matching), dan evaluasi ekspresi postfix.

### Queue
Queue adalah struktur data yang mengikuti prinsip First In, First Out (FIFO), di mana elemen pertama yang dimasukkan ke dalam queue akan menjadi elemen pertama yang dikeluarkan. Operasi-operasi dasar pada queue meliputi enqueue (untuk menambahkan elemen ke dalam queue) dan dequeue (untuk menghapus elemen dari queue). 
Queue sering digunakan dalam simulasi antrian (queueing simulation), pengurutan (sorting), dan penjadwalan (scheduling).

## Guided
### 1. Stack
```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

### 2. Queue
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

## Unguided 
### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkadalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> s;
    string cleanedStr = "";

    // Membersihkan kalimat dari spasi dan tanda baca, serta mengubah huruf menjadi huruf kecil
    for (char ch : str) {
        if (isalnum(ch)) {
            cleanedStr += tolower(ch);
        }
    }

    // Memasukkan semua karakter ke dalam stack
    for (char ch : cleanedStr) {
        s.push(ch);
    }

    // Mengecek apakah kalimat tersebut palindrom
    for (char ch : cleanedStr) {
        if (ch != s.top()) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}
```
#### Output
![Screenshot 202024-06-10 20113007](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%207/Screenshot%202024-06-10%20113007.png)
#### Penjelasan
Di dalam fungsi isPalindrome(), sebuah objek stack dari tipe char digunakan untuk menyimpan karakter-karakter dari kalimat yang telah dibersihkan dari spasi, tanda baca, dan diubah menjadi huruf kecil menggunakan fungsi tolower(). Setelah kalimat dibersihkan, karakter-karakternya dimasukkan ke dalam stack.
Setelah itu, program memeriksa setiap karakter dalam kalimat dengan karakter yang berada di atas stack. Jika terdapat perbedaan karakter antara kalimat asli dan kalimat yang telah dibalik, maka program mengembalikan false, menandakan bahwa kalimat tersebut bukanlah palindrom. Jika tidak ada perbedaan, program mengeluarkan karakter dari stack dan melanjutkan perulangan hingga semua karakter dalam kalimat telah diperiksa.
Jika semua karakter dalam kalimat cocok dengan karakter yang telah dibalik, maka program mengembalikan true, menandakan bahwa kalimat tersebut merupakan palindrom. Kembali ke dalam fungsi main(), program mencetak pesan sesuai dengan hasil pengecekan palindrom, yaitu "Kalimat tersebut adalah palindrom" jika benar, dan "Kalimat tersebut bukan palindrom" jika salah.
### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.
```c++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0; 
string queueTeller[maksimalQueue]; 

bool isFull() { 
    return back == maksimalQueue;
}

bool isEmpty() { 
    return back == 0;
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data;
        back++;
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; 
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { // Menghapus semua antrian
    for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
    }
    back = 0;
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    int choice;
    string nama;
    do {
        cout << "\nMenu Antrian Teller:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Kurangi Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hapus Semua Antrian" << endl;
        cout << "5. Jumlah Antrian" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore(); // Mengabaikan karakter newline setelah pilihan

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 6);

    return 0;
}
```

#### Output
![Screenshot 202024-06-10 20113205](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%207/Screenshot%202024-06-10%20113205.png)
![Screenshot 202024-06-10 20113215](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%207/Screenshot%202024-06-10%20113215.png)
![Screenshot 202024-06-10 20113223](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%207/Screenshot%202024-06-10%20113223.png)
![Screenshot 202024-06-10 20113233](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%207/Screenshot%202024-06-10%20113233.png)
#### Penjelasan
Fungsi isFull() digunakan untuk memeriksa apakah antrian sudah penuh, sedangkan isEmpty() digunakan untuk memeriksa apakah antrian kosong. Fungsi enqueueAntrian() digunakan untuk menambahkan data ke dalam antrian, dan dequeueAntrian() digunakan untuk menghapus data dari antrian.
Fungsi countQueue() mengembalikan jumlah antrian yang ada, sementara fungsi clearQueue() menghapus semua data antrian. Fungsi viewQueue() digunakan untuk menampilkan seluruh data dalam antrian.
Di dalam fungsi main(), program memberikan pilihan kepada pengguna untuk melakukan operasi-operasi pada antrian melalui menu yang disediakan. Pengguna dapat memilih menu yang diinginkan dengan memasukkan nomor pilihan. 
Program akan melakukan operasi sesuai dengan pilihan pengguna, dan akan terus berjalan hingga pengguna memilih untuk keluar dari program.
