#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

void ft_putnbr(int n);
void ft_putstr(char *str);
void print_grid(int *grid[], int N);
int is_valid(int **grid, int **views, int row, int col, int val, int N);

int **init_grid(int N) {
    int **grid = (int **)malloc(N * sizeof(int *));
    if (grid == NULL) {
        return NULL;
    }
    for (int i = 0; i < N; ++i) {
        grid[i] = (int *)malloc(N * sizeof(int));
        if (grid[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; ++j) {
                free(grid[j]);
            }
            free(grid);
            return NULL;
        }
        // Initialize elements of each row to 0
        for (int j = 0; j < N; ++j) {
            grid[i][j] = 0;
        }
    }
    return grid;
}


int check_empty_cell(int **grid, int *row, int *col, int N) {
    int i = 0;
    int j;

    while (i < N) {
        j = 0;
        while (j < N) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                printf("\nEmpty cell found at row: %d, col: %d\n", *row, *col);
                return -1;
            }
            j++;
        }
        i++;
    }
    printf("No empty cells found.\n");
    return 1;
}

void free_grids(int *views[], int *grid[]){
    int i;

    i = 0;
    while (i < GRID_SIZE) {
        free(grid[i]);
        i++;
    }
    i = 0;
    while (i < NUM_VIEWS) {
        free(views[i]);
        i++;
    }
}

int puzzle_algorithm(int **grid, int **views, int N, int *counter) {
    int row = 0; 
    int col = 0;
    int building;
    int building2;

    // Increment the counter
    (*counter)++;

    print_grid(grid, N);
    // Check for empty cells
    if (check_empty_cell(grid, &row, &col, N) == 1) {
        // If no empty cell is found, print debug message and return 1
        return 1;
    }

    // Debug message if an empty cell is found
    // print_grid(grid, N);
    // Iterate through possible building heights
    building = 1;
    building2 = 0;
    
    printf("%d",9999);

    ft_putstr("\nBuilding2: ");
    printf("%d",building2);
    ft_putstr("\nN: ");
    printf("%d",N);
    while (building <= N) {
        ft_putstr("\ntesting Building: ");
        printf("%d",building);

        if (is_valid(grid, views, row, col, building, N)) {
            grid[row][col] = building;
            if (puzzle_algorithm(grid, views, N, counter)) {
                return 1; // If a solution is found, return 1
            }
        }
        // Increment building to try the next possible value
        building++;
    }
    // If no valid building height is found, return -1
    // If no solution is found, backtrack
    grid[row][col] = 0;
    printf("\nHere. -1\n");
    return -1;
}

