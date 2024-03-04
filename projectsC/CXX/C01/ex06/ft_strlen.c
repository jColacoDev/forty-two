int ft_strlen(char *str){
    int count = 0;

    while (*str) {
        count++;
        str++;
    }

    return count;
}

