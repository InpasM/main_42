/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:57:33 by msapin            #+#    #+#             */
/*   Updated: 2023/11/13 21:20:08 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <ctime>
# include <string>
# include <sstream>
# include <cstdlib>

# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

void displayError(int index, std::string const & elem);

class BitcoinExchange {

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & copy);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & src);

		bool initCurrentDate(void);

		void displayResult(char * inputFileName) const;
		void displayLine(std::string const & date, std::string const & value) const;
		
		double	getResult(std::string const & date, double const & value) const;

		class MissingDatabaseException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Database: cannot be found");
				}
		};

		class InvalidDatabaseException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Database: invalid");
				}
		};

		class CannotSetDateException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Date: cannot get current date");
				}
		};

		class MissingInputFileException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Input file: cannot be open");
				}
		};

	private:
		std::map<std::string, double> _database;
		std::string _currentDate;
};

#endif