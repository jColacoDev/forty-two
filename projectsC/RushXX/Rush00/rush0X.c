#include "ft_putchar.c" 

void drawX( int x, int y, int i_y, char edges[], char fillers[]){
    char token = '\n';

    for(int i_x = 0; i_x < x; i_x++){
        if(i_x == 0 || i_x == x-1){
            token = fillers[1]; // wall filler
        } else if(i_y == 0 || i_y == y-1){
            token = fillers[2]; // base filler
        } else {
            token = fillers[0]; // void filler
        }

        if(i_x == 0 && i_y == 0){
            token = edges[0];
        } else if(i_x == x-1 && i_y == 0){
            token = edges[1];
        } else if(i_x == 0 && i_y == y-1){
            token = edges[2];
        } else if(i_x == x-1 && i_y == y-1){
            token = edges[3];
        }
        ft_putchar(token);
    }

    token = '\n';
    ft_putchar(token);
}

void drawY(int x, int y, char edges[], char fillers[]){
    for(int i_y = 0; i_y < y; i_y++){
        drawX(x, y, i_y, edges, fillers);
    }
}

void rush(int x, int y, int rush){
    // fillers -> void, wall, base
    char fillers[3] = {' ', ' ', ' '};
    char edges[4] = {' ', ' ', ' ', ' '};

    switch (rush){
        case 0:
            edges[0] = 'o';
            edges[1] = 'o';
            edges[2] = 'o';
            edges[3] = 'o';

            fillers[0] = ' ';
            fillers[1] = '|';
            fillers[2] = '-';
            
            break;
        case 1:
            edges[0] = '/';
            edges[1] = '\\';
            edges[2] = '\\';
            edges[3] = '/';

            fillers[0] = ' ';
            fillers[1] = '*';
            fillers[2] = '*';
            
            break;
        case 2:
            edges[0] = 'A';
            edges[1] = 'A';
            edges[2] = 'C';
            edges[3] = 'C';

            fillers[0] = ' ';
            fillers[1] = 'B';
            fillers[2] = 'B';
            
            break;
        
        case 3:
            edges[0] = 'A';
            edges[1] = 'C';
            edges[2] = 'A';
            edges[3] = 'C';

            fillers[0] = ' ';
            fillers[1] = 'B';
            fillers[2] = 'B';
            break;

        case 4:
            edges[0] = 'A';
            edges[1] = 'C';
            edges[2] = 'C';
            edges[3] = 'A';

            fillers[0] = ' ';
            fillers[1] = 'B';
            fillers[2] = 'B';
            break;
        
        default:
            break;
    }

     drawY(x, y, edges, fillers);
}

int checkInputArgs(int argc, char *argv[]){
    if (argc != 4) {
        ft_putstr("Usage: main.exe <rush_n>  < x > < y >\n");
        return 1;
    }

    char *arg = argv[1];
    if (*arg >= '0' && *arg <= '4' && *(arg + 1) == '\0') {
        ft_putstr("I wanna be the very best\n");
    } else {
        ft_putstr("Invalid value for rush_n. Please enter a value between 0 and 4.\n");
        return 1;
    }
    arg = argv[2];
    if (*arg >= '1') {
        ft_putstr("Like no one ever was\n");
    } else {
        ft_putstr("Invalid value for rush_x. Please enter a value between 0 and infinity!.\n");
        return 1;
    }
    arg = argv[3];
    if (*arg >= '1') {
        ft_putstr("To catch them is my real test\n");
        ft_putstr("To train them is my cause\n");
    } else {
        ft_putstr("Invalid value for rush_y. Please enter a value between 0 and infinity!.\n");
        return 1;
    }

    return 0;
}