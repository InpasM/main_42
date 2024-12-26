/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:45:37 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 14:06:20 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form(void);
		Form(std::string _name, int _gradeSign, int _gradeExec);
		Form(Form const & copy);
		~Form(void);

		Form & operator=(Form const & src);

		void	beSigned(Bureaucrat const & member);

		const std::string & getName(void) const;

		bool getIsSigned(void) const;

		int getGradeSign(void) const;
		int getGradeExec(void) const;

		void setIsSigned(bool isSigned);
		
		int setGradeSign(int gradeSign);
		int setGradeExec(int gradeExec);

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

		class AlreadySignedException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("form already Signed!");
				}
		};

	private:
		const std::string _name;

		bool _isSigned;

		const int _gradeSign;
		const int _gradeExec;
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif