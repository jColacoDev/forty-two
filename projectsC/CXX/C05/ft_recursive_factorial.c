

// 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 x 0...
int ft_recursive_factorial(int nb){
    if( nb == 0 || nb == 1)
        return (1);
    return ( nb * ft_recursive_factorial(--nb));
}

int main(){
    printf("%d\n",ft_recursive_factorial(4));
    return (0);
}
