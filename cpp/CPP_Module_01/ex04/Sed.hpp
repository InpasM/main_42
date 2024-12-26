/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:59:03 by msapin            #+#    #+#             */
/*   Updated: 2023/08/27 20:42:40 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP
# include <iostream>
# include <fstream>

class Sed {

	public:
		Sed(void);
		~Sed(void);

		int	parseArgs(char** argv);
		int	setFileContent(void);

		void	searchFile();
		void	fillFile(std::string newContent) const;

	private:
		std::string	_fileName;
		std::string	_fileContent;
		std::string	_newContent;
		std::string	_s1;
		std::string	_s2;

};

int	displayError(std::string name, int numError);

#endif