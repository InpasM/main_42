/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:49:27 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 13:02:40 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {

	public:
		Intern(void);
		Intern(Intern const & copy);
		~Intern(void);

		Intern & operator=(Intern const & src);

		Form * makeForm(std::string name, std::string target);

		Form * getShrubbery(std::string target);
		Form * getRobotomy(std::string target);
		Form * getPresidential(std::string target);
};

#endif