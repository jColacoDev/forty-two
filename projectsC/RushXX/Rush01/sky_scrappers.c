
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

// This is the function we use to validate moves
// So, we have to translate the puzzle rules into Code!
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
