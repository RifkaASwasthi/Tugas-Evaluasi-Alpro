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
