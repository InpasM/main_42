/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:43 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 17:42:28 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int main(void) {

	std::cout << std::endl << "\033[1m\033[32m" << "TESTS EX01 - Ice" << "\033[0m" << std::endl;
	{
		displayMessage("Create default Ice");
		Ice ice = Ice();

		displayMessage("Cloning Ice");
		AMateria* cloned = ice.clone();

		displayMessage("Displaying cloned type");
		std::cout << "cloned type: " << cloned->getType() << std::endl;

		displayMessage("Deleting cloned");
		delete cloned;
	}

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX02 - Cure" << "\033[0m" << std::endl;
	{
		displayMessage("Create default Cure");
		Cure cure = Cure();

		displayMessage("Cloning Cure");
		AMateria* cloned = cure.clone();

		displayMessage("Displaying cloned type");
		std::cout << "cloned type: " << cloned->getType() << std::endl;

		displayMessage("Deleting cloned");
		delete cloned;
	}

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX03 - Copy / affectation Character" << "\033[0m" << std::endl;
	{
		displayMessage("Creating MateriaSource");
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		displayMessage("Making 2 Character with 2 materia equip and 2 unequip");
		Character* first = new Character("first");
		Character* second = new Character("second");
		AMateria* tmp;

		tmp = src->createMateria("cure");
		first->equip(tmp);
		tmp = src->createMateria("cure");
		first->equip(tmp);
		tmp = src->createMateria("ice");
		first->equip(tmp);
		tmp = src->createMateria("ice");
		first->equip(tmp);

		first->unequip(0);
		first->unequip(1);

		tmp = src->createMateria("cure");
		second->equip(tmp);
		tmp = src->createMateria("cure");
		second->equip(tmp);
		tmp = src->createMateria("ice");
		second->equip(tmp);
		tmp = src->createMateria("ice");
		second->equip(tmp);

		displayMessage("Displaying character first");
		first->displayCharacter();

		displayMessage("Creating character by copy of first");
		Character copyChar(*first);

		displayMessage("Displaying character copied");
		first->displayCharacter();

		displayMessage("Displaying character second");
		second->displayCharacter();

		displayMessage("Assigning second character to first");
		*first = *second;

		displayMessage("Displaying stat of both character");

		displayMessage("FIRST:");
		first->displayCharacter();
		
		displayMessage("SECOND:");
		second->displayCharacter();
		
		displayMessage("Deleting everything");
		delete src;
		delete first;
		delete second;
	}

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX04 - Equip / Unequip" << "\033[0m" << std::endl;
	{
		displayMessage("Creating MateriaSource");
		IMateriaSource* src = new MateriaSource();
		(void)src;

		displayMessage("Displaying MateriSource stat before");
		src->displayContent();

		displayMessage("Learning 4 Materia");
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		displayMessage("Displaying MateriSource stat after learning");
		src->displayContent();

		displayMessage("Trying to learn an extra Materia");
		src->learnMateria(new Cure());

		displayMessage("Creating character");
		ICharacter* me = new Character("me");
		AMateria* tmp;

		displayMessage("Displaying character before equipping Materia");
		me->displayCharacter();

		displayMessage("Trying creating and equipping invalid Materia");
		tmp = src->createMateria("invalid");
		me->equip(tmp);

		displayMessage("Equip two ice");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		displayMessage("Equip one cure");
		tmp = src->createMateria("cure");
		me->equip(tmp);

		displayMessage("Equip the same cure");
		me->equip(tmp);

		displayMessage("Equip an other cure");
		tmp = src->createMateria("cure");
		me->equip(tmp);

		displayMessage("Displaying character stat after equip 4 materia");
		me->displayCharacter();

		displayMessage("Unequip invalid index");
		me->unequip(-1);
		me->unequip(4);

		displayMessage("Unequip materia index 0 (ice) and 2 (cure)");
		me->unequip(0);
		me->unequip(2);

		displayMessage("Displaying character stat after unequip");
		me->displayCharacter();

		displayMessage("Try unequip materia index 0 now empty");
		me->unequip(0);

		displayMessage("Filling back character Inventory");
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		displayMessage("Displaying character stat after filling");
		me->displayCharacter();
		
		displayMessage("Try to add an extra Materia");
		tmp = src->createMateria("cure");
		me->equip(tmp);

		displayMessage("Unequip all Materia");
		for (int i = 0; i < 4; i++)
			me->unequip(i);

		displayMessage("Displaying character last time");
		me->displayCharacter();

		displayMessage("Deleting everything");
		delete src;
		delete tmp;
		delete me;
	}

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX05 - Use" << "\033[0m" << std::endl;
	{
		displayMessage("Creating MateriaSource");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		displayMessage("Creating Character");
		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		displayMessage("Try using invalid index");
		me->use(-1, *bob);
		me->use(4, *bob);

		displayMessage("Try using empty index");
		me->use(3, *bob);

		displayMessage("Using materia ice (index: 0)");
		me->use(0, *bob);

		displayMessage("Using materia cure (index: 1)");
		me->use(1, *bob);
		
		displayMessage("Deleting everything");
		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX03 - Subject" << "\033[0m" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	return 0;
}
