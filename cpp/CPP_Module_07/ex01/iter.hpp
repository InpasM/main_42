/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:49:26 by msapin            #+#    #+#             */
/*   Updated: 2023/11/22 17:39:38 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

template<typename T>
void iter(T* addressArray, int sizeArray, void (*func)(T &)) {
	for(int i = 0; i < sizeArray; i++) {
		func(addressArray[i]);
	}
}

template<typename T>
void iter(T const * addressArray, int sizeArray, void (*func)(T const &)) {
	for(int i = 0; i < sizeArray; i++) {
		func(addressArray[i]);
	}
}

template<typename T>
void displayVar(T & var) {
	std::cout << var << std::endl;
}

#endif