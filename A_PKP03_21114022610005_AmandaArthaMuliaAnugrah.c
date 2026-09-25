
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int permainanTebakKode(int jawaban, int minimum, int maksimum, int *percobaan) {
    int tebakan;

    printf("Masukkan tebakan anda (%d - %d): ", minimum, maksimum);
    scanf("%d", &tebakan);

    (*percobaan)++;

    if (tebakan < jawaban) {
        printf("Terlalu kecil! Silakan coba lagi.\n"); 

        return permainanTebakKode(
            jawaban,
            minimum,
            maksimum,
            percobaan
        );

    } else if (tebakan > jawaban) {
        printf("Terlalu besar! Silakan coba lagi.\n");

        return permainanTebakKode(
            jawaban,
            minimum,
            maksimum,
            percobaan
        );

    } else {
        printf(
            "Selamat! Anda berhasil menebak angka %d dalam %d percobaan.\n",
            jawaban,
            *percobaan
        );

        return tebakan;
    }
}

void tampilkanHasil(int percobaan) {
    if (percobaan <= 5) {
        printf("Kerja sangat bagus! Anda berhasil menebaknya dengan cepat!\n");
    } else if (percobaan <= 10) {
        printf("Kerja bagus! Jumlah percobaan anda cukup baik.\n");
    } else {
        printf("Anda masih bisa lebih baik! terus berlatih agar semakin mahir.\n");
    }
}

void jalankanPermainan() {
    int minimum = 1;
    int maksimum = 100;
    int percobaan = 0;

    int jawaban = (rand() % (maksimum - minimum + 1)) + minimum;

    printf("========================================\n");
    printf("          PERMAINAN TEBAK KODE          \n");
    printf("========================================\n");
    printf("Selamat datang di permainana tebak kode!\n");
    printf("Saya telah memilih sebuah angka antara %d dan %d.\n", 
           minimum, maksimum);

    permainanTebakKode(
        jawaban,
        minimum,
        maksimum,
        &percobaan
    );

    tampilkanHasil(percobaan);

    printf("Angka yang benar adalah: %d\n", jawaban);
    printf("Jumlah percobaan: %d\n", percobaan);
}

int main() {

    srand(time(NULL));

    jalankanPermainan();

    return 0;
}