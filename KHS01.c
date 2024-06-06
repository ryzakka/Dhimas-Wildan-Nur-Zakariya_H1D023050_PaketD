#include <stdio.h>

// Deklarasi struktur KHS
typedef struct {
    int NIM;
    float IP;
    informasi* KHS;} KHS;

// Fungsi cetak KHS
void printKHS(KHS* khs) {
    printf("NIM: %d\n", khs->NIM);
    printf("IP: %.f\n", khs->IP);
}

int main() {
    KHS khs;
    khs.NIM = 0292023;
    khs.IP = 3.75;
    
    // Cetak KHS sebelum perubahan
    printf("Sebelum IP diperbarui:\n");
    printKHS(&khs);
    printf("\n");

    // Ubah IP Mahasiswa
    khs.IP = 3.90;

    // Cetak KHS setelah perubahan
    printf("Setelah IP diperbarui:\n");
    printKHS(&khs);

    return 0;
}
