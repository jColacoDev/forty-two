
int ft_iterative_power(int nb, int power){
    int counter;
    
    if(power < 0)
      return (0);
    else if(power == 0)
      return (1);
    else if(nb == 0)
      return (0);

    counter = nb;
    while(--power > 0)
        counter *= nb;

    return counter;
}

int main(){
  ft_iterative_power(2,5);
    return (0);
}