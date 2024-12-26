/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:50:15 by msapin            #+#    #+#             */
/*   Updated: 2023/11/08 13:09:49 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <list>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const & copy) : std::stack<T>(copy) {}
		~MutantStack(void) {}

		MutantStack & operator=(MutantStack const & src) {
			std::stack<T>::operator=(src);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {
			return this->c.begin();
		}

		iterator end(void) {
			return this->c.end();
		}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin(void) const {
			return this->c.begin();
		}
		const_iterator cend(void) const {
			return this->c.end();
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) {
			return this->c.rbegin();
		}
		reverse_iterator rend(void) {
			return this->c.rend();
		}

		typedef typename std::stack<int>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void) const {
			return this->c.rbegin();
		}
		const_reverse_iterator crend(void) const {
			return this->c.rend();
		}
};

#endif