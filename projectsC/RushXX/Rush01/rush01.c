void printGrid(int **grid, int N) {
    int i = -1;
    int j = -1;
    
    while (i++ < N) { // run all the **grid rows
        while (j++ < N) { // run all the **grid cols
            printf("%d ", grid[i][j]); // print the value!
        }
        printf("\n");
    }
}

int countVisibleBuildings(int **grid, int row, int col, int direction, int N) {
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

int checkVisibility(int **grid, int **views, int row, int col, int N, int val) {
    int visibleBuildings;
    int viewCount;
    int direction;
    // Check visibility in each direction and compare with view counts
    direction = 0;
    while (direction < 4) {
        viewCount = views[direction][direction % 2 ? col : row];
        visibleBuildings = countVisibleBuildings(grid, row, col, direction, N);
        if (viewCount > 0 && visibleBuildings > viewCount) {
            return -1; // Visibility rules violated
        }
        direction++;
    }

    return 1; // Visibility rules satisfied
}

int isValid(int **grid, int **views, int row, int col, int val, int N) {
    // check if there are repeated Numbers in the 
    // Row and Col of the coordinate we are validating 
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == val || grid[i][col] == val) {
            return -1;
        }
    }
    //Check if the Visibility rules are Ok or not and returns the result
    return (checkVisibility(grid, views, row, col, N, val));
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

int puzzle_algorithm(int **grid, int **views, int N) {
    int row = -1; 
    int col = -1;
    int building_height = 0;

    // First we check if the puzzle has empty cells
    // or by other words, if it's complete and solved 
    if (check_empty_cell(grid, &row, &col, N)) {
        return 1;
    }

    // After finding an empty cell we try buildings 1->n sizes
    while (building_height++ <= N) {
        // And we validate if it's a valid move or not
        if (isValid(grid, views, row, col, building_height, N)) {
            // if it's valid we put it there!
            grid[row][col] = building_height;
            // And we move on to the next move by calling 
            // puzzle_algorithm recursively
            if (puzzle_algorithm(grid, views, N)) {
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

int main() {
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