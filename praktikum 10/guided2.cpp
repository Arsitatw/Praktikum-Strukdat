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