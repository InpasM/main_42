/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:34:04 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 13:04:25 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CPP
# define SCALARCONVERTER_CPP
# include <iostream>
# include <sstream>
# include <limits>

# define RED "\033[0;31m"
# define RESET "\033[0m" 
# define BOLD "\033[1m"

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter {
	public:
		static void convert(std::string const & literal);
		static void toChar(std::string const & literal);
		static void toInt(std::string const & literal);
		static void toFloat(std::string const & literal);
		static void toDouble(std::string const & literal);

		static bool isSpecial(std::string const & literal, int type);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		~ScalarConverter(void);

		ScalarConverter & operator=(ScalarConverter const & src);
};
#endif