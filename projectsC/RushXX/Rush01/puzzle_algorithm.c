#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

void print_grid(int *grid[], int N);
int is_valid(int **grid, int **views, int row, int col, int val, int N);

int init_grid(int *grid[], int N) {
    int i = 0;
    while (i < N) { // Allocate memory for each row
        grid[i] = (int *)malloc(N * sizeof(int)); 
        if (grid[i] == NULL) { // Check for memory allocation failure
            // Free previously allocated memory
            while (i > 0) {
                free(grid[--i]);
            }
            return -1; // Return -1 for failure
        }
        int j = 0;
        while (j < N) {
            grid[i][j] = 0; // Initialize element to 0
            j++;
        }
        i++;
    }
    return 1; // Return 1 for success
}

int check_empty_cell(int **grid, int *row, int *col, int N) {
    int i = -1;
    int j = -1;

    // Double loop to run a n*n matrix and check if 
    // it's empty by looking for 0's
    // if it is, we save the coordinates in Row and Col variables
    while (i++ < N) { // loop the rows 
        while (j++ < N) { // loop the cols
            if (grid[i][j] == 0) { // it has a 0 means it's an empty cell
                *row = i;   // we save the coordinates
                *col = j;

                return(-1); // and return -1, meaning there is a empty cell
            }
        }
    }           // Success!
    return (1); // if there were no empty cells, it's FINISH HIM!
}

int puzzle_algorithm(int **grid, int **views, int N, int counter) {
    int row = -1; 
    int col = -1;
    int building_height = 0;

    printf("\nHere.\n");
    // print_grid(grid, N);
    // print_grid(views, NUM_VIEWS);

    counter++;
    // First we check if the puzzle has empty cells
    // or by other words, if it's complete and solved 
    if (check_empty_cell(grid, &row, &col, N)) {
        return 1;
    }

    // After finding an empty cell we try buildings 1->n sizes
    while (building_height++ <= N) {
        // And we validate if it's a valid move or not
        if (is_valid(grid, views, row, col, building_height, N)) {
            // if it's valid we put it there!
            grid[row][col] = building_height;
            // And we move on to the next move by calling 
            // puzzle_algorithm recursively
            if (puzzle_algorithm(grid, views, N, counter)) {
                //if this returns true, means some other call to this function
                //was successful! And so We also return 1 to signal the success!
                return 1;
            }
            // If we didn't return before with a success
            // Than let's backtrace, we place a 0 to flag 
            // empty cell, where we were testing out buildings
            grid[row][col] = 0;
        }
    }
    // after a bunch of tries and no valid moves
    // We return -1 to flag that we must go back 
    // and try another building
    return -1;
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

