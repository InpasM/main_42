/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:46:12 by msapin            #+#    #+#             */
/*   Updated: 2023/08/24 22:20:30 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class	Weapon {

	public:
		Weapon(std::string type);
		
		std::string const &	getType(void) const;

		void	setType(std::string newType);

	private:
		std::string	_type;
};

#endif