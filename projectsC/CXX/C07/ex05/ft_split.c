#include <stdlib.h>
#include <stdio.h>

int is_separator(char c, char *charset) 
{
    while (*charset != '\0')
    {
        if (c == *charset)
            return 1;
        charset++;
    }
    
    return (0);
}

int count_words(char *str, char *charset) {
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    while (*str != '\0') 
    {
        if (!is_separator(*str, charset)) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else 
            in_word = 0;
        str++;
    }

    return (count);
}

char **ft_split(char *str, char *charset) {
    int num_words;
    char **result;
    int word_index;
    
    num_words = count_words(str, charset);
    result = (char **)malloc((num_words + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;
    word_index = 0;

    while (*str != '\0') 
    {
        if (!is_separator(*str, charset)) 
        {
            result[word_index] = str;
            word_index++;
            while (*str != '\0' && !is_separator(*str, charset))
                str++;
        } else 
            str++;
    }
    result[word_index] = NULL;
    
    return (result);
}



void print_str_array(char **arr) {
    if (arr == NULL) {
        printf("Array is NULL\n");
        return;
    }

    printf("[");
    for (int i = 0; arr[i] != NULL; i++) {
        printf("\"%s\"", arr[i]);
        if (arr[i + 1] != NULL)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    // Test 1: Splitting a string with a single separator
    char *str1 = "hello/world";
    char *charset1 = "/";
    printf("Test 1:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str1, charset1);
    char **result1 = ft_split(str1, charset1);
    print_str_array(result1);

    for (int i = 0; result1[i] != NULL; i++)
        free(result1[i]);
    free(result1);

    // Test 2: Splitting a string with multiple separators
    char *str2 = "apple,banana,orange";
    char *charset2 = ",";
    printf("\nTest 2:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str2, charset2);
    char **result2 = ft_split(str2, charset2);
    print_str_array(result2);

    for (int i = 0; result2[i] != NULL; i++)
        free(result2[i]);
    free(result2);

    // Test 3: Splitting a string with no separators
    char *str3 = "hello";
    char *charset3 = ",";
    printf("\nTest 3:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str3, charset3);
    char **result3 = ft_split(str3, charset3);
    print_str_array(result3);

    for (int i = 0; result3[i] != NULL; i++)
        free(result3[i]);
    free(result3);

    return 0;
}