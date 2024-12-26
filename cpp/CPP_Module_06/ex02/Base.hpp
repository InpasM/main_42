/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:25:14 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 13:09:13 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <cstdlib>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

class Base {
	public:
		virtual ~Base(void) {};
};

#endif