/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:38:11 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 09:06:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

# include <iostream>
# include <iomanip>
# include <climits>
# include <cfloat>

class ScalarConverter
{
private:
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( const ScalarConverter & src );
	ScalarConverter	&operator=( const ScalarConverter & src );

	static bool isChar( std::string _scalar );
	static bool isInt( std::string _scalar );
	static bool isFloat( std::string _scalar );
	static bool isDouble( std::string _scalar );

	static void	putChar( char character );
	static void	putInt( int num );
	static void putFloat( float num );
	static void	putDouble( double num );
	static void	put_inf_case( std::string _scalar );

	static bool	parseInput(std::string _scalar);
	static int	check_type( std::string _scalar );

public:
	static void	convert( std::string _scalar );
};

#endif