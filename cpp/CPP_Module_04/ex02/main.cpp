/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:01 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 17:27:23 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << "\033[1m\033[32m" << "TESTS making AAnimal array with a copy of cat/dog" << "\033[0m" << std::endl << std::endl;

		int	nbAnimals = 4;
		AAnimal*   animals[nbAnimals];

		for (int i = 0; i < nbAnimals; i++)
		{
			if (i == nbAnimals / 2)
				std::cout << std::endl;
			if (i < nbAnimals / 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}

		displayMessage("Displaying all animals before");
		for (int i = 0; i < nbAnimals; i++)
			std::cout << animals[i]->getType() << std::endl;

		displayMessage("All animals make sound");
		for (int i = 0; i < nbAnimals; i++)
			animals[i]->makeSound();

		displayMessage("Deleting first cat");
		delete animals[0];

		displayMessage("Displaying all animals after removing first AAnimal (cat)");
		for (int i = 0; i < nbAnimals; i++)
		{
			if (i != 0)
				std::cout << animals[i]->getType() << std::endl;
		}

		displayMessage("Deleting first dog");
		delete animals[2];

		displayMessage("Displaying all animals after removing first AAnimal (cat) and third (dog)");
		for (int i = 0; i < nbAnimals; i++)
		{
			if (i != 0 && i != 2)
				std::cout << animals[i]->getType() << std::endl;
		}

		displayMessage("Deleting remaining animals");
		delete animals[1];
		delete animals[3];
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS making copy of cat" << "\033[0m" << std::endl;

		displayMessage("Creating cat");
		Cat   cat = Cat();

		displayMessage("Making copy of cat");
		Cat   copyCat(cat);
			
		displayMessage("Displaying cat with an empty brain");
		std::cout << cat << std::endl;

		displayMessage("Displaying copy of Cat with an empty brain");
		std::cout << copyCat << std::endl;

		cat.setIdea("First idea", 0);
		cat.setIdea("Second idea", 1);

		displayMessage("Displaying cat after adding two idea (index 0 and 1)");
		std::cout << cat << std::endl;

		displayMessage("Displaying copy of Cat after adding two idea to the original cat");
		std::cout << copyCat << std::endl;

		displayMessage("Add idea in copyCat");
		copyCat.setIdea("First idea copyCat", 0);

		displayMessage("Display cat");
		std::cout << cat << std::endl;

		displayMessage("Display copyCat");
		std::cout << copyCat << std::endl;

		displayMessage("Adding idea with invalid index");
		cat.setIdea("Invalid idea", 150);

		displayMessage("Adding idea index 50");
		cat.setIdea("Other idea", 50);
		std::cout << cat << std::endl;

		displayMessage("Delete cat and his copy");
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS making copy of dog" << "\033[0m" << std::endl;

		displayMessage("Creating dog");
		Dog   dog = Dog();

		displayMessage("Making copy of dog");
		Dog   copyDog(dog);
			
		displayMessage("Displaying dog with an empty brain");
		std::cout << dog << std::endl;

		displayMessage("Displaying copy of Dog with an empty brain");
		std::cout << copyDog << std::endl;

		dog.setIdea("First idea", 0);
		dog.setIdea("Second idea", 1);

		displayMessage("Displaying dog after adding two idea (index 0 and 1)");
		std::cout << dog << std::endl;

		displayMessage("Displaying copy of Dog after adding two idea to the original dog");
		std::cout << copyDog << std::endl;

		displayMessage("Add idea in copyDog");
		copyDog.setIdea("First idea copyDog", 0);

		displayMessage("Display dog");
		std::cout << dog << std::endl;

		displayMessage("Display copyDog");
		std::cout << copyDog << std::endl;

		displayMessage("Adding idea with invalid index");
		dog.setIdea("Invalid idea", 150);

		displayMessage("Adding idea index 50");
		dog.setIdea("Other idea", 50);
		std::cout << dog << std::endl;

		displayMessage("Delete dog and his copy");
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS abstract" << "\033[0m" << std::endl;

		// this will not work, uncomment to test
		// AAnimal* abstractAnimal = new AAnimal(); 
		// (void)abstractAnimal;
	}
	return 0;
}
