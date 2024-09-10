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

// Function to preprocess the message (remove spaces and add X between duplicate letters)
void preprocess_message(const char *message, char *processed) {
    int len = strlen(message);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            processed[index++] = toupper(message[i]);
            if (i < len - 1 && message[i] == message[i + 1]) {
                processed[index++] = 'X';  // Add 'X' between duplicate letters
            }
        }
    }
    if (index % 2 != 0) {
        processed[index++] = 'X';  // Add padding if odd length
    }
    processed[index] = '\0';
}

// Playfair encryption function
void playfair_encrypt(const char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        find_position(plaintext[i], &row1, &col1);
        find_position(plaintext[i + 1], &row2, &col2);

        if (row1 == row2) {
            // Same row, move right
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            // Same column, move down
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            // Rectangle rule
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }
    ciphertext[len] = '\0';  // Null-terminate the string
}

// Main function
int main() {
    const char *message = "Must see you over Cadogan West. Coming at once.";
    char processed[MAX_TEXT_LEN] = {0};
    char ciphertext[MAX_TEXT_LEN] = {0};

    preprocess_message(message, processed);
    playfair_encrypt(processed, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

