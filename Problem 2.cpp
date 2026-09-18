#include <iostream>
using namespace std;

const int MAX_LEN = 1000000;

// ---------- Deklarasi fungsi user-defined ----------
int panjangPesan(char pesan[]);
int nilaiHuruf(char c);
char huruf(int nilai);
void enkripsiAlienDiTengah(char pesan[], char hasil[], int n);
void cetakHasil(char hasil[], int n);

int main() {
    char pesan[MAX_LEN];

    cout << "Masukkan pesan (huruf kapital A-Z, tanpa spasi): ";
    cin >> pesan;

    int n = panjangPesan(pesan);

    if (n < 1) {
        cout << "Error: pesan tidak boleh kosong" << endl;
        return 0;
    }

    char hasil[MAX_LEN];
    enkripsiAlienDiTengah(pesan, hasil, n);

    cout << "Sandi: ";
    cetakHasil(hasil, n);

    return 0;
}

int panjangPesan(char pesan[]) {
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang = panjang + 1;
    }
    return panjang;
}

// Mengonversi huruf menjadi nilai numerik: A=1, B=2, ..., Z=26
int nilaiHuruf(char c) {
    return (c - 'A' + 1);
}

// Mengonversi nilai numerik menjadi huruf: 1=A, 2=B, ..., 26=Z
char huruf(int nilai) {
    return (char)('A' + nilai - 1);
}

void enkripsiAlienDiTengah(char pesan[], char hasil[], int n) {
    // Inisialisasi: hasil[0] dan i = 1 (sesuai flowchart)
    hasil[0] = pesan[0];
    int nilai_huruf_sebelumnya = nilaiHuruf(pesan[0]);

    int i = 1;
    while (i < n) {
        int nilai_huruf_asli = nilaiHuruf(pesan[i]);
        int nilai_huruf_baru = nilai_huruf_asli + nilai_huruf_sebelumnya;

        int nilai_huruf;
        if (nilai_huruf_baru > 26) {
            nilai_huruf = nilai_huruf_baru - 26;
        } else {
            nilai_huruf = nilai_huruf_baru;
        }

        hasil[i] = huruf(nilai_huruf);
        nilai_huruf_sebelumnya = nilai_huruf;

        i = i + 1;
    }
    hasil[n] = '\0';
}

// Mencetak hasil (sandi) 
void cetakHasil(char hasil[], int n) {
    for (int i = 0; i < n; i++) {
        cout << hasil[i];
    }
    cout << endl;
}