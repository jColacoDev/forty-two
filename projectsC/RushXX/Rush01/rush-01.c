#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4
#define NUM_VIEWS 4

void print_grid(int *grid[], int N);
int init_views_xargs(int argc, char *argv[], int *views[]);
int **init_grid(int N);
void free_grids(int *views[], int *grid[]);
void handle_result(int *grid[], int counter, int result);
int puzzle_algorithm(int **grid, int **views, int N, int *counter);
void ft_putstr(char *str);


int main(int argc, char **argv) {
    int result;
    int counter;
    int **grid;
    int *views[4];

    counter = 0;

    if (init_views_xargs(argc, argv, views) == -1) {
        ft_putstr("Error initializing Views grid\n");
        return (-1);
    }
    grid = init_grid(GRID_SIZE); 
    if (grid == NULL) {
        ft_putstr("Error initializing Matrix grid\n");
        return (-1);
    }
    ft_putstr("Views grid initialized\n");
    print_grid(views, NUM_VIEWS);
    ft_putstr("Matrix grid initialized\n");
    print_grid(grid, GRID_SIZE);

    result = puzzle_algorithm(grid, views, 4, &counter); 
    handle_result(grid, counter, result);
    free_grids(views, grid);

    return 0;
}
