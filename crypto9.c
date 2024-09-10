#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define MAX_TEXT_LEN 100

// Playfair cipher matrix
char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'J'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

// Function to find the position of a letter in the matrix
void find_position(char letter, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Playfair decryption function
void playfair_decrypt(const char *ciphertext, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        find_position(ciphertext[i], &row1, &col1);
        find_position(ciphertext[i + 1], &row2, &col2);

        if (row1 == row2) {
            // Same row, move left
            plaintext[i] = matrix[row1][(col1 + SIZE - 1) % SIZE];
            plaintext[i + 1] = matrix[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {
            // Same column, move up
            plaintext[i] = matrix[(row1 + SIZE - 1) % SIZE][col1];
            plaintext[i + 1] = matrix[(row2 + SIZE - 1) % SIZE][col2];
        } else {
            // Rectangle rule
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
        }
    }
    plaintext[len] = '\0';  // Null-terminate the string
}

// Main function
int main() {
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPO";
    char plaintext[MAX_TEXT_LEN] = {0};

    playfair_decrypt(ciphertext, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}

