#include "../../ft_printf/ft_printf.h"

int main(void)
{
	ft_printf("-----------------------------\n");
	ft_printf("------  ft_printf( )  -------\n");
	ft_printf("-----------------------------\n");
	ft_printf("------  TESTING AREA  -------\n");
	ft_printf("-----------------------------\n");

    // Test for %c
    ft_printf("Char: %c\n", 'A');
    printf("Char: %c\n", 'A');
	ft_printf("-----------------------------\n");

    // Test for %s
    ft_printf("String: %s\n", "Hello, world!");
    printf("String: %s\n", "Hello, world!");
	ft_printf("-----------------------------\n");

    // Test for %p
    ft_printf("Pointer: %p\n", (void *)main);
    printf("Pointer: %p\n", (void *)main);
	ft_printf("-----------------------------\n");

    // Test for %d
    ft_printf("Decimal: %d\n", 1234);
    printf("Decimal: %d\n", 1234);
	ft_printf("-----------------------------\n");

    // Test for %i
    ft_printf("Integer: %i\n", -1234);
    printf("Integer: %i\n", -1234);
	ft_printf("-----------------------------\n");

    // Test for %u
    ft_printf("Unsigned: %u\n", 4294967295U);
    printf("Unsigned: %u\n", 4294967295U);
	ft_printf("-----------------------------\n");

    // Test for %x
    ft_printf("Hex (lowercase): %x\n", 255);
    printf("Hex (lowercase): %x\n", 255);
	ft_printf("-----------------------------\n");

    // Test for %X
    ft_printf("Hex (uppercase): %X\n", 255);
    printf("Hex (uppercase): %X\n", 255);
	ft_printf("-----------------------------\n");

    // Test for %%
    ft_printf("Percent: %%\n");
    printf("Percent: %%\n");
	ft_printf("-----------------------------\n");

    // Test for flags: '-'
    ft_printf("Left align: %-10d END\n", 42);
    printf("Left align: %-10d END\n", 42);
	ft_printf("-----------------------------\n");

    // Test for flags: '0'
    ft_printf("Zero pad: %010d\n", 42);
    printf("Zero pad: %010d\n", 42);
	ft_printf("-----------------------------\n");

    // Test for flags: '.'
    ft_printf("Precision: %.5d\n", 42);
    printf("Precision: %.5d\n", 42);
	ft_printf("-----------------------------\n");

    // Test for field minimum width
    ft_printf("Width: %10d\n", 42);
    printf("Width: %10d\n", 42);
	ft_printf("-----------------------------\n");

    // Test for flag: '#'
    ft_printf("Alternate form: %#x\n", 255);
    printf("Alternate form: %#x\n", 255);
	ft_printf("-----------------------------\n");

    // Test for flag: ' '
    ft_printf("Space: % d\n", 42);
    printf("Space: % d\n", 42);
	ft_printf("-----------------------------\n");

    // Test for flag: '+'
    ft_printf("Signed: %+d\n", 42);
    printf("Signed: %+d\n", 42);
	ft_printf("-----------------------------\n");

    // Test for combination of flags
    ft_printf("Combination: %#08x\n", 255);
    printf("Combination: %#08x\n", 255);
	ft_printf("-----------------------------\n");

    ft_printf("Combination: %-#8xEND\n", 255);
    printf("Combination: %-#8xEND\n", 255);
	ft_printf("-----------------------------\n");

    ft_printf("Combination: % 08d\n", 42);
    printf("Combination: % 08d\n", 42);
	ft_printf("-----------------------------\n");

    ft_printf("Combination: %+08d\n", 42);
    printf("Combination: %+08d\n", 42);
	ft_printf("-----------------------------\n");

	// Test for minimum and maximum values of integer types
	ft_printf("Min Integer: %d\n", INT_MIN);
	printf("Min Integer: %d\n", INT_MIN);
	ft_printf("-----------------------------\n");

	ft_printf("Max Integer: %d\n", INT_MAX);
	printf("Max Integer: %d\n", INT_MAX);
	ft_printf("-----------------------------\n");

	ft_printf("Max Unsigned Integer: %u\n", UINT_MAX);
	printf("Max Unsigned Integer: %u\n", UINT_MAX);
	ft_printf("-----------------------------\n");

	// Test for special characters
	ft_printf("Special Characters: \\t, \\n, \\r, \\a, \\b, \\f, \\v\n");
	printf("Special Characters: \\t, \\n, \\r, \\a, \\b, \\f, \\v\n");
	ft_printf("-----------------------------\n");

	// Test for long long types
	ft_printf("Long Long Integer: %lld\n", LLONG_MAX);
	printf("Long Long Integer: %lld\n", LLONG_MAX);
	ft_printf("-----------------------------\n");

	ft_printf("Long Long Unsigned: %llu\n", ULLONG_MAX);
	printf("Long Long Unsigned: %llu\n", ULLONG_MAX);
	ft_printf("-----------------------------\n");

	// Test for floating point types
	ft_printf("Floating Point: %f\n", 3.14159);
	printf("Floating Point: %f\n", 3.14159);
	ft_printf("-----------------------------\n");

	ft_printf("Scientific Notation: %e\n", 3.14159e-10);
	printf("Scientific Notation: %e\n", 3.14159e-10);
	ft_printf("-----------------------------\n");

	ft_printf("Hexadecimal Floating Point: %a\n", 3.14159);
	printf("Hexadecimal Floating Point: %a\n", 3.14159);
	ft_printf("-----------------------------\n");

    // ADITIONAL TESTS
    int chars_printed;

	// Test string with maximum length
	//     char *max_length_string = malloc(INT_MAX);
	//	memset(max_length_string, 'a', INT_MAX - 1);
	//	max_length_string[INT_MAX - 1] = '\0';
	
	//	ft_printf("Test 1 - Maximum length string \n");
	//	chars_printed = ft_printf("[%s]\n", max_length_string);
	//	printf("[%s]\n", max_length_string);
	//	printf("Characters printed: [%d]\n", chars_printed);
	//	printf("--------------------------------\n");
	//	free(max_length_string); 

	// Test string with minimum length
	char *min_length_string = "";

	ft_printf("Test 2 - Minimum length string \n"); 
	chars_printed = ft_printf("[%s]\n", min_length_string);
	printf("[%s]\n", min_length_string);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test string with special characters
	char *special_chars_string = "Hello, world!\n\t\b\a\r\f\v\\\'\"";

	ft_printf("Test 3 - String with special characters \n");
	chars_printed = ft_printf("[%s]\n", special_chars_string);
	printf("[%s]\n", special_chars_string);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test string, char, and int together
	char *str = "Hello, world!";
	char b = 'b';
	int i = 123;

	ft_printf("Test 4 - String, char, and int together \n");
	chars_printed = ft_printf("[%s] [%c] [%d]\n", str, b, i);
	printf("[%s] [%c] [%d]\n", str, b, i);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test string, char, and int together with width and precision
	ft_printf("Test 5 - String, char, and int together with width and precision \n");
	chars_printed = ft_printf("[%20.5s] [%-7c] [%05d]\n", str, b, i);
	printf("[%20.5s] [%-7c] [%05d]\n", str, b, i);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	char *null_string = NULL;

	ft_printf("Test 7 - NULL string \n");
	chars_printed = ft_printf("[%s]\n", null_string);
	printf("[%s]\n", null_string);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with large integer
	int large_int = INT_MAX;

	ft_printf("Test 8 - Large integer \n");
	chars_printed = ft_printf("[%d]\n", large_int);
	printf("[%d]\n", large_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with small integer
	int small_int = INT_MIN;

	ft_printf("Test 9 - Small integer \n");
	chars_printed = ft_printf("[%d]\n", small_int);
	printf("[%d]\n", small_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with zero integer
	int zero_int = 0;

	ft_printf("Test 10 - Zero integer \n");
	chars_printed = ft_printf("[%d]\n", zero_int);
	printf("[%d]\n", zero_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with negative integer
	int negative_int = -123;

	ft_printf("Test 11 - Negative integer \n");
	chars_printed = ft_printf("[%d]\n", negative_int);
	printf("[%d]\n", negative_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with positive integer
	int positive_int = 123;

	ft_printf("Test 12 - Positive integer \n");
	chars_printed = ft_printf("[%d]\n", positive_int);
	printf("[%d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with zero padding
	ft_printf("Test 13 - Zero padding \n");
	chars_printed = ft_printf("[%05d]\n", positive_int);
	printf("[%05d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with width
	ft_printf("Test 14 - Width \n");
	chars_printed = ft_printf("[%10d]\n", positive_int);
	printf("[%10d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with width and zero padding
	ft_printf("Test 15 - Width and zero padding \n");
	chars_printed = ft_printf("[%010d]\n", positive_int);
	printf("[%010d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with width and negative integer
	ft_printf("Test 16 - Width and negative integer \n");
	chars_printed = ft_printf("[%10d]\n", negative_int);
	printf("[%10d]\n", negative_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with width and zero padding and negative integer
	ft_printf("Test 17 - Width, zero padding, and negative integer \n");
	chars_printed = ft_printf("[%010d]\n", negative_int);
	printf("[%010d]\n", negative_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with width and zero padding and positive integer
	ft_printf("Test 18 - Width, zero padding, and positive integer \n");
	chars_printed = ft_printf("[%010d]\n", positive_int);
	printf("[%010d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with all the flags
	ft_printf("Test 19 - All the flags \n");
	chars_printed = ft_printf("[%+010d]\n", positive_int);
	printf("[%+010d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test with all the flags and negative integer and multiple arguments
	ft_printf("Test 20 - All the flags, negative integer, and multiple arguments \n");
	chars_printed = ft_printf("[%+010d] [%s] [%c]\n", negative_int, str, b);
	printf("[%+010d] [%s] [%c]\n", negative_int, str, b);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// test with integer no padding but with + flag
	ft_printf("Test 21 - Integer no padding but with + flag \n");
	chars_printed = ft_printf("[%+d]\n", positive_int);
	printf("[%+d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// test with iteger no padding but with - flag
	ft_printf("Test 22 - Integer no padding but with - flag \n");
	chars_printed = ft_printf("[%-d]\n", positive_int);
	printf("[%-d]\n", positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// test pointer
	ft_printf("Test 23 - Pointer \n");
	chars_printed = ft_printf("[%p]\n", &positive_int);
	printf("[%p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 24: Pointer with left padding
	ft_printf("Test 24 - Pointer with left padding \n");
	chars_printed = ft_printf("[%10p]\n", &positive_int);
	printf("[%10p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 25: Pointer with right padding
	ft_printf("Test 25 - Pointer with right padding \n");
	chars_printed = ft_printf("[%-10p]\n", &positive_int);
	printf("[%-10p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 26: Pointer with a large field width
	ft_printf("Test 26 - Pointer with a large field width \n");
	chars_printed = ft_printf("[%50p]\n", &positive_int);
	printf("[%50p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 27: Pointer with a small field width
	ft_printf("Test 27 - Pointer with a small field width \n");
	chars_printed = ft_printf("[%2p]\n", &positive_int);
	printf("[%2p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 28: Pointer with left justification
	ft_printf("Test 28 - Pointer with left justification \n");
	chars_printed = ft_printf("[%-20p]\n", &positive_int);
	printf("[%-20p]\n", &positive_int);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 29: Comprehensive test with pointers, characters, strings, and integers
	ft_printf("Test 29 - Comprehensive test \n");
	char z = 'A';
	char *string = "Hello, world!";
	void *ptr = &negative_int;

	chars_printed = ft_printf("Character: [%-5c], String: [%20s], Integer: [%+010d], Pointer: [%-20p]\n", z, string, negative_int, ptr);
	printf("Character: [%-5c], String: [%20s], Integer: [%+010d], Pointer: [%-20p]\n", z, string, negative_int, ptr);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 30 - Multiple arguments of different types
	ft_printf("Test 30 - Multiple arguments of different types \n");
	int test_var = -123;
	chars_printed = ft_printf("String: [%s], Character: [%c], Integer: [%d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("String: [%s], Character: [%c], Integer: [%d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 31 - Width and precision with all argument types
	ft_printf("Test 31 - Width and precision with all argument types \n");
	chars_printed = ft_printf("String: [%20.10s], Character: [%3c], Integer: [%010d], Pointer: [%20p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("String: [%20.10s], Character: [%3c], Integer: [%010d], Pointer: [%20p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 32 - Flags with all argument types
	ft_printf("Test 32 - Flags with all argument types \n");
	chars_printed = ft_printf("String: [%-20s], Character: [%-3c], Integer: [%+d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("String: [%-20s], Character: [%-3c], Integer: [%+d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 33- Width and precision with unsigned integer
	ft_printf("Test 33 - Width and precision with unsigned integer \n");
	unsigned int test_unsigned_var = 1234567890;
	chars_printed = ft_printf("Unsigned integer: [%010u]\n", test_unsigned_var);
	printf("Unsigned integer: [%010u]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 34 - Width and zero padding with unsigned integer
	ft_printf("Test 34 - Width and zero padding with unsigned integer \n");
	chars_printed = ft_printf("Unsigned integer: [%20u]\n", test_unsigned_var);
	printf("Unsigned integer: [%20u]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 1: Basic test with no flags
	test_unsigned_var = 123;
	printf("Test 1 - Basic test with no flags\n");
	chars_printed = ft_printf("Hexadecimal: [%x]\n", test_unsigned_var);
	printf("Hexadecimal: [%x]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 2: Test with # flag
	test_unsigned_var = 123;
	printf("Test 2 - Test with # flag\n");
	chars_printed = ft_printf("Hexadecimal: [%#x]\n", test_unsigned_var);
	printf("Hexadecimal: [%#x]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 3: Test with - flag
	test_unsigned_var = 123;
	printf("Test 3 - Test with - flag\n");
	chars_printed = ft_printf("Hexadecimal: [%-5x]\n", test_unsigned_var);
	printf("Hexadecimal: [%-5x]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 4: Test with field width
	test_unsigned_var = 123;
	printf("Test 4 - Test with field width\n");
	chars_printed = ft_printf("Hexadecimal: [%5x]\n", test_unsigned_var);
	printf("Hexadecimal: [%5x]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	// Test 5: Test with uppercase X
	test_unsigned_var = 123;
	printf("Test 5 - Test with uppercase X\n");
	chars_printed = ft_printf("Hexadecimal: [%X]\n", test_unsigned_var);
	printf("Hexadecimal: [%X]\n", test_unsigned_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	ft_printf("Test 32 - Flags with all argument types \n");
	chars_printed = ft_printf("String: [%-20s], Character: [%-3c], Integer: [%+d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("String: [%-20s], Character: [%-3c], Integer: [%+d], Pointer: [%p]\n", "Hello, world!", 'A', test_var, &test_var);
	printf("Characters printed: [%d]\n", chars_printed);
	printf("--------------------------------\n");

	test_var = 0; // Example integer variable for testing
    char *null_str = NULL; // Example null string for testing

    ft_printf("Test - Null cases for various format specifiers\n");

    // Testing null case for %x and %X format specifiers
    ft_printf("Null case for hexadecimal (lowercase): [%x]\n", 0);
    printf("Null case for hexadecimal (lowercase): [%x]\n", 0);

    ft_printf("Null case for hexadecimal (uppercase): [%X]\n", 0);
    printf("Null case for hexadecimal (uppercase): [%X]\n", 0);

    // Testing null case for %u and %d format specifiers
    ft_printf("Null case for unsigned integer: [%u]\n", 0);
    printf("Null case for unsigned integer: [%u]\n", 0);

    ft_printf("Null case for integer: [%d]\n", 0);
    printf("Null case for integer: [%d]\n", 0);

    // Testing null case for %p format specifier
    ft_printf("Null case for pointer: [%p]\n", NULL);
    printf("Null case for pointer: [%p]\n", NULL);

    // Testing null case for %i, %s, and %c format specifiers
    ft_printf("Null case for integer: [%i]\n", 0);
    printf("Null case for integer: [%i]\n", 0);

    ft_printf("Null case for string: [%s]\n", null_str);
    printf("Null case for string: [%s]\n", null_str);

    ft_printf("Null case for character: [%c]\n", '\0');
    printf("Null case for character: [%c]\n", '\0');

    return 0;
}
