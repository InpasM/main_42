/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:06 by msapin            #+#    #+#             */
/*   Updated: 2023/11/26 14:13:11 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

void	display_message(char * message, char * color)
{
	printf("%s%s%s%s\n", color, BOLD, message, RESET);
}

int	main(void)
{
	display_message("\nFT_PRINTF - TESTS\n", GREEN);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("Lm dolor %c %c %c %c %c %d %s %%", 'a', 'b', 'c', 'd', 'e', 580000000, "teedefrfrfgrergegergerst"));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf("Lm dolor %c %c %c %c %c %d %s %%", 'a', 'b', 'c', 'd', 'e', 580000000, "teedefrfrfgrergegergerst"));

	// no format
	display_message("\nNO FORMAT", YELLOW);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf("\001\002\007\v\010\f\r\n"));

	// convert c
	display_message("\nCONVERT C", YELLOW);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf(" %c", 'x'));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf(" %c", 'x'));

	// convert pointer
	display_message("\nCONVERT POINTER", YELLOW);
	int	int_test = 500;
	int	*address = &int_test;
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("%p %p", &int_test, address));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf("%p %p", &int_test, address));

	// convert string
	display_message("\nCONVERT STRING", YELLOW);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf(" %s", "can it handle \t and \n?"));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf(" %s", "can it handle \t and \n?"));

	// // convert d
	display_message("\nCONVERT D", YELLOW);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("Je fais un test %d", -2147483647));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n\n", printf("Je fais un test %d", -2147483647));
	
	// // convert i
	display_message("\nCONVERT I", YELLOW);
	display_message("ft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("Je fais un test %i", -21474836490));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf("Je fais un test %li", -21474836490));

	// convert percent
	display_message("\nCONVERT PERCENT", YELLOW);
	display_message("ft_printf", BLACK);
	printf("Nombre de char total : %d\n", ft_printf(" %%"));
	display_message("\nOriginal", BLACK);
	printf("Nombre de char total : %d\n", printf(" %%"));

	// convert unsigned
	display_message("\nCONVERT UNSIGNED", YELLOW);
	display_message("ft_printf", BLACK);
	ft_printf("%u\n", -154564222);
	display_message("\nOriginal", BLACK);
	printf("%u\n", -154564222);

	// convert hexa lowercase
	display_message("\nCONVERT HEXA LOWERCASE", YELLOW);
	display_message("ft_printf", BLACK);
	ft_printf("%x\n Test\n\n", -154564222);
	display_message("Original", BLACK);
	printf("%x\n Test\n", -154564222);

	// convert hexa uppercase
	display_message("\nCONVERT HEXA UPPERCASE", YELLOW);
	display_message("ft_printf", BLACK);
	ft_printf("%X\n Test\n", -154564222);
	display_message("\nOriginal", BLACK);
	printf("%X\n Test\n", -154564222);

	// no arg
	display_message("\nSTRING NULL", YELLOW);
	display_message("\nft_printf", BLACK);
	printf("\nNombre de char total : %d\n", ft_printf("Je fais un test %s\n", ""));
	display_message("\nOriginal", BLACK);
	printf("\nNombre de char total : %d\n", printf("Je fais un test %s\n", ""));
	return (0);
}
