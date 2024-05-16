#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah dua string adalah anagram
bool areAnagrams(string str1, string str2) {
    // Jika panjang kedua string berbeda, maka bukan anagram
    if (str1.length() != str2.length()) {
        return false;
    }
    
    // Mengubah string menjadi huruf kecil agar tidak case sensitive
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // Mengurutkan kedua string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Membandingkan kedua string
    return str1 == str2;
}

int main() {
    string string1 = "bahu";
    string string2 = "buah";

    if (areAnagrams(string1, string2)) {
        cout << "anagram" << endl;
    } else {
        cout << "tidak anagram" << endl;
    }

    string1 = "makan";
    string2 = "minum";

    if (areAnagrams(string1, string2)) {
        cout << "anagram" << endl;
    } else {
        cout << "tidak anagram" << endl;
    }

    return 0;
}