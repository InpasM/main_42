/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:48 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 11:14:51 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

class Bureaucrat {
	
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & copy);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & src);

		const std::string & getName(void) const;
		
		int	getGrade(void) const;
		void	setGrade(int newGrade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("grade too High!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("grade too Low!");
				}
		};

	private:
		const std::string _name;

		int _grade;
};

std::ostream & operator<<(std::ostream & o, const Bureaucrat & i);

#endif