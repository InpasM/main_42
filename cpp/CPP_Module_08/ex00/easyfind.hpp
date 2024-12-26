/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:44:50 by msapin            #+#    #+#             */
/*   Updated: 2023/11/06 15:15:18 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

class IntNotFoundException : std::exception {
	public:
		virtual const char* what(void) const throw() {
			return ("not found!");
		}
};

template<typename T>
typename T::iterator easyfind(T container, int toFind)
{
	typename T::iterator indexFind = std::find(container.begin(), container.end(), toFind);
	typename T::iterator it;

	if (indexFind != container.end())
		return indexFind;
	else
		throw IntNotFoundException();
}
