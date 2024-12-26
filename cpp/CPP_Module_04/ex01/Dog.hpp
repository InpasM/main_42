/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:06 by msapin            #+#    #+#             */
/*   Updated: 2023/11/08 13:19:49 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog(void);
		Dog(Dog const & copy);
		~Dog(void);

		Dog & operator=(Dog const & src);

		void	setIdea(std::string idea, int index);
		void	makeSound(void) const;

		void	display(std::ostream & o) const;
	
	private:
		Brain*	_brain;
};

#endif