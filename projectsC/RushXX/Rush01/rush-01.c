#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

void free_grids(int *views[], int *grid[]);
void handle_result(int *grid[], int counter, int result);
int init_grids(int argc, char **argv, int *views[], int *grid[]);
int puzzle_algorithm(int **grid, int **views, int N, int counter);

int main(int argc, char **argv) {
    int result;
    int counter;
    int *grid[4];
    int *views[4];

    counter = 0;
    init_grids(argc, argv, views, grid);
    result = puzzle_algorithm(grid, views, GRID_SIZE, counter); 
    handle_result(grid, counter, result);
    free_grids(views, grid);

    return 0;
}
