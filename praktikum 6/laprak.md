# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
Linked list adalah salah satu struktur data yang penting dalam pemrograman komputer yang digunakan untuk menyimpan sekumpulan elemen data terurut secara linear. Setiap elemen, disebut node, terdiri dari dua bagian utama: data dan pointer yang menunjuk ke node berikutnya dalam urutan. 
Ada beberapa jenis linked list, termasuk singly linked list, doubly linked list, dan circular linked list. Singly linked list memiliki satu pointer yang menunjuk ke node berikutnya, sementara doubly linked list memiliki dua pointer yang menunjuk ke node sebelumnya dan berikutnya. 
Keuntungan utama linked list adalah kemampuannya untuk memperluas atau menyusut secara dinamis, memungkinkan alokasi memori yang efisien. Namun, pengaksesan elemen di linked list memerlukan traversal dari awal hingga elemen yang diinginkan, yang dapat mengakibatkan kinerja yang lebih lambat dibandingkan dengan struktur data lain seperti array. 
Meskipun demikian, linked list tetap menjadi pilihan yang kuat dalam beberapa aplikasi seperti implementasi stack, queue, dan dalam situasi di mana penambahan atau penghapusan elemen sering terjadi.

## Guided
### 1. Single linked list
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next; //mencari posisi -1
            nomor++;
        }
        baru->next = bantu->next; //note baru
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head; //pointer hapus diletakan di head, head digeser ke next nya 
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL; //bantu yg sebelumnya akan menjadi tail dan tail akan dihapus
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
### 2. Double Linked list
```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
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
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
## Unguided
### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user.
a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data

```C++
#include <iostream>
using namespace std;


struct Node {

    string nama;
    int usia;
    Node* next;
};

Node* head;
Node* tail;


void init() {
    head = NULL;
    tail = NULL;
}


bool isEmpty() {
    return (head == NULL);
}


void insertDepan(string nama, int usia) {

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


void insertBelakang(string nama, int usia) {

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


void tampilkanList() {
    Node* bantu = head;
    while (bantu != NULL) {
        cout << bantu->nama << "\t" << bantu->usia << endl;
        bantu = bantu->next;
    }
}

int main() {
    init();

    
    insertDepan("Arsita", 18);
    insertDepan("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertTengah("Akechi", 20, 4); 
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

  
    hapusData("Akechi");

   
    insertTengah("Futaba", 18, 2);

   
    insertDepan("Igor", 20);

 
    ubahData("Michael", "Reyn", 18);


    cout << "Seluruh Data:" << endl;
    tampilkanList();

    return 0;
}
```
#### Output

#### Penjelasan 
Dalam kode ini, terdapat fungsi-fungsi dasar untuk mengelola linked list seperti init() untuk menginisialisasi linked list, isEmpty() untuk memeriksa apakah linked list kosong, serta insertDepan(), insertBelakang(), dan insertTengah() untuk menambahkan node baru ke dalam linked list sesuai dengan posisi yang diinginkan.
Selain itu, terdapat juga fungsi-fungsi hapusData() untuk menghapus node berdasarkan nama, ubahData() untuk mengubah data node berdasarkan nama, dan tampilkanList() untuk menampilkan seluruh data dalam linked list. Di dalam fungsi main(), linked list diinisialisasi menggunakan fungsi init(), kemudian beberapa node ditambahkan ke linked list dengan menggunakan fungsi-fungsi penambahan yang telah disediakan.
Setelah itu, beberapa operasi dilakukan pada linked list seperti menghapus data dengan nama "Akechi" menggunakan fungsi hapusData(), menambahkan data "Futaba" di posisi kedua menggunakan fungsi insertTengah(), menambahkan data "Igor" di depan linked list menggunakan fungsi insertDepan(), dan mengubah data "Michael" menjadi "Reyn" menggunakan fungsi ubahData(). 
Akhirnya, seluruh data dalam linked list ditampilkan ke layar menggunakan fungsi tampilkanList().

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga
[screenshoot]
Case:
1.	Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :
[screenshoot]
```C++
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
```
#### Output

#### Penjelasan
Pada program ini, terdapat dua class utama: class Node yang merepresentasikan setiap node dalam linked list, dan class DoublyLinkedList yang bertanggung jawab atas operasi-operasi pada linked list.
Di dalam class DoublyLinkedList, terdapat fungsi-fungsi seperti tambahDepan(), hapusDepan(), perbarui(), hapusSemua(), tampilkan(), tambahDiUrutan(), dan hapusDiUrutan(), yang masing-masing berfungsi untuk menambahkan node di depan linked list, menghapus node dari depan linked list, mengubah informasi node, menghapus semua node, menampilkan seluruh data dalam linked list, menambahkan node di posisi tertentu, dan menghapus node dari posisi tertentu.
Di dalam fungsi main(), program ini memberikan pilihan kepada pengguna untuk melakukan berbagai operasi pada linked list, seperti menambah data, menghapus data, mengupdate data, menampilkan data, serta menghapus semua data. Pengguna dapat memilih operasi yang diinginkan melalui menu yang disediakan, dan program akan mengeksekusi operasi tersebut sesuai dengan pilihan pengguna.
