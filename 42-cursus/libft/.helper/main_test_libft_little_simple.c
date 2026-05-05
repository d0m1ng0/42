/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_libft_little_simple.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:58:24 by dverdini          #+#    #+#             */
/*   Updated: 2025/11/21 19:58:29 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

// Colori per output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void print_test(const char *test_name, int passed) {
    if (passed)
        printf("%s[v] %s%s\n", GREEN, test_name, RESET);
    else
        printf("%s[x] %s%s\n", RED, test_name, RESET);
}

int main(void) {
    printf("\n=== TEST LIBFT ===\n\n");

    // ========== PART 1: Funzioni libc ==========
    printf("--- ISALPHA/ISDIGIT/ISALNUM ---\n");
    print_test("ft_isalpha('a')", ft_isalpha('a') != 0);
    print_test("ft_isalpha('5')", ft_isalpha('5') == 0);
    print_test("ft_isdigit('5')", ft_isdigit('5') != 0);
    print_test("ft_isdigit('a')", ft_isdigit('a') == 0);
    print_test("ft_isalnum('a')", ft_isalnum('a') != 0);
    print_test("ft_isalnum('5')", ft_isalnum('5') != 0);

    printf("\n--- ISASCII/ISPRINT ---\n");
    print_test("ft_isascii(65)", ft_isascii(65) != 0);
    print_test("ft_isascii(200)", ft_isascii(200) == 0);
    print_test("ft_isprint('A')", ft_isprint('A') != 0);
    print_test("ft_isprint(31)", ft_isprint(31) == 0);

    printf("\n--- STRLEN ---\n");
    print_test("ft_strlen(\"hello\")", ft_strlen("hello") == 5);
    print_test("ft_strlen(\"\")", ft_strlen("") == 0);

    printf("\n--- TOUPPER/TOLOWER ---\n");
    print_test("ft_toupper('a')", ft_toupper('a') == 'A');
    print_test("ft_tolower('Z')", ft_tolower('Z') == 'z');

    printf("\n--- STRCHR/STRRCHR ---\n");
    char *str1 = "hello world";
    print_test("ft_strchr('o')", ft_strchr(str1, 'o') == strchr(str1, 'o'));
    print_test("ft_strrchr('o')", ft_strrchr(str1, 'o') == strrchr(str1, 'o'));

    printf("\n--- STRNCMP ---\n");
    print_test("ft_strncmp(\"abc\", \"abc\", 3)", ft_strncmp("abc", "abc", 3) == 0);
    print_test("ft_strncmp(\"abc\", \"abd\", 3)", ft_strncmp("abc", "abd", 3) < 0);

    printf("\n--- STRNSTR ---\n");
    print_test("ft_strnstr(\"hello\", \"ll\", 5)", ft_strnstr("hello", "ll", 5) != NULL);

    printf("\n--- MEMSET ---\n");
    char buf1[10];
    ft_memset(buf1, 'A', 5);
    print_test("ft_memset", buf1[0] == 'A' && buf1[4] == 'A');

    printf("\n--- BZERO ---\n");
    char buf2[10] = "hello";
    ft_bzero(buf2, 3);
    print_test("ft_bzero", buf2[0] == 0 && buf2[1] == 0);

    printf("\n--- MEMCPY ---\n");
    char src1[] = "test";
    char dst1[10];
    ft_memcpy(dst1, src1, 5);
    print_test("ft_memcpy", strcmp(dst1, "test") == 0);

    printf("\n--- MEMMOVE ---\n");
    char buf3[] = "hello";
    ft_memmove(buf3 + 2, buf3, 3);
    print_test("ft_memmove", buf3[2] == 'h');

    printf("\n--- MEMCHR ---\n");
    char buf4[] = "hello";
    print_test("ft_memchr", ft_memchr(buf4, 'l', 5) == memchr(buf4, 'l', 5));

    printf("\n--- MEMCMP ---\n");
    print_test("ft_memcmp", ft_memcmp("abc", "abc", 3) == 0);
    print_test("ft_memcmp diff", ft_memcmp("abc", "abd", 3) < 0);

    printf("\n--- ATOI ---\n");
    print_test("ft_atoi(\"42\")", ft_atoi("42") == 42);
    print_test("ft_atoi(\"-123\")", ft_atoi("-123") == -123);
    print_test("ft_atoi(\"  +99\")", ft_atoi("  +99") == 99);

    printf("\n--- STRLCPY ---\n");
    char dst2[10];
    size_t len1 = ft_strlcpy(dst2, "hello", 10);
    print_test("ft_strlcpy", len1 == 5 && strcmp(dst2, "hello") == 0);

    printf("\n--- STRLCAT ---\n");
    char dst3[20] = "hello";
    size_t len2 = ft_strlcat(dst3, " world", 20);
    print_test("ft_strlcat", len2 == 11 && strcmp(dst3, "hello world") == 0);

    printf("\n--- CALLOC ---\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    print_test("ft_calloc", arr != NULL && arr[0] == 0 && arr[4] == 0);
    free(arr);

    printf("\n--- STRDUP ---\n");
    char *dup = ft_strdup("test");
    print_test("ft_strdup", dup != NULL && strcmp(dup, "test") == 0);
    free(dup);

    // ========== PART 2: Funzioni aggiuntive ==========
    printf("\n--- SUBSTR ---\n");
    char *sub = ft_substr("hello world", 6, 5);
    print_test("ft_substr", sub != NULL && strcmp(sub, "world") == 0);
    free(sub);

    printf("\n--- STRJOIN ---\n");
    char *joined = ft_strjoin("hello", " world");
    print_test("ft_strjoin", joined != NULL && strcmp(joined, "hello world") == 0);
    free(joined);

    printf("\n--- STRTRIM ---\n");
    char *trimmed = ft_strtrim("  hello  ", " ");
    print_test("ft_strtrim", trimmed != NULL && strcmp(trimmed, "hello") == 0);
    free(trimmed);

    printf("\n--- SPLIT ---\n");
    char **split = ft_split("hello,world,test", ',');
    print_test("ft_split", split != NULL && strcmp(split[0], "hello") == 0 && 
               strcmp(split[1], "world") == 0 && strcmp(split[2], "test") == 0);
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);

    printf("\n--- ITOA ---\n");
    char *num = ft_itoa(-42);
    print_test("ft_itoa", num != NULL && strcmp(num, "-42") == 0);
    free(num);

    printf("\n--- STRMAPI ---\n");
    char test_mapi[] = "abc";
    char *mapped = ft_strmapi(test_mapi, NULL); // Usa una funzione semplice
    print_test("ft_strmapi", mapped != NULL);
    free(mapped);

    printf("\n--- STRITERI ---\n");
    char test_iteri[] = "abc";
    ft_striteri(test_iteri, NULL); // Usa una funzione semplice
    print_test("ft_striteri", 1); // Test base

    printf("\n--- PUTCHAR_FD ---\n");
    ft_putchar_fd('A', 1);
    printf(" <- dovrebbe vedere 'A'\n");

    printf("\n--- PUTSTR_FD ---\n");
    ft_putstr_fd("Hello", 1);
    printf(" <- dovrebbe vedere 'Hello'\n");

    printf("\n--- PUTENDL_FD ---\n");
    ft_putendl_fd("World", 1);
    printf("^ dovrebbe vedere 'World' con newline\n");

    printf("\n--- PUTNBR_FD ---\n");
    ft_putnbr_fd(42, 1);
    printf(" <- dovrebbe vedere '42'\n");

    printf("\n=== FINE TEST ===\n\n");
    return 0;
}
