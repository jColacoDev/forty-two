void ft_putstr(char *str);
void print_grid(int *grid[], int N);
void ft_putnbr(int n);


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

int check_visibility(int **grid, int **views, int row, int col, int N, int val) {
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
        visibleBuildings = count_visible_buildings(grid, row, col, direction, N);
        if (viewCount > 0 && visibleBuildings > viewCount) {
            return -1; // Visibility rules violated
        }
        direction++;
    }

    return 1; // Visibility rules satisfied
}

// This is the function we use to validate moves
// So, we have to translate the puzzle rules into Code!
int is_valid(int **grid, int **views, int row, int col, int val, int N) {
    // check if there are repeated Numbers in the 
    // Row and Col of the coordinate we are validating 
    int i;

    print_grid(grid, N);

    i = 0;
    while (i < N) {
        ft_putstr("\nval: ");
        ft_putnbr(val);
        ft_putstr("\ni: ");
        ft_putnbr(i);
        ft_putstr("\n");
        ft_putstr("\nrow: ");
        ft_putnbr(row);
        ft_putstr("\ncol: ");
        ft_putnbr(col);
        ft_putstr("\ngrid[row][i]: ");
        ft_putnbr(grid[row][i]);
        ft_putstr("\ngrid[i][col]: ");
        ft_putnbr(grid[i][col]);
        if ((grid[row][i] == val && i != col) || (grid[i][col] == val && i != row)) {
            ft_putstr("\nReturn -1\n");
            return (-1);
        }
        i++;
    }

    //Check if the Visibility rules are Ok or not and returns the result
    return (check_visibility(grid, views, row, col, N, val));
}

