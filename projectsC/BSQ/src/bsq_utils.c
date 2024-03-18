#include "bsq_utils.h"

int min(int a, int b, int c) {
    int min_value = a;
    if (b < min_value)
        min_value = b;
    if (c < min_value)
        min_value = c;
    return min_value;
}

void ft_display_map(char **map, t_map_info info) {
    int i = 0;
    while (i < info.rows) {
        write(1, map[i], info.rows);
        write(1, "\n", 1);
        i++;
    }
}

char **ft_allocate_map(int rows, int cols) {
    char **map = malloc(sizeof(char *) * rows);
    int i = 0;
    while (i < rows) {
        map[i] = malloc(cols);
        i++;
    }
    return map;
}

void ft_free_map(char **map, int rows) {
    int i = 0;
    while (i < rows) {
        free(map[i]);
        i++;
    }
    free(map);
}

char **ft_read_map(char *file_name, t_map_info *info) {
    int fd;
    char buffer[BUFFER_SIZE];
    char **map;
    // int bytes_read;
    int row = 0;

    if ((fd = open(file_name, O_RDONLY)) < 0)
        return NULL;
    
    // bytes_read = read(fd, buffer, BUFFER_SIZE);
    close(fd);

    // Parsing first line to get map info
    sscanf(buffer, "%d\n%c\n%c\n%c\n", &info->rows, &info->empty, &info->obstacle, &info->full);
    
    // Allocate memory for the map
    map = ft_allocate_map(info->rows, info->rows);

    // Copy map data
    char *ptr = buffer;
    while (*ptr && *ptr != '\n')
        ptr++;
    ptr++;
    while (*ptr && row < info->rows) {
        ft_memcpy(map[row], ptr, info->rows);
        row++;
        ptr += info->rows + 1; // Move to next row
    }

    return map;
}

void ft_memcpy(void *dst, const void *src, int n) {
    char *d = dst;
    const char *s = src;
    while (n--)
        *d++ = *s++;
}

void ft_bsq(char **map, t_map_info info) {
    int **square_sizes = malloc(sizeof(int *) * info.rows);
    for (int i = 0; i < info.rows; i++) {
        square_sizes[i] = malloc(sizeof(int) * info.rows);
        for (int j = 0; j < info.rows; j++) {
            if (i == 0 || j == 0)
                square_sizes[i][j] = (map[i][j] == info.empty) ? 1 : 0;
            else if (map[i][j] == info.empty)
                square_sizes[i][j] = 1 + min(square_sizes[i - 1][j], square_sizes[i][j - 1], square_sizes[i - 1][j - 1]);
            else
                square_sizes[i][j] = 0;
        }
    }

    int max_size = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < info.rows; i++) {
        for (int j = 0; j < info.rows; j++) {
            if (square_sizes[i][j] > max_size) {
                max_size = square_sizes[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Mark the largest square in the map
    for (int i = max_i; i > max_i - max_size; i--) {
        for (int j = max_j; j > max_j - max_size; j--) {
            map[i][j] = info.full;
        }
    }

    // Free memory allocated for square sizes
    for (int i = 0; i < info.rows; i++) {
        free(square_sizes[i]);
    }
    free(square_sizes);
}
