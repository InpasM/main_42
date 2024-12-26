/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:58:04 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:55:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(WrongCat const & copy);
		~WrongCat(void);

		WrongCat & operator=(WrongCat const & src);

		void	makeSound(void) const;
};

#endif