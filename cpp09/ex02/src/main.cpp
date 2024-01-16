/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:16:35 by jsebasti          #+#    #+#             */
/*   Updated: 2024/01/16 10:08:19 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
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
}