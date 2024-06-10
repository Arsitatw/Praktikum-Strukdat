# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
Priority queue adalah struktur data di mana setiap elemen memiliki prioritas tertentu, dan elemen dengan prioritas yang lebih tinggi akan didahulukan untuk diambil daripada elemen dengan prioritas yang lebih rendah. 
Operasi utama pada priority queue adalah insert (penambahan elemen dengan prioritas tertentu) dan remove (penghapusan elemen dengan prioritas tertinggi). 
Priority queue sering digunakan dalam algoritma seperti Dijkstra's Algorithm, Huffman Encoding, dan penjadwalan tugas.

Heap adalah struktur data berhirarki yang merupakan bentuk spesifik dari priority queue. Heap dapat dibagi menjadi dua jenis: max heap, di mana elemen dengan nilai tertinggi berada pada posisi paling atas, dan min heap, di mana elemen dengan nilai terendah berada pada posisi paling atas. 
Operasi-insert dan remove pada heap akan memastikan bahwa properti heap terjaga, yaitu setiap orang tua (parent) memiliki nilai yang lebih tinggi (pada max heap) atau lebih rendah (pada min heap) daripada anak-anaknya. 
Heap sering digunakan dalam algoritma pengurutan seperti heapsort dan dalam implementasi prioritas queue.

## Guided
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
        }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
    maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}
int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax()
<< "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
return 0;
}
```
## Unguided 
### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen yang ingin Anda masukkan ke dalam heap: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Masukkan elemen ke-" << i + 1 << ": ";
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    int index, newValue;
    std::cout << "Masukkan indeks elemen yang ingin diubah prioritasnya: ";
    std::cin >> index;
    std::cout << "Masukkan nilai prioritas baru: ";
    std::cin >> newValue;
    changePriority(index, newValue);

    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Masukkan indeks elemen yang ingin dihapus: ";
    std::cin >> index;
    remove(index);

    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}
```
#### Output
![Screenshot 202024-06-10 20115457](https://github.com/Arsitatw/Praktikum-Strukdat/blob/master/praktikum%208/Screenshot%202024-06-10%20115457.png)
#### Penjelasan
Fungsi parent(i), leftChild(i), dan rightChild(i) digunakan untuk menemukan indeks orang tua, anak kiri, dan anak kanan dari sebuah node di dalam heap. Fungsi shiftUp(i) dan shiftDown(i) digunakan untuk memastikan bahwa properti heap terjaga setelah penambahan atau penghapusan elemen dalam heap.
Fungsi insert(p) digunakan untuk menambahkan elemen ke dalam heap dengan memasukkannya ke dalam array H dan memanggil shiftUp() untuk memastikan bahwa properti heap terjaga. Fungsi extractMax() digunakan untuk menghapus dan mengembalikan elemen dengan prioritas tertinggi dari heap, yaitu elemen pada indeks 0, kemudian memanggil shiftDown() untuk memastikan bahwa properti heap terjaga setelah penghapusan.
Fungsi changePriority(i, p) digunakan untuk mengubah prioritas sebuah elemen di indeks i dengan nilai baru p. Fungsi getMax() digunakan untuk mengembalikan nilai maksimum dari heap.
Di dalam fungsi main(), program meminta pengguna untuk memasukkan jumlah elemen yang ingin dimasukkan ke dalam heap, kemudian meminta nilai-nilai elemen tersebut. Program kemudian melakukan berbagai operasi pada heap seperti menampilkan heap sebelum dan sesudah operasi, mengubah prioritas elemen, dan menghapus elemen dari heap, sesuai dengan input pengguna.






