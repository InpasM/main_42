/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:50:14 by msapin            #+#    #+#             */
/*   Updated: 2023/11/08 13:11:36 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void displayMessage(std::string msg) {
	std::cout << std::endl << YELLOW << BOLD << msg << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - SUBJECT" << RESET << std::endl;
		MutantStack<int>    mstack;

		displayMessage("Push 5 and 17 on stack and display top");
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() <<std::endl;

		mstack.pop();

		displayMessage("Display size of stack");
		std::cout << mstack.size() <<std::endl;

		displayMessage("Push 3, 5, 737, 0 and display content of stack");
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		displayMessage("Display content of stack copy of mutantStack");
		while(s.size())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - SUBJECT WITH LIST" << RESET << std::endl;
		std::list<int>    mlist;

		displayMessage("push_back 5 and 17 on list and display back");
		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << mlist.back() <<std::endl;

		mlist.pop_back();

		displayMessage("Display size of list");
		std::cout << mlist.size() <<std::endl;

		displayMessage("push_back 3, 5, 737, 0 and display content of list");
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);

		displayMessage("Display content of list copy of mlist");
		while(s.size())
		{
			std::cout << s.back() << std::endl;
			s.pop_back();
		}
	}

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - USE ITERATORS" << RESET << std::endl;
		MutantStack<int> iteratorStack;

		displayMessage("Create stack fill with 10 number and displaying it with different iterators");
		for (int i = 1; i <= 10; i++)
			iteratorStack.push(i);

		MutantStack<int>::iterator it;
		std::cout << std::endl << BLACK << BOLD << "iterator:" << RESET << std::endl;
		for (it = iteratorStack.begin(); it != iteratorStack.end(); it++)
			std::cout << *it << std::endl;

		MutantStack<int>::reverse_iterator reit;
		std::cout << std::endl << BLACK << BOLD << "reverse iterator:" << RESET << std::endl;
		for (reit = iteratorStack.rbegin(); reit != iteratorStack.rend(); reit++)
			std::cout << *reit << std::endl;

		const MutantStack<int> constStack(iteratorStack);

		MutantStack<int>::const_iterator cit;
		std::cout << std::endl << BLACK << BOLD << "const iterator:" << RESET << std::endl;
		for (cit = constStack.cbegin(); cit != constStack.cend(); cit++)
			std::cout << *cit << std::endl;

		MutantStack<int>::const_reverse_iterator creit;
		std::cout << std::endl << BLACK << BOLD << "const reverse iterator:" << RESET << std::endl;
		for (creit = constStack.crbegin(); creit != constStack.crend(); creit++)
			std::cout << *creit << std::endl;
	}
	
	return 0;
}
