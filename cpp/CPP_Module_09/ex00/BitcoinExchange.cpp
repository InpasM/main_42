/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:57:32 by msapin            #+#    #+#             */
/*   Updated: 2023/11/13 21:25:24 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool isDateValid(std::string const & year, std::string const & month, std::string const & day) {

	std::stringstream yearStream(year);
	int y;

	yearStream >> y;
	if (month < "01" || month > "12" || day < "01" || day > "31")
		return false;
	if (month == "02")
	{
		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
			return (day <= "29");
		else
			return (day <= "28");
	}
	if (month == "4" || month == "6" || month == "9" || month == "11")
		return (day <= "30");
	return true;
}

static bool isDateFormatValid(std::string const & date) {

	if (date.size() < 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10))
		{
			if(!isdigit(date[i]))
				return false;
		}
		else if (date[i] != '-')
			return false;
	}
	return true;
}

static std::string getValidDate(std::string const & date, std::string const & currentDate) {

	if (date.empty())
		return displayError(2, ""), "";
	else if (!isDateFormatValid(date))
		return displayError(3, ""), "";
	std::stringstream dateStream(date);
	std::string year;
	std::string month;
	std::string day;

	std::getline(dateStream, year, '-');
	std::getline(dateStream, month, '-');
	std::getline(dateStream, day, '-');
	if (date < "2009-01-02")
		return displayError(4, date), "";
	else if (date > currentDate)
		return displayError(5, date), "";
	if (!isDateValid(year, month, day))
		return displayError(6, date), "";
	return date;
}

static bool isValueFormatValid(std::string const & value) {

	int numberDot = 0;

	for (unsigned int i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
			numberDot++;
		else if (!(isdigit(value[i]) || value[i] == '-' || value[i] == '+'))
			return false;
	}
	if (numberDot > 1)
		return false;
	return true;
}

static double getValidValue(std::string const & value) {

	std::stringstream valueStream(value);

	if (value.empty())
		return displayError(7, ""), -1;
	else if (!isValueFormatValid(value))
		return displayError(8, value), -1;
	double returnValue;

	valueStream >> returnValue;
	if (returnValue < 0)
		return displayError(9, value), -1;
	return returnValue;
}

BitcoinExchange::BitcoinExchange(void) {

	std::ifstream dataFile("data.csv");
	if (!dataFile.good())
		throw MissingDatabaseException();
	if (!this->initCurrentDate())
		throw CannotSetDateException();
	std::string dataContent((std::istreambuf_iterator<char>(dataFile)),
	(std::istreambuf_iterator<char>()));
	std::stringstream dataStream(dataContent);
	std::string tmpLine;

	while(!dataStream.eof())
	{
		std::getline(dataStream, tmpLine, '\n');
		if (isdigit(tmpLine[0]))
		{
			std::stringstream lineStream(tmpLine);
			std::string tmpSplit, date;
			double value = -1;

			std::getline(lineStream, tmpSplit, ',');
			date = getValidDate(tmpSplit, this->_currentDate);
			std::getline(lineStream, tmpSplit, ',');
			value = getValidValue(tmpSplit);
			if (!date.empty() && !(value < 0))
				this->_database.insert(std::pair<std::string, double>(date, value));
			else
				throw InvalidDatabaseException();
		}
	}
	if (this->_database.begin() == this->_database.end())
	{
		displayError(10, "");
		throw InvalidDatabaseException();
	}
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src) {

	if (this != &src)
	{
		this->_database = src._database;
		this->_currentDate = src._currentDate;
	}
	return *this;
}

bool BitcoinExchange::initCurrentDate(void) {

	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	std::stringstream ss;
	std::string year, month, day;

	ss << now->tm_year + 1900;
	year = ss.str();
	ss.clear();
	if (now->tm_mon + 1 < 10)
		ss << '0';
	ss << now->tm_mon + 1;
	month = ss.str();
	ss.clear();
	if (now->tm_mday < 10)
		ss << '0';
	ss << now->tm_mday;
	day = ss.str();
	if (year.empty() || month.empty() || day.empty())
		return false;
	this->_currentDate = year + '-' + month + '-' + day;
	return true;
}

double	BitcoinExchange::getResult(std::string const & date, double const & value) const {

	std::map<std::string,double>::const_iterator itfind = this->_database.find(date);

	if (itfind != this->_database.end())
		return (*itfind).second * value;
	std::map<std::string,double>::const_iterator itlow = this->_database.lower_bound(date);

	if (itlow == this->_database.begin())
		return displayError(12, date), -1;
	return (*--itlow).second * value;
}

void BitcoinExchange::displayLine(std::string const & date, std::string const & value) const {

	try
	{
		std::string validDate = getValidDate(date, this->_currentDate);
		double validValue = 0;

		if (!validDate.empty())
		{
			validValue = getValidValue(value);
			if (validValue == -1)
				std::cout << std::endl;
			else
			{
				if (validValue > 1000)
					displayError(11, value);
				else
				{
					double result = this->getResult(validDate, validValue);

					if (result != -1)
						std::cout << validDate << " => " << validValue << " = " << result << std::endl;
				}
			}
		}
		else
			std::cout << std::endl;
	}
	catch (...) {}
}

void BitcoinExchange::displayResult(char * inputFileName) const {

	std::ifstream inputFile(inputFileName);
	if (!inputFile.good())
		throw MissingInputFileException();
	std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
	(std::istreambuf_iterator<char>()));
	std::stringstream inputStream(fileContent);
	std::string tmpLine;
	while(!inputStream.eof())
	{
		std::getline(inputStream, tmpLine, '\n');
		if (isdigit(tmpLine[0]))
		{
			std::stringstream lineStream(tmpLine);
			std::string date;
			std::string value;

			std::getline(lineStream, date, '|');
			date.erase(date.find_last_not_of(' ') + 1);
			std::getline(lineStream, value);
			value.erase(0, value.find_first_not_of(' '));
			this->displayLine(date, value);
		}
	}
}
