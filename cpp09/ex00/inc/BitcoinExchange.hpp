/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:28:42 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/09 16:30:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# define DATA_BASE "src/data.csv"
# define DATA_FORMAT "date,exchange_rate"
# define FILE_FORMAT "date | value"

# include <iomanip>
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>

# define IN_MAX_VALUE 1000.0f

class BitcoinExchange
{
private:
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &srcBEx );
	~BitcoinExchange( void );

	BitcoinExchange	&operator=( const BitcoinExchange &srcBEx );

	static void	checkFormatDB( std::ifstream &db );
	static void	checkDatabase( std::ifstream &db );

	static void	checkFormatIN( std::ifstream &in, std::map<std::string, float> &info );
	static void	checkValue( std::string value );

	static bool	saveDatabase( std::ifstream &db, std::map<std::string, float> &info );
	static bool	checkFile( std::ifstream &in, std::string file, std::map<std::string, float> &info );

	static void	checkDate( std::string date );
	static void	checkYear( const std::string date );
	static void	checkMonth( const std::string date );
	static void	checkDay( const std::string date );

public:
	static void	exchange( std::string file );
	
};

#endif