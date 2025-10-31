#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    string jenis;
    int umur;
    int darurat;
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore();

    // Dynamic array
    Pasien* daftar = new Pasien[n];

    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, daftar[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, daftar[i].jenis);
        cout << "Umur: ";
        cin >> daftar[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> daftar[i].darurat;
        cin.ignore();
    }

    // Urutkan secara manual 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (daftar[j].darurat > daftar[i].darurat) {
                swap(daftar[i], daftar[j]);
            }
        }
    }

    cout << "\n=== Urutan Pelayanan ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << daftar[i].nama 
             << " (" << daftar[i].umur << " tahun) - Darurat "
             << daftar[i].darurat << endl;
    }

    delete[] daftar; 
    return 0;
}