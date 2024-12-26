/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:38:26 by msapin            #+#    #+#             */
/*   Updated: 2023/10/26 12:56:48 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

	public:
		Character(void);
		Character(std::string name);
		Character(Character const & copy);
		~Character(void);

		Character & operator=(Character const & src);

		std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		void displayCharacter(void) const;

	private:
		std::string _name;
		AMateria* _inventory[4];
		AMateria* _unequipped[4];
};

#endif