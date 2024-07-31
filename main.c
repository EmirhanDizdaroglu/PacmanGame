#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAW_SIZE 7
#define COLUMN_SIZE 7

// Rastgele bir sayı döndürür
int getRandomNumber() {
    return rand() % 10;
}

// Matrisi rastgele değerlerle doldurur
void initializeMatrix(int matrix[RAW_SIZE][COLUMN_SIZE]) {
    for (int i = 0; i < RAW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            matrix[i][j] = getRandomNumber();
        }
    }
}

// Matrisi ekrana yazdırır
void printMatrix(int matrix[RAW_SIZE][COLUMN_SIZE], int pacmanX, int pacmanY) {
    printf("  ");
    for (int i = 0; i < COLUMN_SIZE; i++) {
        printf(" %d   ", i);
    }
    printf("\n");

    for (int i = 0; i < RAW_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (i == pacmanX && j == pacmanY) {
                printf(" [PC] ");
            } else if (matrix[i][j] < 5) {
                printf(" [W] ");
            } else {
                printf(" [C] ");
            }
        }
        printf("\n");
    }
}

// Kullanıcının hareket girişini alır
void getUserInput(char *direction) {
    printf("Enter move direction (W/A/S/D): ");
    scanf(" %c", direction);
}

// Tüm hareketlerin geçerli olup olmadığını kontrol eder
int hasValidMove(int matrix[RAW_SIZE][COLUMN_SIZE], int pacmanX, int pacmanY) {
    // Yukarı
    if (pacmanX > 0 && matrix[pacmanX - 1][pacmanY] >= 5) return 1;
    // Aşağı
    if (pacmanX < RAW_SIZE - 1 && matrix[pacmanX + 1][pacmanY] >= 5) return 1;
    // Sol
    if (pacmanY > 0 && matrix[pacmanX][pacmanY - 1] >= 5) return 1;
    // Sağ
    if (pacmanY < COLUMN_SIZE - 1 && matrix[pacmanX][pacmanY + 1] >= 5) return 1;
    return 0;
}

// Oyunun ana fonksiyonu
int main() {
    srand(time(NULL));
    int matrix[RAW_SIZE][COLUMN_SIZE];
    int pacmanX = rand() % RAW_SIZE;
    int pacmanY = rand() % COLUMN_SIZE;
    int score = 0;

    initializeMatrix(matrix);

    char direction;

    while (1) {
        printMatrix(matrix, pacmanX, pacmanY);
        printf("Score: %d\n", score);
        getUserInput(&direction);

        // Kullanıcı hareketini uygular
        int newX = pacmanX;
        int newY = pacmanY;

        switch (direction) {
            case 'W': // Yukarı
                newX = pacmanX - 1;
                break;
            case 'S': // Aşağı
                newX = pacmanX + 1;
                break;
            case 'A': // Sol
                newY = pacmanY - 1;
                break;
            case 'D': // Sağ
                newY = pacmanY + 1;
                break;
            default:
                printf("Invalid move! Use W, A, S, or D.\n");
                continue;
        }

        // Sınır kontrolü
        if (newX < 0 || newX >= RAW_SIZE || newY < 0 || newY >= COLUMN_SIZE) {
            printf("Boundary reached! Cannot move further.\n");
            continue;
        }

        // Duvar kontrolü
        if (matrix[newX][newY] < 5) {
            printf("Cannot move through walls!\n");
            continue;
        }

        // Skoru güncelle ve matris güncelle
        if (matrix[newX][newY] >= 5) {
            score++;
            matrix[newX][newY] = getRandomNumber(); // Yeni bir değer ata
        }

        pacmanX = newX;
        pacmanY = newY;

        // Oyunun bitiş koşulunu kontrol et
        if (!hasValidMove(matrix, pacmanX, pacmanY)) {
            printf("Game over! No more moves available.\n");
            break;
        }
    }

    printf("Final Score: %d\n", score);
    return 0;
}
