/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:16 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:48:29 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal {

	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const & copy);
		virtual ~Animal(void);

		Animal & operator=(Animal const & src);

		std::string getType(void) const;

		virtual void	setIdea(std::string idea, int index);
		virtual void	display(std::ostream & o) const;
		virtual void	makeSound(void) const;

	protected:
		std::string type;
};

std::ostream &	operator<<(std::ostream & o, Animal const & i);

#endif