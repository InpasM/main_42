/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:10:52 by msapin            #+#    #+#             */
/*   Updated: 2023/11/25 20:39:32 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
	return(c);
}

void	ft_test_striteri(unsigned int n, char *c)
{
	(void)n;

	*c = 'a';
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
		char    s[] = "bonjour";
		int c = 'j';

		display_message("Libft", BLACK);
		printf("%s\n", ft_strchr(s, c));

		display_message("Original", BLACK);
		printf("%s\n", strchr(s, c));
	}

	{
		display_message("\n\nFT_STRRCHR:", YELLOW);
		char    s[] = "bonjour";
		int c = '\0';

		display_message("Libft", BLACK);
		printf("%s\n", ft_strrchr(s, c));

		display_message("Original", BLACK);
		printf("%s\n", strrchr(s, c));
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
			default:
				printf("%s%sError: %s%s: invalid index\n", RED, BOLD, RESET, argv[1]);
		}
	}

	// //////////////////////////////////////////////////////////// TESTS ft_striteri
	// char	str_toupper[] = "avant ft_toupper";
	
	// printf("str_toupper avant :\n%s\n", str_toupper);
	// ft_striteri(str_toupper, ft_test_striteri);
	// printf("\nPuis apres :\n%s\n\n", str_toupper);


	// // //////////////////////////////////////////////////////////// TESTS ft_strmapi
	// char	*s = "avant ft_toupper";
	// char	*s_after;
	
	// s_after = ft_strmapi(s, ft_test_strmapi);
	// printf("s avant :\n%s\nPuis apres :\n%s", s, s_after);


	// //////////////////////////////////////////////////////////// TESTS ft_itoa
	// printf("|%s|\n", ft_itoa(0));
	// printf("|%s|\n", ft_itoa(9));
	// printf("|%s|\n", ft_itoa(-9));
	// printf("|%s|\n", ft_itoa(10));
	// printf("|%s|\n", ft_itoa(-10));
	// printf("|%s|\n", ft_itoa(8124));
	// printf("|%s|\n", ft_itoa(-9874));
	// printf("|%s|\n", ft_itoa(543000));
	// printf("|%s|\n", ft_itoa(-2147483648LL));
	// printf("|%s|\n", ft_itoa(2147483647));


	// //////////////////////////////////////////////////////////// TESTS ft_split
	// //char	*s1 = "lorem ipsum dolor sit amet";
	// char	*s1 = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	// char	c = ' ';
	// char	**tab;
	// size_t	i = 0;
	// tab = ft_split(s1, c);
	// while (tab[i])
	// {
	// 	printf("%s\n", tab[i]);
	// 	i++;
	// }


	// //////////////////////////////////////////////////////////////TESTS ft_strtrim
	// //char	*s1 = "lorem ipsum dolor sit amet";
	// char	*s1 = "lorem ipsum dolor sit amet";
	// //char	*s1 = "          ";
	// char	*set = " lote";
	// printf("ft_strtrim:\n%s", ft_strtrim(s1, set));


	// //////////////////////////////////////////////////////////// TESTS ft_strjoin
	// char	*s1 = "Debut de phrase ";
	// char	*s2 = "et fin de phrase";
	// printf("%s", ft_strjoin(s1, s2));


	// //////////////////////////////////////////////////////////////TESTS ft_substr
	// char	str[] = "lorem ipsum dolor sit amet";
	// char	*strsub;
	// int		arg;

	// char *bullshit;
	// if (!(strsub = ft_substr(str, 400, 20)))
	// 	printf("NULL");
	// else
	// {
	// 	bullshit = (char *)&strsub[30];
	// 	bullshit = "FULL BULLSHIT";
	// 	if (strsub)
	// 		printf("%s", strsub);
	// 	else
	// 		printf("rip");
	// }
	// if (str == strsub)
	// 	printf("\nA new string was not returned");
	// (void)bullshit;


	// //////////////////////////////////////////////////////////// TESTS ft_putnbr_fd
	// ft_putnbr_fd(-2147483648LL, 2);

	// //////////////////////////////////////////////////////////// TESTS ft_putstr_fd
	// ft_putendl_fd("Test de phrase avec retour a la ligne", 0);
	
	// //////////////////////////////////////////////////////////// TESTS ft_putstr_fd
	// ft_putstr_fd("Test de phrase", 0);

	// //////////////////////////////////////////////////////////// TESTS ft_putchar_fd
	// ft_putchar_fd('c', 0);


	// //////////////////////////////////////////////////////////// TESTS ft_strdup et strdup
	// char	*strdup_str = "Phrase a copier";
	// printf("ft_strdup :\n%s", ft_strdup(strdup_str));


	// //////////////////////////////////////////////////////////// TESTS ft_calloc et calloc
	// int calloc_count = 30;
	// int calloc_size = 1;
	// printf("calloc :\n%d\n\n", (int)calloc(calloc_count, calloc_size));
	// printf("ft_calloc :\n%d", (int)ft_calloc(calloc_count, calloc_size));


	// //////////////////////////////////////////////////////////// TESTS ft_atoi et atoi
	// char    atoi_str[60] = "     \n\t\v\f\r    -01234567890.7151a";
	// printf("String avant atoi : %s\n", atoi_str);
	// printf("String apres atoi : %d\n", atoi(atoi_str));

	// printf("String avant ft_atoi : %s\n", atoi_str);
	// printf("String apres ft_atoi : %d\n", ft_atoi(atoi_str));


	// //////////////////////////////////////////////////////////// TESTS ft_strnstr et strnstr
	// char    *strnstr_haystack = "Phrase dans laquelle chercher";
	// char    *strnstr_needle = "laqu";
	// size_t strnstr_len = 20;
	// printf("%s\n", strnstr(strnstr_haystack, strnstr_needle, strnstr_len));
	// printf("%s\n", ft_strnstr(strnstr_haystack, strnstr_needle, strnstr_len));


	// //////////////////////////////////////////////////////////// TESTS ft_strncmp et strncmp
	// char    *strncmp_s1 = "ab\ncdefg";
	// char    *strncmp_s2 = "abcdefgh";
	// char    *strncmp_s1 = "test\200";
	// char    *strncmp_s2 = "test\0";

	// size_t  n = 6;

	// printf("strncmp :\n%s vs %s = %d\n", strncmp_s1, strncmp_s2, strncmp(strncmp_s1, strncmp_s2, n));
	// printf("ft_strncmp :\n%s vs %s = %d\n", strncmp_s1, strncmp_s2, ft_strncmp(strncmp_s1, strncmp_s2, n));
	

	// //////////////////////////////////////////////////////////// TESTS ft_strlcat et strlcat
	// char    dst[100] = "Debut de ";
	// //char    src[] = "phrase fin de phrase";
	
	// //char    dst[11] = "a";
	// char    src[] = "lorem";

	// size_t dstsize = 15;
	// printf("Avant strlcat\ndst = %s, src = %s, dstsize = %zu\n", dst, src, dstsize);
	// size_t return_value = strlcat(dst, src, dstsize);
	// printf("Apres strlcat\ndst = %s, src = %s, dstsize = %zu, return value = %lu\n\n", dst, src, dstsize, return_value);

	// char    ft_dst[11] = "a";
	// printf("Avant ft_strlcat\ndst = %s, src = %s, dstsize = %zu\n", ft_dst, src, dstsize);
	// size_t return_value = ft_strlcat(ft_dst, src, dstsize);
	// printf("Apres ft_strlcat\ndst = %s, src = %s, dstsize = %zu, return value = %lu\n", ft_dst, src, dstsize, return_value);

	// char	dest[11] = "a";
	// printf("%zu", ft_strlcat(dest, "lorem", 15));
	// write(1, "\n", 1);
	// write(1, dest, 15);


	// //////////////////////////////////////////////////////////// TESTS ft_strlcpy et strlcpy
	// char    dst[100] = "Destination";
	// char    src[] = "Remplacement";
	// size_t dstsize = 10;
	// printf("Avant strlcpy\ndst = %s, src = %s, dstsize = %zu\n", dst, src, dstsize);
	// strlcpy(dst, src, dstsize);
	// printf("Apres strlcpy\ndst = %s, src = %s, dstsize = %zu, return value = %lu\n\n", dst, src, dstsize, strlcpy(dst, src, dstsize));

	// char    ft_dst[100] = "Destination";
	// printf("Avant ft_strlcpy\ndst = %s, src = %s, dstsize = %zu\n", ft_dst, src, dstsize);
	// ft_strlcpy(ft_dst, src, dstsize);
	// printf("Apres ft_strlcpy\ndst = %s, src = %s, dstsize = %zu, return value = %lu\n", ft_dst, src, dstsize, ft_strlcpy(ft_dst, src, dstsize));
	


	// //////////////////////////////////////////////////////////// TESTS ft_memmove
	// char	src[] = "lorem ipsum dolor sit amet";
	// char	ft_src[] = "lorem ipsum dolor sit amet";
	// char	*dest;
	// char	*ft_dest;
	// int		arg;
	// dest = src + 1;
	// ft_dest = ft_src + 1;
	// printf("memmove:\n");
	// if (dest != memmove(dest, src, 8))
	// 	write(1, "dest's adress was not returned\n", 31);
	// write(1, dest, 22);

	// printf("\n\nft_memmove:\n");
	// if (ft_dest != ft_memmove(ft_dest, ft_src, 8))
	// 	write(1, "dest's adress was not returned\n", 31);
	// //printf("\n");
	// write(1, ft_dest, 22);
	
	// printf("memmove:\n");
	// if (dest != memmove(dest, "con\0sec\0\0te\0tur", 10))
	// 	write(1, "dest's adress was not returned\n", 31);
	// write(1, dest, 22);

	// printf("\n\nft_memmove:\n");
	// if (ft_dest != ft_memmove(ft_dest, "con\0sec\0\0te\0tur", 10))
	// 	write(1, "dest's adress was not returned\n", 31);
	// write(1, ft_dest, 22);



	// //////////////////////////////////////////////////////////// TESTS ft_strrchr et strrchr
	// char    s[] = "bonjour phrase dans laquelle chercher";
	// int c = 'b';
	// printf("%s\n", strrchr(s, c));
	// printf("%s\n", ft_strrchr(s, c));


	// //////////////////////////////////////////////////////////// TESTS ft_strchr et strchr
	// //char    s[] = "Phrase dans laquelle chercher";
	// char    s[] = "bonjour";
	// int c = '\0';
	// printf("%s\n", strchr(s, c));
	// printf("%s\n", ft_strchr(s, c));

	
	return 0;
}