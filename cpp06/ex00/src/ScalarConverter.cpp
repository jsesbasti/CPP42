/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:38:24 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 17:48:42 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	return ;
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	(void)src;
	return ;
}

ScalarConverter::~ScalarConverter( void )
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter & src )
{
	(void)src;
	return (*this);
}

bool	ScalarConverter::isChar( std::string _scalar )
{
	if (_scalar.length() == 3 && _scalar[0] == '\'' && _scalar[2] == '\'')
	{
		if(std::isprint(_scalar[1]))
			return (true);
		else
			return (false);
	}
	return (false);
}

bool ScalarConverter::isInt( std::string _scalar )
{
	if (_scalar.length() >= 12)
		return false;
	for (int i = 0; i < (int)_scalar.length(); i++)
	{
		if (i == 0 && _scalar[i] == '-')
			continue ;
		else if (!std::isdigit(_scalar[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat( std::string _scalar )
{
	bool	dot = false;

	for (int i = 0; i < (int)_scalar.length(); i++)
	{
		if (!std::isdigit(_scalar[i]))
		{
			if (_scalar[i] == '.')
				dot = true;
			else if (i == (int)_scalar.length() - 1 && _scalar[i] == 'f' && _scalar.length() > 2)
				return (true);
			else if (i == 0 && _scalar[i] == '-')
				continue ;
			else
				return (false);
		}
	}
	return (false);
}

bool	ScalarConverter::isDouble( std::string _scalar )
{
	bool dot = false;

	for (int i = 0; i < (int)_scalar.length(); i++)
	{
		if (!std::isdigit(_scalar[i]))
		{
			if (_scalar[i] == '.' && dot == false)
				dot = true;
			else if (i == 0 && _scalar[i] == '-')
				continue ;
			else
				return (false);
		}
	}
	if (dot == true)
		return (true);
	return (false);
}

void ScalarConverter::putChar( char character )
{
	std::cout << "Char: '" << character << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(character) << std::endl;
	std::cout << "Float: " << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(character) << ".0" << std::endl;
}

void ScalarConverter::putInt( int num )
{
	if ((num < 127 && num > 0))
	{
		char c = static_cast<char>(num);
		if (std::isprint(c))
			std::cout << "Char: '" << c << "'" << std::endl;
		else
			std::cout << "Char: Non printable" << std::endl;
	}
	else
		std::cout << "Char: Out of Range" << std::endl;

	std::cout << "Int: " << num << std::endl;

	float f = static_cast<float>(num);
	if (f < FLT_MAX && f > -FLT_MAX)
		std::cout << "Float: " << f << ".0f" << std::endl;
	else
		std::cout << "Float: Out of Range" << std::endl;
	double d = static_cast<double>(num);
	std::cout << "Double: " << d << ".0" << std::endl;
}

void	ScalarConverter::putFloat( float num )
{
	if ((num < 127 && num > 0))
	{
		char c = static_cast<char>(num);
		if (std::isprint(c))
			std::cout << "Char: '" << c << "'" << std::endl;
		else
			std::cout << "Char: Non printable" << std::endl;
	}
	else
		std::cout << "Char: Out of Range" << std::endl;

	int in = static_cast<int>(num);
	if (in < INT_MAX && in > INT_MIN)
		std::cout << "Int: " << in << std::endl;
	else
		std::cout << "Int: Out of Range" << std::endl;

	std::cout << "Float: " << num << "f" << std::endl;

	std::cout << "Double: " << static_cast<double>(num) << std::endl;
}

void	ScalarConverter::putDouble( double num )
{
	if ((num < 127 && num > 0))
	{
		char c = static_cast<char>(num);
		if (std::isprint(c))
			std::cout << "Char: '" << c << "'" << std::endl;
		else
			std::cout << "Char: Non printable" << std::endl;
	}
	else
		std::cout << "Char: Out of Range" << std::endl;

	int in = static_cast<int>(num);
	if (in < INT_MAX && in > INT_MIN)
		std::cout << "Int: " << in << std::endl;
	else
		std::cout << "Int: Out of Range" << std::endl;

	float f = static_cast<float>(num);
	if (f < FLT_MAX && f > -FLT_MAX)
		std::cout << "Float: " << f << "f" << std::endl;
	else
		std::cout << "Float: Out of Range" << std::endl;

	std::cout << "Double: " << num << std::endl;
}

void	ScalarConverter::put_inf_case( std::string _scalar )
{
	std::cout << "Char: Out of Range" << std::endl;
	std::cout << "Int: Out of Range" << std::endl;
	if (_scalar == "-inf" || _scalar == "+inf" || _scalar == "nan")
	{
		std::cout << "Float: " << _scalar << "f" << std::endl;
		std::cout << "Double: " << _scalar << std::endl;
	}
	else
	{
		std::cout << "Float: " << _scalar << std::endl;
		std::cout << "Double: " << _scalar.substr(0, _scalar.length() - 1) << std::endl;
	}
}

int		ScalarConverter::check_type( std::string _scalar )
{
	bool	(*type[4])( std::string _scalar ) = \
	{&ScalarConverter::isChar, \
	 &ScalarConverter::isInt, \
	 &ScalarConverter::isFloat, \
	 &ScalarConverter::isDouble};

	for (int i = 0; i < 4; i++)
	{
		if ((type[i])(_scalar) == true)
			return (i);
	}
	return (4);
}

bool	ScalarConverter::parseInput(std::string _scalar)
{
	bool			dot = false;

	try
	{
		if (_scalar == "." || _scalar == ".f" || _scalar == "" || _scalar == "-" || _scalar == "-." || _scalar == "-.f" )
			throw std::logic_error("Parsing error, invalid digit.");
		if (isChar(_scalar))
			return (true);
		for (int i = 0; i < (int)_scalar.length(); i++)
		{
			if (_scalar[i] == '-' && i == 0)
				continue ;
			if (_scalar[i] == '.' && dot == false)
				dot = true;
			else if (_scalar[i] == '.' && dot == true)
				throw std::logic_error("Parsing error, double dot.");
			else if (i == (int)_scalar.length() - 1 && _scalar[i] == 'f' && dot == true)
				return (true);
			else if (!std::isdigit(_scalar[i]))
					throw std::logic_error("Parsing error, invalid digit.");
		}
	}
	catch (const std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}

void	ScalarConverter::convert( std::string _scalar )
{
	if (_scalar == "-inf" || _scalar == "-inff" || _scalar == "+inf" || _scalar == "+inff" || _scalar == "nanf" || _scalar == "nan")
		put_inf_case(_scalar);
	else if (parseInput(_scalar))
	{
		try
		{
			switch (check_type(_scalar))
			{
				case 0:
				{
					char c = _scalar[1];
					putChar(c);
					break ;
				}
				case 1:
				{
					int in = std::stoi(_scalar);
					putInt(in);
					break ;
				}
				case 2:
				{
					float f = std::stof(_scalar);
					putFloat(f);
					break ;
				}
				case 3:
				{
					double d = std::stod(_scalar);
					putDouble(d);
					break ;
				}
				default:
					throw std::out_of_range("Not any type");
			}
		}
		catch(std::out_of_range & error)
		{
			std::cerr << "Conversion falied beacause: " << error.what() << std::endl;
		}
	}
}
