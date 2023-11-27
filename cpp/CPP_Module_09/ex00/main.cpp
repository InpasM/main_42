/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:57:31 by msapin            #+#    #+#             */
/*   Updated: 2023/11/13 21:26:55 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void displayError(int index, std::string const & elem) {

	std::string error[] = {
		"missing a file. Expect:  ./btc file",
		"too much argument. Expect:  ./btc file",
		"date empty.",
		"invalid date format.",
		"bitcoin wasn't available yet.",
		"after current date.",
		"date invalid.",
		"value empty.",
		"invalid value format.",
		"value cannot be negative.",
		"database empty.",
		"value cannot be bigger than 1000.\n",
		"cannot found this date or a more recent one.\n",
	};
	std::cout << RED << BOLD << "Error: " << RESET;
	if (index == -1)
		std::cout << elem << std::endl;
	else
	{
		if (!elem.empty())
			std::cout << elem << ": ";
		std::cout << error[index];
	}
}

int main(int argc, char * argv[]) {

	if (argc == 1)
		return (displayError(0, ""), -1);
	else if (argc > 2)
		return (displayError(1, ""), -1);
	try
	{
		BitcoinExchange datas;
		datas.displayResult(argv[1]);
	}
	catch(BitcoinExchange::InvalidDatabaseException & e) {
		std::cout << " " << e.what() << std::endl;
	}
	catch(std::exception & e) {
		std::string strWhat = e.what();
		displayError(-1, strWhat);
	}
	return 0;
}
