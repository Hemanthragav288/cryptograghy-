#include <stdio.h>
#include <ctype.h>

void polyalphabetic_cipher(char *text, char *key) {
    char ch;
    int key_len = strlen(key);
    int i = 0;

    while (*text) {
        ch = *text;
        if (isalpha(ch)) {
            int shift = toupper(key[i % key_len]) - 'A';
            if (isupper(ch)) {
                ch = (ch - 'A' + shift) % 26;
                ch += 'A';
            } else {
                ch = (ch - 'a' + shift) % 26;
                ch += 'a';
            }
            i++;
        }
        putchar(ch);
        text++;
    }
    putchar('\n');
}

int main() {
    char text[] = "HELLO WORLD";
    char key[] = "KEY"; // Example key

    printf("Original text: %s\n", text);
    printf("Encrypted text: ");
    polyalphabetic_cipher(text, key);

    return 0;
}

