/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:12 by msapin            #+#    #+#             */
/*   Updated: 2023/11/08 13:19:52 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(Cat const & copy);
		~Cat(void);

		Cat & operator=(Cat const & src);

		void	setIdea(std::string idea, int index);
		void	makeSound(void) const;
		void	display(std::ostream & o) const;

	private:
		Brain*	_brain;
};

#endif