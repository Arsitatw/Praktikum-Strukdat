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
