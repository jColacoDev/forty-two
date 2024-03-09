
int countVisibleBuildings(int **grid, int row, int col, int direction, int N) {
    int count = 0;
    int maxHeight = 0;

    // TODO

    return count;
}

int checkVisibility(int **grid, int **views, int row, int col, int N, int val) {

    // TODO
    
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
