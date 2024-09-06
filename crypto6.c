#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to find modular multiplicative inverse of a mod m
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse does not exist
}

void affine_decrypt(char *text, int a, int b) {
    int a_inv = mod_inverse(a, ALPHABET_SIZE);
    char ch;

    if (a_inv == -1) {
        printf("No modular inverse exists for a=%d.\n", a

