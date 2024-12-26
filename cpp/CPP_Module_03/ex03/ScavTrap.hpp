/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:10:14 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:40:17 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & copy);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & src);

		void	attack(std::string const & target);
		void	guardGate(void);

		bool	getGuardingGate(void) const;
		void	setGuardingGate(bool mode);
		
	private:
		bool	_guardingGate;
};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i);

#endif