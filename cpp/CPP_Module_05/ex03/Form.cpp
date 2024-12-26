/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:45:34 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 14:23:32 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _isSigned(false), _gradeSign(75), _gradeExec(75) {
	std::cout << BLACK << "Form: DefaultForm constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false),
_gradeSign(this->setGradeSign(gradeSign)), _gradeExec(this->setGradeExec(gradeExec)) {
	std::cout << BLACK << "Form: " << name << " Overloaded constructor called" << RESET << std::endl;
}

Form::Form(Form const & copy) : _name(copy._name), _isSigned(copy._isSigned),
_gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {
	std::cout << BLACK << "Form: " << this->_name << " Copy constructor called" << RESET << std::endl;
}

Form::~Form(void) {
	std::cout << BLACK << "Form: " << this->_name << " Destructor called" << RESET << std::endl;
}

Form & Form::operator=(Form const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "Form: Copy assignment operator" << RESET << std::endl;
		this->_isSigned = src._isSigned;
	}
	return *this;
}

void	Form::beSigned(Bureaucrat const & member) {

	if (this->_isSigned)
		throw Form::AlreadySignedException();
	else if (member.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

bool	Form::isExecutable(Bureaucrat const & executor) const {

	if (!this->_isSigned)
		throw Form::UnsignedException();
	else if (this->_gradeExec < executor.getGrade())
		throw Form::GradeTooLowException();
	return true;
}

const std::string & Form::getName(void) const {
	return this->_name;
}

bool Form::getIsSigned(void) const {
	return this->_isSigned;
}

int Form::getGradeSign(void) const {
	return this->_gradeSign;
}

int Form::getGradeExec(void) const {
	return this->_gradeExec;
}

void Form::setIsSigned(bool isSigned) {
	this->_isSigned = isSigned;
}

int	Form::setGradeSign(int gradeSign) {

	try
	{
		if (gradeSign < 1)
			throw Form::GradeTooHighException();
		else if (gradeSign > 150)
			throw Form::GradeTooLowException();
	}
	catch(Form::GradeTooHighException& e) {
		std::cout << RED << "Form: Cannot set Sign " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << std::endl;
		return 1;
	}
	catch(Form::GradeTooLowException& e) {
		std::cout << RED << "Form: Cannot set Sign " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << std::endl;
		return 150;
	}
	return gradeSign;
}

int	Form::setGradeExec(int gradeExec) {

	try
	{
		if (gradeExec < 1)
			throw Form::GradeTooHighException();
		else if (gradeExec > 150)
			throw Form::GradeTooLowException();
	}
	catch(Form::GradeTooHighException& e) {
		std::cout << RED << "Form: Cannot set Exec " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << std::endl;
		return 1;
	}
	catch(Form::GradeTooLowException& e) {
		std::cout << RED << "Form: Cannot set Exec " << e.what()
		<< " Grade range: 1 (highest) <- 150 (lowest)" << std::endl;
		return 150;
	}
	return gradeExec;
}

std::ostream & operator<<(std::ostream & o, Form const & i) {
	o << i.getName() << ", grade to Sign: " << i.getGradeSign()
	<< ", grade to Execute: "<< i.getGradeExec() << ", ";
	if (i.getIsSigned())
		o << "signed.";
	else
		o << "unsigned.";
	return o;
}
