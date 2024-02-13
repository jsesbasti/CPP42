/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:16:35 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/16 10:29:35 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {

}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &srcBEx ) {
	(void)srcBEx;
}

BitcoinExchange::~BitcoinExchange( void ) {

}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &srcBEx ) {
	(void)srcBEx;
	return (*this);
}

/*
	Database functions to check if it is in the correct format and it's posible
	to open the file.

	Second part saving database in a container.
*/

void	BitcoinExchange::checkFormatDB( std::ifstream &db )
{
	std::string	expectedFormat = DATA_FORMAT;
	std::string inputFormat;

	std::getline(db, inputFormat);
	if (inputFormat != expectedFormat)
	{
		db.close();
		throw std::runtime_error("Invalid header.");
	}
}

void	BitcoinExchange::checkDatabase( std::ifstream &db ) {
	db.open( DATA_BASE );
	try 
	{
		if (!db.is_open())
			throw std::logic_error("Did you deleted the database?");
		checkFormatDB(db);
	}
	catch ( const std::exception &e )
	{
		std::cout << "Database failed due: ";
		std::cout << e.what() << std::endl;
	}

}

//-------- Second part ---------

bool	BitcoinExchange::saveDatabase( std::ifstream &db, std::map<std::string, float> &info ) {
	int	lineCount = 2;
	std::string line;

	checkDatabase(db);
	while (std::getline(db, line))
	{
		std::istringstream	linestream(line);
		std::string			date;
		std::string			value;

		if (std::getline(linestream, date, ',') && std::getline(linestream, value))
		{
			try
			{
				float fvalue = stringToFloat(value);
				checkDate(date);
				info[date] = fvalue;
			}
			catch (const std::exception &e)
			{
				std::cout << "Error in CSV line " << lineCount << ": " << e.what() << std::endl;
				return (false);
			}
		}
		lineCount++;
	}
	return (true);
}

/*
	Input file functions to check the format of the inputs
	and their value in the database.
*/

void	BitcoinExchange::checkValue( std::string value ) {

	for (int i = 0; i < (int)value.length(); i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
			throw std::invalid_argument("value invalid number.");
	}
	float fvalue = stringToFloat(value);
	
	if (fvalue < 0)
		throw std::out_of_range("Negative number");
	if (fvalue > IN_MAX_VALUE)
		throw std::out_of_range("Too large number");
}

void	BitcoinExchange::checkFormatIN( std::ifstream &in, std::map<std::string, float> &info)
{
	int	lineCount = 1;
	std::string line;

	while (std::getline(in, line))
	{
		std::istringstream	linestream(line);
		std::string			date;
		std::string			value;

		if (std::getline(linestream, date, '|') && std::getline(linestream, value))
		{
			try
			{
				date = date.substr(0, 10);
				value = value.substr(1, value.length());
				float fvalue = 0;
				try
				{
					checkValue(value);
					fvalue = stringToFloat(value);
					checkDate(date);
				}
				catch (const std::exception &e)
				{
					throw std::invalid_argument(e.what());
				}
				std::map<std::string, float>::const_iterator it = info.lower_bound(date);
				if (it == info.begin() || (it != info.end() && it->first != date))
					--it;
				std::cout << date << " => " << fvalue << " = " << it->second * fvalue << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "Input file error in line " << lineCount << " due: " << e.what() << std::endl;
			}
		}
		lineCount++;
	}
}

bool	BitcoinExchange::checkFile( std::ifstream &in, const char *file, std::map<std::string, float> &info )
{
	in.open( file );
	try
	{
		if (!in.is_open())
		{
			std::string error("Cannot open the file: ");
			error.append(file);
			throw std::logic_error(error);
			return (false);
		}
	}
	catch ( const std::exception &e )
	{
		std::cout << "Problems with the input file due: ";
		std::cout << e.what() << std::endl;
	}
	checkFormatIN(in, info);
	return (true);
}

//AUX FUNCTIONS

void	BitcoinExchange::checkYear( const std::string date )
{
	std::string stringYear = date.substr(0, 4);
	int	year = stringToInt(stringYear);
	if (year < 2009 || year > 2023)
		throw std::out_of_range(" year is out of range");
}

void	BitcoinExchange::checkMonth( const std::string date )
{
	std::string stringMonth = date.substr(5, 2);
	int month = stringToInt(stringMonth);
	if (month < 1 || month > 12)
		throw std::out_of_range(" month is out of range");
}

void	BitcoinExchange::checkDay( const std::string date )
{
	std::string stringMonth = date.substr(5, 2);
	int month = stringToInt(stringMonth);
	bool thirtyOne = false;
	bool february = false;

	std::string stringDay = date.substr(8, 2);
	int day = stringToInt(stringDay);

	if (month == 2)
		february = true;
	else if (month % 2 != 0 && month <= 7)
		thirtyOne = true;
	if (month % 2 == 0 && month > 7)
		thirtyOne = true;
	if (day < 1)
		throw std::out_of_range(" day is out of range");
	if (february == true && day > 29)
		throw std::out_of_range(" day is out of range");
	else if (thirtyOne == false && day > 30)
		throw std::out_of_range(" day is out of range");
	else if (thirtyOne == true && day > 31)
		throw std::out_of_range(" day is out of range");
}

void	BitcoinExchange::checkDate( const std::string date ) {
	for ( size_t i = 0; i < date.length(); i++)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
				throw std::runtime_error("date must be separated by '-'");
		else if ((date[i] < '0' || date[i] > '9') && !(i == 4 || i == 7))
				throw std::runtime_error("only numbers accepted");
		else
			continue ;
	}
	try
	{
		checkYear(date);
		checkMonth(date);
		checkDay(date);
	}
	catch (const std::exception &e)
	{
		std::string error("Error in ");
		error.append(date);
		error.append(e.what());
		error.append("\n");
		throw std::invalid_argument(error);
	}
}

/*
	Main function of exchange where you recive the input file
*/

void	BitcoinExchange::exchange( const char *file ) {
	std::map<std::string, float>	info;
	std::ifstream					in;
	std::ifstream					db;

	if (saveDatabase(db, info) == false)
		return ;
	if (checkFile(in, file, info) == false)
		return ;
}

int stringToInt(const std::string& str) {
    const char* cStr = str.c_str();
    char* endptr;
    int result = std::strtol(cStr, &endptr, 10);
    if (*endptr != '\0' && !std::isspace(*endptr)) {
        result = 0;
    }
    return result;
}

float stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> result;
    return result;
}