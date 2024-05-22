#ifndef BSQ_UTILS_H
#define BSQ_UTILS_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define BUFFER_SIZE 4096

typedef struct s_map_info {
    int rows;
    char empty;
    char obstacle;
    char full;
} t_map_info;

void ft_display_map(char **map, t_map_info info);
char **ft_allocate_map(int rows, int cols);
void ft_free_map(char **map, int rows);
char **ft_read_map(char *file_name, t_map_info *info);
void ft_memcpy(void *dst, const void *src, int n);
void ft_bsq(char **map, t_map_info info);

#endif
