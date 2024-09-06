#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generatePlayfairMatrix(char *key, char matrix[SIZE][SIZE]) {
    int i, j, k;
    int used[26] = {0}; // Keep track of used letters
    char key_clean[26];
    int len = 0;

    // Clean the key: remove non-alphabetic characters and convert to uppercase
    for (i = 0; key[i]; i++) {
        if (isalpha(key[i])) {
            key_clean[len++] = toupper(key[i]);
        }
    }

    // Remove duplicates and 'J' (usually combined with 'I')
    len = 0;
    for (i = 0; i < strlen(key_clean); i++) {
        if (!used[key_clean[i] - 'A'] && key_clean[i] != 'J') {
            used[key_clean[i] - 'A'] = 1;
            key_clean[len++] = key_clean[i];
        }
    }
    // Fill matrix
    k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < len) {
                matrix[i][j] = key_clean[k++];
            } else {
                while (used[k % 26]) k++;
                matrix[i][j] = 'A' + (k++ % 26);
                if (matrix[i][j] == 'J') matrix[i][j] = 'I'; // Combine J and I
            }
        }
    }
}

void playfairEncrypt(char *text, char matrix[SIZE][SIZE]) {
    int i, j;
    char a, b;
    
    while (*text) {
        a = toupper(*text);
        b = toupper(*(text + 1));
        if (!isalpha(a)) {
            putchar(a);
            text++;
            continue;
        }
        if (!isalpha(b) || a == b) {
            b = 'X'; // Insertion for double letters or single letter at the end
        }
        text++;
        
        // Locate characters in the matrix
        int row1, col1, row2, col2;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (matrix[i][j] == a) {
                    row1 = i;
                    col1 = j;
                }
                if (matrix[i][j] == b) {
                    row2 = i;
                    col2 = j;
                }
            }
        }
        
        if (row1 == row2) {
            putchar(matrix[row1][(col1 + 1) % SIZE]);
            putchar(matrix[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) {
            putchar(matrix[(row1 + 1) % SIZE][col1]);
            putchar(matrix[(row2 + 1) % SIZE][col2]);
        } else {
            putchar(matrix[row1][col2]);
            putchar(matrix[row2][col1]);
        }
    }
    putchar('\n');
}

int main() {
    char text[] = "HELLO WORLD";
    char key[] = "KEYWORD"; // Example key
    char matrix[SIZE][SIZE];

    generatePlayfairMatrix(key, matrix);

    printf("Original text: %s\n", text);
    printf("Encrypted text: ");
    playfairEncrypt(text, matrix);

    return 0;
}

