/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:16:35 by jsebasti          #+#    #+#             */
/*   Updated: 2024/02/13 19:03:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::cout << std::setprecision(4);
	if (ac <= 2 || ac > 3000)
	{
		std::cout << "Error: Not the expected amount of arguments" << std::endl;
		std::cout << "Usage: ./PmergeMe numbers_to_order (MAX 3000 numbers)" << std::endl;
		std::cout << "Exemple: ./PmergeMe 2 1 4 3" << std::endl;
		return (1);
	}

	std::string *avc = new std::string[ac - 1];
	for (int i = 1; i  < ac; i++)
		avc[i - 1] = av[i];
	PmergeMe::order( avc, ac - 1 );
	delete [] avc;
	return (0);
}