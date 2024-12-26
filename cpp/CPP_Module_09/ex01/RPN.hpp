/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:56:47 by msapin            #+#    #+#             */
/*   Updated: 2023/11/14 21:58:24 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>

# define RED "\033[0;31m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

void displayError(int index);
bool isDigit(char elem);
bool isOperator(char elem);

class RPN {

	public:
		RPN(std::string const & arg);
		RPN(RPN const & copy);
		~RPN(void);

		RPN & operator=(RPN const & src);

		bool isValid(void) const;
		void	displayResult(void);

	private:
		RPN(void);
		
		std::stack<int> _numberStack;
		std::stack<int> _operatorStack;
};

#endif