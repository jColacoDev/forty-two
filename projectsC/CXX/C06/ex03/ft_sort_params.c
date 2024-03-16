#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) 
    {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high]; 
    int i = low - 1;
    int j = low;

    while (j <= high - 1) {
        if (ft_strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int i = 1;

    i = 1;
    while (i < argc) {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }

    ft_putstr("\n---------------\n");
    quickSort(argv, 1, argc - 1);

    i = 1;
    while (i < argc) {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }

    return (0);
}
