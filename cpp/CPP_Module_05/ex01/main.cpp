/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:46 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 14:36:57 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX01 - Testing Form" << "\033[0m" << std::endl;

		displayMessage("Testing create different form");
		Form classicForm("ClassicForm", 50, 30);
		Form* newForm = new Form("NewForm", 100, 70);
		Form defaultForm;

		displayMessage("Displaying all Form");
		std::cout << classicForm << std::endl;
		std::cout << *newForm << std::endl;
		std::cout << defaultForm << std::endl;

		displayMessage("Creating copy of classicForm and displaying it");
		Form classicCopy(classicForm);
		std::cout << classicCopy << std::endl;

		displayMessage("Creating Form with grade Sign too high");
		Form gradeSignHigh("gradeSignHigh", 0, 75);

		displayMessage("Creating Form with grade Sign too low");
		Form gradeSignLow("gradeSignLow", 200, 75);

		displayMessage("Creating Form with grade Exec too high");
		Form gradeExecHigh("gradeExecHigh", 75, 0);

		displayMessage("Creating Form with grade Exec too low");
		Form gradeExecLow("gradeExecLow", 75, 200);

		displayMessage("Creating Form with both grade invalid");
		Form gradeInvalid("gradeInvalid", 0, 200);

		displayMessage("Displaying all invalid Form");
		std::cout << gradeSignHigh << std::endl;
		std::cout << gradeSignLow << std::endl;
		std::cout << gradeExecHigh << std::endl;
		std::cout << gradeExecLow << std::endl;
		std::cout << gradeInvalid << std::endl;
		
		displayMessage("Deleting all Form");
		delete newForm;
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX01 - Testing beSigned()" << "\033[0m" << std::endl;

		displayMessage("Creating two Bureaucrat with high and low grade");
		const Bureaucrat* memberHigh = new Bureaucrat("MemberHigh", 5);
		const Bureaucrat* memberLow = new Bureaucrat("MemberLow", 131);

		displayMessage("Creating high and low grade Form");
		Form highGradeForm("HighGradeForm", 25, 5);
		Form lowGradeForm("LowGradeForm", 150, 130);

		displayMessage("Displaying stats both Form");
		std::cout << highGradeForm << std::endl;
		std::cout << lowGradeForm << std::endl;

		displayMessage("Using Form function: beSigned()");
		displayMessage("highGradeForm sign by low grade Bureaucrat");
		try
		{
			highGradeForm.beSigned(*memberLow);
		}
		catch(Form::AlreadySignedException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << highGradeForm << std::endl;

		displayMessage("lowGradeForm sign by high grade Bureaucrat");
		try
		{
			lowGradeForm.beSigned(*memberHigh);
		}
		catch(Form::AlreadySignedException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << lowGradeForm << std::endl;

		displayMessage("Deleting all Form");
		delete memberHigh;
		delete memberLow;
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX01 - Testing signForm()" << "\033[0m" << std::endl;

		displayMessage("Creating Bureaucrat and a Form");
		Bureaucrat member("Member", 25);
		Form formular("Formular", 24, 10);

		displayMessage("Displaying stats of Bureaucrat");
		std::cout << member << std::endl;

		displayMessage("Displaying stats of Form");
		std::cout << formular << std::endl;

		displayMessage("Bureaucrat try to sign form");
		member.signForm(formular);

		displayMessage("Increment grade of Bureaucrat and display stats");
		member.incrementGrade();
		std::cout << member << std::endl;

		displayMessage("Try to sign with higher Grade");
		member.signForm(formular);

		displayMessage("Try to sign Form already signed");
		member.signForm(formular);

		displayMessage("Deleting all");
	}
	return 0;
}
