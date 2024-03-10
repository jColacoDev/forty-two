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


int count_visible_buildings(int **grid, int row, int col, int direction, int N) {
    int count = 0;
    int maxHeight = 0;

    // Calculate the starting and ending indices based on the direction
    int startRow = row, endRow = row, startCol = col, endCol = col;
    if (direction == 0 || direction == 2) {
        endRow = (direction == 0) ? 0 : N - 1;
    } else {
        startCol = (direction == 1) ? N - 1 : 0;
    }

    while ((direction == 0 || direction == 2) ? startRow != endRow : startCol != endCol) {
        if (grid[row][col] > maxHeight) {
            maxHeight = grid[row][col];
            count++;
        }
        if (direction == 0 || direction == 2) {
            startRow += (endRow < startRow) ? -1 : 1;
        } else {
            startCol += (endCol < startCol) ? -1 : 1;
        }
    }

    return count;
}

int check_visibility(int **grid, int **views, int row, int col, int size, int val) {
    int visibleBuildings;
    int viewCount;
    int direction;

    int temp = val * 2;
        if (temp != 0) {
        temp++;
    }
    // Check visibility in each direction and compare with view counts
    direction = 0;
    while (direction < 4) {
        viewCount = views[direction][direction % 2 ? col : row];
        visibleBuildings = count_visible_buildings(grid, row, col, direction, size);
        if (viewCount > 0 && visibleBuildings > viewCount) {
            return -1; // Visibility rules violated
        }
        direction++;
    }

    return 1; // Visibility rules satisfied
}

int is_valid(int **grid, int **views, int row, int col, int val, int size) {
    // Check if the value already exists in the same row or column
    for (int i = 0; i < size; i++) {
        if ((grid[row][i] == val && i != col) || (grid[i][col] == val && i != row)) {
            return 0; // Not valid
        }
    }

    // Check visibility rules
    return check_visibility(grid, views, row, col, size, val);
}



int init_views_xargs(int argc, char *argv[], int *views[]) {
    // Check if the correct number of arguments is provided

    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", argv[0]);
    //     return -1;
    // }

    // char *arg = argv[1]; // Extract numbers from the second argument
    // char *arg = "2 1 4 2 2 1 3 2 2 3 1 3 2 3 1 2";
    char *arg = "1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5";
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

int solve_sky_scrapper(int **grid, int **views, int row, int col, int size) {
    if (row == size) {
        return 1;
    }
    if (col == size) {
        return solve_sky_scrapper(grid, views, row + 1, 0, size);
    }
    if (grid[row][col] != 0) {
        return solve_sky_scrapper(grid, views, row, col + 1, size);
    }
    for (int num = 1; num <= size; num++) {
            printf("\nValidating...\n");
        if (is_valid(grid, views, row, col, num, size)) {
            grid[row][col] = num;
            printf("\nValidation\n");

            // print_grid(grid, views);
            if (solve_sky_scrapper(grid, views, row, col + 1, size)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
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

    if (solve_sky_scrapper(grid, views, 0, 0, GRID_SIZE)) {
        printf("Solution found:\n");
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
