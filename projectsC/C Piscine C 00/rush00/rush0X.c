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
            edges[0] = '/';
            edges[1] = '\\';
            edges[2] = '/';
            edges[3] = '\\';

            fillers[0] = ' ';
            fillers[1] = '*';
            fillers[2] = '*';
            
            break;
        case 1:
            edges[0] = 'A';
            edges[1] = 'A';
            edges[2] = 'C';
            edges[3] = 'C';

            fillers[0] = ' ';
            fillers[1] = 'B';
            fillers[2] = 'B';
            
            break;
        
        case 2:
            edges[0] = 'A';
            edges[1] = 'C';
            edges[2] = 'A';
            edges[3] = 'C';

            fillers[0] = ' ';
            fillers[1] = 'B';
            fillers[2] = 'B';

            break;
        
        case 3:
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
