#include <unistd.h> 
#include <stdio.h>
#include "puzzle_algorithm.c" 
// notice that including standard public libraries is with <>
// but to include local files e make it under "" like above.

int main(int argc, int **argv) {
    int N = 4; // grid size
    int grid[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int views[4][4] = {
        {1, 2, 2, 1},
        {2, 0, 0, 2},
        {2, 0, 0, 2},
        {1, 2, 2, 1}
    };

    printf("Initial grid:\n");
    printGrid(grid, N);

    if (puzzle_algorithm(grid, views, N)) {
        printf("\nSolution found:\n");
        printGrid(grid, N);
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}