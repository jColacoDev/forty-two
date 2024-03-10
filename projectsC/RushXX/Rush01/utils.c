#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

int ft_atoi(const char *str);
char *ft_strdup(const char *str);
char *ft_strtok(char *str, const char *delim);
void ft_putstr(char *str);
void ft_putnbr(int n);
int **init_grid(int N);

int is_number(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

void print_views(int *views[]) {
    printf("Views matrix:\n");
    for (int i = 0; i < NUM_VIEWS; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", views[i][j]);
        }
        printf("\n");
    }
}

void print_grid(int *grid[], int N) {
    int i;

    i = 0;
    ft_putstr("\n");
    while (i < N) {
        int j = 0;
        while (j < N) {
            ft_putnbr(grid[i][j]);
            j++;
        }
        ft_putstr("\n");
        i++;
    }
    ft_putstr("\n");
}

int init_views_xargs(int argc, char *argv[], int *views[]) {
    // Check if the correct number of arguments is provided

    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", argv[0]);
    //     return -1;
    // }

    // char *arg = argv[1]; // Extract numbers from the second argument
    char *arg = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    if (arg == NULL || *arg == '\0') {
        fprintf(stderr, "No input provided.\n");
        return -1;
    }

    // Count the number of tokens in arg
    int numCount = 0;
    char *arg_copy = ft_strdup(arg);
    if (arg_copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    char *token = ft_strtok(arg_copy, " ");
    while (token) {
        numCount++;
        token = ft_strtok(NULL, " ");
    }
    free(arg_copy); // Free the memory allocated for arg_copy

    // Check if the correct number of numbers is provided
    if (numCount != GRID_SIZE * NUM_VIEWS && numCount != 0) {
        fprintf(stderr, "Incorrect number of numbers: %d\n", numCount);
        fprintf(stderr, "Expected: %d\n", GRID_SIZE * NUM_VIEWS);
        return -1;
    }

    // Initialize views array
    for (int i = 0; i < NUM_VIEWS; i++) {
        views[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        if (views[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return -1;
        }
        // Initialize each element to a default value (e.g., 0)
        for (int j = 0; j < GRID_SIZE; j++) {
            views[i][j] = 0;
        }
    }

    // Tokenize arg again and populate views array
    arg_copy = ft_strdup(arg);
    if (arg_copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    token = ft_strtok(arg_copy, " ");
    numCount = 0;
    while (token) {
        views[numCount / GRID_SIZE][numCount % GRID_SIZE] = ft_atoi(token);
        numCount++;
        token = ft_strtok(NULL, " ");
    }
    free(arg_copy); // Free the memory allocated for arg_copy

    return 1; // Success
}

void handle_result(int *grid[], int counter, int result){
    if (result) {
        ft_putstr("\nSolution found:\n");
        print_grid(grid, GRID_SIZE);
    } else {
        ft_putstr("\nNo solution exists.\n");
    }
    ft_putstr("\nCounter: ");
    ft_putnbr(counter);
    ft_putstr("\n");
}
