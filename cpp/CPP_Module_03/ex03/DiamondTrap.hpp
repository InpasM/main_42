/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:35:41 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:39:45 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & copy);
		~DiamondTrap(void);

		DiamondTrap & operator=(DiamondTrap const & src);

		std::string getDiamondName(void) const;

		void	whoAmI(void);
		void	attack(std::string const & target);

	private:
		std::string	_name;
};

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i);

#endif