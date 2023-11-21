/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:36:43 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/21 10:37:08 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	std::cout << std::setprecision(4);
	if (ac != 1)
	{
		for (int i = 1; i < ac; i++)
		{
			std::string scalar = av[i];
			std::cout << std::endl;
			ScalarConverter::convert(scalar);
		}
	}
	return 0;
}