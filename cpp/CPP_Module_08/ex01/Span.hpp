/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:55 by msapin            #+#    #+#             */
/*   Updated: 2023/11/07 22:10:44 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <bits/stdc++.h>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

class Span {

	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const & copy);
		~Span(void);

		Span & operator=(Span const & src);

		void addNumber(int toAdd);
		void fillRange(std::vector<int>::iterator position, std::vector<int>::iterator start, std::vector<int>::iterator end);
		void fillSpan(void);

		long	shortestSpan(void) const;
		long	longestSpan(void) const;

		std::vector<int> & getVector(void);

		class CannotAddNumberException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Span: cannot add number"); 
				}
		};

		class NotEnoughNumberException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Span: need at least two number"); 
				}
		};

	private:
		unsigned int _nbNumber;
		std::vector<int> _vectorNumber;
};

std::ostream & operator<<(std::ostream & o, Span & i);

#endif