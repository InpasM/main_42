/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:46:14 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 22:17:22 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include "Weapon.hpp"

class	HumanA {

	public:
		HumanA(std::string name, Weapon& weaponA);
		
		void	attack(void) const;

	private:
		std::string	_name;
		
		Weapon&	_weapon;
	
};

#endif