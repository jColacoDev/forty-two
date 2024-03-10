#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4
#define NUM_DIRECTIONS 4


int init_grid(int *grid[], int N);
void print_grid(int *grid[], int N);
int init_views_xargs(int argc, char *argv[], int *views[]);
int puzzle_algorithm(int **grid, int **views, int N, int counter);

int main(int argc, char **argv) {
    int i;
    int counter = 0;
    int *grid[4];
    int *views[4];

    if (init_views_xargs(argc, argv, views) != -1) {
        print_views(views);
    }
    if (init_grid(grid, GRID_SIZE)) {
        print_grid(grid, GRID_SIZE);
    }
    
    // print_grid(grid, GRID_SIZE);
    if (puzzle_algorithm(grid, views, GRID_SIZE, counter)) {
        printf("\nSolution found:\n");
        print_grid((int **)grid, GRID_SIZE);
    } else {
        printf("\nNo solution exists.\n");
    }
    printf("\nCounter: %d\n", counter);

    i = 0;
    while (i < GRID_SIZE) {
        free(grid[i]);
        i++;
    }

    return 0;
}
