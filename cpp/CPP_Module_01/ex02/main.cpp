/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:02:20 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 17:39:28 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	
	std::string		brain("HI THIS IS BRAIN");
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "ADDRESSES" << std::endl
	<< "string:     " << &brain << std::endl
	<< "stringPTR:  " << stringPTR << std::endl
	<< "stringREF:  " << &stringREF << std::endl << std::endl
	
	<< "VALUES" << std::endl
	<< "string:     " << brain << std::endl
	<< "stringPTR:  " << *stringPTR << std::endl
	<< "stringREF:  " << stringREF << std::endl << std::endl;

	return 0;
}
