/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:46 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 11:14:30 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX00 - Testing create Bureaucrat" << "\033[0m" << std::endl;

		displayMessage("Trying create invalid Bureaucrat with grade too high / low");
		Bureaucrat tooHigh("tooHigh", 0);
		Bureaucrat tooLow("tooLow", 200);

		displayMessage("Displaying stats of both");
		std::cout << tooHigh << std::endl;
		std::cout << tooLow << std::endl;

		displayMessage("Deleting both");
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX00 - Testing make copy Bureaucrat" << "\033[0m" << std::endl;

		displayMessage("Creating a Bureaucrat than create a copy of it");
		Bureaucrat origin("Origin", 100);

		displayMessage("Making a copy of it");
		Bureaucrat copyOrigin(origin);

		displayMessage("Displaying both");
		std::cout << origin << std::endl;
		std::cout << copyOrigin << std::endl;

		displayMessage("Deleting both");
	}
	
	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX00 - Testing Bureaucrat functions" << "\033[0m" << std::endl;

		displayMessage("Creating three Bureaucrat");
		Bureaucrat thomas("Thomas", 1);
		Bureaucrat* clement = new Bureaucrat("Clement", 75);
		Bureaucrat noName;

		displayMessage("Diplaying names with function getName()");
		std::cout << thomas.getName() << std::endl;
		std::cout << clement->getName() << std::endl;
		std::cout << noName.getName() << std::endl;

		displayMessage("Diplaying grades with function getGrade()");
		std::cout << thomas.getGrade() << std::endl;
		std::cout << clement->getGrade() << std::endl;
		std::cout << noName.getGrade() << std::endl;

		displayMessage("Diplaying info with operator <<");
		std::cout << thomas << std::endl;
		std::cout << *clement << std::endl;
		std::cout << noName << std::endl;

		displayMessage("Incrementing grade of Thomas than displaying stats");
		thomas.incrementGrade();
		std::cout << thomas << std::endl;

		displayMessage("Incrementing grade of Clement than displaying stats");
		clement->incrementGrade();
		std::cout << *clement << std::endl;

		displayMessage("Decrementing grade of Clement than displaying stats");
		clement->decrementGrade();
		std::cout << *clement << std::endl;

		displayMessage("Decrementing grade of noName than displaying stats");
		noName.decrementGrade();
		std::cout << noName << std::endl;

		displayMessage("Deleting all Bureaucrat");
		delete clement;
	}
	return 0;
}
