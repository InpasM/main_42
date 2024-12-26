/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:54 by msapin            #+#    #+#             */
/*   Updated: 2023/11/15 14:02:32 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <list>
# include <sstream>
# include <ctime>

# define RED "\033[0;31m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

void    displayError(int index, char * elem);

class PmergeMe {

	public:
		PmergeMe(char * argv[]);
		PmergeMe(PmergeMe const & copy);
		~PmergeMe(void);

		PmergeMe & operator=(PmergeMe const & src);

		bool getValidity(void) const;

		void	sortAll(void);

		std::ostream &	displaySequence(std::ostream & o) const;

	private:
		PmergeMe(void);

		std::vector<int> _intVector;
		std::list<int> _intList;

		bool _validity;

		// add time to process for both
};

std::ostream & operator<<(std::ostream & o, PmergeMe const & i);

#endif