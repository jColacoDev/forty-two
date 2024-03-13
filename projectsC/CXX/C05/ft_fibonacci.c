
int ft_fibonacci(int index){
    if(index < 0) 
        return (-1);
    if(index < 2)
        return (index);
    return ( ft_fibonacci(index-1) + ft_fibonacci(index-2));
}

int main(){
    int result = ft_fibonacci(3);

    printf("%d\n",result);
    return (0);
}
