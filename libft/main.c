/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:10:52 by msapin            #+#    #+#             */
/*   Updated: 2023/11/26 13:35:07 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

char	ft_test_strmapi(unsigned int n, char c)
{
	(void)n;
	(void)c;
	// ft_toupper(c);
	printf("%c", ft_toupper(c));
	return(ft_toupper(c));
}

void	ft_test_striteri(unsigned int n, char *c)
{
	(void)n;
	(void)c;

	// *c = 'a';
	printf("%c|", *c);
}

void	display_message(char * message, char * color)
{
	printf("%s%s%s%s\n", color, BOLD, message, RESET);
}

void	test_functions_one()
{
	display_message("\nLIBFT - FUNCTIONS 1\n", GREEN);
	{
		display_message("FT_STRLEN:", YELLOW);
		char    s[] = "abcdefghijklmnopqrstuvwxyz";
		display_message("Libft", BLACK);
		printf("%s is %zu characters long", s, ft_strlen(s));
		display_message("\nOriginal", BLACK);
		printf("%s is %zu characters long\n\n", s, strlen(s));
	}

	{
		display_message("FT_MEMCPY:", YELLOW);
		char    mem_src[100] = "lorem ipsum dolor sit amet";
		char    dst_ft_cpy[12];
		char    dst_cpy[12];

		size_t n = 11;
		display_message("Libft", BLACK);
		printf("DST before ft_memcpy : %s\n", dst_ft_cpy);
		ft_memcpy(dst_ft_cpy, mem_src, n);
		printf("DST after ft_memcpy : %s", dst_ft_cpy);

		display_message("\nOriginal", BLACK);
		printf("DST before memcpy : %s\n", dst_cpy);
		memcpy(dst_cpy, mem_src, n);
		printf("DST after memcpy : %s\n\n", dst_cpy);
	}

	{
		display_message("FT_MEMSET:", YELLOW);
		char    s[100] = "Phrase dans laquelle ajouter";
		char    ft_s[100] = "Phrase dans laquelle ajouter";
		int c = 'e';
		size_t len = 20;
		
		display_message("Libft", BLACK);
		printf("STR before ft_memset : %s\n", ft_s);
		ft_memset(ft_s, c, len);
		printf("STR after ft_memset : %s", ft_s);
		display_message("\nOriginal", BLACK);
		printf("STR before ft_memset : %s\n", s);
		memset(s, c, len);
		printf("STR after ft_memset : %s\n\n", s);
	}

	{
		display_message("FT_BZERO:", YELLOW);
		char    s[10] = "123456789";
		char    ft_s[10] = "123456789";
		size_t len = 2;
		unsigned long int i = 0;

		display_message("Libft", BLACK);
		printf("STR before ft_bzero : %s\n", ft_s);
		ft_bzero(ft_s, len);
		printf("STR after ft_bzero : ");
		while (i < sizeof(ft_s))
		{
			printf("%c", ft_s[i]);
			i++;
		}

		i = 0;
		display_message("\nOriginal", BLACK);
		printf("STR before bzero : %s\n", s);
		bzero(s, len);
		printf("STR after bzero : ");
		while (i < sizeof(s))
		{
			printf("%c", s[i]);
			i++;
		}
	}

	{
		display_message("\n\nFT_MEMMOVE:", YELLOW);
		char    mem_src[100] = "lorem ipsum dolor sit amet";
		char    ft_mem_src[100] = "lorem ipsum dolor sit amet";
		char    *dst_move = mem_src + 1;
		char    *ft_dst_move = ft_mem_src + 1;
		size_t n = 10;

		display_message("Libft", BLACK);
		printf("DST before ft_memmove : %s\n", ft_dst_move);
		 ft_memmove(ft_dst_move, "con\0sec\0\0te\0tur", 10);
		printf("DST after ft_memmove : %s", ft_dst_move);

		display_message("\nOriginal", BLACK);
		printf("DST before memmove : %s\n", dst_move);
		memmove(dst_move, "con\0sec\0\0te\0tur", n);
		printf("DST after memmove : %s\n\n", dst_move);
	}

	{
		display_message("\n\nFT_MEMCMP:", YELLOW);
		char    *memcmp_s1 = "abcdefg";
		char    *memcmp_s2 = "aBCDEFG";
		size_t  memcmp_n = 10;

		display_message("Libft", BLACK);
		printf("ft_memcmp :\n%s vs %s = %d\n", memcmp_s1, memcmp_s2, ft_memcmp(memcmp_s1, memcmp_s2, memcmp_n));

		display_message("Original", BLACK);
		printf("memcmp :\n%s vs %s = %d\n", memcmp_s1, memcmp_s2, memcmp(memcmp_s1, memcmp_s2, memcmp_n));
	}

	{
		display_message("\n\nFT_MEMCHR:", YELLOW);
		char    tab[7] = {-49, 49, 1, -1, 0, -2, 2};

		display_message("Libft", BLACK);
		printf("ft_memchr :\n%s\n", (char *)ft_memchr(tab, -1, 7));

		display_message("Original", BLACK);
		printf("memchr :\n%s\n", (char *)memchr(tab, -1, 7));
	}
}

void	test_is_function(char * name_test, char * version, int (*f)(int))
{
	int i = 0;
	int count_non = 0;
	char    alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_-+=.,/;:'\"[{}]0123456789";

	display_message(version, BLACK);
	while (alphabet[i] != '\0') 
	{
		if (f(alphabet[i]) == '\0')
		{
			printf("%c, ", alphabet[i]);
			count_non++;
		}
		i++;
	}
	printf("There are %d characters %s\n", count_non, name_test);
}

void	test_functions_two()
{
	display_message("\nLIBFT - FUNCTIONS 2\n", GREEN);

	display_message("FT_ISALPHA:", YELLOW);
	test_is_function("non alphabetic", "Libft", ft_isalpha);
	test_is_function("non alphabetic", "Original", isalpha);

	display_message("\nFT_ISDIGIT:", YELLOW);
	test_is_function("non digital", "Libft", ft_isdigit);
	test_is_function("non digital", "Original", isdigit);

	display_message("\nFT_ISALNUM:", YELLOW);
	test_is_function("non alphanumeric", "Libft", ft_isalnum);
	test_is_function("non alphanumeric", "Original", isalnum);

	display_message("\nFT_ISASCII:", YELLOW);
	test_is_function("non ascii", "Libft", ft_isascii);
	test_is_function("non ascii", "Original", isascii);

	display_message("\nFT_ISPRINT:", YELLOW);
	test_is_function("non printable", "Libft", ft_isprint);
	test_is_function("non printable", "Original", isprint);
}

void	test_functions_three()
{
	display_message("\nLIBFT - FUNCTIONS 2\n", GREEN);

	{
		display_message("FT_TOUPPER:", YELLOW);
		char    text[] = "abHDEJsjbdejqDUEJdeg";
		int i = 0;

		display_message("Libft", BLACK);
		printf("STR before ft_toupper : %s\nSTR after ft_toupper : ", text);
		while (text[i] != '\0')
		{
		    printf("%c", ft_toupper(text[i]));
		    i++;
		}
		display_message("\nOriginal", BLACK);
		i = 0;
		printf("STR before toupper : %s\nSTR after toupper : ", text);
		while (text[i] != '\0')
		{
		    printf("%c", toupper(text[i]));
		    i++;
		}
	}

	{
		display_message("\n\nFT_TOLOWER:", YELLOW);
		char    text[] = "abHDEJsjbdejqDUEJdeg";
		int i = 0;

		display_message("Libft", BLACK);
		printf("STR before ft_tolower : %s\nSTR after ft_toupper : ", text);
		while (text[i] != '\0')
		{
		    printf("%c", ft_tolower(text[i]));
		    i++;
		}
		display_message("\nOriginal", BLACK);
		i = 0;
		printf("STR before tolower : %s\nSTR after tolower : ", text);
		while (text[i] != '\0')
		{
		    printf("%c", tolower(text[i]));
		    i++;
		}
	}

	{
		display_message("\n\nFT_STRCHR:", YELLOW);
		char    str[] = "lorem ipsum dolor sit amet";
		char	*charToFound = "orzdt\0m";
		int i;

		display_message("Libft", BLACK);
		for (i = 0; i < 7; i++)
			printf("%c: %s\n", charToFound[i], ft_strchr(str, charToFound[i]));

		display_message("Original", BLACK);
		for (i = 0; i < 7; i++)
			printf("%c: %s\n", charToFound[i], strchr(str, charToFound[i]));
	}

	{
		display_message("\n\nFT_STRRCHR:", YELLOW);
		char    str[] = "lorem ipsum dolor sit amet";
		char	*charToFound = "orzdt\0m";
		int i;

		display_message("Libft", BLACK);
		for (i = 0; i < 7; i++)
			printf("%c: %s\n", charToFound[i], ft_strrchr(str, charToFound[i]));

		display_message("Original", BLACK);
		for (i = 0; i < 7; i++)
			printf("%c: %s\n", charToFound[i], strrchr(str, charToFound[i]));
	}
}

void	test_functions_four()
{
	display_message("\nLIBFT - FUNCTIONS 4\n", GREEN);
	{
		display_message("FT_STRLCAT:", YELLOW);
		char    ft_dst[100] = "lorem ipsum ";
		char    src[] = "dolor sit amet";
		size_t return_value;
		size_t dstsize = 22;

		display_message("Libft", BLACK);
		printf("DST before : %s\n", ft_dst);
		return_value = ft_strlcat(ft_dst, src, dstsize);
		printf("DST after : %s / return value : %lu / dstsize : %lu\n", ft_dst, return_value, dstsize);

		// display_message("Original", BLACK);
		// char    dst[100] = "lorem ipsum ";
		// printf("DST before : %s\n", dst);
		// strncat(dst, src, dstsize);
		// return_value = strlen(dst);
		// printf("DST after : %s / return value : %lu / dstsize : %lu\n", dst, return_value, dstsize);
	}

	{
		display_message("\nFT_STRLCPY:", YELLOW);
		char    ft_dst[100] = "Destination";
		char    src[] = "Replacement";
		size_t dstsize = 12;
		size_t return_value;

		display_message("Libft", BLACK);
		printf("DST before : %s\n", ft_dst);
		return_value = ft_strlcpy(ft_dst, src, dstsize);
		printf("DST after : %s / return value = %lu\n", ft_dst, return_value);
	
		// display_message("Original", BLACK);
		// char    dst[100] = "Destination";
		// printf("DST before : %s\n", dst);
		// strncpy(dst, src, dstsize);
		// printf("DST after : %s\n", dst);
	}

	{
		display_message("\nFT_ATOI:", YELLOW);
		char    atoi_str[60] = "     \n\t\v\f\r    -01234567890.7151a";

		display_message("Libft", BLACK);
		printf("STR before : %s\n", atoi_str);
		printf("STR after : %d\n", ft_atoi(atoi_str));

		display_message("Original", BLACK);
		printf("STR before : %s\n", atoi_str);
		printf("STR after : %d\n", atoi(atoi_str));
	}

	{
		display_message("\nFT_STRNSTR:", YELLOW);
		char    *strnstr_haystack = "lorem ipsum dolor sit amet";
		char    *strnstr_needle = "sit ";
		size_t strnstr_len = 26;

		display_message("Libft", BLACK);
		printf("%s\n", ft_strnstr(strnstr_haystack, strnstr_needle, strnstr_len));
	}

	{
		display_message("\nFT_STRNCMP:", YELLOW);
		char    *one_str_s1 = "ab\ncdefg";
		char    *one_str_s2 = "abcdefgh";
		char    *two_str_s1 = "test\200";
		char    *two_str_s2 = "test\0";
		size_t  n = 6;

		display_message("Libft", BLACK);
		printf("TEST 1 :\n%s vs %s = %d\n", one_str_s1, one_str_s2, ft_strncmp(one_str_s1, one_str_s2, n));
		printf("TEST 2 :\n%s vs %s = %d\n", two_str_s1, two_str_s2, ft_strncmp(two_str_s1, two_str_s2, n));
	
		display_message("Original", BLACK);
		printf("TEST 1 :\n%s vs %s = %d\n", one_str_s1, one_str_s2, strncmp(one_str_s1, one_str_s2, n));
		printf("TEST 2 :\n%s vs %s = %d\n", two_str_s1, two_str_s2, strncmp(two_str_s1, two_str_s2, n));
	}

	{
		display_message("\nFT_CALLOC:", YELLOW);
		int calloc_count = 30;
		int calloc_size = 1;

		display_message("Libft", BLACK);
		printf("number bit allocated :%ld\n", malloc_usable_size(ft_calloc(calloc_count, calloc_size)));

		display_message("Original", BLACK);
		printf("number bit allocated :%ld\n\n", malloc_usable_size(calloc(calloc_count, calloc_size)));
	}

	{
		display_message("\nFT_STRDUP:", YELLOW);
		char	*str = "lorem ipsum dolor sit amet";

		display_message("Libft", BLACK);
		char *ft_str = ft_strdup(str);
		printf("ft_strdup :\n%s\n", ft_str);
		free(ft_str);

		display_message("Original", BLACK);
		char *or_str = ft_strdup(str);
		printf("strdup :\n%s\n", or_str);
		free(or_str);
	}
}

void	test_functions_five()
{
	display_message("\nLIBFT - FUNCTIONS 5\n", GREEN);
	{
		display_message("FT_SUBSTR:", YELLOW);
		char	str[] = "lorem ipsum dolor sit amet";
		char	*strsub;

		display_message("Libft", BLACK);
		strsub = ft_substr(str, 12, 9);
		printf("%s\n", strsub);
		free(strsub);
	}

	{
		display_message("\nFT_STRJOIN:", YELLOW);
		char	str_begin[] = "lorem ipsum ";
		char	str_end[] = "dolor sit amet";
		char	*new_str;

		display_message("Libft", BLACK);
		new_str = ft_strjoin(str_begin, str_end);
		printf("%s+ %s = %s\n", str_begin, str_end, new_str);
		free(new_str);
	}

	{
		display_message("\nFT_PUTCHAR_FD:", YELLOW);

		display_message("Libft", BLACK);
		ft_putchar_fd('c', 0);
	}

	{
		display_message("\n\nFT_PUTSTR_FD:", YELLOW);

		display_message("Libft", BLACK);
		ft_putstr_fd("lorem ipsum dolor sit amet", 0);
	}

	{
		display_message("\n\nFT_PUTENDL_FD:", YELLOW);

		display_message("Libft", BLACK);
		ft_putendl_fd("lorem ipsum dolor sit amet", 0);
	}

	{
		display_message("\nFT_PUTNBR_FD:", YELLOW);

		display_message("Libft", BLACK);
		ft_putnbr_fd(-2147483648LL, 2);
	}
}

void	test_functions_six()
{
	display_message("\nLIBFT - FUNCTIONS 6\n", GREEN);
	{
		display_message("\nFT_STRMAPI:", YELLOW);
		char	*s = "abcdefghijklmnopqrstuvwxyz";
		
		display_message("Libft", BLACK);
		printf("Use strmapi with function ft_test_strmapi on :\n%s\n", s);
		ft_strmapi(s, ft_test_strmapi);
	}

	{
		display_message("\n\nFT_STRITERI:", YELLOW);
		char	*s = "abcdefghijklmnopqrstuvwxyz";
	
		display_message("Libft", BLACK);
		printf("STR before :\n%s\n", s);
		printf("STR after :\n");
		ft_striteri(s, ft_test_striteri);
	}

	{
		display_message("\n\nFT_STRTRIM:", YELLOW);
		char	*s1 = "lorem ipsum dolor sit amet";
		char	*set = " lote";

		display_message("Libft", BLACK);
		printf("ft_strtrim:\n%s", ft_strtrim(s1, set));
	}

	{
		display_message("\n\nFT_SPLIT:", YELLOW);
		char	*s1 = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
		char	c = ' ';
		char	**tab;
		size_t	i = 0;
		tab = ft_split(s1, c);
		display_message("Libft", BLACK);
		printf("STR before : %s\n", s1);
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}

	{
		display_message("\nFT_ITOA:", YELLOW);
		display_message("Libft", BLACK);
		printf("%d : %s\n", 0, ft_itoa(0));
		printf("%d : %s\n", 9, ft_itoa(9));
		printf("%d : %s\n", -9, ft_itoa(-9));
		printf("%d : %s\n", 10, ft_itoa(10));
		printf("%d : %s\n", -10, ft_itoa(-10));
		printf("%d : %s\n", 8124, ft_itoa(8124));
		printf("%d : %s\n", -9874, ft_itoa(-9874));
		printf("%d : %s\n", 543000, ft_itoa(543000));
		printf("%s : %s\n", "-2147483648LL", ft_itoa(-2147483648LL));
		printf("%s : %s\n", "2147483647", ft_itoa(2147483647));
	}
}

int	getIndexTest(char * arg)
{
	int	sizeArg = strlen(arg);

	if (sizeArg == 1)
	{
		if (arg[0] == '1')
			return 1;
		else if (arg[0] == '2')
			return 2;
		else if (arg[0] == '3')
			return 3;
		else if (arg[0] == '4')
			return 4;
		else if (arg[0] == '5')
			return 5;
		else if (arg[0] == '6')
			return 6;
	}
	else if (sizeArg == 5)
	{
		if (arg[0] == 'b' && arg[1] == 'o' && arg[2] == 'n' && arg[3] == 'u' && arg[4] == 's')
			return 7;
	}
	return 0;
}

int main(int argc, char * argv[])
{
	if (argc == 1)
		test_functions_one();
	else if (argc == 2)
	{
		switch(getIndexTest(argv[1])) {
			case 1:
				test_functions_one();
				break;
			case 2:
				test_functions_two();
				break;
			case 3:
				test_functions_three();
				break;
			case 4:
				test_functions_four();
				break;
			case 5:
				test_functions_five();
				break;
			case 6:
				test_functions_six();
				break;
			default:
				printf("%s%sError: %s%s: invalid index\n", RED, BOLD, RESET, argv[1]);
		}
	}

	return 0;
}
