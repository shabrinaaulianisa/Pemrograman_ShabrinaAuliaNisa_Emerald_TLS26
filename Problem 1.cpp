#include <iostream>
using namespace std;

// ---------- Deklarasi fungsi ----------
void inputData(int &n, int &k_awal);
void inisialisasiSisa(int sisa[], int n);
int hitungPosisiEliminasi(int p, int k, int s);
void tambahKeUrutan(int urutan[], int &e, int nilai);
void hapusDariSisa(int sisa[], int &s, int p);
void perbaruiK(int &k, int nilaiEliminasi);
void cetakUrutanEliminasi(int urutan[], int e);

int main() {
    int n, k_awal;
    inputData(n, k_awal);

    // Validasi n
    if (n < 1) {
        cout << "Error: jumlah astronaut harus minimal 1" << endl;
        return 0;
    }

    // Validasi k_awal minimal 2
    if (k_awal < 2) {
        k_awal = 2;
    }

    int *sisa = new int[n];
    int *urutan_eliminasi = new int[n];

    int k = k_awal;
    int e = 0;
    int basis_indeks = 0;
    int p = basis_indeks;

    inisialisasiSisa(sisa, n);
    int s = n;

    while (s > 1) {
        p = hitungPosisiEliminasi(p, k, s);

        tambahKeUrutan(urutan_eliminasi, e, sisa[p]);
        cout << "Dieliminasi: " << sisa[p] << endl;

        // Perbarui k
        perbaruiK(k, sisa[p]);

        // Hapus elemen dari sisa; mengurangi s
        hapusDariSisa(sisa, s, p);

        // k minimum 2
        if (k < 2) {
            k = 2;
        }

        // Reset posisi acuan jika keluar batas
        if (p >= s) {
            p = 0;
        }
    }

    cout << "----------------------------------" << endl;
    cout << "Urutan astronaut yang dieliminasi:" << endl;
    cetakUrutanEliminasi(urutan_eliminasi, e);

    cout << "Astronaut terakhir: " << sisa[0] << endl;

    // Bebaskan memori yang dialokasikan dengan new
    delete[] sisa;
    delete[] urutan_eliminasi;

    return 0;
}

// Meminta input nilai n dan nilai k awal dari pengguna
void inputData(int &n, int &k_awal) {
    cout << "Masukkan jumlah astronaut (n): ";
    cin >> n;
    cout << "Masukkan nilai k awal: ";
    cin >> k_awal;
}

// Mengisi array sisa dengan id astronaut 0..n-1
void inisialisasiSisa(int sisa[], int n) {
    for (int i = 0; i < n; i++) {
        sisa[i] = i;
    }
}

// Menghitung posisi astronaut yang akan dieliminasi
// berdasarkan rumus Josephus: p_baru = (p + k - 1) mod s
int hitungPosisiEliminasi(int p, int k, int s) {
    return (p + k - 1) % s;
}

// Menambahkan nilai astronaut yang dieliminasi ke urutan_eliminasi
void tambahKeUrutan(int urutan[], int &e, int nilai) {
    urutan[e] = nilai;
    e = e + 1;
}

void hapusDariSisa(int sisa[], int &s, int p) {
    for (int i = p; i < s - 1; i++) {
        sisa[i] = sisa[i + 1];
    }
    s = s - 1;
}

// Memperbarui nilai k
// dieliminasi: genap -> k+2, ganjil -> k-1
void perbaruiK(int &k, int nilaiEliminasi) {
    int sisaBagi = nilaiEliminasi % 2;
    if (sisaBagi == 0) {
        k = k + 2;
    } else {
        k = k - 1;
    }
}

// Mencetak seluruh urutan eliminasi
void cetakUrutanEliminasi(int urutan[], int e) {
    for (int i = 0; i < e; i++) {
        cout << urutan[i];
        if (i < e - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}