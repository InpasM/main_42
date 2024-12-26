/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:46:16 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 22:22:22 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include "Weapon.hpp"

class	HumanB {

	public:
		HumanB(std::string name);

		void	setWeapon(Weapon& weapon);
		void	attack(void) const;

	private:
		std::string	_name;
		
		Weapon* _weapon;
	
};

#endif