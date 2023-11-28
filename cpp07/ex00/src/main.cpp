/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:16:12 by jsebasti          #+#    #+#             */
/*   Updated: 2023/11/28 11:18:04 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main( void )
{
	int i = 0, j = 5, k = 5, h = 1;

	std::cout << "-----MAX-----" << std::endl << std::endl;

	std::cout << "Values to compare j = " << j << " & k = " << k << std::endl;

	std::cout << "before i: " << i << std::endl;
	i = max<int>(j, k);
	std::cout << "after i: " << i << std::endl;

	std::cout << std::endl;

	std::cout << "-----SWAP-----" << std::endl << std::endl;

	std::cout << "Values to swap j = " << j << " & k = " << k << std::endl;

	std::cout << "before k: " << k << std::endl;
	std::cout << "before j: " << j << std::endl;
	swap<int>(k, j);
	std::cout << "after k: " << k << std::endl;
	std::cout << "after j: " << j << std::endl;

	std::cout << std::endl;

	std::cout << "-----MIN-----" << std::endl << std::endl;

	std::cout << "Values to compare k = " << k << " & h = " << h << std::endl;

	std::cout << "before i: " << i << std::endl;
	i = min<int>(k, h);
	std::cout << "after i: " << i << std::endl;

	std::cout << std::endl;

	return (0);
}