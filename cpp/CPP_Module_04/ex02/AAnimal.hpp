/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:16 by msapin            #+#    #+#             */
/*   Updated: 2023/10/02 17:57:32 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class AAnimal {

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const & copy);
		virtual ~AAnimal(void);

		AAnimal & operator=(AAnimal const & src);

		std::string getType(void) const;

		virtual void	setIdea(std::string idea, int index) = 0;
		virtual void	display(std::ostream & o) const = 0;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string type;
};

std::ostream &	operator<<(std::ostream & o, AAnimal const & i);

#endif