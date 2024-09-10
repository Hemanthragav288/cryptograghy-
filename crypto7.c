#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CIPHERTEXT_LEN 1000
#define MAX_ALPHABET 256

// Function to calculate character frequencies
void calculate_frequency(const char *ciphertext, int freq[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        freq[(unsigned char)ciphertext[i]]++;
    }
}

// Function to display frequencies
void display_frequencies(int freq[]) {
    for (int i = 0; i < MAX_ALPHABET; i++) {
        if (freq[i] > 0) {
            printf("Character '%c' has frequency %d\n", i, freq[i]);
        }
    }
}

// Main function
int main() {
    // Ciphertext provided
    const char ciphertext[] = "53‡‡†305))6*34826)4‡.)4‡);806*;48†860))85;;]8*;:*8+83"
                              "(88)5*†;46(;88*96*7;8)*‡(;485);5*†2:*‡(;4956*2(5*-4)88*"
                              ";4069285);)6+8)4‡‡;1(‡9;48081;8:81;48+85;4)485+528806*81 "
                              "($9;48;(88;4(‡?34;48)4;161;:188;‡?";

    int freq[MAX_ALPHABET] = {0}; // Array to store frequency of each character

    // Step 1: Calculate frequency of each character in the ciphertext
    calculate_frequency(ciphertext, freq);

    // Step 2: Display the frequency of each character
    display_frequencies(freq);

    // Step 3: Start mapping (manual work needed here for decryption)
    printf("\nNow, manually map the most frequent characters to English letters like 'e', 't', 'a', etc.\n");

    return 0;
}

