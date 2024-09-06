#include <stdio.h>
#include <string.h>
#include "libft.h" // Ensure this header file contains the prototype for ft_strlcpy

void test_strlcpy()
{
    char dest[100]; // Ensure `dest` is large enough to hold all test cases

    // Test case 1: Copy string with exact buffer size
    printf("\033[0;31mft_strlcpy:\033[0m ");
    ft_strlcpy(dest, "Hello, World!", 13); // Buffer size matches the length of "Hello, World!"
    if (strcmp(dest, "Hello, World!") != 0)
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 2: Buffer size larger than string
    ft_strlcpy(dest, "Hello", 100); // Buffer size much larger than "Hello"
    if (strcmp(dest, "Hello") != 0)
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 3: Buffer size smaller than string
    ft_strlcpy(dest, "Hello, World!", 5); // Buffer size smaller than "Hello, World!"
    if (strcmp(dest, "Hell") != 0) // Only the first 4 characters should be copied
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 4: Buffer size is 1
    ft_strlcpy(dest, "Hello", 1); // Buffer size is 1
    if (strcmp(dest, "") != 0) // Only the null terminator should be copied
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 5: Empty source string
    ft_strlcpy(dest, "", 10); // Empty source string
    if (strcmp(dest, "") != 0) // Destination should be an empty string
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 6: Buffer size is 0
    ft_strlcpy(dest, "Hello", 0); // Buffer size is 0
    if (strcmp(dest, "") != 0) // Destination should be an empty string
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 7: Buffer size exactly one more than the source length
    ft_strlcpy(dest, "Hello", 6); // Buffer size is 6, which is one more than the length of "Hello"
    if (strcmp(dest, "Hello") != 0) // Should copy the entire source string including the null terminator
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 8: Large buffer size
    ft_strlcpy(dest, "Hello", 1000); // Large buffer size
    if (strcmp(dest, "Hello") != 0) // Should copy the entire source string
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 9: Null pointer as source
    // Assuming your implementation of ft_strlcpy handles NULL source correctly
    char *null_source = NULL;
    ft_strlcpy(dest, null_source, 10); // Null source string
    if (strcmp(dest, "") != 0) // Destination should be an empty string
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    // Test case 10: Source with special characters
    ft_strlcpy(dest, "!@#$%^&*()", 20); // Special characters in source
    if (strcmp(dest, "!@#$%^&*()") != 0) // Should copy the entire source string
    {
        printf(" \033[0;31mKO \033[0m");
        return;
    }
    printf(" \033[0;32mOK \033[0m");

    printf("\n");
}


int main()
{
    test_strlcpy();
    return 0;
}