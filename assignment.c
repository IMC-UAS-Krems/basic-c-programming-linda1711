#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

// String represents a positive integer
int is_positive_integer(char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    // Number of arguments is exactly 2
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }

    // Validate that both arguments are positive integers
    if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2])) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    // Convert to int
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Dimensions are greater than 0
    if (rows <= 0 || cols <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }



    // Random number generator
    srand(time(NULL));
    int min_r = 1;
    int max_r = 100;

    // Dynamic matrix
    int** matrix = malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Random numbers matrix fill
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            matrix[x][y] = min_r + rand() % (max_r - min_r + 1);
        }
    }

    // Print
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
