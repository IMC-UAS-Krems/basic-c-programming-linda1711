#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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

    // Dynamically allocate the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    // Fill the matrix -> int 1 - 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    // Create, open output file
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    // Width for printing numbers (alignment)
    int field_width = 3; // Adjust based on the max number size

    // Write the matrix into a file with colum alignment
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%*d", field_width, matrix[i][j]); // *d allows dynamic width specification
            if (j < cols - 1) {
                fprintf(file, " ");  // Space between numbers
            }
        }
        fprintf(file, "\n"); // End of row
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Close file
    fclose(file);

    // Success message
    printf("Matrix created successfully and written to 'matrix.txt'\n");

    return 0;
}


