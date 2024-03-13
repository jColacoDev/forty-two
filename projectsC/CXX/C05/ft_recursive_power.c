

int ft_recursive_power(int nb, int power){
    if(power < 0)
      return (0);
    else if(power == 0)
      return (1);
    else if(nb == 0)
      return (0);

    return (nb * ft_recursive_power(nb, power-1));
}

int main(){
    int result = ft_recursive_power(2,3);

    printf("%d\n",result);
    return (0);
}
