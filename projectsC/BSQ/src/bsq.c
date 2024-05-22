#include "bsq_utils.h"

int main(int argc, char **argv) {
    t_map_info info;
    char **map;
    int i;

    i = 1;
    if (argc < 2) {
        // Read from standard input
        map = ft_read_map(NULL, &info);
        if (!map) {
            ft_puterror("Error reading map from standard input\n");
            return (1);
        }
        ft_bsq(map, info);
        ft_display_map(map, info);
        ft_free_map(map, info.rows);
    } else {
        // Read from given maps
        while (i < argc) {
            map = ft_read_map(argv[i], &info);
            if (!map) {
                ft_puterror("Error reading map from file\n");
                i++;
                continue;
            }
            ft_bsq(map, info);
            ft_display_map(map, info);
            ft_free_map(map, info.rows);
            if (i != argc - 1)
                ft_putchar('\n');
            i++;
        }
    }

    return (0);
}