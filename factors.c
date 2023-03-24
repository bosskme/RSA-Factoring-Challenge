#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void find_factors(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
    printf("%d=1*%d\n", n, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int n;
    while (fscanf(file, "%d", &n) != EOF) {
        find_factors(n);
    }

    fclose(file);
    return 0;
}