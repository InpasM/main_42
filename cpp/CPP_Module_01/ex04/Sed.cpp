/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:58:46 by msapin            #+#    #+#             */
/*   Updated: 2023/08/27 22:37:21 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(void) {}

Sed::~Sed(void) {}

int	Sed::setFileContent(void) {

	char	c;

	if (this->_fileName.empty())
		return displayError("filename", 1);
	std::ifstream tmpFile(this->_fileName.c_str());
	if (!tmpFile.is_open())
		return displayError(this->_fileName, 2);
	while (tmpFile.get(c))
		this->_fileContent.push_back(c);
	tmpFile.close();
	return 0;
}

int	Sed::parseArgs(char** argv) {

	this->_fileName = argv[1];
	if (this->_fileName.empty())
		return displayError("filename", 1);
	if (this->setFileContent() != 0)
		return -1;
	this->_s1 = argv[2];
	this->_s2 = argv[3];
	return 0;
}

void	Sed::fillFile(std::string newContent) const {

	std::ofstream tmpFile((this->_fileName + ".replace").c_str());
	tmpFile << newContent;
	tmpFile.close();
}

void	Sed::searchFile() {

	int	i = -1;

	if (this->_s1.empty())
		this->fillFile(this->_fileContent);
	else
	{
		while (this->_fileContent[++i])
		{
			if (this->_fileContent.substr(i, this->_s1.size()) == this->_s1)
			{
				this->_newContent.append(this->_s2);
				i += this->_s1.size() - 1;
			}
			else
				this->_newContent.append(this->_fileContent.substr(i, 1));
		}
		this->fillFile(this->_newContent);
	}
}
