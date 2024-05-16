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
