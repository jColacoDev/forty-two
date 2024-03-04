void ft_rev_int_tab(int *tab, int size){
    int i = 0;
    int aux_arr[size];

    for (i = 0; i < size; i++) {
        aux_arr[i] = tab[size - 1 - i];
    }
    for (i = 0; i < size; i++) {
        tab[i] = aux_arr[i];
    }
}