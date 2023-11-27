/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:01 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 13:53:01 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << "\033[1m\033[32m" << "TESTS using all constructor" << "\033[0m" << std::endl;

		displayMessage("Animal: Making default Animal and a copy of it");
		const Animal*   meta = new Animal();
		const Animal   copyAnimalMeta(*meta);

		displayMessage("Animal: Using makeSound() on meta and his copy");
		meta->makeSound();
		copyAnimalMeta.makeSound();

		displayMessage("Cat: Making new cat and a copy of it");
		const Cat* cat = new Cat();
		const Cat copyCat(*cat);

		displayMessage("Cat: Using MakeSound() on cat and his copy");
		cat->makeSound();
		copyCat.makeSound();

		displayMessage("Dog: Making new dog and a copy of it");
		const Dog* dog = new Dog();
		const Dog copyDog(*dog);

		displayMessage("Dog: Using MakeSound() on dog and his copy");
		dog->makeSound();
		copyDog.makeSound();

		displayMessage("Deleting meta (Notype), dog and cat");
		delete meta;
		delete cat;
		delete dog;

		displayMessage("Deleting copies of meta (Notype), dog and cat");
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS subject right classes" << "\033[0m" << std::endl << std::endl;
		const Animal*   meta = new Animal();
		const Animal*   j = new Dog();
		const Animal*   i = new Cat();

		std::cout << std::endl << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl << std::endl;

		meta->makeSound();
		j->makeSound();
		i->makeSound();

		displayMessage("Deleting meta (Notype), dog and cat");
		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS subject wrong cat" << "\033[0m" << std::endl << std::endl;
		const WrongAnimal*   wrongAnimal = new WrongAnimal();
		const WrongAnimal*   wrongCat = new WrongCat();

		std::cout << std::endl << wrongAnimal->getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl << std::endl;

		wrongAnimal->makeSound();
		wrongCat->makeSound();

		displayMessage("Deleting wrongAnimal (Notype) and wrongCat");
		delete wrongAnimal;
		delete wrongCat;
	}
	return 0;
}
