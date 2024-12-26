/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:06 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:54:27 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog(void);
		Dog(Dog const & copy);
		~Dog(void);

		Dog & operator=(Dog const & src);

		void	makeSound(void) const;
};

#endif