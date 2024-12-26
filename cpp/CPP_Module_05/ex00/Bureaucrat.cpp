/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:51 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 11:15:17 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout << BLACK << "Bureaucrat: Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << BLACK << "Bureaucrat: " << name << " Overloaded constructor called" << RESET << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		this->_grade = 1;
		std::cout << RED << "Constructor " << this->_name << ": " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		this->_grade = 150;
		std::cout << RED << "Constructor " << this->_name << ": " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << RESET << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << BLACK << "Bureaucrat: " << copy._name << " Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << BLACK << "Bureaucrat: " << this->_name << " Destructor called" << RESET << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & src) {
	
	if (this != &src)
	{
		std::cout << BLACK << "Bureaucrat: Copy assignment operator" << RESET << std::endl;
		this->_grade = src._grade;
	}
	return *this;
}

const std::string & Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int newGrade) {

	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = newGrade;
}

void Bureaucrat::incrementGrade(void) {

	try {
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cout << RED << "increment: " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << RESET << std::endl;
	}
}

void Bureaucrat::decrementGrade(void) {

	try {
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cout << RED << "decrement: " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << RESET << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, const Bureaucrat & i) {

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;	
}
