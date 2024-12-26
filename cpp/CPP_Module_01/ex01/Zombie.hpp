/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:11:26 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 14:37:43 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class	Zombie {

	public:
		Zombie(void);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);

	private:
		std::string _name;

};

Zombie* zombieHorde(int N, std::string name);

#endif