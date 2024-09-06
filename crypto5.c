#include <stdio.h>
#include <ctype.h>

void affine_cipher(char *text, int a, int b) {
    char ch;
    while (*text) {
        ch = *text;
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ((a * (ch - 'A') + b) % 26) + 'A';
            } else {
                ch = ((a * (ch - 'a') + b) % 26) + 'a';
            }
        }
        putchar(ch);
        text++;
    }
    putchar('\n');
}

int main() {
    char text[] = "HELLO WORLD";
    int a = 5; // Example 'a' value
    int b = 8; // Example 'b' value

    printf("Original text: %s\n", text);
    printf("Encrypted text: ");
    affine_cipher(text, a, b);

    return 0;
}

