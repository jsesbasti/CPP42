/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:16:12 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 11:53:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	convert_letter_to(char &c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		c = 'e';
}

void	print_array(int &num)
{
	std::cout << "[" << num << "]" << std::endl;
}

int	main( void )
{
	char	str[26] = "Mi moto alpina derrapante";
	int		array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << str << std::endl;

	iter<char>(str, 26, convert_letter_to);

	std::cout << str << std::endl;
	std::cout << std::endl;

	std::cout << "Printing the array of integers" << std::endl;
	iter<int>(array, 10, print_array);
	std::cout << "end of the array" << std::endl;

	std::cout << std::endl;

	return (0);
}