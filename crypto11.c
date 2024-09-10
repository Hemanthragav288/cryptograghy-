#include <stdio.h>

int main() {
    // Precomputed value for 25!
    double playfair_key_space = 1;
    for (int i = 1; i <= 25; i++) {
        playfair_key_space *= i;
    }

    printf("The number of possible Playfair keys is approximately: %.0f\n", playfair_key_space);
    
    return 0;
}

