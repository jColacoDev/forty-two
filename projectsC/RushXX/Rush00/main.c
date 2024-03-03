#include "rush0X.c" 

int main(int argc, char *argv[]){
    int flag = 0;

    flag = checkInputArgs(argc, argv);
    if(flag != 0){
        return flag;
    };

    rush(
        ft_stringToInt(argv[2]), // x
        ft_stringToInt(argv[3]), // y
        ft_stringToInt(argv[1])  // rush_n
    );
    
    return (0);
}
