# <h1 align="center">EVALUASI ALPRO CPMK-2 </h1>
<p align="center">Rifka Annisa Swasthi</p>
<p align="center">2311110040</p>

### CPMK2-SUB CPMK-2

1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

Bubble Sort
Alur Algoritma
Iterasi Pertama:

Bandingkan elemen pertama dengan elemen kedua.
Jika elemen pertama lebih besar, tukar posisinya dengan elemen kedua.
Lanjutkan dengan membandingkan elemen kedua dengan elemen ketiga, dan seterusnya hingga akhir array.
Elemen terbesar akan "mengapung" ke posisi terakhir di array.
Iterasi Selanjutnya:

Ulangi proses di atas untuk elemen-elemen yang belum tersorting, mengabaikan elemen terakhir yang sudah berada di posisi yang benar.
Setiap iterasi mengurangi jumlah elemen yang perlu diperiksa dengan satu.
Pengulangan:

Lanjutkan hingga tidak ada lagi elemen yang perlu ditukar, yaitu saat array sudah tersorting.
Runtime
Best Case: O(n) - terjadi saat array sudah tersorting dari awal. Algoritma hanya perlu satu kali pengecekan seluruh array tanpa melakukan pertukaran.
Worst Case: O(n²) - terjadi saat array tersorting secara terbalik. Setiap elemen harus dibandingkan dan ditukar di setiap iterasi.
Selection Sort
Alur Algoritma
Iterasi Pertama:

Temukan elemen terkecil di seluruh array.
Tukar elemen terkecil tersebut dengan elemen pertama di array.
Iterasi Selanjutnya:

Temukan elemen terkecil di sisa array (mengabaikan elemen pertama yang sudah di tempatkan dengan benar).
Tukar elemen terkecil tersebut dengan elemen kedua, dan seterusnya.
Pengulangan:

Lanjutkan proses ini hingga seluruh array tersorting.
Runtime
Best Case: O(n²) - Selection Sort tidak tergantung pada urutan awal array karena tetap harus mencari elemen terkecil di sisa array pada setiap iterasi.
Worst Case: O(n²) - Sama dengan best case karena algoritma tetap melakukan pencarian yang sama di setiap iterasi.
Merge Sort
Alur Algoritma
Pembagian:

Bagilah array menjadi dua bagian yang kira-kira sama besar.
Rekursif:

Lakukan merge sort secara rekursif pada setiap bagian hingga setiap bagian hanya terdiri dari satu elemen.
Penggabungan:

Gabungkan dua bagian yang sudah tersorting menjadi satu array yang tersorting dengan cara membandingkan elemen dari setiap bagian dan menempatkannya di posisi yang benar.
Runtime
Best Case: O(n log n) - karena array dibagi dua secara rekursif dan setiap elemen dibandingkan sekali pada setiap level rekursi.
Worst Case: O(n log n) - sama dengan best case karena mekanisme pembagian dan penggabungan tetap sama tidak tergantung pada urutan awal array.
Kesimpulan
Bubble Sort:
Best Case: O(n)
Worst Case: O(n²)
Selection Sort:
Best Case: O(n²)
Worst Case: O(n²)
Merge Sort:
Best Case: O(n log n)
Worst Case: O(n log n)
Dari penjelasan di atas, Merge Sort merupakan algoritma yang paling efisien dalam hal runtime baik untuk best case maupun worst case, dibandingkan dengan Bubble Sort dan Selection Sort yang memiliki runtime O(n²) pada worst case.

2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; j++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i]= arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
    bubble_sort(a, length);
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}

```
Kode di atas adalah conoth dari bubble sort yang mengurutkan data dari terkecil ke besar atau ascending. dari kodingan menggunakan looping while yang akan berjalan selama pertukaran eleman dalam array terjadi jika dalam iterasi tidak ada pertukaran yang dilakukan, artinya array sudah terurut dan not_sorted diubah menjadi false. jika di run akan menghasilkan output angka 15.3 maju menggantikan angka 22.1.

Kompleksitas Waktu O(n2)
While loop sampai tidak ada lagi pertukaran yang dilakukan, array sudah terurut, jumlah iterasi loop while bergantung pada banyaknya pertukaran yang dilakukan iterasi sebelumnya, jumlah operasi komparasi dan pertukaran pada iterasi luar adalah Jumlah(j=1 hingga n-1) dari (n-1), yaitu setara (n-1)*(n-1)

3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 
contoh
Input string1 = “bahu” string2 = “buah”
Output: “anagram”
Input string1 = “makan” string2 = “minum”
Output: “tidak anagram


```C++
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

```
Fungsi areAnagrams:

Parameter: Fungsi ini menerima dua string str1 dan str2.
Panjang String: Fungsi pertama-tama mengecek apakah panjang kedua string sama. Jika tidak, langsung mengembalikan false karena string dengan panjang berbeda tidak mungkin anagram.
Transformasi ke Huruf Kecil: Menggunakan transform untuk mengubah semua karakter dalam kedua string menjadi huruf kecil agar pengecekan tidak case sensitive.
Sorting: Menggunakan fungsi sort dari STL untuk mengurutkan kedua string. Jika kedua string memiliki karakter yang sama dalam jumlah yang sama, string yang telah disorting akan sama.
Perbandingan: Setelah disorting, fungsi membandingkan kedua string. Jika sama, maka fungsi mengembalikan true (anagram), jika tidak mengembalikan false (tidak anagram).
Fungsi main:

Menguji fungsi areAnagrams dengan dua pasangan string.
Mengoutput "anagram" jika string tersebut adalah anagram, dan "tidak anagram" jika bukan.
Contoh Penggunaan
Input: string1 = "bahu", string2 = "buah"
Output: "anagram"
Input: string1 = "makan", string2 = "minum"
Output: "tidak anagram"
Program ini mengecek apakah dua string adalah anagram dengan cara menyorting kedua string dan kemudian membandingkan hasil sortingnya. Jika kedua string yang sudah disorting sama, maka string tersebut adalah anagram.


4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut:
Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

```C++
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

```
Fungsi mergeArrays:

Parameter: Fungsi ini menerima tiga parameter:
vector<int>& A: Array pertama yang terurut dan memiliki ruang cukup untuk menampung elemen-elemen dari B.
vector<int>& B: Array kedua yang terurut.
int sizeA: Ukuran asli dari array A sebelum penggabungan.
int sizeB: Ukuran dari array B.
Inisialisasi Indeks:
indexA: Indeks elemen terakhir dari bagian valid array A.
indexB: Indeks elemen terakhir dari array B.
indexMerged: Indeks elemen terakhir dari array A setelah digabungkan dengan B.
Resize Array A: Memperbesar ukuran array A untuk menampung elemen-elemen dari B.
Penggabungan dari Belakang:
Menggabungkan elemen dari A dan B dari belakang ke depan untuk menghindari overwrite elemen yang belum diproses.
Membandingkan elemen dari A dan B, menempatkan elemen yang lebih besar di posisi yang sesuai dalam array A yang telah diperbesar.
Mengurangi indeks yang sesuai setelah penempatan elemen.
Fungsi main:

Menginisialisasi dua array terurut A dan B.
Menyimpan ukuran asli dari array A.
Memanggil fungsi mergeArrays untuk menggabungkan dan mengurutkan array.
Mencetak hasil array yang telah digabungkan dan diurutkan.
Contoh Penggunaan
Input:
Array A: {1, 3, 5, 7}
Array B: {2, 4, 6, 8}
Output:
Array setelah digabungkan dan diurutkan: 1 2 3 4 5 6 7 8
Program ini menggunakan pendekatan penggabungan dari belakang untuk menghindari konflik penulisan dan memastikan elemen-elemen dari kedua array tetap terurut setelah digabungkan.

### CMPK-2 SUBCPMK-3

1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 


Binary Search

Alur Algoritma
Binary Search adalah algoritma pencarian efisien yang bekerja pada array yang sudah terurut. Algoritma ini menggunakan prinsip divide and conquer untuk mengurangi ruang pencarian secara drastis di setiap langkah.

Inisialisasi:

Tetapkan batas bawah (low) ke indeks awal array (0) dan batas atas (high) ke indeks akhir array (n-1), di mana n adalah ukuran array.
Perulangan:

Selama low kurang dari atau sama dengan high:
Hitung indeks tengah (mid) sebagai mid = low + (high - low) / 2.
Bandingkan elemen di indeks tengah (arr[mid]) dengan elemen yang dicari (target).
Pengecekan:

Jika arr[mid] sama dengan target, elemen ditemukan.
Jika arr[mid] lebih besar dari target, perbarui batas atas (high = mid - 1).
Jika arr[mid] lebih kecil dari target, perbarui batas bawah (low = mid + 1).
Pengulangan:

Ulangi langkah di atas hingga elemen ditemukan atau low melebihi high.
Output:

Jika elemen ditemukan, kembalikan indeks elemen tersebut.
Jika elemen tidak ditemukan, kembalikan nilai yang menunjukkan elemen tidak ada dalam array (misalnya -1).
Runtime
Best Case: O(1) - terjadi saat elemen yang dicari berada tepat di tengah array pada langkah pertama.
Worst Case: O(log n) - terjadi saat elemen yang dicari berada di posisi yang sangat jauh, misalnya di ujung array, sehingga membutuhkan logaritma dari jumlah elemen dalam array untuk menemukannya atau menentukan bahwa elemen tersebut tidak ada.
Binary search merupakan algoritma yang 
dikembangkan dengan ide dasar yang berbeda 
dalam penangan kasus pencarian data pada 
sebuah pemrograman.
Proses pencarian (search) data pada 
sebuah pemrograman merupakan tindakan 
untuk mencari data pada sebuah data base 
berdasarkan satu kunci (key) data
Langkah-langkah Pencarian Binary Search

1. Mengurutkan data terlebih dahulu bisa secara
ascending (dari depan ke belakang) atau
descending (dari belakang ke depan).
2. Membagi dua array atau keseluruhan data.
Apabila data yang dicari lebih kecil dari data
yang terletak di tengah, maka pencarian data
akan berlanjut kesebelah kiri. Apabila data yang
dicari lebih besar dari data terletak ditengah,
maka pencarian data akan berlanjut kesebelah
kanan kemudian proses pencarian tersebut akan
terus berulang sampai data yang dimaksud atau
dicari dapat ditemukan

Linear Search
Alur Algoritma
Linear Search adalah algoritma pencarian sederhana yang bekerja dengan cara memeriksa setiap elemen dalam array satu per satu sampai elemen yang dicari ditemukan atau seluruh elemen telah diperiksa.

Inisialisasi:

Mulai dari elemen pertama di array.
Perulangan:

Periksa elemen saat ini dengan elemen yang dicari (target).
Pengecekan:

Jika elemen saat ini sama dengan target, elemen ditemukan.
Jika elemen saat ini tidak sama dengan target, lanjutkan ke elemen berikutnya.
Pengulangan:

Ulangi proses hingga elemen ditemukan atau akhir array tercapai.
Output:

Jika elemen ditemukan, kembalikan indeks elemen tersebut.
Jika elemen tidak ditemukan setelah memeriksa seluruh array, kembalikan nilai yang menunjukkan elemen tidak ada dalam array (misalnya -1).
Runtime
Best Case: O(1) - terjadi saat elemen yang dicari berada di posisi pertama array.
Worst Case: O(n) - terjadi saat elemen yang dicari berada di posisi terakhir array atau tidak ada dalam array, sehingga seluruh elemen harus diperiksa.

2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut 

```C++
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int Nomor[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{
    int temp, min, i, j;
    for(i=0; i<7;i++)
    {
        min = i;
        for(j = i+1; j<7; j++)
        {
            if(Nomor[j] < Nomor[min])
            {
                min = j;
            }
        }
        temp = Nomor[i];
        Nomor[i] = Nomor[min];
        Nomor[min] = temp;
    }
}

void binarysearch()
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir)
    { 
        tengah = (awal + akhir) / 2;
        if(Nomor[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(Nomor[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\nNomor ditemukan pada indeks ke-" << tengah << endl;
    else
        cout << "\nNomor tidak ditemukan\n";
}

int main()
{
    cout << "\tBINARY SEARCH\n" << endl;
    cout << "Nomor:" << endl;
    //tampilkan Data awal
    for(int x = 0; x<7; x++)
        cout << setw(3) << Nomor[x];
    cout << endl;

    cout << "\nMasukkan Nomor yang Anda ingin cari: ";
    cin >> cari;

    cout << "\nNomor diurutkan:";
    //urutkan Nomor dengan selection sort
    selection_sort();
    //tampilkan Nomor setelah diurutkan
    for(int x = 0; x<7; x++)
        cout << setw(3) << Nomor[x];
    cout << endl;

    binarysearch();
    _getche();
    return 0;
}

```
Kode di atas digunakan untuk memperlihatkan penggunaan algoritma binary search untuk mencari nilai tertentu dalam array setelah array tersebut diurutkan menggunakan algoritma selection sort. Pengguna diminta diminta untuk memasukkan nilai yang ingin dicari, lalu program akan menampilkan apakah nilai tersebut ditemukan dan pada indeks ke berapa dalam array Nomor yang telah diurutkan. 

3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6


```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mencari indeks dari kata yang dicari dalam array terurut yang mengandung string kosong
int searchString(const vector<string>& arr, const string& target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Jika mid adalah string kosong, temukan mid yang valid di sekitar
        if (arr[mid] == "") {
            int left = mid - 1;
            int right = mid + 1;

            // Cari elemen terdekat yang tidak kosong
            while (true) {
                if (left < low && right > high) {
                    return -1; // Tidak ditemukan
                } else if (right <= high && arr[right] != "") {
                    mid = right;
                    break;
                } else if (left >= low && arr[left] != "") {
                    mid = left;
                    break;
                }
                right++;
                left--;
            }
        }

        // Bandingkan elemen di mid dengan target
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Elemen tidak ditemukan
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string target = "bola";
    int result = searchString(arr, target);
    
    if (result != -1) {
        cout << "Elemen ditemukan di indeks: " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan dalam array." << endl;
    }

    return 0;
}
```

Fungsi searchString:

Parameter: Fungsi ini menerima dua parameter:
const vector<string>& arr: Array terurut yang mengandung string kosong.
const string& target: Kata yang dicari.
Inisialisasi: Tetapkan batas bawah (low) ke 0 dan batas atas (high) ke ukuran array dikurangi satu.
Perulangan: Selama low kurang dari atau sama dengan high:
Hitung indeks tengah (mid) sebagai low + (high - low) / 2.
Jika elemen di mid adalah string kosong, cari elemen terdekat yang tidak kosong di sekitar mid.
Bandingkan elemen di mid yang valid dengan target.
Jika elemen di mid sama dengan target, kembalikan mid.
Jika elemen di mid lebih kecil dari target, perbarui batas bawah (low = mid + 1).
Jika elemen di mid lebih besar dari target, perbarui batas atas (high = mid - 1).
Output: Jika elemen ditemukan, kembalikan indeks elemen tersebut. Jika tidak ditemukan, kembalikan -1.
Fungsi main:

Menginisialisasi array arr dengan elemen-elemen termasuk string kosong.
Menetapkan kata yang dicari (target).
Memanggil fungsi searchString untuk mencari indeks kata yang dicari.
Mencetak hasil indeks jika ditemukan atau pesan bahwa elemen tidak ditemukan.
Contoh Penggunaan
Input:
Array arr: {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"}
Kata target: "bola"
Output:
Elemen ditemukan di indeks: 6
Program ini memodifikasi algoritma Binary Search untuk menangani string kosong dalam array, dengan mencari elemen valid terdekat jika elemen tengah (mid) adalah string kosong. Pendekatan ini memastikan algoritma tetap efisien dan mampu menangani kasus khusus string kosong dalam array terurut.

### CPMK-2 SUB CPMK-4

1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct

Srtuktur data adalah langkah-langkah yang dipilih dalam penyusunan intruksi algortima agar mendapatkan hasil yang seefisian mungkin. Beberapa algortima  termasuk algorima pencarian, algoritma pengurutan dan algorima grafik. Struktur Dasar Algorima dibagi menjadi 3 yaitu sequeantial, branching dan looping.

1. Algorima Sekueansial 

Algorima ini menggunakan tahapan atau sequeantial yang dilakukan berurutan sesuai urutan dari penulisnya.

2. Algoritma Percabangan 

Algoritma uni digunakan ketika suatu kondisi fumana kerika itu ada satu atau beberapa aksi denfan pilihan yang kenih dari satu atau banyak.

3. Algoritma Pengulangan

Algortima ini melakukan perulangan terus menerus sehingga didapatkan hasil yang diinginkan 

Pemilihan struktur data yang tepat dapat sangat pentig dalam pengembangan perangkat lunak, contoh dari struktur data umum meliputi array, linked list, stack, queue, tree, graph, hash table.

Pemahaman algoritma dan struktur data memiliki peran yang sangat penting dalam pengembangan perangkat lunak karena dapat mengefisiensikan kinerja.skalabilitas, pemecahan masalah, pengembangan perangkat lunak yang baik, peningkatan kemampuan pemrograman. 

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

Kode di atas digunakan untuk mendefinisikan sebuah struktur bernama buku yang berisi judulbuku, pengarang, penerbit, tebalhalaman, dan harga buku, kemudina mendeklarasikan variabel favorit dengan tipe data buku untuk menyimpan informasi tentang buku favorit. 

### CPMK-2 SUB CPMK-5

1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 

```C++
#include <iostream>
#include <unordered_set>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menghapus duplikasi dalam linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        // Jika elemen telah ditemukan sebelumnya, hapus elemen tersebut
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            // Jika elemen belum ditemukan, tambahkan ke set
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama untuk menguji fungsi removeDuplicates
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 10);
    append(head, 12);
    append(head, 11);
    append(head, 11);
    append(head, 12);
    append(head, 11);
    append(head, 10);

    cout << "Linked list sebelum menghapus duplikasi: ";
    printList(head);

    // Menghapus duplikasi
    removeDuplicates(head);

    cout << "Linked list setelah menghapus duplikasi: ";
    printList(head);

    return 0;
}

```
Struktur Node:

Struktur Node mendefinisikan sebuah node dalam linked list yang terdiri dari data (int) dan pointer (next) ke node berikutnya.
Fungsi removeDuplicates:

Parameter: Menerima pointer ke kepala linked list (Node* head).
Set seen: Menggunakan unordered_set untuk melacak elemen yang telah ditemukan.
Inisialisasi: current untuk node saat ini dan prev untuk node sebelumnya.
Perulangan: Melalui seluruh linked list.
Jika data node saat ini sudah ada di seen, node tersebut dihapus dengan mengatur next dari node sebelumnya (prev->next) ke node berikutnya (current->next).
Jika data node saat ini belum ada di seen, tambahkan data tersebut ke seen dan lanjutkan ke node berikutnya.
Fungsi append:

Menambahkan node baru dengan new_data di akhir linked list.
Jika linked list kosong, node baru menjadi kepala linked list.
Jika tidak, iterasi ke node terakhir dan tambahkan node baru di akhir.
Fungsi printList:

Mencetak seluruh elemen dalam linked list mulai dari node kepala hingga node terakhir.
Fungsi main:

Menginisialisasi linked list dan menambahkan beberapa elemen, termasuk elemen duplikat.
Mencetak linked list sebelum dan sesudah menghapus duplikasi dengan memanggil fungsi removeDuplicates.
Kesimpulan
Program ini menghilangkan duplikasi dalam singly linked list tidak terurut menggunakan struktur data set (unordered_set). Algoritma ini berjalan dalam waktu O(n), di mana n adalah jumlah elemen dalam linked list, karena setiap elemen hanya diproses sekali dan operasi pada set (pengecekan dan penambahan) memiliki kompleksitas waktu rata-rata O(1).

2.	Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

```C++
#include <iostream>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddleNode(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        // Jika linked list kosong atau hanya memiliki satu elemen, tidak ada node tengah untuk dihapus
        return;
    }

    int length = getLength(head);
    int midIndex = length / 2;

    Node* current = head;
    Node* prev = nullptr;

    // Iterasi ke node sebelum node tengah
    for (int i = 0; i < midIndex; ++i) {
        prev = current;
        current = current->next;
    }

    // Hapus node tengah
    if (prev != nullptr) {
        prev->next = current->next;
        delete current;
    } else {
        // Jika prev tetap nullptr, itu berarti kita harus menghapus head
        head = head->next;
        delete current;
    }
}

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama untuk menguji fungsi deleteMiddleNode
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Linked list sebelum menghapus node tengah: ";
    printList(head);

    // Menghapus node tengah
    deleteMiddleNode(head);

    cout << "Linked list setelah menghapus node tengah: ";
    printList(head);

    return 0;
}

```
Algoritma
Hitung Panjang Linked List:

Iterasi melalui linked list untuk menghitung jumlah node (n).
Temukan Node Tengah:

Hitung indeks node tengah sebagai n / 2.
Hapus Node Tengah:

Iterasi ke node sebelum node tengah.
Perbarui pointer next dari node sebelumnya untuk melewati node tengah dan menunjuk ke node setelahnya.
Hapus node tengah.

Struktur Node:

Struktur Node mendefinisikan sebuah node dalam linked list yang terdiri dari data (int) dan pointer (next) ke node berikutnya.
Fungsi getLength:

Menghitung panjang linked list dengan iterasi melalui seluruh node dan menghitung jumlahnya.
Fungsi deleteMiddleNode:

Parameter: Menerima pointer ke kepala linked list (Node*& head).
Jika linked list kosong atau hanya memiliki satu elemen, tidak ada node tengah untuk dihapus.
Menghitung panjang linked list menggunakan getLength.
Menghitung indeks node tengah (midIndex).
Iterasi ke node sebelum node tengah.
Menghapus node tengah dengan memperbarui pointer next dari node sebelumnya untuk melewati node tengah dan menunjuk ke node setelahnya. Jika node tengah adalah node kepala (head), maka kepala diupdate ke node berikutnya.
Fungsi append:

Menambahkan node baru dengan new_data di akhir linked list.
Jika linked list kosong, node baru menjadi kepala linked list.
Jika tidak, iterasi ke node terakhir dan tambahkan node baru di akhir.
Fungsi printList:

Mencetak seluruh elemen dalam linked list mulai dari node kepala hingga node terakhir.
Fungsi main:

Menginisialisasi linked list dan menambahkan beberapa elemen.
Mencetak linked list sebelum dan sesudah menghapus node tengah dengan memanggil fungsi deleteMiddleNode.
Kesimpulan
Program ini menghapus node tengah dalam singly linked list tidak terurut dengan menghitung panjang linked list terlebih dahulu dan kemudian menghapus node di posisi tengah. Algoritma ini efisien dan mudah dipahami, menggunakan pendekatan iteratif untuk menentukan node tengah dan menghapusnya.

3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk membalikkan linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Fungsi untuk mengecek apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // Linked list kosong atau hanya memiliki satu elemen, dianggap sebagai palindrom
        return true;
    }

    // Gunakan dua pointer untuk menemukan titik tengah linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Balikkan setengah kedua dari linked list
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    // Bandingkan setengah pertama dan setengah kedua untuk memastikan palindrom
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            // Linked list bukan palindrom
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Linked list adalah palindrom
    return true;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama untuk menguji fungsi isPalindrome
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    cout << "Linked list: ";
    printList(head);

    // Mengecek apakah linked list adalah palindrom
    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrom." << endl;
    } else {
        cout << "Linked list bukan palindrom." << endl;
    }

    return 0;
}

```
Struktur Node:

Struktur Node mendefinisikan sebuah node dalam linked list yang terdiri dari data (int) dan pointer (next) ke node berikutnya.
Fungsi reverseList:

Mengembalikan linked list yang sudah dibalik.
Fungsi isPalindrome:

Parameter: Menerima pointer ke kepala linked list (Node* head).
Menggunakan dua pointer (slow dan fast) untuk menemukan titik tengah linked list.
Memanggil reverseList untuk membalikkan setengah kedua dari linked list.
Membandingkan setengah pertama dan setengah kedua untuk menentukan apakah linked list adalah palindrom.
Fungsi append:

Menambahkan node baru dengan new_data di akhir linked list.
Jika linked list kosong, node baru menjadi kepala linked list.
Jika tidak, iterasi ke node terakhir dan tambahkan node baru di akhir.
Fungsi printList:

Mencetak seluruh elemen dalam linked list mulai dari node kepala hingga node terakhir.
Fungsi main:

Menginisialisasi linked list dan menambahkan beberapa elemen.
Mencetak linked list.
Mengecek apakah linked list adalah palindrom dengan memanggil fungsi isPalindrome dan mencetak hasilnya.
Contoh Penggunaan
Dalam contoh program di atas, linked list terdiri dari elemen: 1, 2, 3, 2, 1. Program akan mencetak bahwa linked list tersebut adalah palindrom karena elemen-elemen tersebut membentuk pola yang sama jika dibalik.

### CPMK-2 SUB CPMK-6

1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else{
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }else{
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else{
        int index = top; 
        for (int i = 1; i <= posisi; i ++){
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl; 
    }
}

int countStack(){
    return top;
}
void changeArrayBuku (int posisi, string data){
    if (posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku() {
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArraybuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArraybuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout <<"Apakah data stack kosong?" << isEmpty () << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data =" << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArraybuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;

    cetakArraybuku();
    return 0;
}

```

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;
    string formattedStr;

    // Menghapus karakter non-alfabetik dan mengubah huruf kecil menjadi huruf besar
    for (char c : str) {
        if (isalpha(c)) {
            formattedStr += toupper(c);
            charStack.push(toupper(c));
        }
    }

    // Membandingkan kalimat dari depan dan belakang
    while (!charStack.empty()) {
        if (charStack.top() != formattedStr.front()) {
            return false;
        }
        charStack.pop();
        formattedStr.erase(0, 1);
    }

    return true;
}

int main() {
    string input;

    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}

```

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseSentence(string sentence) {
    stack<string> wordStack;
    string word;
    size_t pos = 0;

    // Membagi kalimat menjadi kata-kata dan memasukkan ke dalam stack
    while ((pos = sentence.find(" ")) != string::npos) {
        word = sentence.substr(0, pos);
        wordStack.push(word);
        sentence.erase(0, pos + 1);
    }
    wordStack.push(sentence); // Memasukkan kata terakhir

    // Mencetak kata-kata dalam stack untuk membentuk kalimat terbalik
    cout << "Kalimat terbalik: ";
    while (!wordStack.empty()) {
        cout << wordStack.top() << " ";
        wordStack.pop();
    }
    cout << endl;
}

int main() {
    string input;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, input);

    reverseSentence(input);

    return 0;
}

```

```C++
#include <iostream>
using namespace std;

#define MAX_SIZE 5 

class Stack {
private:
    int top; 
    int arr[MAX_SIZE]; 

public:
    Stack() {
        top = -1; 
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh. Tidak bisa menambahkan elemen lagi.\n";
        } else {
            top++;
            arr[top] = value;
            cout << "Elemen " << value << " berhasil ditambahkan ke dalam stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak ada elemen yang dapat dihapus.\n";
        } else {
            cout << "Elemen " << arr[top] << " dihapus dari stack.\n";
            top--;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
        } else {
            cout << "Isi stack:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << "\n";
            }
        }
    }
};

int main() {
    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.push(6); 

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.pop(); 

    return 0;
}
```
```C++
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Memasukkan elemen ke dalam stack
    s.push(5);
    s.push(10);
    s.push(15);

    // Mengecek apakah stack kosong
    if (s.empty()) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Stack tidak kosong." << endl;
    }

    // Mencetak elemen puncak stack
    cout << "Elemen puncak: " << s.top() << endl;

    // Menghapus elemen puncak dari stack
    s.pop();

    // Mencetak elemen puncak setelah pop
    cout << "Elemen puncak setelah pop: " << s.top() << endl;

    // Mencetak ukuran stack
    cout << "Ukuran stack: " << s.size() << endl;

    return 0;
}

```

2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty. 

```C++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mensortir stack dengan nilai terkecil di atas
void sortStack(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        // Pindahkan item dari temporary stack ke stack asli yang lebih kecil dari temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Salin isi temporary stack ke stack asli
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Fungsi untuk mencetak stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;

    // Menambahkan elemen-elemen ke stack
    myStack.push(30);
    myStack.push(-5);
    myStack.push(18);
    myStack.push(10);
    myStack.push(2);

    cout << "Stack sebelum disorting: ";
    printStack(myStack);

    // Mensortir stack
    sortStack(myStack);

    cout << "Stack setelah disorting: ";
    printStack(myStack);

    return 0;
}

```

### CPMK-2 SUB CPMK-7

1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

```C++
#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << value << " dequeued from the queue." << endl;
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;

    return 0;
}
```

```C++
#include <iostream>
#include <stack>
using namespace std;

// function prototype for display_stack utility
void display_stack(stack<string> st);

int main() {

  // create a stack of strings
  stack<string> colors;

  // push elements into the stack
  colors.push("Red");
  colors.push("Orange");
  colors.push("Blue");
  
  cout << "Initial Stack: ";
  // print elements of stack
  display_stack(colors);
  
  // removes "Blue" as it was inserted last
  colors.pop();
  
  cout << "Final Stack: ";

  // print elements of stack
  display_stack(colors);
  
  return 0;
}

// utility function to display stack elements
void display_stack(stack<string> st) {

  while(!st.empty()) {
    cout << st.top() << ", ";
    st.pop();
  }

  cout << endl;
}
```

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull(){
    if (back == maksimalQueue){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if (back == 0){
        return true;
    } else{
        return false;
    }
}

void enqueueAntrian(string data){
    if (isFull()){
        cout << "Antrian penuh" << endl;
    } else{
        if (isEmpty()) {
            queueTeller[0] = data;
            front ++;
            back ++;
        } else{
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian(){
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    }else{
        for (int i = 0; i< back; i++){
            queueTeller[i] = queueTeller[i+1];
        }
    } back--;
}

int countQueue(){
    return back;
}

void cleanQueue(){
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else{
        for (int i = 0; i < back; i++){
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue(){
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++){
        if (queueTeller[i] != ""){
            cout << i +1 << "." << queueTeller[i] << endl;
        } else{
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main(){
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian =" << countQueue() << endl;
    return 0;
}
```

```C++
#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian teller:" << endl;
            Node* current = front;
            int index = 1;
            while (current != nullptr) {
                cout << index << ". " << current->data << endl;
                current = current->next;
                index++;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void cleanQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }
};

int main() {
    Queue queue;
    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}

```


```C++
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class QueueMahasiswa {
private:
    Mahasiswa* front;
    Mahasiswa* rear;

public:
    QueueMahasiswa() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueMahasiswa(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueMahasiswa() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data mahasiswa dalam antrian:" << endl;
            Mahasiswa* current = front;
            int index = 1;
            while (current != nullptr) {
                cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                index++;
            }
        }
    }

    int countQueue() {
        int count = 0;
        Mahasiswa* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void cleanQueue() {
        while (!isEmpty()) {
            dequeueMahasiswa();
        }
    }
};

int main() {
    QueueMahasiswa queue;
    queue.enqueueMahasiswa("Andi", "2311110050");
    queue.enqueueMahasiswa("Maya", "234100079");
    queue.viewQueue();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    queue.dequeueMahasiswa();
    queue.viewQueue();
    cout << "Jumlah mahasiswa dalam antrian = " << queue.countQueue() << endl;
    return 0;
}

```

2.	Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. 

```C++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi hewan (kucing atau anjing) beserta waktu masuk ke selter
struct Animal {
    string type; // "cat" atau "dog"
    int order; // Waktu masuk ke selter (semakin kecil, semakin tua)
};

class AnimalShelter {
private:
    int order; // Variabel untuk menentukan waktu masuk hewan ke selter
    queue<Animal> catQueue; // Queue untuk kucing
    queue<Animal> dogQueue; // Queue untuk anjing

public:
    AnimalShelter() : order(0) {}

    // Menambahkan hewan ke selter
    void enqueue(string type) {
        Animal animal;
        animal.type = type;
        animal.order = order++;
        
        if (type == "cat") {
            catQueue.push(animal);
        } else if (type == "dog") {
            dogQueue.push(animal);
        }
    }

    // Menghapus hewan tertua dari selter
    Animal dequeueAny() {
        if (catQueue.empty()) {
            return dequeueDog();
        } else if (dogQueue.empty()) {
            return dequeueCat();
        } else {
            if (catQueue.front().order < dogQueue.front().order) {
                return dequeueCat();
            } else {
                return dequeueDog();
            }
        }
    }

    // Menghapus kucing tertua dari selter
    Animal dequeueCat() {
        if (!catQueue.empty()) {
            Animal cat = catQueue.front();
            catQueue.pop();
            return cat;
        }
        // Jika tidak ada kucing, kembalikan hewan dengan order yang sangat besar agar tidak dipilih
        return {"", INT_MAX};
    }

    // Menghapus anjing tertua dari selter
    Animal dequeueDog() {
        if (!dogQueue.empty()) {
            Animal dog = dogQueue.front();
            dogQueue.pop();
            return dog;
        }
        // Jika tidak ada anjing, kembalikan hewan dengan order yang sangat besar agar tidak dipilih
        return {"", INT_MAX};
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");

    Animal adoptedAnimal = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adoptedAnimal.type << endl;

    return 0;
}
```