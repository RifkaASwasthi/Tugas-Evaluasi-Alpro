#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk menggabungkan dua array terurut A dan B ke dalam A
void mergeArrays(vector<int>& A, vector<int>& B, int sizeA, int sizeB) {
    // Indeks untuk melacak elemen terakhir dari A, B, dan array hasil gabungan
    int indexA = sizeA - 1;
    int indexB = sizeB - 1;
    int indexMerged = sizeA + sizeB - 1;

    // Memperbesar ukuran array A untuk menampung elemen-elemen dari B
    A.resize(sizeA + sizeB);

    // Menggabungkan A dan B dari belakang ke depan
    while (indexB >= 0) {
        if (indexA >= 0 && A[indexA] > B[indexB]) {
            A[indexMerged] = A[indexA];
            indexA--;
        } else {
            A[indexMerged] = B[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main() {
    // Contoh penggunaan
    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6, 8};
    
    int sizeA = A.size();
    int sizeB = B.size();

    // Memanggil fungsi mergeArrays
    mergeArrays(A, B, sizeA, sizeB);

    // Output hasil gabungan dan pengurutan
    cout << "Array setelah digabungkan dan diurutkan: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
