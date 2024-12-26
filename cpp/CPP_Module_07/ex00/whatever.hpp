/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:06:44 by msapin            #+#    #+#             */
/*   Updated: 2023/11/21 20:29:25 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

template<typename T>
void swap(T & argOne, T & argTwo) {
	T tmpArg = argOne;
	argOne = argTwo;
	argTwo = tmpArg;
}

template<typename T>
T & min(T & argOne, T & argTwo) {
	return argOne >= argTwo ? argTwo : argOne;
}

template<typename T>
T & max(T & argOne, T & argTwo) {
	return argOne <= argTwo ? argTwo : argOne;
}

#endif