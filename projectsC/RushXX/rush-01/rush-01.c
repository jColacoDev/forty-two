#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

int is_delimiter(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

char *ft_strdup(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if (copy == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        copy[i] = str[i];
    }
    return copy;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

int ft_atoi(const char *str) {
    int result = 0;
    int negative = 0;
    while (str != NULL && (*str == ' ' || *str == '\t' || *str == '\n')) {
        str++;
    }
    if (*str == '-') {
        negative = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (negative) {
        result = -result;
    }
    return result;
}

char *ft_strtok(char *str, const char *delim) {
    static char *value;
    static char *next_value;
    char *result;

    if (str) {
        value = str;
    } else {
        value = next_value;
    }
    if (value == NULL) {
        return NULL;
    }
    while (*value != '\0' && is_delimiter(*value, delim)) {
        value++;
    }
    if (*value == '\0') {
        return NULL;
    }
    result = value;

    while (*value != '\0' && !is_delimiter(*value, delim)) {
        value++;
    }
    if (*value != '\0') {
        *value = '\0';
        value++;
        next_value = value;
    } else {
        next_value = NULL;
    }
    char *token = (char *)malloc((value - result + 1) * sizeof(char));
    if (token == NULL) {
        return NULL;
    }
    strcpy(token, result);
    return token;
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int n) {
    // Handle negative numbers
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    // Handle the case of n being 0 separately
    if (n == 0) {
        ft_putchar('0');
        return;
    }
    // Initialize variables
    int divisor = 1;
    int temp = n;
    // Find the divisor for the highest order digit
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
    }
    // Output each digit one by one using the divisor
    while (divisor > 0) {
        ft_putchar('0' + (n / divisor)); // Output the current digit
        n %= divisor; // Remove the current digit from n
        divisor /= 10; // Update the divisor for the next digit
    }
}

void print_grid(int **grid, int **views) {
    printf(" ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d", views[0][i]);
    }
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", views[2][i]); // Left view
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("%d\n", views[3][i]); // Right view
    }
    printf(" ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d", views[1][i]);
    }
    printf("\n");
}

int check_visibility(int **grid, int **views, int row, int col, int size, int val) {
    int viewVal;
    int direction;
    int counter;
    int flag;

    printf("\ninput Val: %d", val);
    printf(" | grid value: %d", grid[row][col]);
    printf("\nrow: %d", row);
    printf(" | col: %d", col);
    printf("\ntop: %d", views[0][col]);
    printf(" | bot: %d", views[1][col]);
    printf(" | left: %d", views[2][row]);
    printf(" | right: %d \n", views[3][row]);
    print_grid(grid, views);


    flag = 1;
    // Check visibility in each direction and compare with view counts
    for (direction = 0; direction < 4; direction++) {
        viewVal = views[direction][col];

        switch (direction) {
            case 0: // Top
                counter = count_visible_buildings(grid, views, row, col, direction, size, val);
                printf("-----\n");
                printf("topView: %d", viewVal);
                printf(" | counter: %d", counter);

                if (counter > viewVal) {
                    flag = 0; // Visibility rules violated
                }
                if(val > viewVal && row < viewVal-1){
                    flag = 0; // Visibility rules violated
                }
                break;
            case 1: // Bottom
                counter = count_visible_buildings(grid, views, row, col, direction, size, val);
                printf("-----\n");
                printf("botVal: %d", viewVal);
                printf(" | counter: %d", counter);

                if (counter > viewVal) {
                    flag = 0; // Visibility rules violated
                }
                if(val > viewVal && row > viewVal-1){
                    flag = 0; // Visibility rules violated
                }
                break;
            case 2: // Left
                counter = count_visible_buildings(grid, views, row, col, direction, size, val);
                printf("-----\n");
                printf("lefVal: %d", viewVal);
                printf(" | counter: %d", counter);
                if (counter > viewVal) {
                    flag = 0; // Visibility rules violated
                }
                if(val > viewVal && col < viewVal-1){
                    flag = 0; // Visibility rules violated
                }
                break;
            case 3: // Right
                counter = count_visible_buildings(grid, views, row, col, direction, size, val);
                printf("-----\n");
                printf("rigVal: %d | ",viewVal);
                printf("counter: %d\n", counter);
                if (counter > viewVal) {
                    flag = 0; // Visibility rules violated
                }
                break;
        }
        printf("-----\n");

            // printf("\nview nCounter: %d", counter);
    }

    return flag; // Visibility rules satisfied
}

int is_valid(int **grid, int **views, int row, int col, int val, int size) {
    // Check if the value already exists in the same row
    for (int i = 0; i < size; i++) {
        if (grid[row][i] == val && i != col) {
        printf("-----already in row\n");

            return 0; // Not valid
        }
    }

    // Check if the value already exists in the same column
    for (int i = 0; i < size; i++) {
        if (grid[i][col] == val && i != row) {
        printf("-----already in column\n");
            return 0; // Not valid

        }
    }

    // Check visibility rules
    return check_visibility(grid, views, row, col, size, val);
}

int count_visible_buildings(int **grid, int **views, int row, int col, int direction, int size, int val) {
    int count = 0;
    int maxHeight = 0; // Initialize the maxHeight to 0

    // Adjust the starting and ending indices based on the direction
    int start, end, step;
    switch (direction) {
        case 0: // Top
            start = 0;
            end = size;
            step = 1;
            break;
        case 1: // Bottom
            start = size - 1;
            end = -1;
            step = -1;
            break;
        case 2: // Left
            start = 0;
            end = size;
            step = 1;
            break;
        case 3: // Right
            start = size - 1;
            end = -1;
            step = -1;
            break;
        default:
            return -1; // Invalid direction
    }

    // Traverse the specified row or column based on the direction
    for (int i = start; i != end; i += step) {
        int currentHeight = (direction == 0 || direction == 1) ? grid[i][col] : grid[row][i];
        if (currentHeight > maxHeight) {
            count++;
            maxHeight = currentHeight;
        }
    }

    return count;
}

int init_views_xargs(int argc, char *argv[], int *views[]) {
    // Check if the correct number of arguments is provided

    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", argv[0]);
    //     return -1;
    // }

    // char *arg = argv[1]; // Extract numbers from the second argument
    char *arg = "1 2 3 3 3 3 1 2 1 2 2 2 4 3 1 2";
    if (arg == NULL || *arg == '\0') {
        fprintf(stderr, "No input provided.\n");
        return 0;
    }

    // Count the number of tokens in arg
    int numCount = 0;
    char *arg_copy = ft_strdup(arg);
    if (arg_copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
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
        return 0;
    }

    // Initialize views array
    for (int i = 0; i < NUM_VIEWS; i++) {
        views[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        if (views[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 0;
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
        return 0;
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


int solve_sky_scrapper(int **grid, int **views, int row, int col, int size, int *deepCounter) {
    (*deepCounter)++;
    printf("\ndeepCounter++: %d", *deepCounter);
    if (row == size) {
        (*deepCounter)--;
        printf("\ndeepCounter--: %d", *deepCounter);
        return 1;
    }
    if (col == size) {
        (*deepCounter)--;
        printf("\ndeepCounter--: %d", *deepCounter);
        if (solve_sky_scrapper(grid, views, row + 1, 0, size, deepCounter)) {
            (*deepCounter)++;
            printf("\ndeepCounter++: %d", *deepCounter);
            return 1;
        } else {
            (*deepCounter)--;
            printf("\ndeepCounter--: %d", *deepCounter);
            return 0;
        }
    }
    if (grid[row][col] != 0) {
        if (solve_sky_scrapper(grid, views, row, col + 1, size, deepCounter)) {
            (*deepCounter)++;
            printf("\ndeepCounter++: %d", *deepCounter);
            return 1;
        } else {
            (*deepCounter)--;
            printf("\ndeepCounter--: %d", *deepCounter);
            return 0;
        }
    }
    for (int num = 1; num <= size; num++) {
        if (is_valid(grid, views, row, col, num, size)) {
            grid[row][col] = num;
            if (solve_sky_scrapper(grid, views, row, col + 1, size, deepCounter)) {
                (*deepCounter)--;
                printf("\ndeepCounter--: %d", *deepCounter);
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    (*deepCounter)--;
    printf("\ndeepCounter--: %d", *deepCounter);
    return 0;
}



int main() {
    int deepCounter = 0;
    int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    int **views = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }
    for (int i = 0; i < 4; i++) {
        views[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    init_views_xargs(1, NULL, views); // Initialize views
    print_grid(grid, views);

    if (solve_sky_scrapper(grid, views, 0, 0, GRID_SIZE, &deepCounter)) {
        printf("\nSolution found:\n");
        print_grid(grid, views);
    } else {
        printf("No solution found.\n");
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    for (int i = 0; i < 4; i++) {
        free(views[i]);
    }
    free(grid);
    free(views);

    return 0;
}
